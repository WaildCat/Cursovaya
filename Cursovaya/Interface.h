#pragma once
class Soldier;

class Interface
{
	void ControlSoldier(Soldier&, int);
	void ControlHelper();
	void InitInterface();

public:
	void ControlOfficer();
	Interface();
	~Interface();
};

