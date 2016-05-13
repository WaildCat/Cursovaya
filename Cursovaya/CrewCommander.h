#pragma once
#include "Officer.h"
class VehicleCrew;

class CrewCommander
{
	friend class Interface;
	bool LandCrew(Vehicle&, VehicleCrew&);
	bool PutCrew(Vehicle&, VehicleCrew&);
	void RotateTarget(DummyVehicle&);
public:
	CrewCommander();
	~CrewCommander();
};

