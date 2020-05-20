#pragma once
#include <iostream>

using namespace std;
//TODO: Очень негибко получилось... Гибче бы было передавать границы в качестве входных параметров. Поэтому и дублируется с 0-60
template <typename T>
T ReadValuesRangeFrom1to10(T number)
{
	while (true)
	{
		number = ReadNumber<int>();
		if ((number > 0) || (number <= 10))
		{
			break;
		}
		else
		{
			cout << "The value must be in the ";
			cout << "range from 1 to 10. Try again." << endl;
		}
	}
	return number;
}