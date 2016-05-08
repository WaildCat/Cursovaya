#include <string>
#pragma once

class Gun;
class OfficerHelper;

class Soldier
{
	friend class Interface;
	friend class Officer;
	Gun *MyGun;
	
	int HumanSize;
	int ShootingSkill;

	std::string name;
	std::string surname;
	std::string nickname;
	std::string prefferedGun;

	int Shoot(int);
	int ReloadWeapon();
	int TakeWeapon(std::string);
	int DropWeapon();
	int SoldierDetails();

public:
	int getMyGunHolder();
	Soldier();
	Soldier(std::string, std::string, std::string, std::string, int);
	~Soldier();

};