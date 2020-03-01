#include <iostream>
#include "Functions.h"

using namespace std;

int GetPower(int base, int exponent)
{
	int result;
	result = pow(base, exponent);
	return result;
}

void DemoGetPower(int base, int exponent)
{
	cout << base << "^" << exponent << "=" << GetPower(base, exponent) << endl;
}

int RoundToTens(int value)
{
	int remainder = value % 10;
	if (remainder < 5)
	{
		value = (value / 10) * 10;
	}
	else
	{
		value = ((1 + (value / 10)) * 10);
	}
	return value;
}