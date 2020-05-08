#pragma once
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
T ReadValue(T value)
{
	if (value < 0)
	{
		throw exception("Value cannot be negative");
	}
	else
	{
		return value;
	}
}