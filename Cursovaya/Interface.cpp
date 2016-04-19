#include "Interface.h"
#include "Soldier.h"
#include "Officer.h"
#include "DummySoldier.h"
#include <iostream>
#include <conio.h>
 
using namespace std;

Interface::Interface()
{
}


Interface::~Interface()
{
}


void Interface::ControlSoldier(Soldier &Private, int distance)
{
	int key;
	do
	{
		cout << endl;
		std::cout << "1 - ����� ������" << std::endl;
		std::cout << "2 - ���������� �� ������" << std::endl;
		std::cout << "3 - ������������ ������" << std::endl;
		std::cout << "4 - ��������� ������" << std::endl;
		std::cout << "5 - ��������� �����" << std::endl;
		std::cout << "ESC - �����" << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
		{
			int fl = 0;

			if (Private.MyGun)
			{
				cout << "\n� ��� ��� ���� ������\n";
				fl = 1;
			}

			if (fl == 0)
				continue;
			else
				break;

			string wName;
			cout << "\n������� �������� ������, ������� ���������� �����:\n";
			cin >> wName;
			Private.TakeWeapon(wName);
			break;
		}
		case '2':
			if (Private.Shoot(distance))
			{
				if (Private.Shoot(distance) == 2)
					cout << "������" << endl;
				else
					cout << "���������" << endl;
				cout << "�������� " << Private.getMyGunHolder() << " �����������" << endl;
			}
			else
				cout << "������������ ������";
			break;
		case '3':
			Private.ReloadWeapon();
			break;
		case '4':
			Private.DropWeapon();
			break;
		case '5':
			ReturnToOfficer();
			break;
		}
		std::cout << std::endl;
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
		std::cout << "1 - �������� �������" << std::endl;
		std::cout << "2 - ������� �������" << std::endl;
		std::cout << "3 - �������� ������� ������" << std::endl;
		std::cout << "4 - ������ ���������" << std::endl;
		std::cout << "5 - ������� ����" << std::endl;
		std::cout << "6 - ������� � ���������� ��������" << std::endl;
		std::cout << "ESC - �����" << std::endl;
		key = getch();
		switch (key)
		{
		case '1':
			General.AddSoldier();
			break;
		case '2':
			General.FireSoldier();
			break;
		case '3':
			General.ShowCurrentStatus();
			break;
		case '4':
			cout << "������� ���������� �� ����: " << endl;
			General.SetDistance(&(General.chosenDistance));
			break;
		case '5':
			General.SetTarget();
			break;
		case '6':
			Soldier Private1;
			Interface::ControlSoldier(Private1, General.chosenDistance);
			break;
		}
		std::cout << std::endl;
	} while (key != 27);
	return;
}

void Interface::ReturnToOfficer()
{
}

