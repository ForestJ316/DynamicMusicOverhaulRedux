#include "Hooks.h"
#include "Papyrus.h"
#include "Settings.h"
#include "Events.h"
#include "FormHandler.h"

namespace
{
	void InitializeLog()
	{
#ifndef NDEBUG
		auto sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
#else
		auto path = logger::log_directory();
		if (!path) {
			util::report_and_fail("Failed to find standard logging directory"sv);
		}

		*path /= fmt::format("{}.log"sv, Version::PROJECT.data());
		auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
#endif

#ifndef NDEBUG
		const auto level = spdlog::level::trace;
#else
		const auto level = spdlog::level::info;
#endif

		auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));
		log->set_level(level);
		log->flush_on(level);

		spdlog::set_default_logger(std::move(log));
		spdlog::set_pattern("[%H:%M:%S:%e] %v"s);
	}

	void MessageHandler(F4SE::MessagingInterface::Message* a_msg)
	{
		switch (a_msg->type)
		{
			case F4SE::MessagingInterface::kGameDataReady:
				logger::info("{:*^50}", "GAME DATA READY"sv);
				Settings::ReadIniSettings();
				Events::Install();
				FormHandler::InitializeForms();
				logger::info("{:*^50}", ""sv);
				break;
			case F4SE::MessagingInterface::kPreLoadGame:
				Events::CombatEvent::GetSingleton()->OnCombatFinished();
				break;
			default:
				break;
		}
	}

	extern "C" DLLEXPORT bool F4SEAPI F4SEPlugin_Query(const F4SE::QueryInterface * a_f4se, F4SE::PluginInfo * a_info)
	{
		a_info->infoVersion = F4SE::PluginInfo::kVersion;
		a_info->name = Version::PROJECT.data();
		a_info->version = Version::MAJOR;

		const auto ver = a_f4se->RuntimeVersion();
		if (ver < F4SE::RUNTIME_1_10_162) {
			logger::critical("Unsupported Runtime v{}", ver.string());
			return false;
		}

		return true;
	}

	extern "C" DLLEXPORT bool F4SEAPI F4SEPlugin_Load(const F4SE::LoadInterface * a_f4se)
	{
		InitializeLog();
		logger::info(FMT_STRING("{} v{}"), Version::PROJECT.data(), Version::MAJOR);
		logger::info("Game version : {}", a_f4se->RuntimeVersion().string());

		F4SE::Init(a_f4se);
		F4SE::AllocTrampoline(1 * 1024);

		if (!F4SE::GetMessagingInterface()->RegisterListener(MessageHandler))
		{
			logger::critical("Cannot register listener!");
			return false;
		}

		const auto papyrus = F4SE::GetPapyrusInterface();
		if (!papyrus || !papyrus->Register(Papyrus::RegisterFunctions))
		{
			logger::critical("Cannot register Papyrus native functions!");
			return false;
		}

		Hooks::Hook();

		return true;
	}
}
