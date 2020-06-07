#pragma once
#include <iostream>
#include <string>

using namespace std;

class Post
{
	private:
		string _title;
		string _text;
	public:
		void SetTitle(string&);
		void SetText(string&);

		string GetTitle();
		string GetText();

		Post(string&, string&);
};