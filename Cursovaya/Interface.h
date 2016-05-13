#pragma once
#include <vector>

class Vehicle;
class VehicleCrew;
class Officer;
class Soldier;

class Interface
{
	void ControlSoldier(Soldier&, int);
	void ControlCrew(VehicleCrew&, Vehicle&, int);
	std::string ChooseTargetPlace();
	void ControlHelper();

	template<typename T>
	void ControlSearch(T&, std::string);

	int AddToString(std::vector<std::string>&, std::string&);

	void ControlOfficerS(Officer&);
	void ControlOfficerV(Officer&);

public:
	void ChoseMenu();
	Interface();
	~Interface();
};

