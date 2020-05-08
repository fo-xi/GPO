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
		//TODO:  онструктор класса не должен так называтьс€ (+)
		Rectangle(double, double, Point*);
		void SetLength(double);
		void SetWidth(double);
		void SetCenter(Point*);

		void DemoRectangleWithPoint();

		double GetLength();
		double GetWidth();
		Point* GetCenter();
};