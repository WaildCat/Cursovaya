#include "Interface.h"
#include "Localization.h"
#include "Soldier.h"
#include "Officer.h"
#include "OfficerHelper.h"
#include "DummySoldier.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include "IOController.h"
#include "Controller.h"
#include "Vehicle.h"

using namespace std;

void InputDigit(int&);

Interface::Interface()
{
}


Interface::~Interface()
{
}


void Interface::ControlSoldier(Soldier &Private, int distance)
{
	int key, succes;
	do
	{
		cout << endl;
		std::cout << "1 - " << GetLocStr(9) << std::endl;
		std::cout << "2 - " << GetLocStr(10) << std::endl;
		std::cout << "3 - " << GetLocStr(11) << std::endl;
		std::cout << "4 - " << GetLocStr(12) << std::endl;
		std::cout << "5 - " << GetLocStr(7) << std::endl;
		std::cout << "ESC - " << GetLocStr(8) << std::endl;
		key = getch();
		switch (key)
		{

		case '1':
		{
			system("cls");

			if (Private.MyGun)
			{
				cout << "\n" << GetLocStr(13) << "\n";
				break;
			}
			else
			{
				ControlSearch(Private.MyGun, "Weapons.txt");

				if (succes == 2)
					cout << "\n" << GetLocStr(15) << "\n";
				else if (succes == 1) {
					cout << "\n" << GetLocStr(13) << "\n";
				}

				else if (succes == 3)
					cout << "\n" << GetLocStr(16) << "\n";
				else
					cout << "\n" << GetLocStr(17) << "\n";
				break;
			}
		}

		case '2':
			system("cls");
			succes = Private.Shoot(distance);
			if (succes)
			{
				if (succes == 2)
					cout << GetLocStr(18) << endl;
				else if (succes == 1)
					cout << GetLocStr(19) << endl;
				else
				{
					cout << GetLocStr(24) << endl;
					break;
				}
				cout << GetLocStr(20) << Private.getMyGunHolder() << GetLocStr(21) << endl;
			}
			else
				cout << GetLocStr(22);
			break;

		case '3':
			system("cls");
			succes = Private.ReloadWeapon();
			if (succes == 1)
				cout << GetLocStr(24) << endl;
			break;

		case '4':
			system("cls");
			if (Private.DropWeapon() == 0)
				cout << "\n" << GetLocStr(23) << "\n";
			else
				cout << "\n" << GetLocStr(24) << "\n";
			break;
		case '5':
		{
			system("cls");
			Localization::GetInstance().SwitchLang();
			break;
		}
		}
		std::cout << std::endl;
	} while (key != 27);
	system("cls");
	return;
}


void Interface::ControlHelper()
{
	int key;
	do
	{
		std::cout << std::endl;
		std::cout << GetLocStr(35) << std::endl;
		std::cout << "1 - " << GetLocStr(27) << std::endl;
		std::cout << "2 - " << GetLocStr(28) << std::endl;
		std::cout << "3 - " << GetLocStr(29) << std::endl;
		std::cout << "ESC - " << GetLocStr(8) << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
			system("cls");
			std::cout << GetHelpInfo(1) << std::endl;
			break;
		case '2':
			system("cls");
			std::cout << GetHelpInfo(2) << std::endl;
			break;
		case '3':
			system("cls");
			std::cout << GetHelpInfo(3) << std::endl;
			break;
		}
	} while (key != 27);
	system("cls");
	return;
}


template <typename T>
void Interface::ControlSearch(T& myUnit, string fileName)
{
	int key;
	do
	{
		cout << endl;
		std::cout << "1 - " << GetLocStr(46) << std::endl;
		std::cout << "2 - " << GetLocStr(47) << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
			system("cls");
			PrintAllElems(fileName);
			break;
		case '2':
		{
			system("cls");
			int number, succes;
			GetLocStr(48);
			cin >> number;
			do
			{
				CheckIfCorrect(number);
				succes = CheckIfValues(number, 1, GetElemCount(fileName));
				if (succes == 1)
				{
					cout << GetLocStr(49) << 1 << GetLocStr(50) << GetElemCount(fileName) << endl;
					InputDigit(number);
				}
			} while (succes != 0);
			T backupUnit = myUnit;
			if (ChooseMyUnit(number, myUnit))
				cout << "Успешно";
			else
				cout << "При замене ошибка";
		}
		}
	} while (key != 27);
	return;
}


