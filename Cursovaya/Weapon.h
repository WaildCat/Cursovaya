#pragma once

class Weapon
{

protected:
	int holderCapacity;
	int damage;
	int range;
	int accuracy;
public:
	int GetHolderCapacity() { return holderCapacity; }
	void SetHolderCapacity(int newHolder) { holderCapacity = newHolder; }
	Weapon();
	~Weapon();
};

