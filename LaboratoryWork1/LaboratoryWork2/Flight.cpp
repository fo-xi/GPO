#include <iostream>
#include "Flight.h"
#include "Movie.h"
#include "..\Common\ReadNumber.h"

void WriteFlight(Flight& flight)
{
	cout << "Flight " << flight.DeparturePoint << " - "
		<< flight.Destination << " is in flight "
		<< flight.FlightTime << " minutes" << endl;
}

void ReadFlight(Flight& flight)
{
	cout << "Departure Point:\t";
	cin >> flight.DeparturePoint;
	cout << "Destination:\t";
	cin >> flight.Destination;
	cout << "FlightTime:\t";
	flight.FlightTime = ReadNumber<int>();
}

void DemoFlight()
{
	//2.2.3.1
	Flight flight1;
	flight1.DeparturePoint = "Tomsk";
	flight1.Destination = "Novosibirsk";
	flight1.FlightTime = 120;
	//2.2.3.2
	Flight flight2;
	cout << "Departure Point:\t";
	cin >> flight2.DeparturePoint;
	cout << "Destination:\t";
	cin >> flight2.Destination;
	cout << "FlightTime:\t";
	flight2.FlightTime = ReadNumber<int>();
	cout << "Flight " << flight2.DeparturePoint << " - "
		<< flight2.Destination << " is in flight "
		<< flight2.FlightTime << " minutes" << endl;
	cout << endl;
	//2.2.3.3
	const int count = 3;
	Flight arrayFlight[count] = {};
	for (int i = 0; i < count; i++)
	{
		ReadFlight(arrayFlight[i]);
		cout << endl;
	}
	for (int i = 0; i < count; i++)
	{
		WriteFlight(arrayFlight[i]);
		cout << endl;
	}
	//2.2.4.1
	//TODO: RSDN (+)
	Flight* pointerFlight1 = &flight1;
	//2.2.4.2
	//TODO: RSDN (+)
	Flight* pointer2Flight1 = &flight1;
	cout << "The address that is stored in the first pointer to the structure: "
		<< pointerFlight1 << "\n"
		<< "The address that is stored in the first pointer to the structure: "
		<< pointer2Flight1 << endl;
	//2.2.6.3
	cout << endl;
	FindShortestFlight(arrayFlight, count);
}

void WrongPointers()
{
	Flight flight;
	Movie movie;
	//TODO: RSDN (+)
	Flight* pointerFlight = &flight;
	Movie* pointerMovie = &movie;
}

void DemoDynamicFlight()
{
	Flight* pointerFlight = new Flight;
	ReadFlight(*pointerFlight);
	WriteFlight(*pointerFlight);
	delete pointerFlight;
}

void DemoDynamicFlights()
{
	const int count = 4;
	Flight* pointerFlight = new Flight[count];
	for (int i = 0; i < count; i++)
	{
		ReadFlight(pointerFlight[i]);
		cout << endl;
	}
	for (int i = 0; i < count; i++)
	{
		WriteFlight(pointerFlight[i]);
		cout << endl;
	}
	delete[] pointerFlight;
}

void FindShortestFlight(Flight* flights, int count)
{
	Flight maximumFlightTime = flights[0];
	for (int i = 0; i < count; ++i)
	{
		if (flights[i].FlightTime < maximumFlightTime.FlightTime)
		{
			maximumFlightTime = flights[i];
		}
	}
	cout << "The flight with the shortest flight time:" << endl;
	WriteFlight(maximumFlightTime);
	cout << endl;
}

//TODO: передача по значению, насколько правильно? (+)
Flight* MakeFlight(string& departurePoint, string& destination, int flightTime)
{
	Flight* flight = new Flight();
	flight->DeparturePoint = departurePoint;
	flight->Destination = destination;
	flight->FlightTime = flightTime;
	WriteFlight(*flight);
	return flight;
}

Flight* CopyFlight(Flight& flight)
{
	Flight* copiedFlight = new Flight();
	copiedFlight->DeparturePoint = flight.DeparturePoint;
	copiedFlight->Destination = flight.Destination;
	copiedFlight->FlightTime = flight.FlightTime;
	WriteFlight(*copiedFlight);
	return copiedFlight;
}