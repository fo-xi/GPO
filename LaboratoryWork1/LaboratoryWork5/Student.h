#pragma once
#include "Person.h"

class Student : public Person
{
	private:
		int _recordBookNumber;
		int _yearReceipt;
	public:
		Student(const string&, const string&, const string&, int, int);
		void SetRecordBookNumber(int);
		void SetYearReceipt(int);

		int GetRecordBookNumber();
		int GetYearReceipt();
};