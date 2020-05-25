#include <iostream>
#include "..\Common\ReadNumber.h"
#include "Book.h"
#include "Route.h"
#include "ClassRectangle.h"
#include "ClassFlight.h"
#include "ClassBand.h"
#include <Windows.h>

using namespace std;

int main()
{
	//setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Demo Book" << endl;
		cout << "2. Demo Route" << endl;
		cout << "3. Class Demo Rectangle With Point" << endl;
		cout << "4. Class Demo Flight With Time" << endl;
		cout << "5. Class Demo Band" << endl;

		switch (ReadNumber<int>())
		{
		case 1:
		{
			DemoBook();
			system("pause");
			break;
		}
		case 2:
		{
			DemoRoute();
			system("pause");
			break;
		}
		case 3:
		{
			DemoRectangleWithPoint();
			system("pause");
			break;
		}
		case 4:
		{
			DemoFlightWithTime();
			system("pause");
			break;
		}
		case 5:
		{
			DemoBand();
			system("pause");
			break;
		}
		default:
			break;
		}
	}
	return 0;
}