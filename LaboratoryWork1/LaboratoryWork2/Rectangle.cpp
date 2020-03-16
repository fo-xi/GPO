#include <iostream>
#include "Rectangle.h"
#include "..\Common\ReadNumber.h"

void WriteRectangle(Rectangle& rectangle)
{
	cout << "The rectangle measures: " << rectangle.Length << "x"
		<< rectangle.Width << endl;
	cout << endl;
}

void ReadRectangle(Rectangle& rectangle)
{
	cout << "Enter the length of the rectangle:\t";
	rectangle.Length = ReadNumber<int>();
	cout << "Enter the width of the rectangle:\t";
	rectangle.Width = ReadNumber<int>();
	cout << "Enter the color of the rectangle:\t";
	cin >> rectangle.Color;
}

void DemoRectangle()
{
	//2.2.3.1
	Rectangle rectangle1;
	rectangle1.Length = 10;
	rectangle1.Width = 3;
	rectangle1.Color = "Red";
	//2.2.3.2
	Rectangle rectangle2;
	cout << "Enter the length of the rectangle:\t";
	rectangle2.Length = ReadNumber<int>();
	cout << "Enter the width of the rectangle:\t";
	rectangle2.Width = ReadNumber<int>();
	cout << "Enter the color of the rectangle:\t";
	cin >> rectangle2.Color;

	cout << "The rectangle measures: " << rectangle2.Length << "x"
		<< rectangle2.Width << endl;
	cout << endl;
	//2.2.3.3
	const int count = 3;
	Rectangle arrayRectangle[count] = {};
	for (int i = 0; i < count; i++)
	{
		ReadRectangle(arrayRectangle[i]);
		cout << endl;
	}
	for (int i = 0; i < count; i++)
	{
		WriteRectangle(arrayRectangle[i]);
		cout << endl;
	}
	//2.2.4.1
	Rectangle* pointerRectangle1;
	pointerRectangle1 = &rectangle1;
	//2.2.4.2
	Rectangle* pointer2Rectangle1;
	pointer2Rectangle1 = &rectangle1;
	cout << "The address that is stored in the first pointer to the structure: "
		<< pointerRectangle1 << "\n"
		<< "The address that is stored in the first pointer to the structure: "
		<< pointer2Rectangle1 << endl;
	//2.2.5.4
	Rectangle rectangle3;
	rectangle3.Length = 43;
	rectangle3.Width = 12;
	rectangle3.Color = "White";
	cout << endl;
	WriteRectangle(rectangle1);
	WriteRectangle(rectangle3);
	Exchange(rectangle1, rectangle3);
	WriteRectangle(rectangle1);
	WriteRectangle(rectangle3);
	//2.2.5.5
	FindRectangle(arrayRectangle, count);
	//2.2.5.6
	FindMaxRectangle(arrayRectangle, count);
}

void DemoReadAndWriteRectangles()
{
	const int count = 5;
	Rectangle arrayRectangle[count] = {};
	for (int i = 0; i < count; i++)
	{
		ReadRectangle(arrayRectangle[i]);
		cout << endl;
	}
	for (int i = 0; i < count; i++)
	{
		WriteRectangle(arrayRectangle[i]);
		cout << endl;
	}
}

void Exchange(Rectangle& rectangle1, Rectangle& rectangle2)
{
	//TODO: RSDN
	Rectangle swap;
	swap = rectangle1;
	rectangle1 = rectangle2;
	rectangle2 = swap;
}

void FindRectangle(Rectangle* rectangles, int count)
{
	int maximumLength = rectangles[0].Length;
	for (int i = 0; i < count; ++i)
	{
		if (rectangles[i].Length > maximumLength)
		{
			maximumLength = rectangles[i].Length;
		}
	}
	cout << "The maximum length rectangle has a size:\t" << maximumLength << endl;
	cout << endl;
}

void FindMaxRectangle(Rectangle* rectangles, int count)
{
	Rectangle maximumAreaRectangle = rectangles[0];
	int maximumArea = rectangles[0].Length * rectangles[0].Width;

	for (int i = 0; i < count; ++i)
	{
		int maximumTemp = rectangles[i].Length * rectangles[i].Width;
		if (maximumArea < maximumTemp)
		{
			maximumArea = maximumTemp;
			maximumAreaRectangle = rectangles[i];
		}
	}
	cout << "The rectangle with the maximum area measures:\t" << maximumAreaRectangle.Length
		<< "x" << maximumAreaRectangle.Width << endl;
	cout << endl;
}

Rectangle* MakeRectangle(int length, int width, string color)
{
	Rectangle* rectangle = new Rectangle();
	rectangle->Length = length;
	rectangle->Width = width;
	rectangle->Color = color;
	WriteRectangle(*rectangle);
	return rectangle;
}

Rectangle* CopyRectangle(Rectangle& rectangle)
{
	Rectangle* copiedRectangle = new Rectangle();
	copiedRectangle->Length = rectangle.Length;
	copiedRectangle->Width = rectangle.Width;
	copiedRectangle->Color = rectangle.Color;
	WriteRectangle(*copiedRectangle);
	return copiedRectangle;
}