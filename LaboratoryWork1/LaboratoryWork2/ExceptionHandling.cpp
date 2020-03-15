#include <iostream>
#include <exception>
#include "ExceptionHandling.h"

using namespace std;

void Sort(double* values, int count)
{
	if (count < 0)
	{
		throw exception("count < 0");
	}
	double swap;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (values[i] < values[j])
			{
				swap = values[i];
				values[i] = values[j];
				values[j] = swap;
			}
		}
	}
}

void DemoSort()
{
	int count = 5;
	int negativeCount = -1;
	double* values = new double[count] {100.0, 249.0, 12.0, 45.0, 23.5};

	Sort(values, count);
	Sort(values, negativeCount);
}

void DemoSort2()
{
	int count = 5;
	int negativeCount = -1;
	double* values = new double[count] {100.0, 249.0, 12.0, 45.0, 23.5};

	try
	{
		Sort(values, negativeCount);
	}
	catch (exception exception)
	{
		cout << "Exception catched!" << endl
			<< exception.what() << endl;
	}
}