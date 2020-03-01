#include <iostream>
#include "DynamicMemory.h"
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

void MenuDynamicMemory()
{
	setlocale(LC_ALL, "Russian");

	bool isEnd = true;

	while (isEnd)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1: Array of double" << endl;
		cout << "2. Array of bool" << endl;
		cout << "3. Array of char" << endl;
		cout << "4. Array and sort" << endl;
		cout << "5. Search for an array element index" << endl;
		cout << "6. Output all letters in an array" << endl;
		cout << "7. Make random array" << endl;
		cout << "8. Counting elements in an array" << endl;
		cout << "9. Exit" << endl;

		switch (ReadNumber())
		{
			case 1:
			{
				const int arraySize = 8;
				double* array = new double[arraySize]
				{ 1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5 };

				cout << "Array of double: " << endl;
				ShowArray(array, arraySize);

				delete[] array;
				system("pause");
				break;
			}
			case 2:
			{
				const int arraySize = 8;
				bool* array = new bool[arraySize]
				{ true, false, true, true, false, true, false, false };

				cout << "Array of bool: " << endl;
				ShowArray(array, arraySize);

				delete[] array;
				system("pause");
				break;
			}
			case 3:
			{
				cout << "Enter char array size: ";
				const int arraySize = ReadNumber();
				char* array = new char[arraySize];

				for (int i = 0; i < arraySize; i++)
				{
					cout << "array[" << i << "]" << ": ";
					cin >> array[i];
				}
				cout << "Your char array is: " << endl;
				ShowArray(array, arraySize);

				delete[] array;
				system("pause");
				break;
			}
			case 4:
			{
				const int arraySize = 10;
				double* array = new double[arraySize]
				{ 1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5, 16.7, 4.5 };

				cout << "Array of double: " << endl;
				ShowArray(array, arraySize);

				Sorting(array, arraySize);

				cout << "Sorted array is: " << endl;
				ShowArray(array, arraySize);

				delete[] array;
				system("pause");
				break;
			}
			case 5:
			{
				const int arraySize = 10;
				int* array = new int[arraySize]
				{ 1, 15, -8, -3, 12, 38, -0, 4, 16, 4 };

				cout << "Source array is: " << endl;
				ShowArray(array, arraySize);

				cout << "Enter searching value: ";
				int value = ReadNumber();
				int index;
				if (SearchIndex(array, arraySize, value, index))
				{
					cout << "Index of searching value " << value << " is: " << index << endl;
				}
				else
				{
					cout << "Index not found!" << endl;
				}

				delete[] array;
				system("pause");
				break;
			}
			case 6:
			{
				const int arraySize = 15;
				char* array = new char[arraySize]
				{ 'a', '5', 'm', 'i', '%', '!', 's', 'p', '*', '9', 'f', '^', ';', 'q', 'k' };

				cout << "Char array is: " << endl;
				ShowArray(array, arraySize);

				cout << endl;
				cout << "Letters in array: " << endl;
				LettersInDynamicArray(array, arraySize);
				cout << endl;

				delete[] array;
				system("pause");
				break;
			}
			case 7:
			{
				int arraySize = 5;
				int* fiveElementArray = MakeRandomArray(arraySize);
				cout << "Random array of 5: " << endl;
				ShowArray(fiveElementArray, arraySize);

				arraySize = 8;
				int* eightElementArray = MakeRandomArray(arraySize);
				cout << "Random array of 8: " << endl;
				ShowArray(eightElementArray, arraySize);

				arraySize = 13;
				int* thirteenElementArray = MakeRandomArray(arraySize);
				cout << "Random array of 13: " << endl;
				ShowArray(thirteenElementArray, arraySize);

				delete[] fiveElementArray;
				delete[] eightElementArray;
				delete[] thirteenElementArray;
				system("pause");
				break;
			}
			case 8:
			{
				int count = 15;
				int* values = ReadArray(count);
				cout << "Count is: " << CountPositiveValues(values, count) << endl;

				delete[] values;

				count = 20;
				values = ReadArray(count);
				cout << "Count is: " << CountPositiveValues(values, count) << endl;

				delete[] values;
				break;
			}
			case 9:
			{
				isEnd = false;
				break;
			}
		default:
			break;
		}
	}
}