#include <exception>
#include "ClassRectangle.h"

Rectangle::Rectangle(double length, double width, Point* center)
{
	this->SetLength(length);
	this->SetWidth(width);
	this->SetCenter(center);
}

void Rectangle::SetLength(double length)
{
	DoubleValidator::AssertPositiveValue(length);
	this->_length = length;
}

void Rectangle::SetWidth(double width)
{
	DoubleValidator::AssertPositiveValue(width);
	this->_width = width;
}

void Rectangle::SetCenter(Point* center)
{
	//TODO: Может быть утечка памяти, т.к. через конструктор создал точку, а тут просто переопределил, а память не освободил
	this->_center = center;
}

double Rectangle::GetLength()
{
	return this->_length;
}

double Rectangle::GetWidth()
{
	return this->_width;
}

Point* Rectangle::GetCenter()
{
	return this->_center;
}