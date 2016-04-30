#pragma once
#include <vector>
#include <string>

#define WriteFile ProgrammerHelper::GetInstance().WriteToFile
#define ReadFile ProgrammerHelper::GetInstance().ReadFromFile

class ProgrammerHelper   //Singleton
{
	ProgrammerHelper();
public:

	int WriteToFile(std::vector<std::string> &);
	int WriteToFile(std::string &);
	int WriteToFile(int arr []);
	int WriteToFile(int &);

	int ReadFromFile(std::vector<std::string> &);
	int ReadFromFile(std::string &);
	int ReadFromFile(int arr[]);
	int ReadFromFile(int &);

	static ProgrammerHelper& GetInstance();
	~ProgrammerHelper();
};

