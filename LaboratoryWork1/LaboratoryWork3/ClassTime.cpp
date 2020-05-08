#include <exception>
#include "ClassTime.h"

Time::Time(int year, int month, int day, int hour, int minute)
{
	this->SetYear(year);
	this->SetMonth(month);
	this->SetDay(day);
	this->SetHour(hour);
	this->SetMinute(minute);
}

void Time::SetYear(int year)
{
	//TODO: Дублируется между cpp файлами (+)
	if ((year < 0) || (year > 2020))
	{
		throw exception("Year should be positive and not more than this year");
	}
	this->_year = year;
}

void Time::SetMonth(int month)
{
	if ((month > 12) || (month <= 0))
	{
		throw exception("Range from 1 to 12");
	}
	this->_month = month;
}

void Time::SetDay(int day)
{
	if ((day > 30) || (day <= 0))
	{
		throw exception("Range from 1 to 30");
	}
	this->_day = day;
}

void Time::SetHour(int hour)
{
	if ((hour > 24) || (hour <= 0))
	{
		throw exception("Range from 1 to 365");
	}
	this->_hour = hour;
}

void Time::SetMinute(int minute)
{
	if ((minute >= 60) || (minute < 0))
	{
		throw exception("Range from 1 to 60");
	}
	this->_minute = minute;
}

int Time::GetYear()
{
	return this->_year;
}

int Time::GetMonth()
{
	return this->_month;
}

int Time::GetDay()
{
	return this->_day;
}

int Time::GetHour()
{
	return this->_hour;
}

int Time::GetMinute()
{
	return this->_minute;
}