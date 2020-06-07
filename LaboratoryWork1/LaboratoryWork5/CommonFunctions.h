#pragma once
#include "Person.h"
#include "User.h"
#include "DiscountBase.h"
#include "Product.h"
#include <iostream>
#include <string>

using namespace std;

void ShowName(Person*);
User* Login(User**, int, string&, string&);
void ShowCheckWithDiscount(DiscountBase*, Product**, int);