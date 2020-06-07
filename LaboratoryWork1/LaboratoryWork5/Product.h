#pragma once
#include <iostream>
#include <string>
#include "CategoryType.h"

using namespace std;

class Product
{
	private:
		string _productName;
		CategoryType _category;
		double _cost;
	public:
		Product(string&, CategoryType, double);
		void SetProductName(string&);
		void SetCategory(CategoryType);
		void SetCost(double);

		string GetProductName();
		CategoryType GetCategory();
		double GetCost();
};