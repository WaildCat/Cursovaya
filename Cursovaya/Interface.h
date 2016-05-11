#pragma once
#include <vector>

class Officer;
class Soldier;

class Interface
{
	void ControlSoldier(Soldier&, int);
	void ControlHelper();

	template<typename T>
	void ControlSearch(T&, std::string);

	int AddToString(std::vector<std::string>&, std::string&);

	void ControlOfficerS(Officer&);
	void ControlOfficerV(Officer&);
	void ControlOfficerA(Officer&);

public:
	void ChoseMenu();
	Interface();
	~Interface();
};

