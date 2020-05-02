#include <exception>
#include "Time.h"

Time* MakeTime(int year, int month, int day, int hour, int minute)
{
	Time* time = new Time();
	SetYear(time, year);
	SetMonth(time, month);
	SetDay(time, day);
	SetHour(time, hour);
	SetMinute(time, minute);
	return time;
}

void SetYear(Time* time, int year)
{
	if (year < 0)
	{
		throw exception("The year can't be negative");
	}
	time->Year = year;
}

void SetMonth(Time* time, int month)
{
	if ((month > 12) || (month <= 0))
	{
		throw exception("Range from 1 to 12");
	}
	time->Month = month;
}

void SetDay(Time* time, int day)
{
	if ((day > 30) || (day <= 0))
	{
		throw exception("Range from 1 to 30");
	}
	time->Day = day;
}

void SetHour(Time* time, int hour)
{
	if ((hour > 24) || (hour <= 0))
	{
		throw exception("Range from 1 to 365");
	}
	time->Hour = hour;
}

void SetMinute(Time* time, int minute)
{
	if ((minute >= 60) || (minute < 0))
	{
		throw exception("Range from 1 to 60");
	}
	time->Minute = minute;
}