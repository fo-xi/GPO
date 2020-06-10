#include "Teacher.h"
//TODO: RSDN - длинна строки (+)
Teacher::Teacher(const string& name, const string& surname,
	const string& patronymic, const string& position)
	   : Person(name, surname, patronymic)
{
	SetPosition(position);
}

void Teacher::SetPosition(const string& position)
{
	this->_position = position;
}

const string& Teacher::GetPosition()
{
	return this->_position;
}