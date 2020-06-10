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

		void SetCenter(double, double);
	public:
		Rectangle(double, double, double, double);
		void SetLength(double);
		void SetWidth(double);

		double GetLength();
		double GetWidth();
		Point* GetCenter();
		~Rectangle();
};