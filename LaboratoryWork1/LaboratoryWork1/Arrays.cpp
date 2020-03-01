#include <iostream>
#include "Arrays.h"

using namespace std;

void Sorting(int* array, int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = 0; j < arraySize - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int SearchingValue(double* array, int arraySize, int searchingValue)
{
	int count = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] >= searchingValue)
		{
			count++;
		}
	}
	return count;
}

void LettersInArray(char* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] >= 'a' && array[i] <= 'z')
		{
			cout << array[i] << " ";
		}
	}
}