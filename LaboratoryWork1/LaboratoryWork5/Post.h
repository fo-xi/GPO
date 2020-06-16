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
		void SetTitle(const string&);
		void SetText(const string&);
		const string& GetTitle();
		const string& GetText();
		Post(const string&, const string&);
};