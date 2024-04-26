#pragma once

class Settings
{
public:
	static void ReadIniSettings();

	static void ReadBoolSetting(CSimpleIniA& a_ini, const char* a_sectionName, const char* a_settingName, bool& a_setting);

	// General
	static inline bool bModEnabled = true;
	// Enemies
	// -- Fallout4.esm + DLCRobot.esm --
	// Humanoids
	static inline bool bHuman = true;
	static inline bool bSuperMutant = false;
	static inline bool bBehemoth = true;
	static inline bool bGhoul = false;
	// Creatures
	static inline bool bMolerat = false;
	static inline bool bBloodbug = false;
	static inline bool bRadroach = false;
	static inline bool bStingwing = false;
	static inline bool bRadscorpion = true;
	static inline bool bRadstag = false;
	static inline bool bYaoGuai = true;
	static inline bool bBrahmin = false;
	static inline bool bDeathclaw = true;
	static inline bool bDog = false;
	static inline bool bMirelurk = true;
	// Robots
	static inline bool bMrHandy = false;
	static inline bool bEyebot = false;
	static inline bool bSentryBot = false;
	static inline bool bAssaultron = true;
	static inline bool bProtectron = false;
	static inline bool bRobobrain = false;
	static inline bool bTurret = false;
	static inline bool bSynth = true;
	// -- DLCCoast.esm --
	static inline bool bAngler = true;
	static inline bool bFogCrawler = true;
	static inline bool bHermitCrab = true;
	static inline bool bGulper = true;
	// -- DLCNukaWorld.esm --
	static inline bool bBloodworm = false;
	static inline bool bCaveCricket = false;
	static inline bool bRadRat = false;
	static inline bool bRadAnt = false;
	static inline bool bGatorclaw = true;
	static inline bool bGorilla = true;
};
