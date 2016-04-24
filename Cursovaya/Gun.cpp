#include "Gun.h"

Gun::Gun()
{
	name = "AK-47";
	holderCapacity = 30;
	damage = 10;
	range = 800;
	accuracy = 50;
}


Gun::Gun(int weaponHolder, int weaponDamage, int weaponRange, int weaponAccuracy, std::string weaponName)
{
	name = weaponName;
	holderCapacity = weaponHolder;
	damage = weaponDamage;
	range = weaponRange;
	accuracy = weaponAccuracy;
}


Gun::~Gun()
{
}