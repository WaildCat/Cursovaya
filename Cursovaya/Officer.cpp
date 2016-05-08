#include "Officer.h"
#include "DummySoldier.h"
#include "IOController.h"
#include <iostream>
#include "Controller.h"
#include "Soldier.h"
#include "Gun.h"


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
	return WriteFile(mySoldier);
}


Soldier Officer::ChoseSoldier(int & number)
{
	templateIO sArr;
	std::string fileName = "Soldiers.txt";
	if (ChooseNeededElem(sArr, fileName, number) != -1)
	{
		Soldier neededSoldier(sArr.myStringArr[0], sArr.myStringArr[1], sArr.myStringArr[2], sArr.myStringArr[3], sArr.myIntArr[0]);
		neededSoldier.MyGun = new Gun();
		return neededSoldier;
	}
	else
	{
		Soldier standartSoldier;
		return standartSoldier;
	}
}



DummySoldier Officer::SetTarget()
{
	DummySoldier humanDummy;
	return humanDummy;
}


/* DummyVehicle Officer::SetTarget(Vehicle & MyVehicle)
{

} */