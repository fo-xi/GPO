#include <iostream>
#include "Time.h"
#include "..\Common\ReadNumber.h"

void WriteTime(Time& time)
{
	cout << "Time ->\t" << time.Hours << ":"
		<< time.Minutes << ":"
		<< time.Seconds << endl;
}

void ReadTime(Time& time)
{
	cout << "Hours:\t";
	time.Hours = ReadNumber<int>();
	cout << "Minutes:\t";
	time.Minutes = ReadNumber<int>();
	cout << "Seconds:\t";
	time.Seconds = ReadNumber<int>();
}

void DemoTime()
{
	//2.2.3.1
	Time time1;
	time1.Hours = 22;
	time1.Minutes = 15;
	time1.Seconds = 54;
	//2.2.3.2
	Time time2;
	cout << "Hours:\t";
	time2.Hours = ReadNumber<int>();
	cout << "Minutes:\t";
	time2.Minutes = ReadNumber<int>();
	cout << "Seconds:\t";
	time2.Seconds = ReadNumber<int>();

	cout << "Time ->\t" << time2.Hours << ":"
		<< time2.Minutes << ":"
		<< time2.Seconds << endl;
	cout << endl;
	//2.2.3.3
	const int count = 3;
	Time arrayTime[count] = {};

	for (int i = 0; i < count; i++)
	{
		ReadTime(arrayTime[i]);
		cout << endl;
	}
	for (int i = 0; i < count; i++)
	{
		WriteTime(arrayTime[i]);
		cout << endl;
	}
	//TODO: RSDN
	//2.2.4.1
	Time* pointerTime1;
	pointerTime1 = &time1;
	//2.2.4.2
	Time* pointer2Time1;
	pointer2Time1 = &time1;
	cout << "The address that is stored in the first pointer to the structure: "
		<< pointerTime1 << "\n"
		<< "The address that is stored in the first pointer to the structure: "
		<< pointer2Time1 << endl;
}

Time* MakeTime(int hours, int minutes, int seconds)
{
	Time* time = new Time();
	time->Hours = hours;
	time->Minutes = minutes;
	time->Seconds = seconds;
	WriteTime(*time);
	return time;
}

Time* CopyTime(Time& time)
{
	Time* copiedTime = new Time();
	copiedTime->Hours = time.Hours;
	copiedTime->Minutes = time.Minutes;
	copiedTime->Seconds = time.Seconds;
	WriteTime(*copiedTime);
	return copiedTime;
}