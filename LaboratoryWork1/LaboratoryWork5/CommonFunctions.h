#pragma once
#include "Person.h"
#include "User.h"
#include "DiscountBase.h"
#include "Product.h"
#include <iostream>
#include <string>

using namespace std;

//TODO: Почему указатель? (+)
void ShowName(Person&);
User* Login(User**, int, const string&, const string&);
void ShowCheckWithDiscount(DiscountBase*, Product**, int);