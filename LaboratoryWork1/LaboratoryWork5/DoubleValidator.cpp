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

bool DoubleValidator::IsValueRange(double value, 
	double initialBorder, double finalBorder)
{
	if ((value < initialBorder) || (value > finalBorder))
	{
		return false;
	}
	return true;
}

bool DoubleValidator::IsLogin(const string& value)
{
	string login = value;
	for (int i = 0; i < login.length(); i++)
	{
		if (login[i] == '{' || login[i] == '}' || login[i] == '<' || login[i] == '>' ||
			login[i] == '>' || login[i] == '@' || login[i] == '#' || login[i] == '$' ||
			login[i] == '%' || login[i] == '^' || login[i] == ':' || login[i] == '*')
		{
			return false;
		}
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

void DoubleValidator::AssertValueRange(double value, 
	double initialBorder, double finalBorder)
{
	if (!IsValueRange(value, initialBorder, finalBorder))
	{
		string message = "The value does not fall within the acceptable range from "
			+ to_string(initialBorder) + " to " + to_string(finalBorder);
		throw exception(message.c_str());
	}
}

void DoubleValidator::AssertLogin(const string& value)
{
	if (!IsLogin(value))
	{
		throw exception("The login contains undesirable characters");
	}
}


