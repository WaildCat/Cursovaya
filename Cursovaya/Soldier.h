#include <string>
#pragma once

class Gun;
class OfficerHelper;

class Soldier
{
	friend class Interface;

private:
	
	int TakeWeapon(std::string, int);
	int DropWeapon();
	int Shoot(int);
	int ShootingSkill;

protected:
	int HumanSize;
	std::string name;
	std::string surname;
	std::string nickname;

	int ReloadWeapon();
	int SoldierDetails();
public:
	Gun *MyGun;
	int getMyGunHolder();
	int getSkill() const { return ShootingSkill; }
	std::string getName() const { return name; }
	std::string getSurname() const { return surname; }
	std::string getNickname() const { return nickname; }
	Soldier(std::string, std::string, std::string, int);
	Soldier();
	virtual ~Soldier();
};