void Interface::ChoseMenu()
{
	Officer General;
	int key;
	do
	{
		std::cout << endl;
		std::cout << "1 - " << GetLocStr(59) << std::endl;
		std::cout << "2 - " << GetLocStr(60) << std::endl;
		std::cout << "3 - " << GetLocStr(61) << std::endl;
		std::cout << "4 - " << GetLocStr(7) << std::endl;
		std::cout << "ESC - " << GetLocStr(8) << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
			system("cls");
			ControlOfficerS(General);
			break;
		case '2':
			system("cls");
			ControlOfficerV(General);
			break;
		case '3':
			system("cls");
			ControlOfficerA(General);
			break;
		case '4':
			system("cls");
			Localization::GetInstance().SwitchLang();
			break;
		}
	} while (key != 27);
}


void Interface::ControlOfficerS(Officer& General)
{
	Soldier Private1;
	int key;
	do
	{
		cout << endl;
		std::cout << "1 - " << GetLocStr(1) << std::endl;
		std::cout << "2 - " << GetLocStr(48) << std::endl;
		std::cout << "3 - " << GetLocStr(58) << std::endl;
		std::cout << "4 - " << GetLocStr(62) << std::endl;
		std::cout << "5 - " << GetLocStr(3) << std::endl;
		std::cout << "6 - " << GetLocStr(4) << std::endl;
		std::cout << "7 - " << GetLocStr(5) << std::endl;
		std::cout << "8 - " << GetLocStr(6) << std::endl;
		std::cout << "9 - " << GetLocStr(7) << std::endl;
		std::cout << "ESC - " << GetLocStr(8) << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			AddPrivate();
			int number = 1;
			ChooseMyUnit(number, Private1);
			break;
		}
		case '2':
		{
			system("cls");
			ControlSearch(Private1, "Soldiers.txt");
			break;
		}
		case '3':
			system("cls");
			cout << Private1;
			break;
		case '4':
			system("cls");
			int number, succes;
			cin >> number;

			do
			{
				CheckIfCorrect(number);
				succes = CheckIfValues(number, 1, GetElemCount("Soldiers.txt"));
				if (succes == 1)
				{
					cout << GetLocStr(49) << 1 << GetLocStr(50) << GetElemCount("Soldiers.txt") << endl;
					InputDigit(number);
				}
			} while (succes != 0);
			DeleteFFile(number, "Soldiers.txt");
			break;
		case '5':
			system("cls");
			ControlHelper();
			break;
		case '6':
		{
			system("cls");
			cout << GetLocStr(25) << endl;
			int changedDistance, succes;
			cin >> changedDistance;

			do
			{
				CheckIfCorrect(changedDistance);
				succes = CheckIfValues(changedDistance, 1, 2000);
				if (succes == 1)
				{
					cout << GetLocStr(49) << 1 << GetLocStr(50) << 2000 << endl;
					InputDigit(changedDistance);
				}
			} while (succes != 0);

			General.SetDistance(changedDistance);
			break;
		}
		case '7':
			system("cls");
			General.SetTarget();
			break;
		case '8':
		{
			system("cls");
			ControlSoldier(Private1, General.chosenDistance);
			break;
		}
		case '9':
		{
			system("cls");
			Localization::GetInstance().SwitchLang();
			break;
		}
		}
		std::cout << std::endl;
	} while (key != 27);
	return;
}


