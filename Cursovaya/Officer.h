#pragma once
#include <vector>
#include <string>

class Soldier;
class Vehicle;
class DummySoldier;
class DummyVehicle;


class Officer
{
	friend class Interface;

	int chosenDistance;
	int AddSoldier(std::vector<std::string> &);
	int ChoseSoldier();
	int FireSoldier();


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
