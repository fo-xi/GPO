#include <iostream>
#include "..\Common\ReadNumber.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "CommonFunctions.h"
#include "User.h"
#include "PaidUser.h"
#include "Product.h"
#include "PercentDiscount.h"
#include "CertificateDiscount.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	while (true)
	{
		system("cls");
		cout << endl;
		cout << "MENU" << endl;
		cout << "1. Show Name" << endl;
		cout << "2. Login" << endl;
		cout << "3. Discounts" << endl;

		switch (ReadNumber<int>())
		{
			case 1:
			{
				Person* person = new Person("Ilya", "Ivanov", "Igorevich");
				ShowName(*person);
				delete person;
				Student* student = new Student("Ivan", "Kuznetsov",
					"Kuznetsov", 45902, 2013);
				ShowName(*student);
				delete student;
				Teacher* teacher = new Teacher("Alexander", "Popov", 
					"Dmitrievich", "Math Teacher");
				ShowName(*teacher);
				delete teacher;
				system("pause");
				break;
			}
			case 2:
			{
				const int countUser = 4;
				User** users = new User * [countUser]
				{
					new User(100000, "morkovka1995", "1995morkovka"),
					new User(100001, "ilon_mask", "X æ A-12"),
					new User(100002, "megazver", "password"),
					new User(100003, "yogurt", "ksTPQzSu"),
				};
				User** paidUsers = new User * [countUser]
				{
					new PaidUser(200000, "TheKnyazz", "JHPzPGFG"),
					new PaidUser(200001, "system_exe", "UgfkDGmU"),
					new PaidUser(200002, "RazorQ", "TBgRnbCP"),
					new PaidUser(200003, "schdub", "CetyQVID"),
				};
				User* loginedUser = Login(users, 4, "megazver", "password");
				cout << "Signed in as: " << loginedUser->GetLogin() << endl;
				User* loginedPaidUser = Login(paidUsers, 4, "system_exe", "UgfkDGmU");
				cout << "Signed in as: " << loginedPaidUser->GetLogin() << endl;

				for (int i = 0; i < countUser; i++)
				{
					delete users[i];
				}
				delete[] users;

				for (int i = 0; i < countUser; i++)
				{
					delete paidUsers[i];
				}
				delete[] paidUsers;

				system("pause");
				break;
			}
			case 3:
			{
				const int countProduct = 4;
				Product** products = new Product * [countProduct]
				{
					new Product("Potato", Vegetables, 40000),
					new Product("Sprite", Drinks, 2000),
					new Product("Oil", DairyProduce, 8000),
					new Product("Beef", Meat, 11000),
				};

				PercentDiscount* percentDiscount1 = new PercentDiscount(Vegetables, 20.00);
				ShowCheckWithDiscount(percentDiscount1, products, countProduct);
				delete percentDiscount1;

				CertificateDiscount* certificateDiscount = new CertificateDiscount(Drinks, 1000.00);
				ShowCheckWithDiscount(certificateDiscount, products, countProduct);
				delete certificateDiscount;

				for (int i = 0; i < countProduct; i++)
				{
					delete products[i];
				}
				delete[] products;

				system("pause");
				break;
			}
			default:
				break;
		}
	}
	return 0;
}
