#include <exception>
#include "ClassRing.h"

int Ring::AllRingsCount = 0;

Ring::Ring(double outerRadius, double innerRadius, double x, double y)
{
	this->SetRadiuses(outerRadius, innerRadius);
	this->SetCenter(x, y);
	Ring::GrowAllRingsCount();
}

double Ring::AssertOnPositiveValue(double value)
{
	//TODO: ѕравильнее инвертировать условие и в первом блоке писать то, что €вл€етс€ стандартным процессом, а в else - уже нестандартное действие (бросание исключени€) (+)
	if (value > 0)
	{
		return value;
	}
	else
	{
		throw exception("Value cannot be negative");
	}
}

void Ring::SetRadiuses(double outerRadius, double innerRadius)
{
	DoubleValidator::AssertPositiveValue(outerRadius);
	DoubleValidator::AssertPositiveValue(innerRadius);
	if (innerRadius > outerRadius)
	{
		//TODO: RSDN - длина строки (+)
		throw exception("The internal radius cannot be greater than the external one");
	}
	this->_outerRadius = outerRadius;
	this->_innerRadius = innerRadius;
}

void Ring::SetCenter(double x, double y)
{
	this->_center = new Point(x, y);
}

double Ring::GetOuterRadius()
{
	return this->_outerRadius;
}

double Ring::GetInnerRadius()
{
	return this->_innerRadius;
}

Point* Ring::GetCenter()
{
	return this->_center;
}

double Ring::GetArea()
{
	int degree = 2;
	double ringArea = PI * (pow(GetOuterRadius(), degree)
		- pow(GetInnerRadius(), degree));
	return ringArea;
}

int Ring::GetAllRingsCount()
{
	return AllRingsCount;
}

int Ring::GrowAllRingsCount()
{
	Ring::AllRingsCount++;
	return Ring::AllRingsCount;
}

int Ring::DecreaseAllRingsCount()
{
	Ring::AllRingsCount--;
	return Ring::AllRingsCount;
}

Ring::~Ring()
{
	DecreaseAllRingsCount();
	delete this->_center;
}