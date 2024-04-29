#pragma once

namespace Papyrus
{
	void OnConfigClose(std::monostate);
	void PlayerCombatEnded(std::monostate);
	bool RegisterFunctions(RE::BSScript::IVirtualMachine* a_vm);
	bool FileHasForm(std::monostate, int formID, std::string fileName);
}