void Interface::ControlOfficerV(Officer& General)
{
	Vehicle myVehicle;
	int key;
	do
	{
		cout << endl;
		std::cout << "1 - " << GetLocStr(1) << std::endl;
		std::cout << "2 - " << GetLocStr(48) << std::endl;
		std::cout << "3 - " << GetLocStr(58) << std::endl;
		std::cout << "4 - " << GetLocStr(3) << std::endl;
		std::cout << "5 - " << GetLocStr(4) << std::endl;
		std::cout << "6 - " << GetLocStr(5) << std::endl;
		std::cout << "7 - " << GetLocStr(6) << std::endl;
		std::cout << "8 - " << GetLocStr(7) << std::endl;
		std::cout << "ESC - " << GetLocStr(8) << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			AddPrivate();
			break;
		}
		case '2':
		{
			system("cls");
		//	ControlSearch(Private1);
			break;
		}
		case '3':
			system("cls");
			//cout << Private1;
			break;
		case '4':
			system("cls");
			ControlHelper();
			break;
		case '5':
		{
			system("cls");
			cout << GetLocStr(25) << endl;
			int changedDistance, succes;
			cin >> changedDistance;

			do
			{
				CheckIfCorrect(changedDistance);
				succes = CheckIfValues(changedDistance, 1, 2000);
				if (succes == 1)
				{
					cout << GetLocStr(49) << 1 << GetLocStr(50) << 2000 << endl;
					InputDigit(changedDistance);
				}
			} while (succes != 0);

			General.SetDistance(changedDistance);
			break;
		}
		case '6':
			system("cls");
			General.SetTarget();
			break;
		case '7':
		{
			system("cls");
		//	ControlSoldier(Private1, General.chosenDistance);
			break;
		}
		case '8':
		{
			system("cls");
			Localization::GetInstance().SwitchLang();
			break;
		}
		}
		std::cout << std::endl;
	} while (key != 27);
	return;
}


void Interface::ControlOfficerA(Officer& General)
{
	int key;
	do
	{
		cout << endl;
		std::cout << "1 - " << GetLocStr(1) << std::endl;
		std::cout << "2 - " << GetLocStr(48) << std::endl;
		std::cout << "3 - " << GetLocStr(58) << std::endl;
		std::cout << "4 - " << GetLocStr(3) << std::endl;
		std::cout << "5 - " << GetLocStr(4) << std::endl;
		std::cout << "6 - " << GetLocStr(5) << std::endl;
		std::cout << "7 - " << GetLocStr(6) << std::endl;
		std::cout << "8 - " << GetLocStr(7) << std::endl;
		std::cout << "ESC - " << GetLocStr(8) << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			AddPrivate();
			break;
		}
		case '2':
		{
			system("cls");
			//ControlSearch(Private1);
			break;
		}
		case '3':
			system("cls");
			//cout << Private1;
			break;
		case '4':
			system("cls");
			ControlHelper();
			break;
		case '5':
		{
			system("cls");
			cout << GetLocStr(25) << endl;
			int changedDistance, succes;
			cin >> changedDistance;

			do
			{
				CheckIfCorrect(changedDistance);
				succes = CheckIfValues(changedDistance, 1, 2000);
				if (succes == 1)
				{
					cout << GetLocStr(49) << 1 << GetLocStr(50) << 2000 << endl;
					InputDigit(changedDistance);
				}
			} while (succes != 0);

			General.SetDistance(changedDistance);
			break;
		}
		case '6':
			system("cls");
			General.SetTarget();
			break;
		case '7':
		{
			system("cls");
		//	ControlSoldier(Private1, General.chosenDistance);
			break;
		}
		case '8':
		{
			system("cls");
			Localization::GetInstance().SwitchLang();
			break;
		}
		}
		std::cout << std::endl;
	} while (key != 27);
	return;
}


int Interface::AddToString(vector<std::string> & nameArr, std::string & pName)
{
	std::getline(std::cin, pName);
	nameArr.push_back(pName);
	return 0;
}


void InputDigit(int& digit)
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> digit;
}
