#include "User.h"
#include "DoubleValidator.h"

void User::SetId(int id)
{
	_id = id;
}

void User::SetLogin(const string& login)
{
	DoubleValidator::AssertLogin(login);
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
