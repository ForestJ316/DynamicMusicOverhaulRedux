#include "Settings.h"
#include "Events.h"

void Settings::ReadIniSettings()
{
	constexpr auto defaultini_path = L"Data/MCM/Config/DynamicCombatMusic/settings.ini";
	constexpr auto userini_path = L"Data/MCM/Settings/DynamicCombatMusic.ini";

	const auto ReadSettingsIni = [&](std::filesystem::path path) {
		CSimpleIniA ini;
		ini.SetUnicode();
		ini.LoadFile(path.string().c_str());

		// General
		ReadBoolSetting(ini, "General", "bEnabled", bModEnabled);
		// Enemies
		// -- Fallout4.esm + DLCRobot.esm --
		// Humanoids
		ReadBoolSetting(ini, "Enemies", "bHuman", bHuman);
		ReadBoolSetting(ini, "Enemies", "bSuperMutant", bSuperMutant);
		ReadBoolSetting(ini, "Enemies", "bBehemoth", bBehemoth);
		ReadBoolSetting(ini, "Enemies", "bGhoul", bGhoul);
		// Creatures
		ReadBoolSetting(ini, "Enemies", "bMolerat", bMolerat);
		ReadBoolSetting(ini, "Enemies", "bBloodbug", bBloodbug);
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
		ReadBoolSetting(ini, "Enemies", "bRobobrain", bRobobrain);
		ReadBoolSetting(ini, "Enemies", "bEyebot", bEyebot);
		ReadBoolSetting(ini, "Enemies", "bTurret", bTurret);
		ReadBoolSetting(ini, "Enemies", "bSynth", bSynth);
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
	};
	// Read Defaults first
	ReadSettingsIni(defaultini_path);
	ReadSettingsIni(userini_path);

	if (RE::PlayerCharacter::GetSingleton()->IsInCombat() && bModEnabled)
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
