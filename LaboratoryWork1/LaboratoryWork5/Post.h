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
		//TODO: Константные ссылки?
		void SetTitle(string&);
		void SetText(string&);
		//TODO: Константные ссылки?
		string GetTitle();
		string GetText();
		//TODO: Константные ссылки?
		Post(string&, string&);
};