#include "Settings.h"
#include "Events.h"
#include "Hooks.h"

void Settings::ReadIniSettings()
{
	constexpr auto defaultini_path = L"Data/MCM/Config/DynamicMusicOverhaulRedux/settings.ini";
	constexpr auto userini_path = L"Data/MCM/Settings/DynamicMusicOverhaulRedux.ini";

	const auto ReadSettingsIni = [&](std::filesystem::path path) {
		CSimpleIniA ini;
		ini.SetUnicode();
		ini.LoadFile(path.string().c_str());

		// General
		ReadBoolSetting(ini, "General", "bCombatEnabled", bCombatEnabled);
		ReadBoolSetting(ini, "General", "bAmbienceEnabled", bAmbienceEnabled);

		// Enemies
		// -- Fallout4.esm --
		// Humanoids
		ReadBoolSetting(ini, "Enemies", "bHuman", bHuman);
		ReadBoolSetting(ini, "Enemies", "bSuperMutant", bSuperMutant);
		ReadBoolSetting(ini, "Enemies", "bBehemoth", bBehemoth);
		ReadBoolSetting(ini, "Enemies", "bGhoul", bGhoul);
		// Creatures
		ReadBoolSetting(ini, "Enemies", "bMolerat", bMolerat);
		ReadBoolSetting(ini, "Enemies", "bBloodbug", bBloodbug);
		ReadBoolSetting(ini, "Enemies", "bBloatfly", bBloatfly);
		ReadBoolSetting(ini, "Enemies", "bRadroach", bRadroach);
		ReadBoolSetting(ini, "Enemies", "bStingwing", bStingwing);
		ReadBoolSetting(ini, "Enemies", "bRadscorpion", bRadscorpion);
		ReadBoolSetting(ini, "Enemies", "bRadstag", bRadstag);
		ReadBoolSetting(ini, "Enemies", "bYaoGuai", bYaoGuai);
		ReadBoolSetting(ini, "Enemies", "bBrahmin", bBrahmin);
		ReadBoolSetting(ini, "Enemies", "bDeathclaw", bDeathclaw);
		ReadBoolSetting(ini, "Enemies", "bDog", bDog);
		ReadBoolSetting(ini, "Enemies", "bMirelurk", bMirelurk);
		// Robots
		ReadBoolSetting(ini, "Enemies", "bAssaultron", bAssaultron);
		ReadBoolSetting(ini, "Enemies", "bProtectron", bProtectron);
		ReadBoolSetting(ini, "Enemies", "bSentryBot", bSentryBot);
		ReadBoolSetting(ini, "Enemies", "bMrHandy", bMrHandy);
		ReadBoolSetting(ini, "Enemies", "bEyebot", bEyebot);
		ReadBoolSetting(ini, "Enemies", "bTurret", bTurret);
		ReadBoolSetting(ini, "Enemies", "bSynth", bSynth);
		// -- DLCRobot.esm --
		ReadBoolSetting(ini, "Enemies", "bRobobrain", bRobobrain);
		// -- DLCCoast.esm --
		ReadBoolSetting(ini, "Enemies", "bAngler", bAngler);
		ReadBoolSetting(ini, "Enemies", "bFogCrawler", bFogCrawler);
		ReadBoolSetting(ini, "Enemies", "bHermitCrab", bHermitCrab);
		ReadBoolSetting(ini, "Enemies", "bGulper", bGulper);
		// -- DLCNukaWorld.esm --
		ReadBoolSetting(ini, "Enemies", "bBloodworm", bBloodworm);
		ReadBoolSetting(ini, "Enemies", "bCaveCricket", bCaveCricket);
		ReadBoolSetting(ini, "Enemies", "bRadRat", bRadRat);
		ReadBoolSetting(ini, "Enemies", "bRadAnt", bRadAnt);
		ReadBoolSetting(ini, "Enemies", "bGatorclaw", bGatorclaw);
		ReadBoolSetting(ini, "Enemies", "bGorilla", bGorilla);

		// Ambience
		// -- Fallout4.esm --
		ReadBoolSetting(ini, "Ambience", "bAmbienceExplore", bAmbienceExplore);
		ReadBoolSetting(ini, "Ambience", "bAmbienceGlowingSea", bAmbienceGlowingSea);
		ReadBoolSetting(ini, "Ambience", "bAmbienceDungeon", bAmbienceDungeon);
		ReadBoolSetting(ini, "Ambience", "bAmbienceInstitute", bAmbienceInstitute);
		ReadBoolSetting(ini, "Ambience", "bAmbienceBrotherhood", bAmbienceBrotherhood);
		ReadBoolSetting(ini, "Ambience", "bAmbienceRailroad", bAmbienceRailroad);
		ReadBoolSetting(ini, "Ambience", "bAmbienceMinutemen", bAmbienceMinutemen);		
		// -- DLCRobot.esm --
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC01Dungeon", bAmbienceDLC01Dungeon);
		// -- DLCCoast.esm --
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC03Explore", bAmbienceDLC03Explore);
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC03ChildrenOfAtom", bAmbienceDLC03ChildrenOfAtom);
		// -- DLCNukaWorld.esm --
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC04Explore", bAmbienceDLC04Explore);
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC04ExploreWestern", bAmbienceDLC04ExploreWestern);
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC04ExploreGalactic", bAmbienceDLC04ExploreGalactic);
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC04ExploreSafari", bAmbienceDLC04ExploreSafari);
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC04ExploreKiddie", bAmbienceDLC04ExploreKiddie);
		ReadBoolSetting(ini, "Ambience", "bAmbienceDLC04ExploreNukaTown", bAmbienceDLC04ExploreNukaTown);

		// Compatibility
		// Faded Glory. Includes Music Mods Merged.
		ReadBoolSetting(ini, "Compatibility", "bAmbienceFadedGloryVault88", bAmbienceFadedGloryVault88);
	};
	// Read Defaults first
	ReadSettingsIni(defaultini_path);
	ReadSettingsIni(userini_path);

	// If MCM updated in combat
	if (RE::PlayerCharacter::GetSingleton()->IsInCombat() && bCombatEnabled)
		Events::CombatEvent::GetSingleton()->UpdateCombatants();
}

void Settings::ReadBoolSetting(CSimpleIniA& a_ini, const char* a_sectionName, const char* a_settingName, bool& a_setting)
{
	const char* bFound = nullptr;
	bFound = a_ini.GetValue(a_sectionName, a_settingName);
	if (bFound)
	{
		a_setting = a_ini.GetBoolValue(a_sectionName, a_settingName);
	}
}
