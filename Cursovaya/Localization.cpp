#include "Localization.h"
#include <fstream>
#include <string>

const string Localization::PRIMARY_LANG = "rus", Localization::SECONDARY_LANG = "eng";

Localization::Localization()
{
	for (int i = 0; i < STR_COUNT; i++)
		stringSet[i] = "Localization hasn't been loaded / Локализация не загружена";
}

Localization& Localization::GetInstance()
{
	static Localization instance;
	return instance;
}

bool Localization::TryToLocalizate(string emergencyLang, int failedAttempts) const
{
	string targetLang;
	if (failedAttempts == 0)
	{
		ifstream fsettings;
		fsettings.open("settings.cfg");
		if (!fsettings)
		{
			fsettings.close();
			ofstream newsettings;
			newsettings.open("settings.cfg");
			newsettings << PRIMARY_LANG;
			newsettings.close();
			fsettings.open("settings.cfg");
		}
		getline(fsettings, targetLang);
		fsettings.close();
	}
	else
		targetLang = emergencyLang;

	if (GetInstance().SetLang(targetLang))
		return true;
	else
		if (failedAttempts == 0)
		{
			if (targetLang == PRIMARY_LANG)
				return TryToLocalizate(SECONDARY_LANG, 1);
			else
				return TryToLocalizate(PRIMARY_LANG, 1);
		}
		else
			return false;
}

bool Localization::InitLocalization()
{
	return TryToLocalizate("", 0);
}

string Localization::GetString(int n) const
{
	return stringSet[n];
}


bool Localization::SwitchLang()
{
	if (curLang == PRIMARY_LANG)
		return SetLang(SECONDARY_LANG);
	else
		return SetLang(PRIMARY_LANG);
}


bool Localization::SetLang(string lang)
{
	array <string, STR_COUNT> tempLocalization;
	ifstream f;
	f.open(lang + ".loc");
	f >> lang;
	int i = 0;
	if (f)
	{
		while (i < STR_COUNT && !f.eof())
			getline(f, tempLocalization[i++]);
	}
	else
	{
		f.close();
		return false;
	}
	f.close();

	if (i < STR_COUNT)
		return false;
	else
	{
		stringSet = tempLocalization;
		curLang = lang;
		return true;
	}
}

