#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
	private:
		string _name;
		string _surname;
		string _patronymic;
	public:
		Person(string&, string&, string&);
		void SetName(string&);
		void SetSurname(string&);
		void SetPatronymic(string&);
	
		string GetName();
		string GetSurname();
		string GetPatronymic();
};