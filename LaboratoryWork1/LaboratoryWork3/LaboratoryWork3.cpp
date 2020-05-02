#include <iostream>
#include "..\Common\ReadNumber.h"
#include "Book.h"
#include "Route.h"
#include "Rectangle.h"
#include "Flight.h"
#include "Band.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Demo Book" << endl;
		cout << "2. Demo Route" << endl;
		cout << "3. Demo Rectangle With Point" << endl;
		cout << "4. Demo Flight With Time" << endl;
		cout << "5. Demo Band" << endl;
		cout << "6. Class Demo Rectangle With Point" << endl;
		cout << "7. Class Demo Flight With Time" << endl;
		cout << "8. Class Demo Band" << endl;

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
			case 6:
			{
				DemoRectangleWithPoint();
				system("pause");
				break;
			}
			case 7:
			{
				DemoFlightWithTime();
				system("pause");
				break;
			}
			case 8:
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

