#include <iostream>
#include "..\Common\ReadNumber.h"
#include "GeometricProgram.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	GeometricProgram* geometricProgram = new GeometricProgram();
	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Demo Band" << endl;
		cout << "2. Demo Ring" << endl;
		cout << "3. Demo Rectangle leWith Point" << endl;
		cout << "4. Demo Collision" << endl;

		switch (ReadNumber<int>())
		{
		case 1:
		{
			geometricProgram->DemoBand();
			system("pause");
			break;
		}
		case 2:
		{
			geometricProgram->DemoRing();
			system("pause");
			break;
		}
		case 3:
		{
			geometricProgram->DemoRectangleWithPoint();
			system("pause");
			break;
		}
		case 4:
		{
			geometricProgram->DemoCollision();
			system("pause");
			break;
		}
		default:
			break;
		}
	}
	delete geometricProgram;
	return 0;
}