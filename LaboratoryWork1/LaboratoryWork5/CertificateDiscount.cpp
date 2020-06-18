#include "CertificateDiscount.h"
#include "DoubleValidator.h"

CertificateDiscount::CertificateDiscount(CategoryType category, double amount)
	: DiscountBase(category)
{
	this->SetAmount(amount);
}

void CertificateDiscount::SetAmount(double amount)
{
	DoubleValidator::AssertValueRange(amount, 0, 10000);
	this->_amount = amount;
}

double CertificateDiscount::GetAmount()
{
	return this->_amount;
}

double CertificateDiscount::Calculate(Product& product)
{
	if (product.GetCategory() == this->GetCategory())
	{
		if (product.GetCost() <= this->GetAmount())
		{
			this->SetAmount(this->GetAmount() - product.GetCost());
			return 0;
		}
		product.SetCost(product.GetCost() - this->GetAmount());
		this->SetAmount(0);
		return (product.GetCost());
	}
	return product.GetCost();
}