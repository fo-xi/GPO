#include <iostream>
#include "..\Common\ReadNumber.h"
#include "GeometricProgram.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Demo Ring" << endl;
		cout << "2. Demo Rectangle leWith Point" << endl;
		cout << "3. Demo Collision" << endl;

		switch (ReadNumber<int>())
		{
			case 1:
			{
				GeometricProgram::DemoRing();
				system("pause");
				break;
			}
			case 2:
			{
				GeometricProgram::DemoRectangleWithPoint();
				system("pause");
				break;
			}
			case 3:
			{
				GeometricProgram::DemoCollision();
				system("pause");
				break;
			}
		default:
			break;
		}
	}
	return 0;
}