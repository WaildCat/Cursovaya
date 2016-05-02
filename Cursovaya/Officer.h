#pragma once
#include <vector>
#include <string>
#include "ProgrammerHelper.h"

class Soldier;
class Vehicle;
class DummySoldier;
class DummyVehicle;


class Officer
{
	friend class Interface;

	int chosenDistance;
	int AddSoldier(templateIO&);
	int ChoseSoldier(templateIO&);
	int FireSoldier();
	int RemoveSoldier();


	void WriteSoldierToFile(std::vector<std::string> &, int,  std::ofstream&);
	void AskHelper();
	void SetDistance(int*);
	int GetDistance() { return chosenDistance; }
	DummySoldier SetTarget();

public:
	Officer();
	~Officer();
	// DummyVehicle SetTarget(Vehicle &);
};
