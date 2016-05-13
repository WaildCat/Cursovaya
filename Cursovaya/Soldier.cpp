#include "Soldier.h"
#include "OfficerHelper.h"
#include "Gun.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include "IOController.h"

Soldier::Soldier()
{
	HumanSize = 1;
	ShootingSkill = 75;
	SoldierDetails();
	MyGun = new Gun();
	OfficerHelper::GetInstance().SetStatic(1, 1);
}

Soldier::Soldier(std::string pName, std::string pSurname, std::string pNickname, int pShootingSkill)
{
	name = pName;
	surname = pSurname;
	nickname = pNickname;
	ShootingSkill = pShootingSkill;
	HumanSize = 1;
	MyGun = new Gun;
	OfficerHelper::GetInstance().SetStatic(1, 1);
}


Soldier::~Soldier()
{
	if (MyGun)
		MyGun->~Gun();
	OfficerHelper::GetInstance().SetStatic(-1, 1);
}


int Soldier::TakeWeapon(std::string name, int number)
{
	if (MyGun)
		return 1;
	else
	{
		templateIO myGun;
		int succes = ReadFile(myGun, "Weapons.txt", "Gun", number);
		
		if (succes == 1)
		{
			MyGun = new Gun(myGun.myIntArr[0], myGun.myIntArr[1], myGun.myIntArr[2], myGun.myIntArr[3], name);
			return 0;
		}
		else
		{
			return 2;
		}
	}
}



int Soldier::DropWeapon()
{
	if (MyGun)
	{
		delete MyGun;
		 MyGun = 0;
		return 0;
	}
	else
		return 1;
}

int Soldier::SoldierDetails()
{

		std::string pName, pSurname, pNickname, sName;
		int numName;

		std::ifstream fullName("names.loc");
		if (!fullName.is_open())
		{
			return 1;
		}
		else
		{
			while (EOF)
			{
				fullName >> pName;

				if (pName == "first") 
				{
					numName = rand() % 94 + 1;
					for (int i = 0; i < numName; i++)
						fullName >> pName;
					name = pName;
					std::getline(fullName, pName);
				}

				if (pName == "last")
				{
					numName = rand() % 101 + 1;
					for (int i = 0; i < numName; i++)
						fullName >> pName;
					surname = pName; 
					std::getline(fullName, pName);
				}

				if (pName == "nickname")
				{
					numName = rand() % 4 + 1;
					for (int i = 0; i < numName; i++)
						fullName >> pName;
					nickname = pName;
					break;
				}
			}
		}
		fullName.close();
	return 0;
}



int Soldier::ReloadWeapon()
{
	if (!MyGun)
		return 1;
	else
	{
		int newholder = 30;
		MyGun->SetHolderCapacity(newholder);
		return 0;
	}
}


int Soldier::Shoot(int distance)
{
	if (!MyGun)
		return 3;
	else
	{
		if (MyGun->GetHolderCapacity() != 0)
		{
			MyGun->SetHolderCapacity(MyGun->GetHolderCapacity() - 1);
			int chanceOfHit = ShootingSkill + 20 - (pow(distance / 10, distance / 100));



			int ifHit = chanceOfHit + rand() % chanceOfHit;

			if (ifHit > 100)
				return 1;
			else
				return 2;

		}
		else
			return 0;
	}
}



int Soldier::getMyGunHolder()
{
	return MyGun->GetHolderCapacity();
}
