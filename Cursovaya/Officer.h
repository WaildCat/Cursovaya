#pragma once

#define DeletePrivate Officer::GetInstance().FireSoldier
#define RemovePrivate Officer::GetInstance().RemoveSoldier
#define AddPrivate Officer::GetInstance().AddSoldier
#define ChosePrivate Officer::GetInstance().ChoseSoldier

class Soldier;
class Vehicle;
class DummySoldier;
class DummyVehicle;


class Officer
{
	friend class Interface;

	int chosenDistance;

	int FireSoldier();
	int RemoveSoldier();
	int AddSoldier() const;
	Soldier ChoseSoldier(int & number);
	DummySoldier SetTarget();

	Officer();

	// DummyVehicle SetTarget(Vehicle &);

public:
	int GetDistance() const { return chosenDistance; }
	void SetDistance(int myDistance) { chosenDistance = myDistance; };

	static Officer& GetInstance();
	~Officer();
};
