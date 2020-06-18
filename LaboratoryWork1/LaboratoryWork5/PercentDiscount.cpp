#include "PercentDiscount.h"
#include <exception>

PercentDiscount::PercentDiscount(CategoryType category, double percent)
	: DiscountBase(category)
{
	this->SetPercent(percent);
}

void PercentDiscount::SetPercent(double percent)
{
	if ((percent < 0) || (percent > 100))
	{
		throw exception
		("The value does not fall within the range from 0 to 100");
	}
	this->_percent = percent;
}

double PercentDiscount::GetPercent()
{
	return this->_percent;
}

double PercentDiscount::Calculate(Product& product)
{
	if (product.GetCategory() == this->GetCategory())
	{
		int allPercentages = 100.00;
		return (product.GetCost() *
			((allPercentages - this->GetPercent()) / allPercentages));
	}
	return product.GetCost();
}