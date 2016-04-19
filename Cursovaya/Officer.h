#pragma once

class Soldier;
class Vehicle;
class DummySoldier;
class DummyVehicle;


class Officer
{
	friend class Interface;

	int chosenDistance;

	void AddSoldier();
	void FireSoldier();
	void ShowCurrentStatus();
	void SetDistance(int*);
	DummySoldier SetTarget();

public:
	Officer();
	~Officer();
	// DummyVehicle SetTarget(Vehicle &);
};
