#include "FormHandler.h"
#include "Settings.h"

void FormHandler::InitializeForms()
{
	FormHandler::GetSingleton()->InitializeRaces();
	FormHandler::GetSingleton()->InitializeAmbience();
}

void FormHandler::InitializeRaces()
{
	logger::info("Initializing Race Forms...");
	const auto dataHandler = RE::TESDataHandler::GetSingleton();

	Races races = {
		// -- Fallout4.esm + DLCRobot.esm --
		// Humanoids
		.human = dataHandler->LookupForm<RE::TESRace>(0x13746, "Fallout4.esm"),
		.superMutant = dataHandler->LookupForm<RE::TESRace>(0x1A009, "Fallout4.esm"),
		.behemoth = dataHandler->LookupForm<RE::TESRace>(0xBB7D9, "Fallout4.esm"),
		// Ghouls
		.feralGhoul = dataHandler->LookupForm<RE::TESRace>(0x6B4EC, "Fallout4.esm"),
		.feralGhoulGlowing = dataHandler->LookupForm<RE::TESRace>(0xA96BF, "Fallout4.esm"),
		.ghoul = dataHandler->LookupForm<RE::TESRace>(0xEAFB6, "Fallout4.esm"),
		// Creatures
		.molerat = dataHandler->LookupForm<RE::TESRace>(0x1D810, "Fallout4.esm"),
		.bloodbug = dataHandler->LookupForm<RE::TESRace>(0x2456D, "Fallout4.esm"),
		.bloatfly = dataHandler->LookupForm<RE::TESRace>(0x29463, "Fallout4.esm"),
		.radroach = dataHandler->LookupForm<RE::TESRace>(0x4716C, "Fallout4.esm"),
		.stingwing = dataHandler->LookupForm<RE::TESRace>(0x5FBB1, "Fallout4.esm"),
		.radscorpion = dataHandler->LookupForm<RE::TESRace>(0x636AB, "Fallout4.esm"),
		.radstag = dataHandler->LookupForm<RE::TESRace>(0x7ED1D, "Fallout4.esm"),
		.yaoGuai = dataHandler->LookupForm<RE::TESRace>(0xA0F2F, "Fallout4.esm"),
		// Brahmin
		.brahmin = dataHandler->LookupForm<RE::TESRace>(0x2047E, "Fallout4.esm"),
		.dlc04Brahmiluff = dataHandler->LookupForm<RE::TESRace>(0x23435, "DLCNukaWorld.esm"), // DLCNukaWorld.esm
		// Deathclaws
		.deathclaw = dataHandler->LookupForm<RE::TESRace>(0x1DB4A, "Fallout4.esm"),
		.dlc04DeathclawQuantum = dataHandler->LookupForm<RE::TESRace>(0xD329, "DLCNukaWorld.esm"), // DLCNukaWorld.esm
		// Dogs
		.viciousDog = dataHandler->LookupForm<RE::TESRace>(0x3578A, "Fallout4.esm"),
		.raiderDog = dataHandler->LookupForm<RE::TESRace>(0x187AF9, "Fallout4.esm"),
		.mutantHound = dataHandler->LookupForm<RE::TESRace>(0x90C33, "Fallout4.esm"),
		.dlc03MutatedWolf = dataHandler->LookupForm<RE::TESRace>(0x3D077, "DLCCoast.esm"), // DLCCoast.esm
		// Mirelurks
		.mirelurk = dataHandler->LookupForm<RE::TESRace>(0x23FFC, "Fallout4.esm"),
		.mirelurkHunter = dataHandler->LookupForm<RE::TESRace>(0x64C60, "Fallout4.esm"),
		.mirelurkKing = dataHandler->LookupForm<RE::TESRace>(0xB7F91, "Fallout4.esm"),
		.mirelurkQueen = dataHandler->LookupForm<RE::TESRace>(0xE12A6, "Fallout4.esm"),
		// Robots
		.assaultron = dataHandler->LookupForm<RE::TESRace>(0xD8417, "Fallout4.esm"),
		.protectron = dataHandler->LookupForm<RE::TESRace>(0xDFB33, "Fallout4.esm"),
		.sentryBot = dataHandler->LookupForm<RE::TESRace>(0xAE0B7, "Fallout4.esm"),
		.mrHandy = dataHandler->LookupForm<RE::TESRace>(0x359F4, "Fallout4.esm"),
		.eyebot = dataHandler->LookupForm<RE::TESRace>(0xA563A, "Fallout4.esm"),
		.dlc01RoboBrain = dataHandler->LookupForm<RE::TESRace>(0x1129, "DLCRobot.esm"), // DLCRobot.esm
		.dlc01mrHandy = dataHandler->LookupForm<RE::TESRace>(0x27B9, "DLCRobot.esm"), // DLCRobot.esm
		.dlc03RoboBrain = dataHandler->LookupForm<RE::TESRace>(0x33E79, "DLCCoast.esm"), // DLCCoast.esm
		// Turrets
		.turretTripod = dataHandler->LookupForm<RE::TESRace>(0xB1F08, "Fallout4.esm"),
		.turretBubble = dataHandler->LookupForm<RE::TESRace>(0xB28D3, "Fallout4.esm"),
		.dlc04AnimatronicAlien = dataHandler->LookupForm<RE::TESRace>(0x19126, "DLCNukaWorld.esm"), // DLCNukaWorld.esm
		// Synths
		.synthGen1 = dataHandler->LookupForm<RE::TESRace>(0xE8D09, "Fallout4.esm"),
		.synthGen2 = dataHandler->LookupForm<RE::TESRace>(0x10BD65, "Fallout4.esm"),
		.synthGen2Valentine = dataHandler->LookupForm<RE::TESRace>(0x2261A4, "Fallout4.esm"),

		// -- DLCCoast.esm --
		.dlc03Angler = dataHandler->LookupForm<RE::TESRace>(0xFEEA, "DLCCoast.esm"),
		.dlc03FogCrawler = dataHandler->LookupForm<RE::TESRace>(0x14174, "DLCCoast.esm"),
		.dlc03HermitCrab = dataHandler->LookupForm<RE::TESRace>(0x180A8, "DLCCoast.esm"),
		// Gulpers
		.dlc03Gulper = dataHandler->LookupForm<RE::TESRace>(0x247C1, "DLCCoast.esm"),
		.dlc03GuperSmall = dataHandler->LookupForm<RE::TESRace>(0x4E28E, "DLCCoast.esm"),

		// -- DLCNukaWorld.esm --
		.dlc04Bloodworm = dataHandler->LookupForm<RE::TESRace>(0xA1A6, "DLCNukaWorld.esm"),
		.dlc04CaveCricket = dataHandler->LookupForm<RE::TESRace>(0xAAFE, "DLCNukaWorld.esm"),
		.dlc04RadRat = dataHandler->LookupForm<RE::TESRace>(0xC606, "DLCNukaWorld.esm"),
		.dlc04RadAnt = dataHandler->LookupForm<RE::TESRace>(0xCE5E, "DLCNukaWorld.esm"),
		.dlc04Gatorclaw = dataHandler->LookupForm<RE::TESRace>(0x3637A, "DLCNukaWorld.esm"),
		.dlc04Gorilla = dataHandler->LookupForm<RE::TESRace>(0x4CBCE, "DLCNukaWorld.esm")
	};
	MapRaces(races);
}

