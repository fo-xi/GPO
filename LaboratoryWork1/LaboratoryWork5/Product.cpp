#include "Product.h"
#include "DoubleValidator.h"

Product::Product(string& productName, CategoryType category, double cost)
{
	this->SetProductName(productName);
	this->SetCategory(category);
	this->SetCost(cost);
}

void Product::SetProductName(string& productName)
{
	this->_productName = productName;
}

void Product::SetCategory(CategoryType category)
{
	this->_category = category;
}

void Product::SetCost(double cost)
{
	DoubleValidator::AssertCost(cost);
	this->_cost = cost;
}

string Product::GetProductName()
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