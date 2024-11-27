#pragma once
#include "RegisteredUser.h"
#include"Book.h"
class Admin :  public RegisteredUser
{
public:
	Admin();
	Admin(string u,string p,string f,string pN);
	
	void edit(Book* b);
};

