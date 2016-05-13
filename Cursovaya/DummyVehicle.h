#pragma once
#include "Dummy.h"
#include "Vehicle.h"

class DummyVehicle:
	public Dummy, public Vehicle
{
	int rotateDegree;
public:
	int GetRotateDegree() const { return rotateDegree; }
	void SetRotateDegree(int newValue) { rotateDegree = newValue; }

	void KillVehicle() { this->~DummyVehicle(); }
	void ReceiveDamage(std::string, int, double);
	DummyVehicle();
	~DummyVehicle();
};

