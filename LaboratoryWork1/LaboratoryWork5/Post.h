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
		//TODO: Константные ссылки? (+)
		void SetTitle(const string&);
		void SetText(const string&);
		//TODO: Константные ссылки? (+)
		const string& GetTitle();
		const string& GetText();
		//TODO: Константные ссылки? (+)
		Post(const string&, const string&);
};