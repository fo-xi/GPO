#pragma once
#include "Person.h"

class Teacher : public Person
{
	private:
		string _position;
	public:
	//TODO: ����������� ������?
		Teacher(string&, string&, string&, string&);
		void SetPosition(string&);

		string GetPosition();
};