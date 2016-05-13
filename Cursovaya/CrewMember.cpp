#include "CrewMember.h"
#include "DummyVehicle.h"
#include "OfficerHelper.h"

class VehicleGun;

CrewMember::CrewMember()
{
	HumanSize = 1;
	shootingSkill = 75;
	aimingSkill = 75;
	reloadSkill = 75;
	SoldierDetails();
	OfficerHelper::GetInstance().SetStatic(1, 1);
}


CrewMember::~CrewMember()
{
}