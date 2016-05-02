#include "Interface.h"
#include "Localization.h"
#include "Soldier.h"
#include "Officer.h"
#include "OfficerHelper.h"
#include "ProgrammerHelper.h"
#include "DummySoldier.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
 
using namespace std;

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
				string wName;
				cout << "\n" << GetLocStr(14) << "\n";
				cin >> wName;

				succes = Private.TakeWeapon(wName);

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

void Interface::ControlSearch()
{
	std::vector<char> neededParams;
	neededParams.push_back('1');
	int key;
	do
	{
		cout << endl;
		std::cout << "1 - " << GetLocStr(46) << std::endl;
		std::cout << "2 - " << GetLocStr(47) << std::endl;
		std::cout << "3 - " << GetLocStr(48) << std::endl;
		std::cout << "4 - " << GetLocStr(49) << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
			if (neededParams[1])
				break;
			else
				break;
		}
	} while (key != 27);
	return;
}


void Interface::ControlOfficer()
{
	Officer General;
	int key;
	do
	{
		cout << endl;
		std::cout << "1 - " << GetLocStr(1) << std::endl;
		std::cout << "2 - " << GetLocStr(2) << std::endl;
		std::cout << "3 - " << GetLocStr(2) << std::endl;
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
			templateIO sName;
			std::string pName;
			int sSkill;

			for (int i = 0; i < 4; i++)
			{
				std::cout << GetLocStr(i+39);
				AddToString(sName.myStringArr, pName);
				CheckInput(sName.myStringArr[i]);
			}

			std::cout << GetLocStr(43);
			std::cin.clear();
			std::cin.ignore(cin.rdbuf()->in_avail());
			std::cin >> sSkill;
			CheckInput(sSkill);
			sName.myIntArr.push_back(sSkill);

			General.AddSoldier(sName);
			break;
		}
		case '2':
		{
			system("cls");
			ControlSearch();
			break;
		}
		case '3':
			system("cls");
			//General.FireSoldier();
			PrintAllElems("Soldiers.txt");
			break;
		case '4':
			system("cls");
			ControlHelper();
			break;
		case '5':
				 system("cls");
			cout << GetLocStr(25) << endl;
			General.SetDistance(&(General.chosenDistance));
			break;
		case '6':
			system("cls");
			General.SetTarget();
			break;
		case '7':
		{
			system("cls");
			Soldier Private1;
			ControlSoldier(Private1, General.chosenDistance);
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



void Interface::CheckInput(int &x)
{
	bool isGood = std::ios::goodbit;
	do {
		try
		{
			CheckIfValues(x, isGood);
		}
		catch (const char* p)
		{
			std::cout << p << std::endl;
			std::cin.clear();
			std::cin.ignore(cin.rdbuf()->in_avail());
			std::cout << GetLocStr(31) << std::endl;
			std::cin >> x;
			isGood = std::ios::goodbit;
		}
	} while (std::cin.rdstate() != std::ios::goodbit);
}


void Interface::CheckInput(std::string &arrElem)
{
	while (CheckIfValues(arrElem) == 1 || CheckIfValues(arrElem) == 2)
	{
		int i = CheckIfValues(arrElem);
		cout << "\n" << GetLocStr(43 + i);
		std::getline(std::cin, arrElem);
	}
}


int Interface::AddToString(vector<std::string> & nameArr, std::string & pName)
{
	std::getline(std::cin, pName);
	nameArr.push_back(pName);
	return 0;
}
