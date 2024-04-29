#include "Papyrus.h"
#include "Settings.h"
#include "Events.h"
#include "FormHandler.h"

namespace Papyrus
{
	void OnConfigClose(std::monostate)
	{
		Settings::ReadIniSettings();
	}

	void PlayerCombatEnded(std::monostate)
	{
		if (Settings::bCombatEnabled)
			Events::CombatEvent::GetSingleton()->OnCombatFinished();
	}

	bool FileHasForm(std::monostate, int formID, std::string fileName)
	{
		return FormHandler::GetSingleton()->CheckFileHasForm(formID, fileName);
	}

	bool RegisterFunctions(RE::BSScript::IVirtualMachine* a_vm)
	{
		a_vm->BindNativeMethod("DynamicMusic"sv, "OnConfigClose"sv, Papyrus::OnConfigClose);
		a_vm->BindNativeMethod("DynamicMusic"sv, "PlayerCombatEnded"sv, Papyrus::PlayerCombatEnded);
		a_vm->BindNativeMethod("DynamicMusic"sv, "FileHasForm"sv, Papyrus::FileHasForm);
		logger::info("Registered Papyrus native functions.");
		return true;
	}
}
