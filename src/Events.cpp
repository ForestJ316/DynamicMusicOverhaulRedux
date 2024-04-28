#include "Events.h"
#include "Settings.h"
#include "FormHandler.h"

namespace Events
{
	void Install()
	{
		REL::Relocation<RE::BSTEventSource<TESCombatEvent>*> eventSource(REL::ID(21980));
		if (eventSource.get())
		{
			eventSource->RegisterSink(CombatEvent::GetSingleton());
		}
		logger::info("Registered TesCombatEvent."sv);
	}

	CombatEvent::EventResult CombatEvent::ProcessEvent(const TESCombatEvent& a_event, RE::BSTEventSource<TESCombatEvent>*)
	{
		if (!Settings::bCombatEnabled)
			return CombatEvent::EventResult::kContinue;

		if (a_event.sourceActor && a_event.targetActor && a_event.newState)
		{
			if (a_event.targetActor->As<RE::Actor>() == RE::PlayerCharacter::GetSingleton() && a_event.newState != ACTOR_COMBAT_STATE::kNone)
			{
				auto a_sourceHandle = a_event.sourceActor->GetHandle();
				if (a_sourceHandle.native_handle() == 0x200000) // player
					return CombatEvent::EventResult::kContinue;

				if (a_event.newState == ACTOR_COMBAT_STATE::kCombat)
				{
					// Start with false, check for validity later
					CombatantList[a_sourceHandle] = { ACTOR_COMBAT_STATE::kCombat, false};
					// Check if actor is valid and set bool to true to play music accordingly
					auto a_source = a_event.sourceActor->As<RE::Actor>();
					auto& enemySettings = FormHandler::GetSingleton()->EnemySettings;
					auto it = enemySettings.find(a_source->race);
					// Default true for unspecified races
					if ((it != enemySettings.end() && it->second) || it == enemySettings.end())
						CombatantList[a_sourceHandle] = { ACTOR_COMBAT_STATE::kCombat, true};
				}
				// Enemy that is searching is invalid for combat music
				else if (a_event.newState == ACTOR_COMBAT_STATE::kSearching)
					CombatantList[a_sourceHandle] = { ACTOR_COMBAT_STATE::kSearching, false };
			}
		}
		return CombatEvent::EventResult::kContinue;
	}

	void CombatEvent::UpdateCombatants()
	{
		auto& enemySettings = FormHandler::GetSingleton()->EnemySettings;
		for (auto it = CombatantList.begin(); it != CombatantList.end(); ++it)
		{
			auto a_enemyRefr = it->first.get().get();
			if (a_enemyRefr && a_enemyRefr->As<RE::Actor>())
			{
				auto a_enemy = a_enemyRefr->As<RE::Actor>();
				auto musicSetting = enemySettings.find(a_enemy->race);
				if (musicSetting != enemySettings.end() && it->second.combatState == ACTOR_COMBAT_STATE::kCombat && it->second.playMusic != musicSetting->second)
				{
					it->second.playMusic = musicSetting->second;
				}
			}
		}
	}

	void CombatEvent::OnCombatFinished()
	{
		CombatantList.clear();
	}
}
