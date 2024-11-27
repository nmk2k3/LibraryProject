#pragma once
#include<iostream>
#include<string>
#include"Book.h"
#include<ctime>
#include<cstdlib>
using namespace std;

enum ACCESSIBLE_LEVEL
{
	GUEST, MEMBER, ADMIN
};

class User
{
private:
	string userID;
	int accessibleLevel;
	char number[10] = { '0','1','2','3','4','5','6','7','8','9' };
public:
	User();
	User(int aL);

	int getLevel();
	void setLevel(int l);

	string getID();

	virtual void read(Book* b);
};

