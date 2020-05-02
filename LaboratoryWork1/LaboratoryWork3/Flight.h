#pragma once
#include <iostream>
#include <string>
#include "Time.h"

struct Flight
{
	string FlightNumber;
	string PointDeparture;
	string Destination;
	Time* DepartureTime;
	Time* ArrivalTime;
};

Flight* MakeFlight(string, string, string, Time*, Time*);
void SetFlightNumber(Flight*, string);
void SetPointDeparture(Flight*, string);
void SetDestination(Flight*, string);
void SetDepartureTime(Flight*, Time*);
void SetArrivalTime(Flight*, Time*);
int GetFlightTimeMinutes(Flight&);
void DemoFlightWithTime();