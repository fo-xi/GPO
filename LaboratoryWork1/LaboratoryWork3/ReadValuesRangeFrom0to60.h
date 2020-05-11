#pragma once
#include <iostream>

using namespace std;

//TODO: ����� ������� ����������... ����� �� ���� ���������� ������� � �������� ������� ����������. ������� � ����������� � 0-10
template <typename T>
T ReadValuesRangeFrom0to60()
{
	T number;
	while (true)
	{
		number = ReadNumber<int>();
		if ((number > 0) && (number <= 60))
		{
			break;
		}
		else
		{
			cout << "The value must be in the ";
			cout << "range from 0 to 60. Try again." << endl;
		}
	}
	return number;
}