#include "Soldier.h"
#include "Gun.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <math.h>


Soldier::Soldier()
{
	HumanSize = 1;
	ShootingSkill = 75;
	MyGun = new Gun();
}


Soldier::~Soldier()
{
}


int Soldier::TakeWeapon(std::string name)
{
	if (MyGun)
		return 1;
	else
	{
		int weponDamage, weaponAccuracy, weaponRange, weaponHolder;
		std::string wNameFromFile = "name = ";
		wNameFromFile += name;

		std::ifstream myWeapon("Weapons.txt");
		if (!myWeapon.is_open())
		{
			return 2;
		}
		else
		{
			while (std::getline(myWeapon, wNameFromFile))
				if (wNameFromFile == name) {
					std::cout << "ÓÐÐÐÀÀÀÀ";
					break;
				}
			return 0;
		}
		myWeapon.close();
	}
}



void Soldier::DropWeapon(Soldier& Private)
{
	~MyGun();
	/* if (Private.MyGun)
	{
		Private.~MyGun();
	}
	*/
}



int Soldier::ReloadWeapon()
{
	int newholder = 30;
	if (MyGun->GetHolderCapacity() != newholder)
	{
		MyGun->SetHolderCapacity(newholder);
		return 1;
	}
	else
		return 0;
}


int Soldier::Shoot(int distance)
{
	if (MyGun->GetHolderCapacity() != 0)
	{
		MyGun->SetHolderCapacity( MyGun->GetHolderCapacity() - 1 );
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

int Soldier::getMyGunHolder()
{
	return MyGun->GetHolderCapacity();
}
