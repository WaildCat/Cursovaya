#pragma once
#include <string>
#include "VehicleGun.h"
#include <vector>
#include "VehicleCrew.h"

struct module
{
	int durability;
	std::string postion;
};

struct engine
{
	int durability;
	std::string postion;
	bool isFuel;
};
struct tower
{
	int durability;
	int frontArmor;
	int sideArmor;
	int backArmor;
};
struct body
{
	engine myEngine;
	module transmission;
	module ammoHolder;
	int durability;
	int frontArmor;
	int sideArmor;
	int backArmor;
};

class Vehicle
{

private:
	VehicleCrew MyCrew;
	std::string name;
	bool isCharged;

protected:
	tower myTower;
	body myBody;

public:
	VehicleGun *MyGun;
	int GetArmor(std::string position, int turnDegree) const;
	int GetBDurability() const { return myBody.durability; }
	int GetEDurability() const { return myBody.myEngine.durability; }
	int GetTDurability() const { return myTower.durability; }
	int GetTMDurability() const { return myBody.transmission.durability; }
	int GetADurability() const { return myBody.ammoHolder.durability; }
	bool GetEngineFueled() const { return myBody.myEngine.isFuel; }
	bool GetGunCharged() const { return isCharged; }

	void SetArmor(bool isBody, int turnDegree, int armor);
	void SetBDurability(int newDurability) { myBody.durability = newDurability; }
	void SetEDurability(int newDurability) { myBody.myEngine.durability = newDurability; }
	void SetTDurability(int newDurability) { myTower.durability = newDurability; }
	void SetTMDurability(int newDurability) { myBody.transmission.durability = newDurability; }
	void SetADurability(int newDurability) { myBody.ammoHolder.durability = newDurability; }
	void SetEngineFueled(bool isFueled) { myBody.myEngine.isFuel = isFueled; }
	void SetName(std::string newName) { name = newName; }
	void SetGunCharged(bool newValue) { isCharged = newValue; }

	void SetEPos(std::string newValue) { myBody.myEngine.postion = newValue; }
	void SetTMPos(std::string newValue) { myBody.transmission.postion = newValue; }
	void SetAPos(std::string newValue) { myBody.ammoHolder.postion = newValue; }

	std::string GetEPos(int);
	std::string GetTMPos(int) const;
	std::string GetAPos(int) const;
	std::string GetName() const { return name; };

	Vehicle();
	virtual ~Vehicle();
};

