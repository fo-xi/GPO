#include "Route.h"
#include "..\Common\ReadNumber.h"

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

	while (true)
	{
		cout << "Enter the average route length ->\t";
		route.AverageRoute = ReadNumber<int>();
		if ((route.AverageRoute > 0) && (route.AverageRoute <= 60))
		{
			break;
		}
		else
		{
			cout << "The value must be greater than";
			cout << "0 and less than 60. Try again." << endl;
		}
	}

	while (true)
	{
		cout << "Enter the frequency of the route ->\t";
		route.RrequencyRoute = ReadNumber<int>();
		if ((route.RrequencyRoute > 0) && (route.RrequencyRoute <= 60))
		{
			break;
		}
		else
		{
			cout << "The value must be greater than";
			cout << "0 and less than 60. Try again." << endl;
		}
	}

	while (true)
	{
		cout << "Enter the number of stops ->\t";
		route.NumberStops = ReadNumber<int>();
		if ((route.NumberStops >= 1) and (route.NumberStops <= 10))
		{
			break;
		}
		else
		{
			cout << "The number of stops should";
			cout << "be within 1-10. Try again." << endl;
		}
	}

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
		<< ". " << route.RrequencyRoute
		<< endl;
}

int FindRouteTo(Route* routes, int routesCount, string stop)
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