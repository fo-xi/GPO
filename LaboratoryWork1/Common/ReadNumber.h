#pragma once
#include <iostream>

using namespace std;

template <typename T>
T ReadNumber()
{
	bool error;
	T number;
	do
	{
		error = false;
		cin >> number;
		if (cin.fail())
		{
			cout << "Error\n";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);
	return number;
}