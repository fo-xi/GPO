#include <iostream>
#include "Debug.h"
#include "..\Common\ReadNumber.h"

using namespace std;

void MenuDebug()
{
	setlocale(LC_ALL, "Russian");

	bool isEnd = true;

	while (isEnd)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1: Breakpoint1" << endl;
		cout << "2: Breakpoint2" << endl;
		cout << "3. Exit" << endl;

		switch (ReadNumber<int>())
		{
		case 1:
		{
			Breakpoints1();
			system("pause");
			break;
		}
		case 2:
		{
			Breakpoints2();
			system("pause");
			break;
		}
		case 3:
		{
			isEnd = false;
			break;
		}
		default:
			break;
		}
	}
}