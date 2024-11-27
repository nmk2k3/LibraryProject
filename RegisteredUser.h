#pragma once
#include "User.h"
class RegisteredUser : public User
{
private:
	string username;
	string password;
	string fullName;
	string phoneNumber;
public:
	RegisteredUser(int aL=1);
	RegisteredUser(string u, string p, string f, string pN,int aL=1);
	
	string getUsername();
	void setUsername(string u_);

	string getPassword();
	void setPassword(string p_);

	string getFullName();
	void setFullName(string f_);

	string getPhoneNumber();
	void setPhoneNumber(string pN_);

	void displayRegistered();
};

