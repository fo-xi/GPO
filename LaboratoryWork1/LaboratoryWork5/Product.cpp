#include "Product.h"
#include "DoubleValidator.h"

Product::Product(const string& productName, CategoryType category, double cost)
{
	this->SetProductName(productName);
	this->SetCategory(category);
	this->SetCost(cost);
}

void Product::SetProductName(const string& productName)
{
	this->_productName = productName;
}

void Product::SetCategory(CategoryType category)
{
	this->_category = category;
}

void Product::SetCost(double cost)
{
	DoubleValidator::AssertValueRange(cost, 0, 100000);
	this->_cost = cost;
}

const string& Product::GetProductName()
{
	return this->_productName;
}

CategoryType Product::GetCategory()
{
	return this->_category;
}

double Product::GetCost()
{
	return this->_cost;
}