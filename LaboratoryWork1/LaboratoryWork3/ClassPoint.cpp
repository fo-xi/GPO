#include "ClassPoint.h"

Point* Point::MakePoint(double x, double y)
{
	Point* point = new Point();
	this->SetX(x);
	this->SetY(y);
	return point;
}

void Point::SetX(double x)
{
	this->_x = x;
}

void Point::SetY(double y)
{
	this->_y = y;
}

double Point::GetX()
{
	return this->_x;
}

double Point::GetY()
{
	return this->_y;
}