#pragma once
#include <iostream>
#include <string>
#include"ClassTime.h"

class Flight
{
	private:
		string _flightNumber;
		string _pointDeparture;
		string _destination;
		Time* _departureTime;
		Time* _arrivalTime;
	public:
		Flight(string&, string&, string&, Time*, Time*);
		void SetFlightNumber(string&);
		void SetPointDeparture(string&);
		void SetDestination(string&);
		void SetDepartureTime(Time*);
		void SetArrivalTime(Time*);

		int GetFlightTimeMinutes();
		void DemoFlightWithTime();

		string GetFlightNumber();
		string GetPointDeparture();
		string GetDestination();
		Time* GetDepartureTime();
		Time* GetArrivalTime();
};