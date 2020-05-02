#pragma once
#include <iostream>
#include "Point.h"

using namespace std;

struct Rectangle
{
	double Length;
	double Width;
	Point* Center;
};

Rectangle* MakeRectangle(double, double, Point*);
void SetLength(Rectangle*, double);
void SetWidth(Rectangle*, double);
void SetCenter(Rectangle*, Point*);
void DemoRectangleWithPoint();