#pragma once

#include <string>
#include <array>

#define GetLocStr Localization::GetInstance().GetString

using namespace std;

class Localization //Singleton
{
	static const string PRIMARY_LANG, SECONDARY_LANG;
	static const int STR_COUNT = 82;
	string curLang;
	array <string, STR_COUNT> stringSet;
	Localization();
	Localization(const Localization&);
	bool TryToLocalizate(string emergencyLang, int failedAttempts);
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
		PLANTS_LEFT = 30,
		FREE_FEMALE = 31,
		FREE_MALE = 32,
		LEVEL = 33,
		TO_THE_NEXT_LEVEL = 34,
		DEALS = 35,
		DAMAGE_PER_STEP = 36,
		HUNGER = 37,
		FRUTILIZING = 38,
		BACK = 39,
		ASK_SEX = 40,
		GUARDS_ON_THE_FARM = 41,
		PATROL = 42,
		RESTING = 43,
		CHANCE_CATCH_HOOLIGAN = 44,
		NEXT_STEP = 45,
		VILLAGERS_AT_THE_FARM = 46,
		CHECK_THE_STORAGE = 47,
		PLANTS_IN_THE_GARDEN = 48,
		FRUITS_IN_THE_STORAGE = 49,
		SIZE = 50,
		RIPNESS = 51,
		MASS = 52,
		SIZE_SMALL = 53,
		SIZE_MEDIUM = 54,
		SIZE_LARGE = 55,
		CHRONOLOGY_PAGE = 56,
		USE_ARROWS_TO_BROWSE_CHRONOLOGY = 57,
		STEP = 58,
		FAMISHED_FEMALE = 59,
		FAMISHED_MALE = 60,
		LEFT_BCS_FAMISHED_FEMALE = 61,
		LEFT_BCS_FAMISHED_MALE = 62,
		SOW = 63,
		HARVEST = 64,
		FRUTILIZE = 65,
		STRUGGLE = 66,
		ARRIVED_TO_THE_MARKET_FEMALE = 67,
		ARRIVED_TO_THE_MARKET_MALE = 68,
		SPECIFY_TYPE_FOR = 69,
		SOWED_FEMALE = 70,
		SOWED_MALE = 71,
		AT_THE_GARDEN = 72,
		JUST_SELLS_THE_OLD_MAN = 73,
		PRICE = 74,
		ASK_PURCHASE = 75,
		CANT_AFFORD_TRY_ANOTHER_DAY = 76,
		PRESS_ANY_KEY = 77,
		EXPENSES = 78,
		PLANT = 79,
		ROTTED = 80,
		REVERSE_AN_ORDER = 81,
	};
	static Localization& GetInstance();
	bool InitLocalization();
	string GetString(int n) const;
	bool SwitchLang();
	bool SetLang(string lang);
};