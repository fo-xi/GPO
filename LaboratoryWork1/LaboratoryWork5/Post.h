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
		//TODO: ����������� ������?
		void SetTitle(string&);
		void SetText(string&);
		//TODO: ����������� ������?
		string GetTitle();
		string GetText();
		//TODO: ����������� ������?
		Post(string&, string&);
};