void FormHandler::MapRaces(Races& races)
{
	// -- Fallout4.esm + DLCRobot.esm --
	// Humanoids
	if (races.human)
		EnemySettings.insert({ races.human, Settings::bHuman });
	if (races.superMutant)
		EnemySettings.insert({ races.superMutant, Settings::bSuperMutant });
	if (races.behemoth)
		EnemySettings.insert({ races.behemoth, Settings::bBehemoth });
	// Ghouls
	if (races.feralGhoul)
		EnemySettings.insert({ races.feralGhoul, Settings::bGhoul });
	if (races.feralGhoulGlowing)
		EnemySettings.insert({ races.feralGhoulGlowing, Settings::bGhoul });
	if (races.ghoul)
		EnemySettings.insert({ races.ghoul, Settings::bGhoul });
	// Creatures
	if (races.molerat)
		EnemySettings.insert({ races.molerat, Settings::bMolerat });
	if (races.bloodbug)
		EnemySettings.insert({ races.bloodbug, Settings::bBloodbug });
	if (races.radroach)
		EnemySettings.insert({ races.radroach, Settings::bRadroach });
	if (races.stingwing)
		EnemySettings.insert({ races.stingwing, Settings::bStingwing });
	if (races.radscorpion)
		EnemySettings.insert({ races.radscorpion, Settings::bRadscorpion });
	if (races.radstag)
		EnemySettings.insert({ races.radstag, Settings::bRadstag });
	if (races.yaoGuai)
		EnemySettings.insert({ races.yaoGuai, Settings::bYaoGuai });
	// Brahmin
	if (races.brahmin)
		EnemySettings.insert({ races.brahmin, Settings::bBrahmin });
	if (races.dlc04Brahmiluff)
		EnemySettings.insert({ races.dlc04Brahmiluff, Settings::bBrahmin }); // DLCNukaWorld.esm
	// Deathclaws
	if (races.deathclaw)
		EnemySettings.insert({ races.deathclaw, Settings::bDeathclaw });
	if (races.dlc04DeathclawQuantum)
		EnemySettings.insert({ races.dlc04DeathclawQuantum, Settings::bDeathclaw }); // DLCNukaWorld.esm
	// Dogs
	if (races.viciousDog)
		EnemySettings.insert({ races.viciousDog, Settings::bDog });
	if (races.raiderDog)
		EnemySettings.insert({ races.raiderDog, Settings::bDog });
	if (races.mutantHound)
		EnemySettings.insert({ races.mutantHound, Settings::bDog });
	if (races.dlc03MutatedWolf)
		EnemySettings.insert({ races.dlc03MutatedWolf, Settings::bDog }); // DLCCoast.esm
	// Mirelurks
	if (races.mirelurk)
		EnemySettings.insert({ races.mirelurk, Settings::bMirelurk });
	if (races.mirelurkHunter)
		EnemySettings.insert({ races.mirelurkHunter, Settings::bMirelurk });
	if (races.mirelurkKing)
		EnemySettings.insert({ races.mirelurkKing, Settings::bMirelurk });
	if (races.mirelurkQueen)
		EnemySettings.insert({ races.mirelurkQueen, Settings::bMirelurk });
	// Robots (split into their own sections)
	if (races.assaultron)
		EnemySettings.insert({ races.assaultron, Settings::bAssaultron });
	if (races.protectron)
		EnemySettings.insert({ races.protectron, Settings::bProtectron });
	if (races.sentryBot)
		EnemySettings.insert({ races.sentryBot, Settings::bSentryBot });
	if (races.mrHandy)
		EnemySettings.insert({ races.mrHandy, Settings::bMrHandy });
	if (races.eyebot)
		EnemySettings.insert({ races.eyebot, Settings::bEyebot });	
	if (races.dlc01RoboBrain)
		EnemySettings.insert({ races.dlc01RoboBrain, Settings::bRobobrain }); // DLCRobot.esm
	if (races.dlc01mrHandy)
		EnemySettings.insert({ races.dlc01mrHandy, Settings::bMrHandy }); // DLCRobot.esm
	if (races.dlc03RoboBrain)
		EnemySettings.insert({ races.dlc03RoboBrain, Settings::bRobobrain }); // DLCCoast.esm
	// Turrets
	if (races.turretTripod)
		EnemySettings.insert({ races.turretTripod, Settings::bTurret });
	if (races.turretBubble)
		EnemySettings.insert({ races.turretBubble, Settings::bTurret });
	if (races.dlc04AnimatronicAlien)
		EnemySettings.insert({ races.dlc04AnimatronicAlien, Settings::bTurret }); // DLCNukaWorld.esm
	// Synths
	if (races.synthGen1)
		EnemySettings.insert({ races.synthGen1, Settings::bSynth });
	if (races.synthGen2)
		EnemySettings.insert({ races.synthGen2, Settings::bSynth });
	if (races.synthGen2Valentine)
		EnemySettings.insert({ races.synthGen2Valentine, Settings::bSynth });
	
	// -- DLCCoast.esm --
	if (races.dlc03Angler)
		EnemySettings.insert({ races.dlc03Angler, Settings::bAngler });
	if (races.dlc03FogCrawler)
		EnemySettings.insert({ races.dlc03FogCrawler, Settings::bFogCrawler });
	if (races.dlc03HermitCrab)
		EnemySettings.insert({ races.dlc03HermitCrab, Settings::bHermitCrab });
	// Gulpers
	if (races.dlc03Gulper)
		EnemySettings.insert({ races.dlc03Gulper, Settings::bGulper });
	if (races.dlc03GuperSmall)
		EnemySettings.insert({ races.dlc03GuperSmall, Settings::bGulper });

	// -- DLCNukaWorld.esm --
	if (races.dlc04Bloodworm)
		EnemySettings.insert({ races.dlc04Bloodworm, Settings::bBloodworm });
	if (races.dlc04CaveCricket)
		EnemySettings.insert({ races.dlc04CaveCricket, Settings::bCaveCricket });
	if (races.dlc04RadRat)
		EnemySettings.insert({ races.dlc04RadRat, Settings::bRadRat });
	if (races.dlc04RadAnt)
		EnemySettings.insert({ races.dlc04RadAnt, Settings::bRadAnt });
	if (races.dlc04Gatorclaw)
		EnemySettings.insert({ races.dlc04Gatorclaw, Settings::bGatorclaw });
	if (races.dlc04Gorilla)
		EnemySettings.insert({ races.dlc04Gorilla, Settings::bGorilla });

	logger::info("...Finished initializing Race Forms.");
}

