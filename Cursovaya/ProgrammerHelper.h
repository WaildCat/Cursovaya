#pragma once
#include <vector>
#include <string>

#define WriteFile ProgrammerHelper::GetInstance().WriteToFile
#define ReadFile ProgrammerHelper::GetInstance().ReadFromFile
#define CheckIfValues ProgrammerHelper::GetInstance().CheckValues
#define PrintAllElems ProgrammerHelper::GetInstance().PrintList

struct templateIO
{
	std::vector<std::string> myStringArr;
	std::vector<int> myIntArr;
};


class ProgrammerHelper   //Singleton
{
	friend class Interface;
	ProgrammerHelper();
public:

	int WriteToFile(std::vector<std::string> &) const;
	int WriteToFile(templateIO&) const;
	int WriteToFile(std::string &) const;
	int WriteToFile(int arr []) const;
	int WriteToFile(int &) const;

	int ReadFromFile(std::vector<std::string> &);
	int ReadFromFile(templateIO & myStruct, std::string&, int);
	int ReadFromFile(std::string &);
	int ReadFromFile(int arr[]);
	int ReadFromFile(int &);

	std::vector<bool> SearchParams(std::string&);
	int PrintList(std::string);


	int CheckValues(int&, bool&) const;
	int CheckValues(std::string&) const;

	static ProgrammerHelper& GetInstance();
	~ProgrammerHelper();
};

bool operator!(const std::string& i);