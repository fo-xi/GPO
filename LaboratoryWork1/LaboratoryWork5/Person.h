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
		Person(const string&, const string&, const string&);
		void SetName(const string&);
		void SetSurname(const string&);
		void SetPatronymic(const string&);
	
		const string& GetName();
		const string& GetSurname();
		const string& GetPatronymic();
};