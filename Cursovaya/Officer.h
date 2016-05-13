#pragma once

#define DeletePrivate Officer::GetInstance().FireSoldier
#define RemovePrivate Officer::GetInstance().RemoveSoldier
#define AddPrivate Officer::GetInstance().AddSoldier
#define AddCrewmember Officer::GetInstance().AddCrewMember
#include <string>

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
	int AddCrewMember() const;


	DummySoldier SetTarget();

	Officer();

	// DummyVehicle SetTarget(Vehicle &);

public:
	int GetDistance() const { return chosenDistance; }
	void SetDistance(int myDistance) { chosenDistance = myDistance; };

	static Officer& GetInstance();
	~Officer();
};
