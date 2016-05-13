#pragma once
#include <string>

class Weapon
{

protected:
	int holderCapacity;
	int damage;
	int range;
	int accuracy;
	std::string name;
public:
	int GetHolderCapacity() const { return holderCapacity; }
	int GetDamage() const { return damage; }
	int GetRange() const { return range; }
	int GetAccuracy() const { return accuracy; }
	std::string GetName() { return name; }

	void SetHolderCapacity(int newValue) { holderCapacity = newValue; }
	void SetDamage(int newValue) { damage = newValue; }
	void SetRange(int newValue) { range = newValue; }
	void SetAccuracy(int newValue) { accuracy = newValue; }
	void SetName(std::string newValue) { name = newValue; }
	Weapon();
	~Weapon();
};

