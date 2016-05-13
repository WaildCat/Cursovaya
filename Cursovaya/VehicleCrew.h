#pragma once
#include "CrewMember.h"
#include "CrewCommander.h"

class VehicleCrew
{
	friend class Interface;
	bool InVehicle;
	int Shoot(int, std::string, Vehicle&, DummyVehicle&, int);
public:
	bool GetInVehicle() const { return InVehicle; }

	void SetInVehicle(bool newValue) { InVehicle = newValue; }
	
	CrewCommander Commander;
	CrewMember Aimer;
	CrewMember Loader;
	CrewMember Shooter;
	VehicleCrew();
	~VehicleCrew();
};

