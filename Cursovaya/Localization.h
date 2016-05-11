#pragma once

#include <array>

#define GetLocStr Localization::GetInstance().GetString

using namespace std;

class Localization //Singleton
{
	static const string PRIMARY_LANG, SECONDARY_LANG;
	static const int STR_COUNT = 63;
	string curLang;
	array <string, STR_COUNT> stringSet;
	Localization();
	Localization(const Localization&);
	bool TryToLocalizate(string emergencyLang, int failedAttempts) const;
public:
	enum Strings
	{
		LANG = 0,
		ADD_SOLDIER = 1,
		FIRE_SOLDIER = 2,
		SHOW_SATUS = 3,
		CHANGE_DISTANCE = 4,
		SET_TARGET = 5,
		GOTO_SCONTROLL = 6,
		SWITCH_LANG = 7,
		EXIT = 8,
		TAKE_WEAPON = 9,
		SHOOT = 10,
		RELOAD = 11,
		DROP_WEAPON = 12,
		WEAPON_EXIST = 13,
		ENTER_WNAME = 14,
		CANT_OPEN_FILE = 15,
		CANT_FIND_WEAPON = 16,
		WCHANGE_SUCCES = 17,
		MISS = 18,
		HIT = 19,
		AMMO = 20,
		LEFT = 21,
		RELOAD_YOUR_WEAPON = 22,
		WEAPON_DROPPED = 23,
		DONT_HAVE_WEAPON = 24,
		ENTER_DISTANCE = 25,
		SPACE_OR_NOW_ON_POLYGON = 26,
		SOLDIERS = 27,
		WEAPONS = 28,
		ARMORED_VEHICLES = 29,
		ENTER_SNAME = 30,
		ENTER_SSURNAME = 31,
		ENTER_SNICKNAME = 32,
	};
	static Localization& GetInstance();
	bool InitLocalization();
	string GetString(int n) const;
	bool SwitchLang();
	bool SetLang(string lang);
};