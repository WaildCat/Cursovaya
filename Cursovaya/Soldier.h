#include <string>
#pragma once

class Gun;

class Soldier
{
	friend class Interface;
	Gun *MyGun;
	
	int HumanSize;
	int ShootingSkill;
	std::string name;
	std::string surname;

	int Shoot(int);
	int ReloadWeapon();
	int TakeWeapon(std::string);
	void DropWeapon(Soldier&);

public:
	int getMyGunHolder();
	Soldier();
	~Soldier();

};