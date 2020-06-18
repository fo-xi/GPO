#pragma once
#include <iostream>
#include <string>

using namespace std;

static class DoubleValidator
{
	public:
		static bool IsValuePositive(double);
		static bool IsValueRange(double, double, double);
		static bool IsLogin(const string&);
		static void AssertPositiveValue(double);
		static void AssertValueRange(double, double, double);
		static void AssertLogin(const string&);
};