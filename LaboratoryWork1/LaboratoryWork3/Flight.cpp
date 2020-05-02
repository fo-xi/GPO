#include <exception>
#include "Flight.h"

Flight* MakeFlight(string flightNumber, string pointDeparture, string destination,
	Time* departureTime, Time* arrivalTime)
{
	Flight* flight = new Flight();
	SetFlightNumber(flight, flightNumber);
	SetPointDeparture(flight, pointDeparture);
	SetDestination(flight, destination);
	SetDepartureTime(flight, departureTime);
	SetArrivalTime(flight, arrivalTime);
	return flight;
}

void SetFlightNumber(Flight* flight, string flightNumber)
{
	flight->FlightNumber = flightNumber;
}

void SetPointDeparture(Flight* flight, string pointDeparture)
{
	flight->PointDeparture = pointDeparture;
}

void SetDestination(Flight* flight, string destination)
{
	flight->Destination = destination;
}

void SetDepartureTime(Flight* flight, Time* departureTime)
{
	flight->DepartureTime = departureTime;
}

void SetArrivalTime(Flight* flight, Time* arrivalTime)
{
	if ((flight->DepartureTime->Year > arrivalTime->Year) ||
		(flight->DepartureTime->Month > arrivalTime->Month) ||
		(flight->DepartureTime->Day > arrivalTime->Day))
	{
		throw exception("Time arrival cannot be earlier than the departure time");
	}
	flight->ArrivalTime = arrivalTime;
}

int GetFlightTimeMinutes(Flight* flight)
{
	int minutesInHour = 60;
	int hoursInDay = 24;
	int flightTimeHours = flight->ArrivalTime->Hour - 
		flight->DepartureTime->Hour;
	int flightTimeMinutes = flight->ArrivalTime->Minute - 
		flight->DepartureTime->Minute;
	int daysInFlight = (flight->ArrivalTime->Day - 
		flight->DepartureTime->Day) * hoursInDay;

	if (flightTimeMinutes < 0)
	{
		flightTimeHours--;
		flightTimeMinutes = minutesInHour + flightTimeMinutes;
	}

	return abs((((daysInFlight + flightTimeHours) * minutesInHour) + flightTimeMinutes));
}

void DemoFlightWithTime()
{
	const int count = 5;
	Time* departures[count];
	departures[0] = MakeTime(2019, 1, 23, 14, 21);
	departures[1] = MakeTime(2018, 2, 12, 15, 30);
	departures[2] = MakeTime(2017, 3, 11, 21, 59);
	departures[3] = MakeTime(2016, 4, 5, 16, 48);
	departures[4] = MakeTime(2015, 5, 17, 4, 31);

	Time* arrivals[count];
	arrivals[0] = MakeTime(2019, 1, 23, 17, 44);
	arrivals[1] = MakeTime(2018, 2, 13, 17, 56);
	arrivals[2] = MakeTime(2017, 3, 11, 23, 59);
	arrivals[3] = MakeTime(2016, 4, 5, 20, 57);
	arrivals[4] = MakeTime(2015, 5, 18, 12, 44);

	Flight* flights[count];
	flights[0] = MakeFlight("S578D", "Chelyabinsk", "Yekaterinburg",
		departures[0], arrivals[0]);
	flights[1] = MakeFlight("MRM43", "Samara", "Kazan",
		departures[1], arrivals[1]);
	flights[2] = MakeFlight("LF543", "Omsk", "Perm",
		departures[2], arrivals[2]);
	flights[3] = MakeFlight("SLD33", "Krasnoyarsk", "Saratov",
		departures[3], arrivals[3]);
	flights[4] = MakeFlight("R34R2", "Novosibirsk", "Izhevsk",
		departures[4], arrivals[4]);

	for (int i = 0; i < count; i++)
	{
		cout << flights[i]->FlightNumber << " "
			<< flights[i]->PointDeparture << " - "
			<< flights[i]->Destination << " Departure "
			<< flights[i]->DepartureTime->Month << "."
			<< flights[i]->DepartureTime->Day << " "
			<< flights[i]->DepartureTime->Hour << ":"
			<< flights[i]->DepartureTime->Minute << " Arrival "
			<< flights[i]->ArrivalTime->Month << "."
			<< flights[i]->ArrivalTime->Day << " "
			<< flights[i]->ArrivalTime->Hour << ":"
			<< flights[i]->ArrivalTime->Minute << endl;
	}
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		int result = GetFlightTimeMinutes(flights[i]);
		int minutes = 60;
		int flightHours = result / minutes;
		int flightMinute = result % minutes;

		cout << flights[i]->FlightNumber << " "
			<< flights[i]->PointDeparture << " - "
			<< flights[i]->Destination << " flight time: "
			<< flightHours << "h " << flightMinute
			<< "min" << endl;
	}
	for (int i = 0; i < count; i++)
	{
		delete departures[i];
		delete arrivals[i];
		delete flights[i];
	}
}
