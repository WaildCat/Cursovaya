#pragma once
#include <vector>
#include <string>

#define WriteFile IOController::GetInstance().WriteToFile
#define ReadFile IOController::GetInstance().ReadFromFile
#define PrintAllElems IOController::GetInstance().PrintList
#define GetElemCount IOController::GetInstance().GetAllElemCount
#define CheckIfCorrect IOController::GetInstance().CheckInput
#define InputUnitFields IOController::GetInstance().InputUnitParams
#define DeleteFFile IOController::GetInstance().DeleteFromFile
//#define PrintInfo IOController::GetInstance().PrintMyInfo


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

bool operator!(const std::string& i);
std::ostream& operator<<(std::ostream& os, const Soldier& Private);