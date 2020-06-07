#pragma once
#include "DiscountBase.h"

class CertificateDiscount : public DiscountBase
{
	private:
		double _amount;
	public:
		CertificateDiscount(CategoryType, double);

		void SetAmount(double);

		double GetAmount();

		double Calculate(Product*) override;
};