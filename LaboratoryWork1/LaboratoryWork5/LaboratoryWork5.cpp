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
				string name = "Ilya";
				string surname = "Ivanov";
				string patronymic = "Igorevich";
				Person* person = new Person(name, surname, patronymic);
				ShowName(person);
				delete person;
				name = "Ivan";
				surname = "Kuznetsov";
				patronymic = "Sergeevich";
				Student* student = new Student(name, surname, patronymic, 45902, 2013);
				ShowName(student);
				delete student;
				name = "Alexander";
				surname = "Popov";
				patronymic = "Dmitrievich";
				string position = "Math Teacher";
				Teacher* teacher = new Teacher(name, surname, patronymic, position);
				ShowName(teacher);
				delete teacher;
				system("pause");
				break;
			}
			case 2:
			{
				const int countUser = 4;

				string login1 = "morkovka1995";
				string login2 = "ilon_mask";
				string login3 = "megazver";
				string login4 = "yogurt";
				string password1 = "1995morkovka";
				string password2 = "X æ A-12";
				string password3 = "password";
				string password4 = "ksTPQzSu";

				User** users = new User * [countUser]
				{
					new User(100000, login1, password1),
					new User(100001, login2, password2),
					new User(100002, login3, password3),
					new User(100003, login4, password4),
				};

				login1 = "TheKnyazz";
				login2 = "system_exe";
				login3 = "RazorQ";
				login4 = "schdub";
				password1 = "JHPzPGFG";
				password2 = "UgfkDGmU";
				password3 = "TBgRnbCP";
				password4 = "CetyQVID";

				User** paidUsers = new User * [countUser]
				{
					new PaidUser(200000, login1, password1),
					new PaidUser(200001, login2, password2),
					new PaidUser(200002, login3, password3),
					new PaidUser(200003, login4, password4),
				};

				string login = "megazver";
				string password = "password";
				User* loginedUser = Login(users, 4, login, password);
				cout << "Signed in as: " << loginedUser->GetLogin() << endl;

				login = "system_exe";
				password = "UgfkDGmU";
				User* loginedPaidUser = Login(paidUsers, 4, login, password);
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

				string product1Name = "Potato";
				string product2Name = "Sprite";
				string product3Name = "Oil";
				string product4Name = "Beef";

				Product** products = new Product * [countProduct]
				{
					new Product(product1Name, Vegetables, 40000),
					new Product(product2Name, Drinks, 2000),
					new Product(product3Name, DairyProduce, 8000),
					new Product(product4Name, Meat, 11000),
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
