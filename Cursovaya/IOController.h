#pragma once
#include <vector>
#include <string>

#define WriteFile IOController::GetInstance().WriteToFile
#define ReadFile IOController::GetInstance().ReadFromFile
#define PrintAllElems IOController::GetInstance().PrintList
#define CheckIfCorrect IOController::GetInstance().CheckInput
#define InputUnitFields IOController::GetInstance().InputUnitParams


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

	int WriteToFile(templateIO&) const;
	int ReadFromFile(templateIO & myStruct, std::string, int);
	int DeleteFromFile(int, std::string);
	int PrintList(std::string) const;
	int GetAllElemCount(std::string fileName) const;
	templateIO InputUnitParams(std::string typeOfUnit);
	void CheckInput(int&);
	void CheckInput(std::string &);

	static IOController& GetInstance();
	~IOController();
};

bool operator!(const std::string& i);