#pragma once

// Offsets
typedef bool(_fastcall* tShouldPlayCombatMusic)(__int64* combatManager);
static REL::Relocation<tShouldPlayCombatMusic> OriginalShouldPlayCombatMusic{ REL::ID(1280640) };

// Hooks
class Hooks
{
public:
	static void Hook()
	{
		_CanPlayCombatMusic = F4SE::GetTrampoline().write_call<5>(REL::ID(1121527).address() + 0x6F, CanPlayCombatMusic);
		_DoPrepareMusicType = REL::Relocation<uintptr_t>(RE::VTABLE::BGSMusicType[1]).write_vfunc(0x06, DoPrepareMusicType);

		logger::info("Installed Hooks.");
	}

private:
	static bool CanPlayCombatMusic(__int64* combatManager);
	static inline REL::Relocation<decltype(CanPlayCombatMusic)> _CanPlayCombatMusic;
	
	// Keep DoPrepare() for now. If some kind of bugs arise with ambience playing
	// when it shouldn't then consider hooking DoUpdate() instead.
	static void DoPrepareMusicType(RE::BSIMusicType* argMusicType);
	static inline REL::Relocation<decltype(DoPrepareMusicType)> _DoPrepareMusicType;
};
