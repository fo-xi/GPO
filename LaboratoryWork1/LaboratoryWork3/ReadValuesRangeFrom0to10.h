#pragma once
#include <iostream>

using namespace std;

template <typename T>
T ReadValuesRangeFrom0to10()
{
	T number;
	while (true)
	{
		number = ReadNumber<int>();
		if ((number >= 1) and (number <= 10))
		{
			break;
		}
		else
		{
			cout << "The value must be in the ";
			cout << "range from 0 to 10. Try again." << endl;
		}
	}
	return number;
}