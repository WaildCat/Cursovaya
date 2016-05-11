#include <iostream>
#include <string>
#include "Localization.h"
#include "ErrorsCatcher.h"
#include "Controller.h"


ErrorsCatcher::ErrorsCatcher()
{
}


ErrorsCatcher::~ErrorsCatcher()
{
}



void ErrorsCatcher::OutOfBounds()
{
	std::cerr << GetLocStr(0);
}



void ErrorsCatcher::ErrorInInput(int& x)
{
	do
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cerr << GetLocStr(51) << endl;
		std::cout << GetLocStr(52) << endl;
		std::cin >> x;
	} while (ios::goodbit != std::cin.rdstate());
}



void ErrorsCatcher::ErrorInInput(string& arrElem, int& succes)
{
	while (succes == 1 || succes == 2)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cerr << "\n" << GetLocStr(43 + succes);
		std::getline(std::cin, arrElem);
		succes = CheckIfValues(arrElem);
	}
}


void ErrorsCatcher::CorruptedFileData()
{
	cerr << "\n" << "corrupted data in the file";
}
