#include "Controller.h"
#include "IOController.h"
#include "Soldier.h"
#include "Vehicle.h"
#include "Gun.h"

class ErrorsCatcher;

Controller::Controller()
{
}


Controller::~Controller()
{
}


int Controller::CheckValues(int x, int lowerBorder, int upperBorder) const
{
	if (x > upperBorder || x < lowerBorder)
	{
		return 1;
	}
	return 0;
}

int Controller::CheckValues(std::string & pName) const
{
	//if (isdigit(pName.at(0)))
	for (int i = 0; i < 10; i++)
	{
		if (pName.at(0) == (i + 0x30))
			return 2;
	}

	for (int i = 0; i < pName.length(); i++)
	{
		if (pName.at(i) == ' ')
			return 1;
	}

	return 0;
}



int* Controller::GetNumOfFields(std::string unitName)
{
	int numOfFields[2];

	if (unitName == "Soldiers")
	{
		numOfFields[0] = 3;
		numOfFields[1] = 1;
	}
	else if (unitName == "Vehicles")
	{
		numOfFields[0] = 0;
		numOfFields[1] = 0;
	}
	else if (unitName == "Weapons")
	{
		numOfFields[0] = 1;
		numOfFields[1] = 4;
	}
	else
	{
		numOfFields[0] = 0;
		numOfFields[1] = 0;
	}
		return numOfFields;
}


Controller& Controller::GetInstance()
{
	static Controller instanceController;
	return instanceController;
}



bool Controller::AssignFields(templateIO& myArr, std::string type, Soldier& neededUnit)
{
	Soldier typeUnit(myArr.myStringArr[0], myArr.myStringArr[1], myArr.myStringArr[2], myArr.myIntArr[0]);
	neededUnit = typeUnit;
	return true;
}


bool Controller::AssignFields(templateIO& myArr, std::string type, Vehicle& neededUnit)
{
//	Vehicle typeUnit(myArr.myStringArr[0]);
	//neededUnit = typeUnit;
	return true;
}


bool Controller::AssignFields(templateIO& myArr, std::string type, Gun* neededUnit)
{
	Gun typeUnit(myArr.myIntArr[0], myArr.myIntArr[1], myArr.myIntArr[2], myArr.myIntArr[3], myArr.myStringArr[0]);
	*neededUnit = typeUnit;
	return true;
}


bool Controller::AssignFields(templateIO& myArr, std::string type, VehicleGun& neededUnit)
{
//	VehicleGun typeUnit(myArr.myStringArr[0], myArr.myStringArr[1], myArr.myStringArr[2], myArr.myIntArr[0]);
//	neededUnit = typeUnit;
	return true;
}


bool Controller::ChooseUnit(int & number, Soldier& myUnit)
{
	templateIO sArr;
	std::string filename = "Soldiers.txt";
	std::string unitType = filename;
	unitType.erase(unitType.find('.'), 4);
	if (ReadFile(sArr, filename, unitType, number) == 0)
	{
		Soldier backup = myUnit;
		if (AssignValues(sArr, unitType, myUnit))
			return true;
		else
		{
			myUnit = backup;
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Controller::ChooseUnit(int & number, Vehicle& myUnit)
{
	templateIO sArr;
	std::string filename = "Vehicles.txt";
	std::string unitType = filename.erase(filename.find('.'), 4);
	if (ReadFile(sArr, filename, unitType, number) == 0)
	{
		Vehicle backup = myUnit;
		if (AssignValues(sArr, unitType, myUnit))
			return true;
		else
		{
			myUnit = backup;
			return false;
		}
	}
	else
	{
		return false;
	}
}


bool Controller::ChooseUnit(int & number, Gun* myUnit)
{
	templateIO sArr;
	std::string filename = "Weapons.txt";
	std::string unitType = filename.erase(filename.find('.'), 4);
	if (ReadFile(sArr, filename, unitType, number) == 0)
	{
		Gun backup = *myUnit;
		if (AssignValues(sArr, unitType, myUnit))
			return true;
		else
		{
			*myUnit = backup;
			return false;
		}
	}
	else
	{
		return false;
	}
}

