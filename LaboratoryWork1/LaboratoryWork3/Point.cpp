#include "Point.h"

Point* MakePoint(double x, double y)
{
	Point* point = new Point();
	SetX(point, x);
	SetY(point, y);
	return point;
}

void SetX(Point* point, double x)
{
	point->X = x;
}

void SetY(Point* point, double y)
{
	point->Y = y;
}