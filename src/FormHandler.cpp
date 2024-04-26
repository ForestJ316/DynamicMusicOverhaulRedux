#include "FormHandler.h"
#include "Settings.h"

void FormHandler::InitializeForms()
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
	FormHandler::GetSingleton()->MapRaces(races);
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
