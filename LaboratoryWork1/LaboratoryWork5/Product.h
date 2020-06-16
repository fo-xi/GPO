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
		Product(const string&, CategoryType, double);
		void SetProductName(const string&);
		void SetCategory(CategoryType);
		void SetCost(double);
		const string& GetProductName();
		CategoryType GetCategory();
		double GetCost();
};