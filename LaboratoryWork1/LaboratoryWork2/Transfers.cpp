#include <iostream>
#include "Transfers.h"
#include "..\Common\ReadNumber.h"

using namespace std;

void DemoEnums()
{
	Color color = Red;
	Color arrayColor[6]
	{ Red, Green, Blue, Orange, Purple, Green };

	DayOfTheWeek dayOfTheWeek = Wednesday;
	DayOfTheWeek arrayDayOfTheWeek[6]
	{ Wednesday, Thursday, Saturday, Monday, Friday, Sunday };

	Genre genre = Horror;
	Genre arrayGenre[6]
	{ Comedy, Drama, Thriller, Horror, Blockbuster, ActionMovie };

	StudentForm studentForm = Distance;
	StudentForm arrayStudentForm[4]
	{ FullTime, Distance, Evening, Extramural };

	SmartphoneManufacturers smartphoneManufacturers = Apple;
	SmartphoneManufacturers arraySmartphoneManufacturers[6]
	{ Apple, Samsung, Xiaomi, Sony, Huawei, Nokia };

	Season season = Spring;
	Season arraySeason[4]
	{ Autumn, Summer, Winter, Spring };
}

void WriteColor(Color color)
{
	switch (color)
	{
	case Red:
	{
		cout << "Red color" << endl;
		break;
	}
	case Orange:
	{
		cout << "Orange color" << endl;
		break;
	}
	case Yellow:
	{
		cout << "Yellow color" << endl;
		break;
	}
	case Green:
	{
		cout << "Green color" << endl;
		break;
	}
	case Blue:
	{
		cout << "Blue color" << endl;
		break;
	}
	case DarkBlue:
	{
		cout << "DarkBlue color" << endl;
		break;
	}
	case Purple:
	{
		cout << "Purple color" << endl;
		break;
	}
	}
}

Color ReadColor()
{
	Color color;
	cout << "\n0 - red\n1 - orange\n2 - yellow"
		<< "\n3 - green\n4 - blue\n5 - dark - blue\n6 - purple\n"
		<< "Enter a number from 0 to 6:\t";

	switch (ReadNumber<int>())
	{
	case 0:
	{
		color = Red;
		cout << "Red color" << endl;
		break;
	}
	case 1:
	{
		color = Orange;
		cout << "Orange color" << endl;
		break;
	}
	case 2:
	{
		color = Yellow;
		cout << "Yellow color" << endl;
		break;
	}
	case 3:
	{
		color = Green;
		cout << "Green color" << endl;
		break;
	}
	case 4:
	{
		color = Blue;
		cout << "Blue color" << endl;
		break;
	}
	case 5:
	{
		color = DarkBlue;
		cout << "Dark - blue color" << endl;
		break;
	}
	case 6:
	{
		color = Purple;
		cout << "Purple color" << endl;
		break;
	}
	}
	return color;
}

int CountRed(Color* colors, int count)
{
	int counter = 0;
	for (int i = 0; i < count; i++)
	{
		if (colors[i] == Red)
		{
			counter++;
		}
	}
	return counter;
}

int CountColor(Color* colors, int count, Color findedColor)
{
	int counter = 0;
	for (int i = 0; i < count; i++)
	{
		if (colors[i] == findedColor)
		{
			counter++;
		}
	}
	return counter;
}

void DemoCountColor()
{
	const int count = 11;
	Color arrayColor[count]
	{ Red, Purple, Green, Blue, Red, Red, Red, Orange, Purple, Green, Orange };

	cout << "Quantity:\t" << CountColor(arrayColor, count, Green) << endl;
}