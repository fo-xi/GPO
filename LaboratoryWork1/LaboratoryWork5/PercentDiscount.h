#pragma once
#include "DiscountBase.h"

class PercentDiscount : public DiscountBase
{
	private:
		double _percent;
	public:
		PercentDiscount(CategoryType, double);

		void SetPercent(double);

		double GetPercent();

		double Calculate(Product*) override;
};
