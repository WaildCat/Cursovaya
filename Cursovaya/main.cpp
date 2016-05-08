#include "Interface.h"
#include "Localization.h"
#include <locale.h>
#include <ctime>
#include <cstdlib>

int main()
{
	setlocale(0, "RUS");
	srand(time(NULL));
	Interface myInterface;
	Localization::GetInstance().InitLocalization();
	myInterface.ControlOfficer();
	return 0;
}