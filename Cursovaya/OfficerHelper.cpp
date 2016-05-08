#include "OfficerHelper.h"
#include "Localization.h"

int OfficerHelper::soldiers = 0, OfficerHelper::weapons = 0, OfficerHelper::vehicles = 0;


OfficerHelper::OfficerHelper()
{
}


OfficerHelper::~OfficerHelper()
{
}


OfficerHelper& OfficerHelper::GetInstance()
{
	static OfficerHelper instanceHelper;
	return instanceHelper;
}


std::string OfficerHelper::GetInfo(int n)
{
	std::string fullNumOfUnits;
	char numOfUnits = (GetNumber(n) + 0x30);
	fullNumOfUnits = GetLocStr(26) + numOfUnits + GetLocStr(26 + n);
	return fullNumOfUnits;
}


int OfficerHelper::GetNumber(int n)
{
	if (n == 1)
	{
		return soldiers;
	}
	else if (n == 2)
	{
		return weapons;
	}
	else
	{
		return vehicles;
	}
}


void OfficerHelper::SetStatic(int digit, int n)
{
	if (n == 1)
	{
		soldiers += digit;
	}
	else if (n == 2)
	{
		weapons += digit;
	}
	else
	{
		vehicles += digit;
	}
}