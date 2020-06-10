#include "CommonFunctions.h"

void ShowName(Person& person)
{
	cout << person.GetName() << " "
		 << person.GetSurname() << " "
		 << person.GetPatronymic() << endl;
}

User* Login(User** users, int usersCount, 
	const string& enteredLogin, const string& enteredPassword)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]->GetLogin() == enteredLogin)
		{
			if (users[i]->IsCorrectPassword(enteredPassword))
			{
				return users[i];
			}
			else
			{
				throw exception("Uncorrect password");
			}
		}
	}
	return nullptr;
}

void ShowCheckWithDiscount(DiscountBase* discount, 
	Product** products, int productsCount)
{
	double fullCost = 0;
	for (int i = 0; i < productsCount; i++)
	{
		cout << products[i]->GetProductName() << "\t"
			 << "Old Cost: " << products[i]->GetCost() << "\t";
		double newCost = discount->Calculate(*products[i]);
		cout << "New Cost: " << newCost << endl;
		fullCost += newCost;
	}
	cout << "Full Cost with Discount" << "\t" << fullCost << endl;
}