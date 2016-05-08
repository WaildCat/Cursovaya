#include "IOController.h"
#include "fstream"
#include "iostream"
#include "vector"
#include "string"
#include "Controller.h"
#include "Localization.h"



IOController& IOController::GetInstance()
{
	static IOController instanceProgrammer;
	return instanceProgrammer;
}


int IOController::WriteToFile(templateIO& myStruct) const
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

		int count = GetAllElemCount("Soldiers.txt");
		if (count != -1)
			toFile << count + 1;
		
		toFile.close();
		return 0;
	}
}


int IOController::ReadFromFile(templateIO& myStruct, std::string fileName, int number)
{
	std::ifstream fromFile(fileName);

	if (!fromFile.is_open())
	{
		return 2;
	}

	else
	{
		string stringFromFile, neededNumber = " ";
		neededNumber += ((number - 1) + 0x30);
		int digit;
		while (!fromFile.eof())
		{
			getline(fromFile, stringFromFile);

			size_t pos;

			if (!myStruct.myStringArr[0])
				size_t pos = stringFromFile.find(neededNumber);
			else
				size_t pos = stringFromFile.find(myStruct.myStringArr[0] + " ");

			if (pos != std::string::npos || (pos != std::string::npos && number == 1))
			{
					for (int i = 0; i < 4/*myStruct.myStringArr.size()*/; i++)
					{
						fromFile >> stringFromFile;
						myStruct.myStringArr.push_back(stringFromFile);
					}
					for (int i = 0; i < 1/*myStruct.myIntArr.size()*/; i++)
					{
						try
						{
							fromFile >> digit;
							if (digit < 1 || digit > 99)
								throw "Corrupted data in the file";
							myStruct.myIntArr.push_back(digit);
						}
						catch (char* error)
						{
							cout << error << ". " << GetLocStr(40);
							int mySkill;
							cin >> mySkill;
							CheckInput(mySkill);
							myStruct.myIntArr.push_back(mySkill);
						}
					}
					break;
			}
		}
	}
	fromFile.close();
	return 0;
}



int IOController::DeleteFromFile(int number, string fileName)
{
	{
		std::ifstream fromFile(fileName);

		if (!fromFile.is_open())
		{
			return 2;
		}

		else
		{
			string stringFromFile, neededNumber = " ";
			neededNumber += ((number - 1) + 0x30);
			while (!fromFile.eof())
			{
				getline(fromFile, stringFromFile);
				size_t pos = stringFromFile.find(neededNumber);
				if (pos != std::string::npos || (pos != std::string::npos && number == 1))
				{
					//Удалить строку
				}
				break;
			}
			return 1;
		}
	}
}



int IOController::PrintList(std::string fileName) const
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



int IOController::GetAllElemCount(std::string fileName) const
{
	std::ifstream fromFile(fileName);
	int count = 0;

	if (!fromFile.is_open())
	{
		return -1;
	}

	else
	{
		std::cout << std::endl;
		std::string oneOfElem;


		while (!fromFile.eof())
		{
			std::getline(fromFile, oneOfElem);
			if (oneOfElem.length() != 0)
				count++;
		}
	}
	return count;
}

templateIO IOController::InputUnitParams(std::string typeOfUnit)
{
	templateIO myUnit;
	std::string stringFields;
	int intFields, numberOfString, numberOfInt;

	if (typeOfUnit == "Soldier")
	{
		numberOfString = 4;
		numberOfInt = 1;
	}
	else if (typeOfUnit == "Weapon")
	{
		numberOfString = 1;
		numberOfInt = 4;
	}
	else
	{
		numberOfString = 1;
		numberOfInt = 1;
	}

	for (int i = 0; i < numberOfString; i++)
	{
		std::cin >> stringFields;
		myUnit.myStringArr.push_back(stringFields);
	}
	for (int i = 0; i < numberOfInt; i++)
	{
		std::cin >> intFields;
		CheckInput(intFields);
		myUnit.myIntArr.push_back(intFields);
	}
	return myUnit;
}


IOController::IOController()
{
}


IOController::~IOController()
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


void IOController::CheckInput(int &x)
{
	bool isGood = std::cin.rdstate();
	if (!cin)
	{
		do {
			try
			{
				CheckIfValues(x, isGood);
			}
			catch (const char* p)
			{
				std::cout << p << std::endl;
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::cout << GetLocStr(31) << std::endl;
				std::cin >> x;
				isGood = std::cin.rdstate();
			}
		} while /*(std::cin.rdstate() != std::ios::goodbit)*/ (!std::ios::goodbit);
	}
}


void IOController::CheckInput(std::string &arrElem)
{
	while (CheckIfValues(arrElem) == 1 || CheckIfValues(arrElem) == 2)
	{
		int i = CheckIfValues(arrElem);
		cout << "\n" << GetLocStr(43 + i);
		std::getline(std::cin, arrElem);
	}
}