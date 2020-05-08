#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Route
{
	int RouteNumber;
	int AverageRoute;
	//TODO: Опечатка (+)
	int FrequencyRoute;
	string* NamesStops;
	int NumberStops;
};

void DemoRoute();
void ReadRouteFromConsole(Route&);
void WriteRouteFromConsole(Route&);
//TODO: Строку по ссылке? (+)
int FindRouteTo(Route*, int, string&);
