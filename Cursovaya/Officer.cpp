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


int Officer::ChoseSoldier()
{
	std::ifstream chosenSoldier("Soldiers.txt");
	if (!chosenSoldier.is_open())
	{
		return 2;
	}
	else
	{
		std::string pName;
		std::cin >> pName;
		std::string nameFromFile;
		while (EOF)
		{
			chosenSoldier >> nameFromFile;
			//if (nameFromFile == pName)
		}
	}
	return 0;
}


int Officer::FireSoldier()
{
	return 1;
}


int Officer::AddSoldier(std::vector<std::string> &fullName)
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