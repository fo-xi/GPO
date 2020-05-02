#pragma once
#include <iostream>
#include "ClassPoint.h"

using namespace std;

class Rectangle
{
	private:
		double _length;
		double _width;
		Point* _center;
	public:
		Rectangle* MakeRectangle(double, double, Point*);
		void SetLength(double);
		void SetWidth(double);
		void SetCenter(Point*);

		void DemoRectangleWithPoint();

		double GetLength();
		double GetWidth();
		Point* GetCenter();
};