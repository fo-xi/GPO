#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Route
{
	int RouteNumber;
	int AverageRoute;
	int RrequencyRoute;
	string* NamesStops;
	int NumberStops;
};

void DemoRoute();
void ReadRouteFromConsole(Route&);
void WriteRouteFromConsole(Route&);
int FindRouteTo(Route*, int, string);
