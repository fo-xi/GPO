#pragma once
#include <string>

using namespace std;

struct Flight
{
	string DeparturePoint;
	string Destination;
	int FlightTime;
};

void WriteFlight(Flight&);
void ReadFlight(Flight&);
void DemoFlight();
void WrongPointers();
void DemoDynamicFlight();
void DemoDynamicFlights();
void FindShortestFlight(Flight*, int);
Flight* MakeFlight(string&, string&, int);
Flight* CopyFlight(Flight&);