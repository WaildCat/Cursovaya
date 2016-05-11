#pragma once
#include "Dummy.h"
#include "Vehicle.h"
class DummyVehicle:
	public Dummy, public Vehicle
{

	void SetParam();
public:
	DummyVehicle();
	~DummyVehicle();
};

