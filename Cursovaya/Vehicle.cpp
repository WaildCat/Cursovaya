#include "Vehicle.h"


int Vehicle::GetArmor(std::string position, int turnDegree) const
{
	if (turnDegree == 0)
	{
		if (position == "RightTop" || position == "LeftTop")
			return myTower.frontArmor + 10;
		else if (position == "MiddleTop")
			return myTower.frontArmor;
		else if (position == "RightCenter" || position == "LeftCenter" || position == "RightBottom" || position == "LeftBottom")
			return myBody.frontArmor + 5;
		else if (position == "MiddleCenter" || position == "MiddleBottom")
			return myBody.frontArmor;
	}
	else if (turnDegree == 180)
	{
		if (position == "RightTop" || position == "LeftTop")
			return myTower.backArmor + 15;
		else if (position == "MiddleTop")
			return myTower.backArmor;
		else if (position == "RightCenter" || position == "LeftCenter" || position == "RightBottom" || position == "LeftBottom")
			return myBody.backArmor + 5;
		else if (position == "MiddleCenter" || position == "MiddleBottom")
			return myBody.backArmor;
	}
	else
	{
		if (position == "RightTop" || position == "LeftTop")
			return myTower.sideArmor + 5;
		else if (position == "MiddleTop")
			return myTower.sideArmor;
		else if (position == "RightCenter" || position == "LeftCenter" || position == "RightBottom" || position == "LeftBottom")
			return myBody.sideArmor;
		else if (position == "MiddleCenter" || position == "MiddleBottom")
			return myBody.sideArmor - 5;
	}
}


void Vehicle::SetArmor(bool isBody, int turnDegree, int armor)
{
	if (turnDegree == 0)
	{
		if (isBody)
			myBody.frontArmor = armor;
		else
			myTower.frontArmor = armor;
	}
	else if (turnDegree == 180)
	{
		if (isBody)
			myBody.backArmor = armor;
		else
			myTower.backArmor = armor;
	}
	else
	{
		if (isBody)
			myBody.sideArmor = armor;
		else
			myTower.sideArmor = armor;
	}
}


std::string Vehicle::GetEPos(int turnDegree)
{
	std::string pos;
	if (turnDegree == 0 || turnDegree == 180)
		pos = "MiddleCenter";
	else if (turnDegree == 90)
		pos = "LeftCenter";
	else
		pos = "RightCenter";
	return pos;
}


std::string Vehicle::GetTMPos(int turnDegree) const
{
	std::string pos;
	pos = "BottomCenter";
	return pos;
}


std::string Vehicle::GetAPos(int turnDegree) const
{
	std::string pos;
	if (turnDegree == 0 || turnDegree == 180)
		pos = "LeftCenter";
	else if (turnDegree == 90)
		pos = "MiddleCenter";
	else
		pos = "RightCenter";
	return pos;

}


Vehicle::Vehicle()
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
	SetGunCharged(true);
	MyGun = new VehicleGun();
}


Vehicle::~Vehicle()
{
	if (MyGun)
		MyGun->~VehicleGun();
	MyGun = nullptr;
}
