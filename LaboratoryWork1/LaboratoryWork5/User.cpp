#include "User.h"
#include <exception> 


void User::SetId(int id)
{
	_id = id;
}

void User::SetLogin(const string& login)
{
	for (int i = 0; i < login.length(); i++)
	{
		if (login[i] == '{' || login[i] == '}' || login[i] == '<' || login[i] == '>' ||
			login[i] == '>' || login[i] == '@' || login[i] == '#' || login[i] == '$' ||
			login[i] == '%' || login[i] == '^' || login[i] == ':' || login[i] == '*')
		{
			throw exception("The login contains undesirable characters");
		}
	}
	_login = login;
}

void User::SetPassword(const string& password)
{
	_password = password;
}

int User::GetId()
{
	return _id;
}

const string& User::GetLogin()
{
	return _login;
}

const string& User::GetPassword()
{
	return _password;
}

User::User(int id, const string& login, const string& password)
{
	SetId(id);
	SetLogin(login);
	SetPassword(password);
}

bool User::IsCorrectPassword(const string& password)
{
	return (password == _password);
}
