#pragma once
#include <iostream>
#include "ClassPoint.h"
#include "DoubleValidator.h"

using namespace std;

class Ring
{
	private:
		static int AllRingsCount;
		const double PI = 3.14159;
		double _outerRadius;
		double _innerRadius;
		Point* _center;

		double AssertOnPositiveValue(double);

	public:
		void SetRadiuses(double, double);
		void SetCenter(Point*);

		double GetOuterRadius();
		double GetInnerRadius();
		Point* GetCenter();
		double GetArea();
		static int GetAllRingsCount();

		static int GrowAllRingsCount();
		static int DecreaseAllRingsCount();

		Ring(double, double, Point*);
		~Ring();
};