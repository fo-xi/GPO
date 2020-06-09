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
	//TODO: ����������� ������?
		Product(string&, CategoryType, double);
	//TODO: ����������� ������?
		void SetProductName(string&);
		void SetCategory(CategoryType);
		void SetCost(double);
	//TODO: ����������� ������?
		string GetProductName();
		CategoryType GetCategory();
		double GetCost();
};