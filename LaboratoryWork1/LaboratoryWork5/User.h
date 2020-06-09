#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
	private:
		int _id;
		string _login;
		string _password;

		void SetId(int);
	public:
	//TODO: ����������� ������?
		void SetLogin(string&);
		void SetPassword(string&);

		int GetId();
	//TODO: ����������� ������?
		string GetLogin();
		string GetPassword();
		//TODO: ����������� ������?
		User(int, string&, string&);
		bool IsCorrectPassword(string&);
};