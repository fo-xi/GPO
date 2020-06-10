#include "PercentDiscount.h"
#include "DoubleValidator.h"

PercentDiscount::PercentDiscount(CategoryType category, double percent)
	: DiscountBase(category)
{
	this->SetPercent(percent);
}

void PercentDiscount::SetPercent(double percent)
{
	DoubleValidator::AssertValueRange(percent, 0, 100);
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