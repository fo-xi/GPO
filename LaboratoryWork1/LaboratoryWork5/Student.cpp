#include "Student.h"
#include <exception> 

Student::Student(const string& name, const string& surname, 
	const string& patronymic, int recordBookNumber, int yearReceipt)
	: Person(name, surname, patronymic)
{
	SetRecordBookNumber(recordBookNumber);
	SetYearReceipt(yearReceipt);
}

void Student::SetRecordBookNumber(int recordBookNumber)
{
	if (recordBookNumber < 0)
	{
		throw exception("The value cannot be negative");
	}
	this->_recordBookNumber = recordBookNumber;
}

void Student::SetYearReceipt(int yearReceipt)
{
	if ((yearReceipt < 0) || (yearReceipt > 2020))
	{
		throw exception
		("The value does not fall within the range from 0 to 2020");
	}
	this->_yearReceipt = yearReceipt;
}

int Student::GetRecordBookNumber()
{
	return this->_recordBookNumber;
}

int Student::GetYearReceipt()
{
	return this->_yearReceipt;
}