#pragma once

#include <unordered_map>

// Hashing function for RE::ObjectRefHandle
// Ty to Ersh1 for the implementation!
template <class T>
struct std::hash<RE::BSPointerHandle<T>>
{
	uint32_t operator()(const RE::BSPointerHandle<T>& a_handle) const
	{
		uint32_t nativeHandle = const_cast<RE::BSPointerHandle<T>*>(&a_handle)->native_handle();
		return nativeHandle;
	}
};

namespace Events
{
	enum class ACTOR_COMBAT_STATE
	{
		kNone = 0,
		kCombat = 1,
		kSearching = 2
	};
	struct TESCombatEvent
	{
		RE::NiPointer<RE::TESObjectREFR> sourceActor;
		RE::NiPointer<RE::TESObjectREFR> targetActor;
		F4SE::stl::enumeration<ACTOR_COMBAT_STATE, std::uint32_t> newState;
	};
	class CombatEvent : public RE::BSTEventSink<TESCombatEvent>
	{
	private:
		using EventResult = RE::BSEventNotifyControl;

	public:
		static CombatEvent* GetSingleton()
		{
			static CombatEvent singleton;
			return std::addressof(singleton);
		}
		EventResult ProcessEvent(const TESCombatEvent& a_event, RE::BSTEventSource<TESCombatEvent>* a_eventSource);
		void UpdateCombatants();
		void OnCombatFinished();

		struct CombatantState
		{
			ACTOR_COMBAT_STATE combatState;
			bool playMusic;
		};
		std::unordered_map<RE::ObjectRefHandle, CombatantState> CombatantList;		
	};

	void Install();
}


