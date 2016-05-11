#include "Officer.h"
#include "DummySoldier.h"
#include "IOController.h"
#include <iostream>


Officer::Officer()
{
	chosenDistance = 100;
}


Officer::~Officer()
{
}


Officer& Officer::GetInstance()
{
	static Officer instanceOfficer;
	return instanceOfficer;
}


int Officer::FireSoldier()
{
	return 1;
}


int Officer::RemoveSoldier()
{
	return 0;
}


int Officer::AddSoldier() const
{
	templateIO mySoldier = InputUnitFields("Soldier");
	return WriteFile(mySoldier, "Soldiers.txt");
}


DummySoldier Officer::SetTarget()
{
	DummySoldier humanDummy;
	return humanDummy;
}


/* DummyVehicle Officer::SetTarget(Vehicle & MyVehicle)
{

} */