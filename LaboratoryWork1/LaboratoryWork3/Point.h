#pragma once
#include <iostream>

struct Point
{
	double X;
	double Y;
};

Point* MakePoint(double, double);
void SetX(Point*, double);
void SetY(Point*, double);
