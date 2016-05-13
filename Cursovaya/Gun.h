#pragma once
#include "Weapon.h"
#include <string>

class Gun :
	public Weapon
{
public:
	Gun();
	Gun(int, int, int, int, std::string);
	~Gun();
};

