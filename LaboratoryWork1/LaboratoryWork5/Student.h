#pragma once
#include "Person.h"

class Student : public Person
{
	private:
		int _recordBookNumber;
		int _yearReceipt;
	public:
	//TODO: Константные ссылки?
		Student(string&, string&, string&, int, int);
		void SetRecordBookNumber(int);
		void SetYearReceipt(int);

		int GetRecordBookNumber();
		int GetYearReceipt();
};