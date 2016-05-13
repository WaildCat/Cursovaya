#pragma once
#include "Weapon.h"
#include <string>

struct ammo
{
	std::string ammoType;
	int armorPiercing;
	int damage;
};

class VehicleGun :
	public Weapon
{
	ammo myAmmo;
public:
	std::string GetName() const { return name; }
	std::string GetAmmoType() const { return myAmmo.ammoType; }
	int GetArmorPiercing() const { return myAmmo.armorPiercing; }
	int GetDamage() const { return myAmmo.damage; }

	void SetName(std::string newValue) { name = newValue; }
	void SetAmmoType(std::string userAmmoType) { myAmmo.ammoType = userAmmoType; }
	void SetArmorPiercing(int myAPiercing) { myAmmo.armorPiercing = myAPiercing; }
	void SetDamage(int myDamage) { myAmmo.damage = myDamage; }

	VehicleGun();
	~VehicleGun();
};

