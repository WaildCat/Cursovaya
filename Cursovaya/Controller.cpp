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
		numOfFields[0] = 1;
		numOfFields[1] = 8;
	}
	else if (unitName == "Weapons")
	{
		numOfFields[0] = 1;
		numOfFields[1] = 4;
	}
	else if (unitName == "CrewMembers")
	{
		numOfFields[0] = 3;
		numOfFields[1] = 3;
	}
	else if (unitName == "VehicleGuns")
	{
		numOfFields[0] = 2;
		numOfFields[1] = 2;
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


bool Controller::AssignFields(templateIO& myArr, std::string type, Vehicle& neededUnit, VehicleGun& newGun)
{
	neededUnit.SetName(myArr.myStringArr[0]);
	neededUnit.SetArmor(true, 0, myArr.myIntArr[0]);
	neededUnit.SetArmor(true, 90, myArr.myIntArr[1]);
	neededUnit.SetArmor(true, 180, myArr.myIntArr[2]);
	neededUnit.SetArmor(false, 0, myArr.myIntArr[3]);
	neededUnit.SetArmor(false, 90, myArr.myIntArr[4]);
	neededUnit.SetArmor(false, 180, myArr.myIntArr[5]);
	neededUnit.SetBDurability(myArr.myIntArr[6]);
	neededUnit.SetTDurability(myArr.myIntArr[7]);
	neededUnit.SetADurability(100);
	neededUnit.SetTMDurability(100);
	neededUnit.SetEDurability(100);
	neededUnit.SetEngineFueled(true);
	neededUnit.MyGun->SetAmmoType(newGun.GetAmmoType());
	neededUnit.MyGun->SetArmorPiercing(newGun.GetArmorPiercing());
	neededUnit.MyGun->SetDamage(newGun.GetDamage());
	neededUnit.MyGun->SetName(newGun.GetName());
	return true;
}


bool Controller::AssignFields(templateIO& myArr, std::string type, Gun* neededUnit)
{
	Gun typeUnit(myArr.myIntArr[0], myArr.myIntArr[1], myArr.myIntArr[2], myArr.myIntArr[3], myArr.myStringArr[0]);
	*neededUnit = typeUnit;
	return true;
}


bool Controller::AssignFields(templateIO& myArr, std::string type, VehicleGun& Unit)
{
	Unit.SetName(myArr.myStringArr[0]);
	Unit.SetAmmoType(myArr.myStringArr[1]);
	Unit.SetArmorPiercing(myArr.myIntArr[0]);
	Unit.SetDamage(myArr.myIntArr[1]);
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


bool Controller::ChooseUnit(int& number, CrewMember& myUnit)
{
	templateIO sArr;
	std::string filename = "CrewMembers.txt";
	std::string unitType = filename;
	unitType.erase(unitType.find('.'), 4);
	if (ReadFile(sArr, filename, unitType, number) == 0)
	{
		CrewMember backup = myUnit;
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
	templateIO sArr, sArrGun;
	VehicleGun newGun;
	std::string filename = "Vehicles.txt";
	std::string unitType = filename;
	unitType.erase(unitType.find('.'), 4);
	if (ReadFile(sArr, filename, unitType, number) == 0 && ReadFile(sArrGun, "VehicleGuns.txt", "VehicleGuns", number) == 0)
	{
		Vehicle backup = myUnit;
		if (AssignValues(sArrGun, unitType, newGun))
		{
			if (AssignValues(sArr, unitType, myUnit, newGun))

				return true;
			else
			{
				myUnit = backup;
				return false;
			}
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


/*bool operator!(VehicleCrew& Crew)
{
	try {
		Crew = new VehicleCrew();
	}
	catch (FooError& e) {
		// ...code that handles "foo" errors...
	}
} */
