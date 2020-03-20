#include <iostream>
#include <exception>
#include "ExceptionHandling.h"

using namespace std;
//TODO: Почему две константы оформлены в различном стиле? (+)
const int COUNT = 5;
const int NEGATIVECOUNT = -1;

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

double* СreatArray()
{
	double* values = new double[COUNT] {100.0, 249.0, 12.0, 45.0, 23.5};
	return values;
}

void DemoSort()
{
	double* values = СreatArray();
	Sort(values, COUNT);
	Sort(values, NEGATIVECOUNT);
	delete[] values;
}

void DemoSort2()
{
	double* values = СreatArray();
	try
	{
		Sort(values, NEGATIVECOUNT);
	}
	catch (exception exception)
	{
		cout << "Exception catched!" << endl
			<< exception.what() << endl;
	}
	delete[] values;
}