#include "Hooks.h"
#include "Events.h"
#include "Settings.h"
#include "FormHandler.h"

bool Hooks::CanPlayCombatMusic(__int64* combatManager)
{
	bool shouldPlay = OriginalShouldPlayCombatMusic(combatManager);
	if (!Settings::bCombatEnabled)
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

void Hooks::DoPrepareMusicType(RE::BSIMusicType* argMusicType)
{
	if (!Settings::bAmbienceEnabled)
		return _DoPrepareMusicType(argMusicType);

	auto musicType = static_cast<RE::BGSMusicType*>(argMusicType);
	if (!musicType)
	{
		logger::critical("Cannot cast BSIMusicType to BGSMusicType, returning default Music Type!");
		return _DoPrepareMusicType(argMusicType);
	}
	auto& ambienceSettings = FormHandler::GetSingleton()->AmbienceSettings;
	auto it = ambienceSettings.find(musicType);
	if (it != ambienceSettings.end() && !it->second)
	{
		auto silentTrack = FormHandler::GetSingleton()->silentTrack;
		if (silentTrack)
			return _DoPrepareMusicType(silentTrack);
	}
	return _DoPrepareMusicType(argMusicType); // Just return regular for valid tracks and non-ambience
}
