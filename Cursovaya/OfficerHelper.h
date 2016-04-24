#pragma once
#include "string"

#define GetHelpInfo OfficerHelper::GetInstance().GetInfo

class OfficerHelper
{
	static int soldiers;
	static int weapons;
	static int vehicles;
public:
	void SetStatic(int, int);
	static int GetNumber(int);
	static OfficerHelper& GetInstance();
	std::string GetInfo(int);
	OfficerHelper();
	~OfficerHelper();
};
