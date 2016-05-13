#pragma once
#include "Soldier.h"
#include "Controller.h"

class DummyVehicle;
class VehicleGun;

class CrewMember :
	public Soldier

{
	int reloadSkill;
	int shootingSkill;
	int aimingSkill;
	friend class Controller;
public:
	int GetReloadSkill() const { return  reloadSkill; }
	int GetAimingSkill() const { return  aimingSkill; }
	int GetShootingSkill() const { return  shootingSkill; }

	void SetReloadSkill(int newSkill) { reloadSkill = newSkill; }
	void SetAimingSkill(int newSkill) { aimingSkill = newSkill; }
	void SetShootingSkill(int newSkill) { shootingSkill = newSkill; }
	CrewMember();
	~CrewMember();
};

