#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Route
{
	int RouteNumber;
	int AverageRoute;
	//TODO: �������� (+)
	int FrequencyRoute;
	string* NamesStops;
	int NumberStops;
};

void DemoRoute();
void ReadRouteFromConsole(Route&);
void WriteRouteFromConsole(Route&);
//TODO: ������ �� ������? (+)
int FindRouteTo(Route*, int, string&);
