#pragma once
#include <iostream>

using namespace std;

template <typename T>
T ReadValueRange(T number, T initialBorder, T finalBorder)
{
	while (true)
	{
		number = ReadNumber<int>();
		if ((number > initialBorder) && (number <= finalBorder))
		{
			break;
		}
		else
		{
			cout << "Value is out of bounds. ";
			cout << "Try again." << endl;
		}
	}
	return number;
}