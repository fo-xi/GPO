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
		void SetLogin(const string&);
		void SetPassword(const string&);

		int GetId();
		const string& GetLogin();
		const string& GetPassword();
		User(int, const string&, const string&);
		bool IsCorrectPassword(const string&);
};