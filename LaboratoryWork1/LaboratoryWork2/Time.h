#pragma once

using namespace std;

struct Time
{
	int Hours;
	int Minutes;
	int Seconds;
};

void WriteTime(Time&);
void ReadTime(Time&);
void DemoTime();
Time* MakeTime(int, int, int);
Time* CopyTime(Time&);