#pragma once
#include <vector>
#include <string>
#include "DummyVehicle.h"

#define WriteFile IOController::GetInstance().WriteToFile
#define ReadFile IOController::GetInstance().ReadFromFile
#define PrintAllElems IOController::GetInstance().PrintList
#define GetElemCount IOController::GetInstance().GetAllElemCount
#define CheckIfCorrect IOController::GetInstance().CheckInput
#define InputUnitFields IOController::GetInstance().InputUnitParams
#define DeleteFFile IOController::GetInstance().DeleteFromFile
//#define PrintInfo IOController::GetInstance().PrintMyInfo


class Gun;
class Vehicle;
class VehicleCrew;
class CrewMember;
class Soldier;

struct templateIO
{
	std::vector<std::string> myStringArr;
	std::vector<int> myIntArr;
};


class IOController   //Singleton
{
	friend class Interface;
	IOController();
public:
	int WriteToFile(templateIO&, std::string) const;
	int ReadFromFile(templateIO & myStruct, std::string, std::string, int);
	int DeleteFromFile(int, std::string);
	int PrintList(std::string) const;
	int GetAllElemCount(std::string fileName) const;

	templateIO InputUnitParams(std::string typeOfUnit);
	void CheckInput(int&);
	void CheckInput(std::string &);

	template<typename T>
	void PrintMyInfo(T& unit);

	static IOController& GetInstance();
	~IOController();
};

std::ostream& operator<<(std::ostream& os, const Soldier& Unit);
std::ostream& operator<<(std::ostream& os, const CrewMember& Unit);
std::ostream& operator<<(std::ostream& os, const VehicleCrew& Unit);
std::ostream& operator<<(std::ostream& os, const Vehicle& Unit);
std::ostream& operator<<(std::ostream& os, const Gun* Unit);
std::ostream& operator<<(std::ostream& os, const DummyVehicle& Unit);