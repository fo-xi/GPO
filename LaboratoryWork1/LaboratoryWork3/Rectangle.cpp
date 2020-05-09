#include <exception>
#include "Rectangle.h"

Rectangle* MakeRectangle(double length, double width, Point* center)
{
	Rectangle* rectangle = new Rectangle();
	SetLength(rectangle, length);
	SetWidth(rectangle, width);
	SetCenter(rectangle, center);
	return rectangle;
}

void SetLength(Rectangle* rectangle, double length)
{
	if (length < 0)
	{
		throw exception("Length cannot be negative");
	}
	rectangle->Length = length;
}

void SetWidth(Rectangle* rectangle, double width)
{
	if (width < 0)
	{
		throw exception("Width cannot be negative");
	}
	rectangle->Width = width;
}

void SetCenter(Rectangle* rectangle, Point* center)
{
	rectangle->Center = center;
}

void DemoRectangleWithPoint()
{
	const int countCenters = 5;
	Point* centers[countCenters];
	centers[0] = MakePoint(2.5, 0.45);
	centers[1] = MakePoint(43.56, 77.43);
	centers[2] = MakePoint(11.11, 22.71);
	centers[3] = MakePoint(90.09, 47.56);
	centers[4] = MakePoint(1.98, 59.17);

	const int countRectangles = 5;
	Rectangle* rectangles[countRectangles];
	rectangles[0] = MakeRectangle(45.47, 7.45, centers[0]);
	rectangles[1] = MakeRectangle(17.69, 33.56, centers[1]);
	rectangles[2] = MakeRectangle(90.65, 21.89, centers[2]);
	rectangles[3] = MakeRectangle(27.12, 3.21, centers[3]);
	rectangles[4] = MakeRectangle(15.12, 3.76, centers[4]);

	for (int i = 0; i < countRectangles; i++)
	{
		cout << "X = " << rectangles[i]->Center->X << ";\t"
			<< "Y = " << rectangles[i]->Center->Y << ";\t"
			<< "Length = " << rectangles[i]->Length << ";\t"
			<< "Width = " << rectangles[i]->Width << ";\t" << endl;
	}

	double xCenter = 0.0;
	double yCenter = 0.0;
	for (int i = 0; i < countRectangles; i++)
	{
		xCenter += rectangles[i]->Center->X;
		yCenter += rectangles[i]->Center->Y;
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