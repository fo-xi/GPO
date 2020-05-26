#pragma once
#include <iostream>

using namespace std;

static class DoubleValidator
{
	public:
		static bool IsValuePositive(double);
		static bool IsValueInRange(double, double, double);
		static void AssertPositiveValue(double);
		static void AssertValueInRange(double, double, double);
};