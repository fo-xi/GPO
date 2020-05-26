#pragma once
#include <iostream>

class Point
{
	private:
		double _x;
		double _y;
	public:
		Point(double, double);

		void SetX(double);
		void SetY(double);

		double GetX();
		double GetY();
};