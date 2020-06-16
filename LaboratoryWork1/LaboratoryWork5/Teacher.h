#pragma once
#include "Person.h"

class Teacher : public Person
{
	private:
		string _position;
	public:
		Teacher(const string&, const string&, const string&, const string&);
		void SetPosition(const string&);

		const string& GetPosition();
};