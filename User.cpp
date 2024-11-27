#include "User.h"
#include<ctime>
#include<cstdlib>

User::User()
{
	userID = "";
	for(int i=0;i<10;i++) userID += number[rand() % 10];
	
	accessibleLevel = 0;
}

User::User(int aL)
{
	userID = "";
	for (int i = 0; i < 10; i++) userID += number[rand() % 10];
	accessibleLevel = aL;
}

int User::getLevel()
{
	return accessibleLevel;
}

void User::setLevel(int l)
{
	accessibleLevel = l;
}

string User::getID()
{
	return userID;
}


void User::read(Book* b)
{
	if (accessibleLevel == GUEST)
	{
		if (b->getVisibility() == 0)		cout << "Only free content: " << b->getFreePageNum() << " pages of "<<b->getTitle() << endl;
		else cout << "Full content of "<<b->getPageNum()<<" pages of"<< b->getTitle() << endl;
	}
	else if(accessibleLevel==ADMIN) cout << "Full content" << b->getPageNum() << " pages of" << b->getTitle() << endl;
}
