#pragma once
#include <string>

#define CheckIfValues Controller::GetInstance().CheckValues
#define GetFieldsCount Controller::GetInstance().GetNumOfFields
#define AssignValues Controller::GetInstance().AssignFields
#define ChooseMyUnit Controller::GetInstance().ChooseUnit

class VehicleGun;
class Vehicle;
class Gun;
class Soldier;
struct templateIO;

class Controller
{
public:
	
	~Controller();
	int CheckValues(int, int, int) const;
	int CheckValues(std::string&) const;
	int* GetNumOfFields(std::string);

	bool AssignFields(templateIO&, std::string, Soldier&);
	bool AssignFields(templateIO&, std::string, Gun*);
	bool AssignFields(templateIO&, std::string, Vehicle&);
	bool AssignFields(templateIO&, std::string, VehicleGun&);

	bool ChooseUnit(int&, Soldier&);
	bool ChooseUnit(int&, Vehicle&);
	bool ChooseUnit(int&, Gun*);

	static Controller& GetInstance();
private:
	Controller();
};