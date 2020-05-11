#include "Book.h"
#include "..\Common\ReadNumber.h"
#include "ReadValuesRangeFrom0to10.h"

void DemoBook()
{
	const int count = 1;
	Book books[count];

	for (int i = 0; i < count; i++)
	{
		ReadBookFromConsole(books[i]);
		cout << endl;
	}
	for (int i = 0; i < count; i++)
	{
		WriteBookToConsole(books[i]);
		cout << endl;
	}

	cout << "Enter the author to search for the book ->\t";
	string author;
	cin >> author;
	int indexBook = FindBookByAuthor(books, count, author);
	if (indexBook == -1)
	{
		cout << "There is no book with this author" << endl;
	}

	for (int i = 0; i < count; i++)
	{
		delete[] books[i].Authors;
	}
}

void ReadBookFromConsole(Book& book)
{
	cout << "Enter the name of the book ->\t";
	cin.ignore();
	getline(cin, book.Title);

	while (true)
	{
		cout << "Enter the year of publication ->\t";
		book.YearPublishing = ReadNumber<int>();
		if ((book.YearPublishing > 0) && (book.YearPublishing < 2020))
		{
			break;
		}
		else
		{
			cout << "The year of publication must be positive,";
			cout << "but no more than the current year. Try again." << endl;
		}
	}
	while (true)
	{
		cout << "Enter the number of pages ->\t";
		book.NumberPages = ReadNumber<int>();
		if (book.NumberPages > 0)
		{
			break;
		}
		else
		{
			cout << "The number of pages must be greater than 0.";
			cout << "Try again." << endl;
		}
	}
	cout << "Enter the number of authors ->\t";
	book.NumberAuthors = ReadValuesRangeFrom0to10<int>();

	book.Authors = new string[book.NumberAuthors];
	for (int i = 0; i < book.NumberAuthors; i++)
	{
		if (i == 0)
		{
			cin.ignore();
		}
		cout << "Enter the authors ¹" << i + 1 << ": ";
		getline(cin, book.Authors[i]);
	}

}

void WriteBookToConsole(Book& book)
{
	for (int i = 0; i < book.NumberAuthors; i++)
	{
		cout << book.Authors[i] << ",";
	}
	cout << ". "
		<< book.Title
		<< ". " << book.YearPublishing
		<< ". - " << book.NumberPages
		<< "p." << endl;
}

int FindBookByAuthor(Book* books, int booksCount, string& author)
{
	for (int i = 0; i < booksCount; i++)
	{
		for (int j = 0; j < books[i].NumberAuthors; j++)
		{
			if (books[i].Authors[j] == author)
			{
				return i;
			}
		}
	}
	return -1;
}