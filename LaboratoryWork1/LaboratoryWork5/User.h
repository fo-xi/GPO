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
		//TODO: Константные ссылки? (+)
		void SetLogin(const string&);
		void SetPassword(const string&);

		int GetId();
		//TODO: Константные ссылки? (+)
		const string& GetLogin();
		const string& GetPassword();
		//TODO: Константные ссылки? (+)
		User(int, const string&, const string&);
		bool IsCorrectPassword(const string&);
};