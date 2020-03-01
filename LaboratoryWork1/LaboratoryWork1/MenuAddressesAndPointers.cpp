#include <iostream>
#include "AddressesAndPointers.h"
#include "..\Common\ReadNumber.h"

using namespace std;

void MenuAddressesAndPointers()
{
	setlocale(LC_ALL, "Russian");

	bool isEnd = true;

	while (isEnd)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Addresses" << endl;
		cout << "2. Array cell addresses" << endl;
		cout << "3. Demonstrating how links work" << endl;
		cout << "4. Demonstration of passing variables to a function by value" << endl;
		cout << "5. Demonstration of passing variables to a function by reference" << endl;
		cout << "6. Pointers" << endl;
		cout << "7. Demonstration of passing variables to a function by pointer" << endl;
		cout << "8. Exit" << endl;

		switch (ReadNumber())
		{
			case 1:
			{
				int a = 5;
				int b = 4;

				cout << "Address of a: " << &a << endl;
				cout << "Address of b: " << &b << endl;

				double c = 13.5;
				cout << "Address of c: " << &c << endl;

				bool d = true;
				cout << "Address of d: " << &d << endl;

				system("pause");
				break;
			}
			case 2:
			{
				int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
				cout << "Size of int type: " << sizeof(int) << endl;
				for (int i = 0; i < 10; i++)
				{
					cout << "Address of a[" << i << "]: " << &a[i] << endl;
				}
				cout << endl;
				cout << "Size of double type: " << sizeof(double) << endl;
				double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
				for (int i = 0; i < 10; i++)
				{
					cout << "Address of b[" << i << "]: " << &b[i] << endl;
				}

				system("pause");
				break;
			}
			case 3:
			{
				int a = 5;
				int& b = a;

				cout << "Address of a: " << &a << endl;
				cout << "Address of b: " << &b << endl;

				cout << endl;
				b = 7;
				cout << "Value of a: " << a << endl;

				system("pause");
				break;
			}
			case 4:
			{
				double a = 5.0;
				cout << "Address of a in main(): " << &a << endl;
				cout << "Value of a in main(): " << a << endl;
				cout << endl;

				Foo1(a);

				cout << endl;
				cout << "Value of a in main(): " << a << endl;

				system("pause");
				break;
			}
			case 5:
			{
				double a = 5.0;
				cout << "Address of a in main(): " << &a << endl;
				cout << "Value of a in main(): " << a << endl;
				cout << endl;

				Foo2(a);

				cout << endl;
				cout << "Value of a in main(): " << a << endl;

				system("pause");
				break;
			}
			case 6:
			{
				int a = 5;
				int* pointer = &a;

				cout << "Address of a: " << &a << endl;
				cout << "Address in pointer: " << pointer << endl;
				cout << "Address of pointer: " << &pointer << endl;

				cout << endl;
				*pointer = 7;
				cout << "Value in a: " << a << endl;
				cout << "Value by pointer address: " << *pointer << endl;

				system("pause");
				break;
			}
			case 7:
			{
				double value = 5.0;
				double* pointer = &value;
				cout << "Address of value in main(): " << &value << endl;
				cout << "Address in pointer in main(): " << pointer << endl;
				cout << "Address of pointer in main(): " << &pointer << endl;
				cout << "Value of a in main(): " << value << endl;

				Foo3(pointer);

				cout << endl;
				cout << "Value of a in main(): " << value << endl;

				system("pause");
				break;
			}
			case 8:
			{
				isEnd = false;
				break;
			}
		default:
			break;
		}
	}
}