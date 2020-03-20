#pragma once
#include <string>

using namespace std;

struct Rectangle
{
	int Length;
	int Width;
	string Color;
};

void DemoRectangle();
void WriteRectangle(Rectangle&);
void DemoReadAndWriteRectangles();
void Exchange(Rectangle&, Rectangle&);
void FindRectangle(Rectangle*, int);
void FindMaxRectangle(Rectangle*, int);
Rectangle* MakeRectangle(int, int, string&);
Rectangle* CopyRectangle(Rectangle&);