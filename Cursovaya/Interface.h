#pragma once
#include <vector>
class Soldier;

class Interface
{
	void ControlSoldier(Soldier&, int);
	void ControlHelper();
	void ControlSearch();
	int AddToString(std::vector<std::string>&, std::string&);

public:
	void ControlOfficer();
	Interface();
	~Interface();
};

