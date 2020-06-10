#include "Person.h"

Person::Person(const string& name, 
	const string& surname, const string& patronymic)
{
	this->SetName(name);
	this->SetSurname(surname);
	this->SetPatronymic(patronymic);
}

void Person::SetName(const string& name)
{
	this->_name = name;
}

void Person::SetSurname(const string& surname)
{
	this->_surname = surname;
}

void Person::SetPatronymic(const string& patronymic)
{
	this->_patronymic = patronymic;
}

const string& Person::GetName()
{
	return this->_name;
}

const string& Person::GetSurname()
{
	return this->_surname;
}

const string& Person::GetPatronymic()
{
	return this->_patronymic;
}