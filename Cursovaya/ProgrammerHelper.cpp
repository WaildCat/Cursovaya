#include "ProgrammerHelper.h"
#include "fstream"
#include "iostream"
#include "vector"
#include "string"

ProgrammerHelper& ProgrammerHelper::GetInstance()
{
	static ProgrammerHelper instanceProgrammer;
	return instanceProgrammer;
}


int ProgrammerHelper::WriteToFile(std::vector<std::string> &arr) const
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


int ProgrammerHelper::WriteToFile(templateIO& myStruct) const
{
	std::ofstream toFile("Soldiers.txt", std::ios_base::app);
	if (!toFile.is_open())
	{
		return 2;
	}
	else
	{
		toFile << std::endl;
		for (int i = 0; i < myStruct.myStringArr.size(); i++)
		{
			toFile << myStruct.myStringArr[i] << " ";
		}

		for (int i = 0; i < myStruct.myIntArr.size(); i++)
		{
			toFile << myStruct.myIntArr[i] << " ";
		}

		toFile << std::endl;
		toFile.close();
		return 0;
	}
}

int ProgrammerHelper::WriteToFile(std::string & unit) const
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

int ProgrammerHelper::WriteToFile(int arr[]) const
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

int ProgrammerHelper::WriteToFile(int &a) const
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


int ProgrammerHelper::ReadFromFile(templateIO& myStruct, std::string& fileName, int number)
{
	std::ifstream fromFile(fileName);

	if (!fromFile.is_open())
	{
		return 2;
	}

	/* else
	{
		std::string numberFromFile = myStruct.myStringArr[0];
		int digit, fl = 0;
		char myNumber = 0x30 + number;
		while (!fromFile.eof())
		{
			fromFile >> numberFromFile;
			if (numberFromFile == myNumber)
			{
				int i = 0;
				while (!(fromFile >> digit) || !fromFile.eof())
				{
					i++;
					fromFile >> nameFromFile;
					if (neededParams[i] == false)
					{
						myStruct.myStringArr.push_back(nameFromFile);
					}
					else
					{
						if (nameFromFile == myStruct.myStringArr[i])
							continue;
						else
							break;
					}
				}
			}
			 while (fromFile >> digit || (fromFile >> nameFromFile) == " ")
			{

			} 
		}
	} */
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



std::vector<bool> ProgrammerHelper::SearchParams(std::string& neededParams)
{
	std::vector<bool> whatParams;
	bool isNeeded;
	for (int i = 0; i < 5; i++)
	{
		if (neededParams[i] == '1')
		{
			isNeeded = true;
			whatParams.push_back(isNeeded);
		}
		else
		{
			isNeeded = false;
			whatParams.push_back(isNeeded);
		}
	}

	return whatParams;
}

int ProgrammerHelper::PrintList(std::string fileName)
{
	std::ifstream fromFile(fileName);

	if (!fromFile.is_open())
	{
		return 2;
	}

	else
	{
		std::cout << std::endl;
		std::string oneOfElem;
		while (!fromFile.eof())
		{
			std::getline(fromFile, oneOfElem);
			std::string invertOneElem = oneOfElem;

			if (oneOfElem.length() != 0)
			{

				int i = 0;
				int stringLength = oneOfElem.length();

				for (int j = 0; j < stringLength; j++)
				{
					invertOneElem[j] = oneOfElem[stringLength];
					stringLength--;
				}

				while (invertOneElem[i] != ' ')
				{
					std::cout << invertOneElem[i];
					i++;
				}
				std::cout << " - ";

				i = 0;
				while (oneOfElem[i] != ' ')
				{
					std::cout << oneOfElem[i];
					i++;
				}
				std::cout << std::endl;
			}
		}
	}
	return 0;
}



 int ProgrammerHelper::CheckValues(int &x, bool &goodbit) const
{
	if (!x || !goodbit)
		throw "Error";
	return 0;
}



int ProgrammerHelper::CheckValues(std::string & pName) const
{	
	//if (isdigit(pName.at(0)))
	for (int i = 0; i < 10; i++)
	{
		if (pName.at(0) == (i + 0x30))
			return 2;
	}

	for (int i = 0; i < pName.length(); i++)
	{
		if (pName.at(i) == ' ')
			return 1;
	}

	return 0;
}



ProgrammerHelper::ProgrammerHelper()
{
}


ProgrammerHelper::~ProgrammerHelper()
{
}

bool operator!( std::string & i)
{
	try
	{
		for (int j = 0; ; j++)
			std::cout << i[j];
	}
	catch(int a)
	{
		return false;
	}
	return true;
}
