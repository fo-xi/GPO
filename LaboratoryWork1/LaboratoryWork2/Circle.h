#pragma once
#include <string>

using namespace std;

struct Circle
{
	double X;
	double Y;
	double Radius;
	string Color;
};

Circle* MakeCircle(double, double, double, string&);
Circle* CopyCircle(Circle&);
void DemoCircle();