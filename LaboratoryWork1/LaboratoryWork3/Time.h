#pragma once
#include <iostream>

using namespace std;

struct Time
{
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
};

Time* MakeTime(int, int, int, int, int);
void SetYear(Time*, int);
void SetMonth(Time*, int);
void SetDay(Time*, int);
void SetHour(Time*, int);
void SetMinute(Time*, int);