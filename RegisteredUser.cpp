#include "RegisteredUser.h"

RegisteredUser::RegisteredUser(int aL): User(aL)
{
	username = "";
	password = "";
	fullName = "";
	phoneNumber = "";
}

RegisteredUser::RegisteredUser(string u, string p, string f, string pN,int aL): User(aL)
{
	username = u;
	password = p;
	fullName = f;
	phoneNumber = pN;
}

string RegisteredUser::getUsername()
{
	return username;
}

void RegisteredUser::setUsername(string u_)
{
	username = u_;
}

string RegisteredUser::getPassword()
{
	return password;
}

void RegisteredUser::setPassword(string p_)
{
	password = p_;
}

string RegisteredUser::getFullName()
{
	return fullName;
}

void RegisteredUser::setFullName(string f_)
{
	fullName = f_;
}

string RegisteredUser::getPhoneNumber()
{
	return phoneNumber;
}

void RegisteredUser::setPhoneNumber(string pN_)
{
	phoneNumber = pN_;
}

void RegisteredUser::displayRegistered()
{
	cout << "User ID: " << User::getID() << endl;
	cout << "Accessible level: " << User::getLevel() << endl;
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "Fullname: " << fullName << endl;
	cout << "Phone number: " << phoneNumber << endl;
}
