#include <iostream>
#include "Arrays.h"
#include "..\Common\ReadNumber.h"

using namespace std;

template <typename T>
void ShowArray(T array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

void MenuArrays()
{
	setlocale(LC_ALL, "Russian");

	bool isEnd = true;

	while (isEnd)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Array initialization and sorting" << endl;
		cout << "2. Array initialization and counting" << endl;
		cout << "3. Character array" << endl;
		cout << "4. Exit" << endl;

		switch (ReadNumber())
		{
			case 1:
			{
				const int arraySize = 10;
				int array[arraySize]
				{ 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };

				cout << endl;
				cout << "Source array is: " << endl;
				ShowArray(array, arraySize);

				Sorting(array, arraySize);

				cout << "Sorted array is: " << endl;
				ShowArray(array, arraySize);
				cout << endl;
				system("pause");
				break;
			}
			case 2:
			{
				const int arraySize = 12;
				double array[arraySize]
				{ 12.0, 21,5, 119.2, -80.7, 300.0, 75.5, 81.2, -8.1, 47.3, 31.2, 85.3 };

				cout << endl;
				cout << "Source array is: " << endl;
				ShowArray(array, arraySize);
				cout << endl;

				cout << "Enter searching value: ";
				int searchingValue = ReadNumber();
				cout << "Elements of array more than " << searchingValue
					 << " is: " << SearchingValue(array, arraySize, searchingValue) << endl;
				system("pause");
				break;
			}
			case 3:
			{
				const int arraySize = 8;
				char array[arraySize]
				{ 'a', '1', '5', '@', 'f', '%', 'z', 'u' };
				cout << endl;

				cout << "Your array is: " << endl;
				ShowArray(array, arraySize);

				cout << endl;
				cout << "Letters in array: " << endl;
				LettersInArray(array, arraySize);
				cout << endl;
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