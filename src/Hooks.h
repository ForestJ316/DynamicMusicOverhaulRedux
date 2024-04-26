#pragma once

#include "Events.h"
#include "Settings.h"

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
		logger::info("Installed Hooks.");
	}

private:
	static bool CanPlayCombatMusic(__int64* combatManager)
	{
		bool shouldPlay = OriginalShouldPlayCombatMusic(combatManager);
		if (!Settings::bModEnabled)
			return shouldPlay;

		if (shouldPlay)
		{
			auto& combatantList = Events::CombatEvent::GetSingleton()->CombatantList;
			for (auto it = combatantList.begin(); it != combatantList.end(); ++it)
			{
				// The moment 1 actor is valid, start playing music
				if (it->second.playMusic)
				{
					auto a_actor = it->first.get().get();
					if (a_actor && !a_actor->IsDead(true))
						return true;
				}
			}
			return false;
		}
		return shouldPlay;
	}
	static inline REL::Relocation<decltype(CanPlayCombatMusic)> _CanPlayCombatMusic;
};
