#pragma once
#include <iostream>

using namespace std;

class Time
{
	private:
		int _year;
		int _month;
		int _day;
		int _hour;
		int _minute;
	public:
		Time* MakeTime(int, int, int, int, int);
		void SetYear(int);
		void SetMonth(int);
		void SetDay(int);
		void SetHour(int);
		void SetMinute(int);

		int GetYear();
		int GetMonth();
		int GetDay();
		int GetHour();
		int GetMinute();
};