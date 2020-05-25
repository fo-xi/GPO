#include <exception>
#include "ClassRing.h"

int Ring::AllRingsCount = 0;

Ring::Ring(double outerRadius, double innerRadius, Point* center)
{
	this->SetRadiuses(outerRadius, innerRadius);
	this->SetCenter(center);
	Ring::GrowAllRingsCount();
}

double Ring::AssertOnPositiveValue(double value)
{
	if (value < 0)
	{
		throw exception("Value cannot be negative");
	}
	else
	{
		return value;
	}
}

void Ring::SetRadiuses(double outerRadius, double innerRadius)
{
	DoubleValidator::AssertPositiveValue(outerRadius);
	DoubleValidator::AssertPositiveValue(innerRadius);
	if (innerRadius > outerRadius)
	{
		throw exception("The internal radius cannot be greater than the external one, and the external radius cannot be less than the internal one");
	}
	this->_outerRadius = outerRadius;
	this->_innerRadius = innerRadius;
}

void Ring::SetCenter(Point* center)
{
	this->_center = center;
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
}

void DemoRing()
{
	Ring* ring1 = new Ring(4.47, 1.45, new Point(2.5, 0.45));
	cout << "Количество колец" << ": " << Ring::GetAllRingsCount();
	cout << endl;
	Ring* ring2 = new Ring(3.69, 0.56, new Point(7.56, 2.43));
	cout << "Количество колец" << ": " << Ring::GetAllRingsCount();
	Ring* ring3 = new Ring(7.65, 6.89, new Point(8.11, 17.71));
	cout << endl;
	cout << "Количество колец" << ": " << Ring::GetAllRingsCount();
	cout << endl;

	cout << endl;
	cout << "Area of the first ring" << " = " << ring1->GetArea() << endl;
	cout << "Area of the second ring" << " = " << ring2->GetArea() << endl;
	cout << "Area of the third ring" << " = " << ring3->GetArea() << endl;

	try
	{
		Ring* ring4 = new Ring(-1.78, -3.89, new Point(32.31, 4.79));
		delete ring4;
	}
	catch (exception exception)
	{
		cout << "Exception catched!" << endl
			<< exception.what() << endl;
	}
	try
	{
		Ring* ring5 = new Ring(2.12, 6.65, new Point(11.11, 5.66));
		delete ring5;
	}
	catch (exception exception)
	{
		cout << "Exception catched!" << endl
			<< exception.what() << endl;
	}

	cout << "Количество колец до вызова конструктора: "
		<< Ring::GetAllRingsCount() << endl;
	Ring* ring6 = new Ring(10.0, 5.0, new Point(25.0, 25.0));
	cout << "Количество колец после вызова конструктора: "
		<< Ring::GetAllRingsCount() << endl;
	delete ring6;
	cout << "Количество колец после вызова деструктора: "
		<< Ring::GetAllRingsCount() << endl;

	delete ring1;
	delete ring2;
	delete ring3;
	cout << "Количество колец после вызова деструктора: "
		<< Ring::GetAllRingsCount() << endl;
}