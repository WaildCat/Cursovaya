#pragma once
#include "string"

#define GetHelpInfo OfficerHelper::GetInstance().GetInfo

class OfficerHelper  //Singleton
{
	static int soldiers;
	static int weapons;
	static int vehicles;
public:
	void SetStatic(int, int);
	static OfficerHelper& GetInstance();
	static int GetNumber(int);
	std::string GetInfo(int);
	OfficerHelper();
	~OfficerHelper();
};
