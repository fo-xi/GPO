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
	//TODO: Константные ссылки?
		void SetLogin(string&);
		void SetPassword(string&);

		int GetId();
	//TODO: Константные ссылки?
		string GetLogin();
		string GetPassword();
		//TODO: Константные ссылки?
		User(int, string&, string&);
		bool IsCorrectPassword(string&);
};