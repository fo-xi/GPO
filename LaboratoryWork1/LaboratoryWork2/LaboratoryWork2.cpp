#include <iostream>
#include "ExceptionHandling.h"
#include "Flight.h"
#include "Movie.h"
#include "Rectangle.h"
#include "Time.h"
#include "Transfers.h"
#include "..\Common\ReadNumber.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Demo Sort" << endl;
		cout << "2. Demo Sort 2" << endl;
		cout << "3. Demo Flight" << endl;
		cout << "4. Demo Movie" << endl;
		cout << "5. Demo Rectangle" << endl;
		cout << "6. Demo Time" << endl;
		cout << "7. Wrong Pointers" << endl;
		cout << "8. Demo Read And Write Rectangles" << endl;
		cout << "9. Demo Dynamic Flight" << endl;
		cout << "10. Demo Dynamic Flights" << endl;
		cout << "11. Make Rectangle" << endl;
		cout << "12. Make Flight" << endl;
		cout << "13. Make Movie" << endl;
		cout << "14. Make Time" << endl;
		cout << "15. Demo Count Color" << endl;
		cout << "16. Demo Movie With Genre" << endl;
		cout << "17. Read Color" << endl;
		switch (ReadNumber<int>())
		{
		case 1:
		{
			DemoSort();
			break;
		}
		case 2:
		{
			DemoSort2();
			break;
		}
		case 3:
		{
			DemoFlight();
			system("pause");
			break;
		}
		case 4:
		{
			DemoMovie();
			system("pause");
			break;
		}
		case 5:
		{
			DemoRectangle();
			system("pause");
			break;
		}
		case 6:
		{
			DemoTime();
			system("pause");
			break;
		}
		case 7:
		{
			WrongPointers();
			break;
		}
		case 8:
		{
			DemoReadAndWriteRectangles();
			system("pause");
			break;
		}
		case 9:
		{
			DemoDynamicFlight();
			system("pause");
			break;
		}
		case 10:
		{
			DemoDynamicFlights();
			system("pause");
			break;
		}
		case 11:
		{
			MakeRectangle(12, 13, "Red");
			system("pause");
			break;
		}
		case 12:
		{
			MakeFlight("Tomsk", "Novosibirsk", 40);
			system("pause");
			break;
		}
		case 13:
		{
			MakeMovie("Jumanji", 119, 2018, Comedy, 6.4);
			system("pause");
			break;
		}
		case 14:
		{
			MakeTime(13, 45, 23);
			system("pause");
			break;
		}
		case 15:
		{
			DemoCountColor();
			system("pause");
			break;
		}
		case 16:
		{
			DemoMovieWithGenre();
			system("pause");
			break;
		}
		case 17:
		{
			ReadColor();
			system("pause");
			break;
		}
		default:
			break;
		}
	}
	return 0;
}