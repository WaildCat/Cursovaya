#include "Interface.h"
#include <stdio.h>
#include <locale.h>
#include <ctime>
#include <cstdlib>

int main()
{
	setlocale(0, "RUS");
	srand(time(NULL));
	Interface myInterface;
	myInterface.ControlOfficer();
	return 0;
}