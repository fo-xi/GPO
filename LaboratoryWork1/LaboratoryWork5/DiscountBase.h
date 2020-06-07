#pragma once
#include <iostream>
#include <string>
#include "CategoryType.h"
#include "Product.h"

using namespace std;

class DiscountBase
{
	private:
		CategoryType _category;

		void SetCategory(CategoryType);
	public:
		CategoryType GetCategory();

		virtual double Calculate(Product*) = 0;
	protected:
		DiscountBase(CategoryType);
};