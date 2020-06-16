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
		//TODO: Границы в сообщении исключения могут не соответствовать текущим
		throw exception
		("The year must in the range from 0 to 2020");
	}
}

void DoubleValidator::AssertLogin(const string& value)
{
	if (!IsLogin(value))
	{
		throw exception("The login contains undesirable characters");
	}
}


