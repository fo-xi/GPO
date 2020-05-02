#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Book
{
	string Title;
	int YearPublishing;
	int NumberPages;
	int NumberAuthors;
	string* Authors;
};

void ReadBookFromConsole(Book&);
void WriteBookToConsole(Book&);
int FindBookByAuthor(Book*, int, string);
void DemoBook();