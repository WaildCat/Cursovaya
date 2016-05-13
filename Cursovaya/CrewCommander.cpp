#include "CrewCommander.h"
#include "Vehicle.h";
#include "IOController.h"


bool CrewCommander::LandCrew(Vehicle& Transport, VehicleCrew& Crew)
{
	if (Crew.GetInVehicle())
	{
		Crew.SetInVehicle(false);
		return true;
	}
	else
		return false;
}


bool CrewCommander::PutCrew(Vehicle& Transport, VehicleCrew& Crew)
{
	if (!Crew.GetInVehicle())
	{
		Crew.SetInVehicle(true);
		return true;
	}
	else
		return false;
}


void CrewCommander::RotateTarget(DummyVehicle& Target)
{
	Target.SetRotateDegree(Target.GetRotateDegree() + 90);
	if (Target.GetRotateDegree() >= 360)
		Target.SetRotateDegree(0);
}


CrewCommander::CrewCommander()
{
}


CrewCommander::~CrewCommander()
{
}
