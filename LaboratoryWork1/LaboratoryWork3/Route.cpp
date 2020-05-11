#include "Route.h"
#include "..\Common\ReadNumber.h"
#include "ReadValuesRangeFrom0to60.h"
#include "ReadValuesRangeFrom0to10.h"

void DemoRoute()
{
	const int count = 1;
	Route routes[count] = {};

	for (int i = 0; i < count; i++)
	{
		ReadRouteFromConsole(routes[i]);
		cout << endl;
	}
	for (int i = 0; i < count; i++)
	{
		WriteRouteFromConsole(routes[i]);
		cout << endl;
	}

	cout << "Enter the name stop to search for the route ->\t";
	string nameStop;
	cin >> nameStop;
	int indexRoute = FindRouteTo(routes, count, nameStop);
	if (indexRoute == -1)
	{
		cout << "There is no route with this name stop" << endl;
	}

	for (int i = 0; i < count; i++)
	{
		delete[] routes[i].NamesStops;
	}
}

void ReadRouteFromConsole(Route& route)
{
	cout << "Enter the route number ->\t";
	route.RouteNumber = ReadNumber<int>();
	cout << "Enter the average of the route ->\t";
	route.AverageRoute = ReadValuesRangeFrom0to60<int>();
	cout << "Enter the frequency of the route ->\t";
	route.FrequencyRoute = ReadValuesRangeFrom0to60<int>();
	cout << "Enter the number of stops ->\t";
	route.NumberStops = ReadValuesRangeFrom0to10<int>();

	route.NamesStops = new string[route.NumberStops];
	for (int i = 0; i < route.NumberStops; i++)
	{
		cout << "Enter a stop ¹" << i + 1 << "->\t";
		cin >> route.NamesStops[i];
	}
}

void WriteRouteFromConsole(Route& route)
{
	for (int i = 0; i < route.NumberStops; i++)
	{
		cout << route.NamesStops[i] << ",";
	}
	cout << ". "
		<< route.RouteNumber
		<< ". " << route.AverageRoute
		<< ". " << route.FrequencyRoute
		<< endl;
}

int FindRouteTo(Route* routes, int routesCount, string& stop)
{
	for (int i = 0; i < routesCount; i++)
	{
		for (int j = 0; j < routes[i].NumberStops; j++)
		{
			if (routes[i].NamesStops[j] == stop)
			{
				return i;
			}
		}
	}
	return -1;
}