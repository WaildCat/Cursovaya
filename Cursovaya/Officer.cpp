#include "Officer.h"
#include "Soldier.h"
#include "DummySoldier.h"
#include "DummyVehicle.h"
#include "ProgrammerHelper.h"
#include <iostream>
#include <fstream>
#include <vector>


Officer::Officer()
{
}


Officer::~Officer()
{
}


int Officer::ChoseSoldier(templateIO &fullName)
{
	//return ReadFile(fullName);
	return 0;
}


int Officer::FireSoldier()
{
	return 1;
}

int Officer::RemoveSoldier()
{
	return 0;
}


int Officer::AddSoldier(templateIO &fullName)
{
	return WriteFile(fullName);
}


void Officer::WriteSoldierToFile(std::vector<std::string> &pFullName, int pSkill, std::ofstream &soldiers) // Нужно ли заново открывать файл в методе?
{
	
}

void Officer::AskHelper()
{

}


void Officer::SetDistance(int *distanceToAim)
{
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