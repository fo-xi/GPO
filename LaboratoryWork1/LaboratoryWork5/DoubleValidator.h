#pragma once
#include <iostream>
#include <string>

using namespace std;

static class DoubleValidator
{
	public:
		static bool IsValuePositive(double);
		static bool IsYear(int);
		static bool IsLogin(string&);
		static bool IsCost(double);
		static bool IsPercent(double);
		static bool IsAmount(double);
		static void AssertPositiveValue(double);
		static void AssertYear(int);
		static void AssertLogin(string&);
		static void AssertCost(double);
		static void AssertAmount(double);
		static void AssertPercent(double);
};