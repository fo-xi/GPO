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
	this->_center = center;
}

void DemoRectangleWithPoint()
{
	const int countCenters = 5;
	Point* centers[countCenters];
	centers[0] = new Point(2.5, 0.45);
	centers[1] = new Point(43.56, 77.43);
	centers[2] = new Point(11.11, 22.71);
	centers[3] = new Point(90.09, 47.56);
	centers[4] = new Point(1.98, 59.17);

	const int countRectangles = 5;
	Rectangle* rectangles[countRectangles];
	rectangles[0] = new Rectangle(45.47, 7.45, centers[0]);
	rectangles[1] = new Rectangle(17.69, 33.56, centers[1]);
	rectangles[2] = new Rectangle(90.65, 21.89, centers[2]);
	rectangles[3] = new Rectangle(27.12, 3.21, centers[3]);
	rectangles[4] = new Rectangle(15.12, 3.76, centers[4]);

	for (int i = 0; i < countRectangles; i++)
	{
		cout << "X = " << rectangles[i]->GetCenter()->GetX() << ";\t"
			<< "Y = " << rectangles[i]->GetCenter()->GetY() << ";\t"
			<< "Length = " << rectangles[i]->GetLength() << ";\t"
			<< "Width = " << rectangles[i]->GetWidth() << ";\t" << endl;
	}

	double xCenter = 0.0;
	double yCenter = 0.0;
	for (int i = 0; i < countRectangles; i++)
	{
		xCenter += rectangles[i]->GetCenter()->GetX();
		yCenter += rectangles[i]->GetCenter()->GetY();
	}

	xCenter /= countRectangles;
	yCenter /= countRectangles;
	cout << "\nXcenter = " << xCenter
		<< ";\t" << "Ycenter = " << yCenter << "\n" << endl;
	for (int i = 0; i < countCenters; i++)
	{
		delete centers[i];
	}
	for (int i = 0; i < countRectangles; i++)
	{
		delete rectangles[i];
	}
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