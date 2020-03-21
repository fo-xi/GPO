#include "Circle.h"

Circle* MakeCircle(double x, double y, double radius, string& color)
{
	Circle* circle = new Circle();
	circle->X = x;
	circle->Y = y;
	circle->Radius = radius;
	circle->Color = color;
	return circle;
}

Circle* CopyCircle(Circle& circle)
{
	Circle* copiedCircle = new Circle();
	copiedCircle->X = circle.X;
	copiedCircle->Y = circle.Y;
	copiedCircle->Radius = circle.Radius;
	copiedCircle->Color = circle.Color;
	return copiedCircle;
}

void DemoCircle()
{
	string color = "Red";
	Circle* circle1 = MakeCircle(5.0, 7.0, 7.5, color);
	color = "Green";
	Circle* circle2 = MakeCircle(2.0, -12.0, 12.75, color);
	color = "Blue";
	Circle* circle3 = MakeCircle(10.0, 10.0, 1.45, color);

	Circle* copiedCircle1 = CopyCircle(*circle1);
	Circle* copiedCircle2 = CopyCircle(*circle2);
	Circle* copiedCircle3 = CopyCircle(*circle3);
}