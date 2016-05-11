#include "IOController.h"
#include "fstream"
#include "iostream"
#include "vector"
#include "string"
#include "Controller.h"
#include "Localization.h"
#include "ErrorsCatcher.h"
#include "Soldier.h"


IOController& IOController::GetInstance()
{
	static IOController instanceProgrammer;
	return instanceProgrammer;
}


int IOController::WriteToFile(templateIO& myStruct, std::string fileName) const
{
	std::ofstream toFile(fileName, std::ios_base::app);
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

		int count = GetAllElemCount(fileName);
		if (count != -1)
			toFile << count + 1;
		
		toFile.close();
		return 0;
	}
}


int IOController::ReadFromFile(templateIO& myStruct, std::string fileName, std::string unit, int number)
{
	std::ifstream fromFile(fileName);

	if (!fromFile.is_open())
	{
		return 2;
	}

	string stringFromFile, neededNumber = " ";
	neededNumber += ((number - 1) + 0x30);
	int digit, numOfString, numOfInt;

	while (!fromFile.eof())
	{
		size_t pos = stringFromFile.find(neededNumber);

		if (number > 1)
		{
			getline(fromFile, stringFromFile);
			try // If myStringArr[0] exists
			{
				if (myStruct.myStringArr.size() != 0)
					size_t pos = stringFromFile.find(myStruct.myStringArr[0] + " ");
				else
					throw ErrorsCatcher();
			}
			catch (ErrorsCatcher &foundError)
			{
				foundError.OutOfBounds();
			}
		}

		try // If GetFieldsCount[0] and GetFieldsCount[1] exists
		{
			numOfString = GetFieldsCount(unit)[0]; // Исправить на универсальную
			numOfInt = GetFieldsCount(unit)[1];
			if (numOfString == 0 || numOfInt == 0)
				throw ErrorsCatcher();
		}
		catch(ErrorsCatcher &foundError)
		{
			foundError.OutOfBounds();
			//return 3;
		}

		if (pos != std::string::npos || number == 1)
		{
			try
			{
				for (int i = 0; i < numOfString; i++)
				{
					fromFile >> stringFromFile;
					myStruct.myStringArr.push_back(stringFromFile);
				}
				for (int i = 0; i < numOfInt; i++)
				{
					fromFile >> digit;
					myStruct.myIntArr.push_back(digit);
					if (digit > 2000 || digit < 0)
						throw ErrorsCatcher();
				}
				break;
			}
			catch(ErrorsCatcher& foundError)
			{
				foundError.CorruptedFileData();
				cout << "Please, try again\n";
				fromFile.close();
				return 1;
			}
		}
	}

	fromFile.close();
	return 0;
}



int IOController::DeleteFromFile(int number, string filename)
{
	std::vector<std::string> vec;
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::string str;
		while (std::getline(file, str))
			if (str != "")
			{
				int ls = str[str.size() - 1] - 0x30;
				if ((str[str.size() - 1] - 0x30) > number)
					str[str.size() - 1] = (str[str.size() - 1] - 0x30 - 1) + 0x30;
				vec.push_back(str);
			}
		file.close();
		if (vec.size() < number)
			return false;
		vec.erase(vec.begin() + number - 1);
		std::ofstream outfile(filename);
		if (outfile.is_open())
		{
			std::copy(vec.begin(), vec.end(),
				std::ostream_iterator<std::string>(outfile, "\n"));
			outfile.close();
			return true;
		}
		return false;
	}
	return false;
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
		CheckInput(stringFields);
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


std::ostream& operator<<(std::ostream& os, const Soldier& Private)
{
	cout << GetLocStr(53) << Private.getName() << endl;
	cout << GetLocStr(54) << Private.getSurname() << endl;
	cout << GetLocStr(55) << Private.getNickname() << endl;
	cout << GetLocStr(57) << Private.getSkill() << endl;
	return os;
}


template <typename T>
void IOController::PrintMyInfo(T& unit)
{
	cout << unit;
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
	bool isGood;
	try
	{
		isGood = cin.fail();
		if (isGood)
			throw ErrorsCatcher();
	}
	catch (ErrorsCatcher &foundError)
	{
		foundError.ErrorInInput(x);
	}
}



void IOController::CheckInput(std::string &arrElem)
{
	int succes;
	try
	{
		succes = CheckIfValues(arrElem);
		if (succes == 1 || succes == 2)
			throw ErrorsCatcher();
	}
	catch(ErrorsCatcher &foundError)
	{
		foundError.ErrorInInput(arrElem, succes);
	}
}