#include <string>
#pragma once

class Gun;
class OfficerHelper;

class Soldier
{
	friend class Interface;
//	friend class Officer;
	Gun *MyGun;
	
	std::string prefferedGun;

	int TakeWeapon(std::string, int);
	int DropWeapon();

protected:
	int HumanSize;
	int ShootingSkill;
	std::string name;
	std::string surname;
	std::string nickname;

	int Shoot(int);
	int ReloadWeapon();
	int SoldierDetails();
public:
	int getMyGunHolder();
	int getSkill() const { return ShootingSkill; }
	std::string getName() const { return name; }
	std::string getSurname() const { return surname; }
	std::string getNickname() const { return nickname; }
	std::string getPrefferedGun() const { return prefferedGun; }
	Soldier();
	Soldier(std::string, std::string, std::string, int);
	~Soldier();
};