#pragma once
#include <iostream>
#include "ClassPoint.h"
#include "DoubleValidator.h"

using namespace std;

class Rectangle
{
	private:
		double _length;
		double _width;
		Point* _center;
	public:
		Rectangle(double, double, Point*);
		void SetLength(double);
		void SetWidth(double);
		void SetCenter(Point*);

		double GetLength();
		double GetWidth();
		Point* GetCenter();
};