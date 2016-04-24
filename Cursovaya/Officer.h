#pragma once

class Soldier;
class Vehicle;
class DummySoldier;
class DummyVehicle;


class Officer
{
	friend class Interface;

	int chosenDistance;

	int AddSoldier();
	int ChoseSoldier();
	int FireSoldier();
	void AskHelper();
	void SetDistance(int*);
	DummySoldier SetTarget();

public:
	Officer();
	~Officer();
	// DummyVehicle SetTarget(Vehicle &);
};
