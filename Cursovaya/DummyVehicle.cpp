#include "DummyVehicle.h"



DummyVehicle::DummyVehicle()
{
	SetName("T-34");
	SetArmor(true, 0, 45);
	SetArmor(true, 90, 45);
	SetArmor(true, 180, 40);
	SetArmor(false, 0, 45);
	SetArmor(false, 90, 45);
	SetArmor(false, 180, 45);
	SetBDurability(450);
	SetTDurability(325);
	SetADurability(100);
	SetTMDurability(100);
	SetEDurability(100);
	SetEngineFueled(true);
	SetEPos("MiddleCenter");
	SetTMPos("BottomCenter");
	SetAPos("MiddleLeft");
	SetRotateDegree(0);
}


DummyVehicle::~DummyVehicle()
{
}


void DummyVehicle::ReceiveDamage(std::string position, int damage, double coefficient)
{
	size_t pos1 = position.find("Center");
	size_t pos2 = position.find("Bottom");
	if (pos1 != std::string::npos || pos2 != std::string::npos)
	{
		damage *= coefficient;
		this->SetBDurability(this->GetBDurability() - damage);

		int explCoeff;

		if (coefficient < 1.3)
		{
			damage /= 3;
			int ifHitEng = rand() % 100;
			int ifHitTM = rand() % 100;
			int ifHitA = rand() % 100;
			if (ifHitEng > 15)
			{
				if (ifHitEng > 75)
					this->SetEDurability(this->GetEDurability() - damage);
				else if (ifHitEng > 50)
					this->SetEDurability(this->GetEDurability() - damage / 2);
				else if (ifHitEng > 25)
					this->SetEDurability(this->GetEDurability() - damage / 4);

				explCoeff = (100 / this->GetEDurability()) * 10;
				int isExplosion = rand() % 100;

				if (isExplosion < explCoeff)
					delete this;
			}

			if (ifHitTM > 15)
			{
				if (ifHitTM > 75)
					this->SetTMDurability(this->GetTMDurability() - damage);
				else if (ifHitTM > 50)
					this->SetTMDurability(this->GetTMDurability() - damage / 2);
				else if (ifHitTM > 25)
					this->SetTMDurability(this->GetTMDurability() - damage / 4);
			}

			if (ifHitA > 15)
			{
				if (ifHitA > 75)
				{
					this->SetADurability(this->GetADurability() - damage);
					this->KillVehicle();
				}
				else if (ifHitA > 50)
					this->SetADurability(this->GetADurability() - damage / 2);
				else if (ifHitA > 25)
					this->SetADurability(this->GetADurability() - damage / 4);
			}
		}
		else
		{
			damage /= 1.5;
			if (position == this->GetEPos(rotateDegree))
			{
				SetEDurability(this->GetEDurability() - damage);

				explCoeff = (100 / this->GetEDurability() + 1) * 100;
				int isExplosion = rand() % 100;

				if (isExplosion < explCoeff)
					this->KillVehicle();
			}
			else if (position == this->GetTMPos(rotateDegree))
			{
				SetTMDurability(this->GetTMDurability() - damage);
			}
			else if (position == this->GetAPos(rotateDegree))
			{
				SetADurability(this->GetADurability() - damage);
				this->KillVehicle();
			}
		}
	}
	else
	{
		if (coefficient < 1.5)
		{
			damage /= 4;
			this->SetTDurability(this->GetTDurability() - damage);
		}
		else
			this->SetTDurability(0);
	}
}
