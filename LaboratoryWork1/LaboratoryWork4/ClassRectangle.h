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
	//TODO: ѕочему передавать не Point, а координаты, а Point уже создавать внутри? ≈сли так не сделать, то необоходим внешний контроль за пам€тью точки. (+)
	//TODO: ј если создать точку внутри, тогда мы еЄ инкапсулировали и можем не переживать об утечке, если возвращаем пам€ть в деструкторе (+)
		Rectangle(double, double, double, double);
		void SetLength(double);
		void SetWidth(double);
		void SetCenter(double, double);

		double GetLength();
		double GetWidth();
		Point* GetCenter();
		~Rectangle();

};