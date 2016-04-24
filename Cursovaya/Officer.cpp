#include "Officer.h"
#include "Soldier.h"
#include "DummySoldier.h"
#include "DummyVehicle.h"
#include <iostream>
#include <fstream>


Officer::Officer()
{
}


Officer::~Officer()
{
}


int Officer::AddSoldier()
{
	

	/* while ((!std::cin) || (pShootingSkill > 100 || pShootingSkill < 0))
	{

	} */

	std::ofstream newSoldier("Soldiers.txt", std::ios_base::app);
	if (!newSoldier.is_open())
	{
		return 2;
	}
	 else
	{
		std::string pName;
		std::cin >> pName;
		std::string pSurname;
		std::cin >> pSurname;
		std::string pNickname;
		std::cin >> pNickname;
		int pShootingSkill;
		std::cin >> pShootingSkill;

		newSoldier << pName << " " << pSurname << " " << pNickname << " " << pShootingSkill << std::endl;
		newSoldier.close();
		return 0;
	}
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