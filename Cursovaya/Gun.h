#pragma once
#include "Weapon.h"
#include <string>

class Gun :
	public Weapon
{

private:
	std::string name;

public:
	int GetHolderCapacity() { return holderCapacity; }
	Gun();
	Gun(int, int, int, int, std::string);
	~Gun();
};

