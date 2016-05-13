#include "VehicleCrew.h"
#include "DummyVehicle.h"



VehicleCrew::VehicleCrew()
{
	InVehicle = false;
}


VehicleCrew::~VehicleCrew()
{
}


int VehicleCrew::Shoot(int distance, std::string position, Vehicle& Transport, DummyVehicle& myTarget, int turnDegree)
{
	if (GetInVehicle() && Transport.GetGunCharged())
	{
		Transport.SetGunCharged(false);

		int penalty;
		size_t pos1 = position.find("Bottom");
		size_t pos2;

		if (pos1 != std::string::npos)
		{
			pos1 = position.find("Left");
			pos2 = position.find("Right");

			if (pos1 != std::string::npos || pos2 != std::string::npos)
			{
				pos1 = position.find("Top");

				if (pos1 != std::string::npos)
				{
					penalty = 0;
				}
				else
				{
					penalty = 15;
				}
			}
			else
			{
				pos1 = position.find("Top");
				if (pos1 != std::string::npos)
				{
					penalty = 10;
				}
				else
				{
					penalty = 30;
				}
			}
		}
		else
		{
			pos2 = position.find("Left");
			pos1 = position.find("Right");
			if (pos1 != std::string::npos || pos2 != std::string::npos)
			{
				penalty = 10;
			}
			else
			{
				penalty = 35;
			}
		}

		int chanceOfHit = distance;
		int ifHit = rand() % 100;
		double coefficient = Transport.MyGun->GetArmorPiercing() / myTarget.GetArmor(position, turnDegree);
		if (ifHit < chanceOfHit)
		{
			if (coefficient < 0.8)
				return 1;
			else
			{
				myTarget.ReceiveDamage(position, Transport.MyGun->GetDamage(), coefficient);
			}
		}
	}
	else
		return 3;
}
