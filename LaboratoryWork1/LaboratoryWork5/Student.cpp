#include "Student.h"
#include "DoubleValidator.h"
//TODO: RSDN - длина строки
Student::Student(string& name, string& surname, string& patronymic, int recordBookNumber, int yearReceipt)
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
	DoubleValidator::AssertYear(yearReceipt);
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