void FormHandler::InitializeAmbience()
{
	logger::info("Initializing Ambience Forms...");
	const auto dataHandler = RE::TESDataHandler::GetSingleton();

	silentTrack = dataHandler->LookupForm<RE::BGSMusicType>(0x1BA72, "Fallout4.esm");
	if (!silentTrack)
		logger::critical("Cannot find Silent Track in Fallout4.esm! Ambience will play.");

	Ambience ambience = {
		// Exploration and Exteriors
		// -- Fallout4.esm --
		.exploreRegular = dataHandler->LookupForm<RE::BGSMusicType>(0x1ED25, "Fallout4.esm"),
		.publicOutside = dataHandler->LookupForm<RE::BGSMusicType>(0x8B1D0, "Fallout4.esm"),
		.exploreUrban = dataHandler->LookupForm<RE::BGSMusicType>(0x8792C, "Fallout4.esm"),
		.exploreFoothills = dataHandler->LookupForm<RE::BGSMusicType>(0x127358, "Fallout4.esm"),
		.exploreFoothillsSanctuary = dataHandler->LookupForm<RE::BGSMusicType>(0xD4C3E, "Fallout4.esm"),
		.exploreCoast = dataHandler->LookupForm<RE::BGSMusicType>(0x98183, "Fallout4.esm"),
		.exploreCoastAirport = dataHandler->LookupForm<RE::BGSMusicType>(0x2391BE, "Fallout4.esm"),
		.exploreGlowingSea = dataHandler->LookupForm<RE::BGSMusicType>(0xFDACB, "Fallout4.esm"),
		// -- DLCCoast.esm --
		.dlc03Explore = dataHandler->LookupForm<RE::BGSMusicType>(0x4416F, "DLCCoast.esm"),
		// -- DLCNukaWorld.esm --
		.dlc04ExploreOuter = dataHandler->LookupForm<RE::BGSMusicType>(0x2AEF2, "DLCNukaWorld.esm"),
		.dlc04ExploreInner = dataHandler->LookupForm<RE::BGSMusicType>(0x30EE4, "DLCNukaWorld.esm"),
		.dlc04ExploreInnerWestern = dataHandler->LookupForm<RE::BGSMusicType>(0x30EE5, "DLCNukaWorld.esm"),
		.dlc04ExploreInnerGalactic = dataHandler->LookupForm<RE::BGSMusicType>(0x32969, "DLCNukaWorld.esm"),
		.dlc04ExploreInnerSafari = dataHandler->LookupForm<RE::BGSMusicType>(0x378B6, "DLCNukaWorld.esm"),
		.dlc04ExploreInnerKiddie = dataHandler->LookupForm<RE::BGSMusicType>(0x3B51B, "DLCNukaWorld.esm"),
		.dlc04ExploreInnerNukaTown = dataHandler->LookupForm<RE::BGSMusicType>(0x3B51C, "DLCNukaWorld.esm"),

		// Dungeons and Interiors
		// -- Fallout4.esm --
		.dungeonA = dataHandler->LookupForm<RE::BGSMusicType>(0x2D4C2, "Fallout4.esm"),
		.dungeonB = dataHandler->LookupForm<RE::BGSMusicType>(0x1D4A6D, "Fallout4.esm"),
		.dungeonC = dataHandler->LookupForm<RE::BGSMusicType>(0x1D4A6E, "Fallout4.esm"),
		// -- DLCRobot.esm --
		.dlc01DungeonMechanistLair = dataHandler->LookupForm<RE::BGSMusicType>(0x100F0, "DLCRobot.esm"),

		// Factions
		// -- Fallout4.esm --
		.factionInstitute = dataHandler->LookupForm<RE::BGSMusicType>(0xC9FD4, "Fallout4.esm"),
		.factionBrotherhood = dataHandler->LookupForm<RE::BGSMusicType>(0xCF935, "Fallout4.esm"),
		.factionRailroad = dataHandler->LookupForm<RE::BGSMusicType>(0xCF937, "Fallout4.esm"),
		.factionMinutemen = dataHandler->LookupForm<RE::BGSMusicType>(0xD4C41, "Fallout4.esm"),
		// -- DLCCoast.esm --
		.dlc03FactionChildrenOfAtom = dataHandler->LookupForm<RE::BGSMusicType>(0x56654, "DLCCoast.esm"),
		.dlc03FactionChildrenOfAtomNucleus = dataHandler->LookupForm<RE::BGSMusicType>(0x5D104, "DLCCoast.esm")
	};
	MapAmbience(ambience);
}

