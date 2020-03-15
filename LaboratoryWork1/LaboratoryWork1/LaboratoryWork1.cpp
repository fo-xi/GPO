#include <iostream>
#include "MenuAddressesAndPointers.h"
#include "MenuArrays.h"
#include "MenuDebug.h"
#include "MenuDynamicMemory.h"
#include "MenuFunctions.h"
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
		cout << "1. Debug" << endl;
		cout << "2. Arrays" << endl;
		cout << "3. Functions" << endl;
		cout << "4. Addresses and pointers" << endl;
		cout << "5. Dynamic memory" << endl;

		cout << endl;
		cout << "SELECT AN ACTION :\t";

		switch (ReadNumber<int>())
		{
		case 1:
		{
			MenuDebug();
			break;
		}
		case 2:
		{
			MenuArrays();
			break;
		}
		case 3:
		{
			MenuFunctions();
			break;
		}
		case 4:
		{
			MenuAddressesAndPointers();
			break;
		}
		case 5:
		{
			MenuDynamicMemory();
			break;
		}
		default:
			break;
		}
	}
	return 0;
}