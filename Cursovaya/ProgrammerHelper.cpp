#include "ProgrammerHelper.h"
#include "fstream"
#include "vector"
#include "string"




ProgrammerHelper& ProgrammerHelper::GetInstance()
{
	static ProgrammerHelper instanceProgrammer;
	return instanceProgrammer;
}


int ProgrammerHelper::WriteToFile(std::vector<std::string> &arr)
{
	// char e[13] = "Soldiers.txt";
	std::ofstream toFile("Soldiers.txt", std::ios_base::app);
	if (!toFile.is_open())
	{
		return 2;
	}
	else
	{
		toFile << std::endl;
		for (int i = 0; i < arr.size(); i++)
			toFile << arr[i] << " ";
		toFile << std::endl;
		toFile.close();
		return 0;
	}
}

int ProgrammerHelper::WriteToFile(std::string & unit)
{
	std::ofstream toFile("Soldiers.txt", std::ios_base::app);
	if (!toFile.is_open())
	{
		return 2;
	}
	else
	{
		toFile << unit << " " << std::endl;
		toFile.close();
		return 0;
	}
}

int ProgrammerHelper::WriteToFile(int arr[])
{
	std::ofstream toFile("Soldiers.txt", std::ios_base::app);
	if (!toFile.is_open())
	{
		return 2;
	}
	else
	{
		for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
			toFile << arr[i] << " " << std::endl;
		toFile.close();
		return 0;
	}
}

int ProgrammerHelper::WriteToFile(int &a)
{
	std::ofstream toFile("Soldiers.txt", std::ios_base::app);
	if (!toFile.is_open())
	{
		return 2;
	}
	else
	{
		toFile << a << " " << std::endl;
		toFile.close();
		return 0;
	}
}




int ProgrammerHelper::ReadFromFile(std::vector<std::string>& arr)
{
	std::ifstream fromFile("Weapons.txt");
	if (!fromFile.is_open())
	{
		return 2;
	}
	else
	{
		std::string nameFromFile;
		while (!fromFile.eof())
		{
			std::getline(fromFile, nameFromFile);
			if (nameFromFile == arr[0]) {
				for (int i = 1; i < arr.size(); i++)
				{
					fromFile >> arr[i];
				}
				break;
			}
		}
	}
	fromFile.close();
	return 0;
}



int ProgrammerHelper::ReadFromFile(std::string &unit)
{
	std::ifstream fromFile("Weapons.txt");
	if (!fromFile.is_open())
	{
		return 2;
	}
	else
	{

		fromFile >> unit;
	}
	fromFile.close();
	return 0;
}



int ProgrammerHelper::ReadFromFile(int arr[])
{
	return 0;
}



int ProgrammerHelper::ReadFromFile(int &a)
{
	return 0;
}



ProgrammerHelper::ProgrammerHelper()
{
}


ProgrammerHelper::~ProgrammerHelper()
{
}
