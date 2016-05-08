#include "Controller.h"
#include "IOController.h"


Controller::Controller()
{
}


Controller::~Controller()
{
}


int Controller::CheckValues(int& x, bool& goodbit) const
{
	if (!goodbit)
		throw "Error";
	return 0;
}

int Controller::CheckValues(std::string & pName) const
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



int Controller::ChooseElem(templateIO& neededElem, std::string& fileName, int number)
{
	return ReadFile(neededElem, fileName, number);
}



Controller& Controller::GetInstance()
{
	static Controller instanceController;
	return instanceController;
}
