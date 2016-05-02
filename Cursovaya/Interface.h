#pragma once
#include <string>
#include <vector>
class Soldier;

class Interface
{
	void ControlSoldier(Soldier&, int);
	void ControlHelper();
	void ControlSearch();
	void CheckInput(int&);
	void CheckInput(std::string &);
	int AddToString(std::vector<std::string>&, std::string&);

public:
	void ControlOfficer();
	Interface();
	~Interface();
};

