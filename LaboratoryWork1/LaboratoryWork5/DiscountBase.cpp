#include "DiscountBase.h"

DiscountBase::DiscountBase(CategoryType category)
{
	this->SetCategory(category);
}

void DiscountBase::SetCategory(CategoryType category)
{
	this->_category = category;
}

CategoryType DiscountBase::GetCategory()
{
	return this->_category;
}