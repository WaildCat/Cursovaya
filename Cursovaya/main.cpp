#include "Interface.h"
#include "Localization.h"
#include <locale.h>
#include <ctime>
#include <cstdlib>
#include "Officer.h"

int main()
{
	setlocale(0, "RUS");
	srand(time(NULL));
	Interface myInterface;
	Localization::GetInstance().InitLocalization();
//	Officer General;
	myInterface.ChoseMenu();
	return 0;
}
