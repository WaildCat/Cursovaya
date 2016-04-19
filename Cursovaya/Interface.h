#pragma once
class Soldier;

class Interface
{
	void ControlSoldier(Soldier&, int);
	
	void InitInterface();
	void ReturnToOfficer();
public:
	void ControlOfficer();
	Interface();
	~Interface();
};

