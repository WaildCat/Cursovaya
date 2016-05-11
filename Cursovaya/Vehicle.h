#pragma once
#include <string>
#include "VehicleGun.h"

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
	//gun myGun;
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
	VehicleGun MyGun;
protected:
	tower myTower;
	body myBody;

public:
	Vehicle();
	~Vehicle();
};

