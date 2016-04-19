#include "Officer.h"
#include "Soldier.h"
#include "DummySoldier.h"
#include "DummyVehicle.h"
#include <iostream>



Officer::Officer()
{
}


Officer::~Officer()
{
}


void Officer::AddSoldier()
{

}


void Officer::FireSoldier()
{

}


void Officer::ShowCurrentStatus()
{

}


void Officer::SetDistance(int *distanceToAim)
{
	// std::cout << "На какое расстояние перенести манекен? " << std::endl;
	int userDistance;
	std::cin >> userDistance;
	*distanceToAim = userDistance;
}


DummySoldier Officer::SetTarget()
{
	DummySoldier privateDummy;
	return privateDummy;
}


/* DummyVehicle Officer::SetTarget(Vehicle & MyVehicle)
{

} */