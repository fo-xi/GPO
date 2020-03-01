#include <iostream>
#include "DynamicMemory.h"

using namespace std;

void Sorting(double* array, int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = 0; j < arraySize - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				double temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

bool SearchIndex(int* array, int arraySize, int value, int& index)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] == value)
		{
			index = i;
			return true;
		}
	}
	return false;
}

void LettersInDynamicArray(char* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] >= 'a' && array[i] <= 'z')
		{
			cout << array[i] << " ";
		}
	}
}

int* MakeRandomArray(int arraySize)
{
	int* array = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 100;
	}

	return array;
}

int* ReadArray(int count)
{
	int* values = new int[count];
	for (int i = 0; i < count; i++)
	{
		cin >> values[i];
	}
	return values;
}

int CountPositiveValues(int* values, int count)
{
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (values[i] > 0)
		{
			result++;
		}
	}
	return result;
}