void FormHandler::MapAmbience(Ambience& ambience)
{
	// -- Fallout4.esm --
	// Exploration and Exteriors
	if (ambience.exploreRegular)
		AmbienceSettings.insert({ ambience.exploreRegular, Settings::bAmbienceExplore });
	if (ambience.publicOutside)
		AmbienceSettings.insert({ ambience.publicOutside, Settings::bAmbienceExplore });
	if (ambience.exploreUrban)
		AmbienceSettings.insert({ ambience.exploreUrban, Settings::bAmbienceExplore });
	if (ambience.exploreFoothills)
		AmbienceSettings.insert({ ambience.exploreFoothills, Settings::bAmbienceExplore });
	if (ambience.exploreFoothillsSanctuary)
		AmbienceSettings.insert({ ambience.exploreFoothillsSanctuary, Settings::bAmbienceExplore });
	if (ambience.exploreCoast)
		AmbienceSettings.insert({ ambience.exploreCoast, Settings::bAmbienceExplore });
	if (ambience.exploreCoastAirport)
		AmbienceSettings.insert({ ambience.exploreCoastAirport, Settings::bAmbienceExplore });
	if (ambience.exploreGlowingSea)
		AmbienceSettings.insert({ ambience.exploreGlowingSea, Settings::bAmbienceGlowingSea });
	// Dungeons and Interiors
	if (ambience.dungeonA)
		AmbienceSettings.insert({ ambience.dungeonA, Settings::bAmbienceDungeon });
	if (ambience.dungeonB)
		AmbienceSettings.insert({ ambience.dungeonB, Settings::bAmbienceDungeon });
	if (ambience.dungeonC)
		AmbienceSettings.insert({ ambience.dungeonC, Settings::bAmbienceDungeon });
	if (ambience.dungeonVault111)
		AmbienceSettings.insert({ ambience.dungeonVault111, Settings::bAmbienceDungeon });
	// Factions
	if (ambience.factionInstitute)
		AmbienceSettings.insert({ ambience.factionInstitute, Settings::bAmbienceInstitute });
	if (ambience.factionBrotherhood)
		AmbienceSettings.insert({ ambience.factionBrotherhood, Settings::bAmbienceBrotherhood });
	if (ambience.factionRailroad)
		AmbienceSettings.insert({ ambience.factionRailroad, Settings::bAmbienceRailroad });
	if (ambience.factionMinutemen)
		AmbienceSettings.insert({ ambience.factionMinutemen, Settings::bAmbienceMinutemen });

	// -- DLCRobot.esm --
	if (ambience.dlc01DungeonMechanistLair)
		AmbienceSettings.insert({ ambience.dlc01DungeonMechanistLair, Settings::bAmbienceDLC01Dungeon });

	// -- DLCCoast.esm --
	if (ambience.dlc03Explore)
		AmbienceSettings.insert({ ambience.dlc03Explore, Settings::bAmbienceDLC03Explore });
	if (ambience.dlc03FactionChildrenOfAtom)
		AmbienceSettings.insert({ ambience.dlc03FactionChildrenOfAtom, Settings::bAmbienceDLC03ChildrenOfAtom });
	if (ambience.dlc03FactionChildrenOfAtomNucleus)
		AmbienceSettings.insert({ ambience.dlc03FactionChildrenOfAtomNucleus, Settings::bAmbienceDLC03ChildrenOfAtom });

	// -- DLCNukaWorld.esm --
	if (ambience.dlc04ExploreOuter)
		AmbienceSettings.insert({ ambience.dlc04ExploreOuter, Settings::bAmbienceDLC04Explore });
	if (ambience.dlc04ExploreInner)
		AmbienceSettings.insert({ ambience.dlc04ExploreInner, Settings::bAmbienceDLC04Explore });
	if (ambience.dlc04ExploreInnerWestern)
		AmbienceSettings.insert({ ambience.dlc04ExploreInnerWestern, Settings::bAmbienceDLC04ExploreWestern });
	if (ambience.dlc04ExploreInnerGalactic)
		AmbienceSettings.insert({ ambience.dlc04ExploreInnerGalactic, Settings::bAmbienceDLC04ExploreGalactic });
	if (ambience.dlc04ExploreInnerSafari)
		AmbienceSettings.insert({ ambience.dlc04ExploreInnerSafari, Settings::bAmbienceDLC04ExploreSafari });
	if (ambience.dlc04ExploreInnerKiddie)
		AmbienceSettings.insert({ ambience.dlc04ExploreInnerKiddie, Settings::bAmbienceDLC04ExploreKiddie });
	if (ambience.dlc04ExploreInnerNukaTown)
		AmbienceSettings.insert({ ambience.dlc04ExploreInnerNukaTown, Settings::bAmbienceDLC04ExploreNukaTown });

	logger::info("...Finished initializing Ambience Forms.");
}
