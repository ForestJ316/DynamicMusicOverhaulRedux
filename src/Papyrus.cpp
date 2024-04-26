#include "Papyrus.h"
#include "Settings.h"
#include "Events.h"

namespace Papyrus
{
	void OnConfigClose(std::monostate)
	{
		Settings::ReadIniSettings();
	}

	void PlayerCombatEnded(std::monostate)
	{
		Events::CombatEvent::GetSingleton()->OnCombatFinished();
	}

	bool RegisterFunctions(RE::BSScript::IVirtualMachine* a_vm)
	{
		a_vm->BindNativeMethod("DynamicMusic"sv, "OnConfigClose"sv, Papyrus::OnConfigClose);
		a_vm->BindNativeMethod("DynamicMusic"sv, "PlayerCombatEnded"sv, Papyrus::PlayerCombatEnded);
		logger::info("Registered Papyrus native functions.");
		return true;
	}
}
