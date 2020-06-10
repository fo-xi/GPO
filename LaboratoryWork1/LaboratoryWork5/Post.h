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
		//TODO: ����������� ������? (+)
		void SetTitle(const string&);
		void SetText(const string&);
		//TODO: ����������� ������? (+)
		const string& GetTitle();
		const string& GetText();
		//TODO: ����������� ������? (+)
		Post(const string&, const string&);
};