#pragma once

#include <unordered_map>

class FormHandler
{
public:
	static FormHandler* GetSingleton()
	{
		static FormHandler singleton;
		return std::addressof(singleton);
	}

	static void InitializeForms();
	void InitializeRaces();
	void InitializeAmbience();
	
	// Silent Track
	RE::BGSMusicType* silentTrack;

private:
	struct Races
	{
		// -- Fallout4.esm + DLCRobot.esm --
		// Humanoids
		RE::TESRace* human;
		RE::TESRace* superMutant;
		RE::TESRace* behemoth;
		// Ghouls
		RE::TESRace* feralGhoul;
		RE::TESRace* feralGhoulGlowing;
		RE::TESRace* ghoul;
		// Creatures
		RE::TESRace* molerat;
		RE::TESRace* bloodbug;
		RE::TESRace* bloatfly;
		RE::TESRace* radroach;
		RE::TESRace* stingwing;
		RE::TESRace* radscorpion;
		RE::TESRace* radstag;
		RE::TESRace* yaoGuai;
		// Brahmin
		RE::TESRace* brahmin;
		RE::TESRace* dlc04Brahmiluff; // DLCNukaWorld.esm
		// Deathclaws
		RE::TESRace* deathclaw;
		RE::TESRace* dlc04DeathclawQuantum; // DLCNukaWorld.esm
		// Dogs
		RE::TESRace* viciousDog;
		RE::TESRace* raiderDog;
		RE::TESRace* mutantHound;
		RE::TESRace* dlc03MutatedWolf; // DLCCoast.esm
		// Mirelurks
		RE::TESRace* mirelurk;
		RE::TESRace* mirelurkHunter;
		RE::TESRace* mirelurkKing;
		RE::TESRace* mirelurkQueen;
		// Robots
		RE::TESRace* assaultron;
		RE::TESRace* protectron;
		RE::TESRace* sentryBot;
		RE::TESRace* mrHandy;
		RE::TESRace* eyebot;
		RE::TESRace* dlc01RoboBrain; // DLCRobot.esm
		RE::TESRace* dlc01mrHandy; // DLCRobot.esm
		RE::TESRace* dlc03RoboBrain; // DLCCoast.esm
		// Turrets
		RE::TESRace* turretTripod;
		RE::TESRace* turretBubble;
		RE::TESRace* dlc04AnimatronicAlien; // DLCNukaWorld.esm
		// Synths
		RE::TESRace* synthGen1;
		RE::TESRace* synthGen2;
		RE::TESRace* synthGen2Valentine;

		// -- DLCCoast.esm --
		RE::TESRace* dlc03Angler;
		RE::TESRace* dlc03FogCrawler;
		RE::TESRace* dlc03HermitCrab;
		// Gulpers
		RE::TESRace* dlc03Gulper;
		RE::TESRace* dlc03GuperSmall;

		// -- DLCNukaWorld.esm --
		RE::TESRace* dlc04Bloodworm;
		RE::TESRace* dlc04CaveCricket;
		RE::TESRace* dlc04RadRat;
		RE::TESRace* dlc04RadAnt;
		RE::TESRace* dlc04Gatorclaw;
		RE::TESRace* dlc04Gorilla;
	};
	void MapRaces(Races& races);
	
	struct Ambience
	{
		// Exploration and Exteriors
		// -- Fallout4.esm --
		RE::BGSMusicType* exploreRegular;
		RE::BGSMusicType* publicOutside;
		RE::BGSMusicType* exploreUrban;
		RE::BGSMusicType* exploreFoothills;
		RE::BGSMusicType* exploreFoothillsSanctuary;
		RE::BGSMusicType* exploreCoast;
		RE::BGSMusicType* exploreCoastAirport;
		RE::BGSMusicType* exploreGlowingSea;
		// -- DLCCoast.esm --
		RE::BGSMusicType* dlc03Explore;
		// -- DLCNukaWorld.esm --
		RE::BGSMusicType* dlc04ExploreOuter;
		RE::BGSMusicType* dlc04ExploreInner;
		RE::BGSMusicType* dlc04ExploreInnerWestern;
		RE::BGSMusicType* dlc04ExploreInnerGalactic;
		RE::BGSMusicType* dlc04ExploreInnerSafari;
		RE::BGSMusicType* dlc04ExploreInnerKiddie;
		RE::BGSMusicType* dlc04ExploreInnerNukaTown;

		// Dungeons and Interiors
		// -- Fallout4.esm --
		RE::BGSMusicType* dungeonA;
		RE::BGSMusicType* dungeonB;
		RE::BGSMusicType* dungeonC;
		RE::BGSMusicType* dungeonVault111;
		// -- DLCRobot.esm --
		RE::BGSMusicType* dlc01DungeonMechanistLair;

		// Factions
		// -- Fallout4.esm --
		RE::BGSMusicType* factionInstitute;
		RE::BGSMusicType* factionBrotherhood;
		RE::BGSMusicType* factionRailroad;
		RE::BGSMusicType* factionMinutemen;
		// -- DLCCoast.esm --
		RE::BGSMusicType* dlc03FactionChildrenOfAtom;
		RE::BGSMusicType* dlc03FactionChildrenOfAtomNucleus;
	};
	void MapAmbience(Ambience& ambience);
	
public:
	std::unordered_map<RE::TESRace*, bool&> EnemySettings;
	std::unordered_map<RE::BGSMusicType*, bool&> AmbienceSettings;
};
