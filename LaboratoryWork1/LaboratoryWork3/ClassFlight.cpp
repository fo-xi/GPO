#include <exception>
#include "ClassFlight.h"

Flight::Flight(string& flightNumber, string& pointDeparture, string& destination,
	Time* departureTime, Time* arrivalTime)
{
	this->SetFlightNumber(flightNumber);
	this->SetPointDeparture(pointDeparture);
	this->SetDestination(destination);
	this->SetDepartureTime(departureTime);
	this->SetArrivalTime(arrivalTime);
}

void Flight::SetFlightNumber(string& flightNumber)
{
	this->_flightNumber = flightNumber;
}

void Flight::SetPointDeparture(string& pointDeparture)
{
	this->_pointDeparture = pointDeparture;
}

void Flight::SetDestination(string& destination)
{
	this->_destination = destination;
}

void Flight::SetDepartureTime(Time* departureTime)
{
	this->_departureTime = departureTime;
}

void Flight::SetArrivalTime(Time* arrivalTime)
{
	if ((this->_departureTime->GetYear() > arrivalTime->GetYear()) ||
		(this->_departureTime->GetMonth() > arrivalTime->GetMonth()) ||
		(this->_departureTime->GetDay() > arrivalTime->GetDay()))
	{
		throw exception("Time arrival cannot be earlier than the departure time");
	}
	this->_arrivalTime = arrivalTime;
}

int Flight::GetFlightTimeMinutes()
{
	int minutesInHour = 60;
	int hoursInDay = 24;
	int flightTimeHours = this->_arrivalTime->GetHour() -
		this->_departureTime->GetHour();
	int flightTimeMinutes = this->_arrivalTime->GetMinute() -
		this->_departureTime->GetMinute();
	int daysInFlight = (this->_arrivalTime->GetDay() -
		this->_departureTime->GetDay()) * hoursInDay;

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
	departures[0] = new Time(2019, 1, 23, 14, 21);
	departures[1] = new Time(2018, 2, 12, 15, 30);
	departures[2] = new Time(2017, 3, 11, 21, 59);
	departures[3] = new Time(2016, 4, 5, 16, 48);
	departures[4] = new Time(2015, 5, 17, 4, 31);

	Time* arrivals[count];
	arrivals[0] = new Time(2019, 1, 23, 17, 44);
	arrivals[1] = new Time(2018, 2, 13, 17, 56);
	arrivals[2] = new Time(2017, 3, 11, 23, 59);
	arrivals[3] = new Time(2016, 4, 5, 20, 57);
	arrivals[4] = new Time(2015, 5, 18, 12, 44);

	Flight* flights[count];

	string flightNumber = "S578D";
	string pointDeparture = "Chelyabinsk";
	string destination = "Yekaterinburg";
	flights[0] = new Flight(flightNumber, pointDeparture,
		destination, departures[0], arrivals[0]);

	flightNumber = "MRM43";
	pointDeparture = "Samara";
	destination = "Kazan";
	flights[1] = new Flight(flightNumber, pointDeparture,
		destination, departures[1], arrivals[1]);

	flightNumber = "LF543";
	pointDeparture = "Omsk";
	destination = "Perm";
	flights[2] = new Flight(flightNumber, pointDeparture,
		destination, departures[2], arrivals[2]);

	flightNumber = "SLD33";
	pointDeparture = "Krasnoyarsk";
	destination = "Saratov";
	flights[3] = new Flight(flightNumber, pointDeparture,
		destination, departures[3], arrivals[3]);

	flightNumber = "R34R2";
	pointDeparture = "Novosibirsk";
	destination = "Izhevsk";
	flights[4] = new Flight(flightNumber, pointDeparture,
		destination, departures[4], arrivals[4]);

	for (int i = 0; i < count; i++)
	{
		cout << flights[i]->GetFlightNumber() << " "
			<< flights[i]->GetPointDeparture() << " - "
			<< flights[i]->GetDestination() << " Departure "
			<< flights[i]->GetDepartureTime()->GetYear() << "."
			<< flights[i]->GetDepartureTime()->GetMonth() << "."
			<< flights[i]->GetDepartureTime()->GetDay() << " "
			<< flights[i]->GetDepartureTime()->GetHour() << ":"
			<< flights[i]->GetDepartureTime()->GetMinute() << " Arrival "
			<< flights[i]->GetArrivalTime()->GetYear() << "."
			<< flights[i]->GetArrivalTime()->GetMonth() << "."
			<< flights[i]->GetArrivalTime()->GetDay() << " "
			<< flights[i]->GetArrivalTime()->GetHour() << ":"
			<< flights[i]->GetArrivalTime()->GetMinute() << endl;
	}
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		int result = flights[0]->GetFlightTimeMinutes();
		int minutes = 60;
		int flightHours = result / minutes;
		int flightMinute = result % minutes;

		cout << flights[i]->GetFlightNumber() << " "
			<< flights[i]->GetPointDeparture() << " - "
			<< flights[i]->GetDestination() << " flight time: "
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

string Flight::GetFlightNumber()
{
	return this->_flightNumber;
}

string Flight::GetPointDeparture()
{
	return this->_pointDeparture;
}

string Flight::GetDestination()
{
	return this->_destination;
}

Time* Flight::GetDepartureTime()
{
	return this->_departureTime;
}

Time* Flight::GetArrivalTime()
{
	return this->_arrivalTime;
}