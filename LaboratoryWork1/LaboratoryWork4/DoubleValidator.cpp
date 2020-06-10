#include <exception>
#include "DoubleValidator.h"


bool DoubleValidator::IsValuePositive(double value)
{
	if (value < 0)
	{
		return false;
	}
	return true;
}

bool DoubleValidator::IsValueInRange(double value, double min, double max)
{
	if ((value < min) && (value > max))
	{
		return false;
	}
	return true;
}

void DoubleValidator::AssertPositiveValue(double value)
{
	if (!IsValuePositive(value))
	{
		throw exception("The value cannot be negative!");
	}
}

void DoubleValidator::AssertValueInRange(double value, double min, double max)
{
	if (!IsValueInRange(value, min, max))
	{
		throw exception
		("The value does not fall within the acceptable range!");
	}
}