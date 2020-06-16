#include "Student.h"
#include "DoubleValidator.h"

Student::Student(const string& name, const string& surname, 
	const string& patronymic, int recordBookNumber, int yearReceipt)
	: Person(name, surname, patronymic)
{
	SetRecordBookNumber(recordBookNumber);
	SetYearReceipt(yearReceipt);
}

void Student::SetRecordBookNumber(int recordBookNumber)
{
	DoubleValidator::AssertPositiveValue(recordBookNumber);
	this->_recordBookNumber = recordBookNumber;
}

void Student::SetYearReceipt(int yearReceipt)
{
	DoubleValidator::AssertPositiveValue(yearReceipt);
	DoubleValidator::AssertValueRange(yearReceipt, 0, 2020);
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