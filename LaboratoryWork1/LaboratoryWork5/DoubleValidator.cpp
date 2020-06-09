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

bool DoubleValidator::IsYear(int value)
{
	//TODO: Дублируется ниже	
	if ((value < 0) || (value > 2020))
	{
		return false;
	}
	return true;
}

bool DoubleValidator::IsLogin(string& value)
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

bool DoubleValidator::IsCost(double value)
{
	//TODO: Дублируется разница только в границах
	if ((value < 0) || (value > 100000))
	{
		return false;
	}
	return true;
}

bool DoubleValidator::IsPercent(double value)
{
	//TODO: Дублируется разница только в границах
	if ((value < 0) || (value > 100))
	{
		return false;
	}
	return true;
}

bool DoubleValidator::IsAmount(double value)
{
	if ((value < 0) || (value > 10000))
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

void DoubleValidator::AssertYear(int value)
{
	if (!IsYear(value))
	{
		//TODO: RSDN - длина строки
		throw exception("The year must be positive in the range from 0 to 2020 inclusive");
	}
}

void DoubleValidator::AssertLogin(string& value)
{
	if (!IsLogin(value))
	{
		throw exception("The login contains undesirable characters");
	}
}

void DoubleValidator::AssertCost(double value)
{
	if (!IsCost(value))
	{
		throw exception("The cost must be in the range from 0 to 100,000");
	}
}

void DoubleValidator::AssertPercent(double value)
{
	if (!IsPercent(value))
	{
		throw exception("The cost must be in the range from 0 to 100");
	}
}

void DoubleValidator::AssertAmount(double value)
{
	if (!IsAmount(value))
	{
		throw exception("The cost must be in the range from 0 to 10,000");
	}
}
