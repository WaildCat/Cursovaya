#pragma once
#include <string>

#define CheckIfValues Controller::GetInstance().CheckValues
#define ChooseNeededElem Controller::GetInstance().ChooseElem


struct templateIO;

class Controller
{
public:
	
	~Controller();
	int CheckValues(int&, bool&) const;
	int CheckValues(std::string&) const;
	int ChooseElem(templateIO&, std::string&, int);
	static Controller& GetInstance();
private:
	Controller();
};

