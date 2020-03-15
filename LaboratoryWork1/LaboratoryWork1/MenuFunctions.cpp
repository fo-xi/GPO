#include <iostream>
#include "Functions.h"
#include "..\Common\ReadNumber.h"

using namespace std;

void MenuFunctions()
{
	setlocale(LC_ALL, "Russian");

	bool isEnd = true;

	while (isEnd)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Get power" << endl;
		cout << "2. Demo get power" << endl;
		cout << "3. Round to tens" << endl;
		cout << "4. Exit" << endl;

		switch (ReadNumber<int>())
		{
		case 1:
		{
			int quantity = 3;
			for (int i = 0; i < quantity; i++)
			{
				cout << "Enter value -> ";
				int base = ReadNumber<int>();
				cout << "Enter the power of the value -> ";
				int exponent = ReadNumber<int>();
				cout << base << "^" << exponent << "=" << GetPower(base, exponent) << endl;
				cout << endl;
			}
			system("pause");
			break;
		}
		case 2:
		{
			int quantity = 3;
			for (int i = 0; i < quantity; i++)
			{
				cout << "Enter value -> ";
				int base = ReadNumber<int>();
				cout << "Enter the power of the value -> ";
				int exponent = ReadNumber<int>();
				DemoGetPower(base, exponent);
			}
			system("pause");
			break;
		}
		case 3:
		{
			int quantity = 3;
			for (int i = 0; i < quantity; i++)
			{
				cout << "Enter value -> ";
				int value = ReadNumber<int>();
				cout << "For " << value << " rounded value is ";
				cout << RoundToTens(value) << endl;
			}
			system("pause");
			break;
		}
		case 4:
		{
			isEnd = false;
			break;
		}
		default:
			break;
		}
	}
}