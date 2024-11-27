#include "Member.h"

Member::Member():RegisteredUser()
{
	startYear = 0;
	endYear = 0;
}

Member::Member(int sY, int eY, string u, string p, string f, string pN):RegisteredUser(u,p,f,pN)
{
	startYear = sY;
	endYear = eY;
}

Member::~Member()
{
	if (collectionList.size() == 0)
	{
		for (int i = 0; i < collectionList.size(); i++)
		{
			if (collectionList[i]) delete collectionList[i];
		}
		collectionList.clear();
	}

	if (borrowedBook.size() == 0)
	{
		for (int i = 0; i < borrowedBook.size(); i++)
		{
			if (borrowedBook[i]) delete borrowedBook[i];
		}
		borrowedBook.clear();
	}
}

void Member::subcribe(Collection* c)
{
	collectionList.push_back(c);
	c->addUserToCollection(this);
}

void Member::unsubcribe(Collection* c)
{
	int index = 0;
	for (int i = 0; i < collectionList.size(); i++)
	{
		if (c == collectionList[i]) index = i;
	}
	if (index != 0)
	{
		collectionList.erase(collectionList.begin() + index);
		c->removeUserFromCollection(this);
	}
	else return;
}

void Member::borrow(Book* b)
{
	borrowedBook.push_back(b);
}

void Member::returnBook(Book* b)
{
	int index = 0;
	for (int i = 0; i < borrowedBook.size(); i++)
	{
		if (b == borrowedBook[i]) index = i;
	}
	if (index != 0) borrowedBook.erase(borrowedBook.begin() + index);
	else return;
}

void Member::read(Book* b)
{
	bool check = 0;
	for (int i = 0; i < borrowedBook.size(); i++)
	{
		if (b == borrowedBook[i]) check = true;
	}
	if (check == true) cout << "Full content " << b->getPageNum() << " pages of " << b->getTitle() << endl;
	if(check==false) cout << "Only free content: " << b->getFreePageNum() << " pages of " << b->getTitle() << endl;
}

bool Member::checkBorrow(Book* b)
{
	if (b->getVisibility() == 1) return true;
	else
	{
		bool check = 0;
		for (int i = 0; i < borrowedBook.size(); i++)
		{
			if (b == borrowedBook[i]) check = true; break;
		}
		return check;
	}
}

bool Member::checkSubcribe(Collection* c)
{
	bool check = false;
	for (int i = 0; i < collectionList.size(); i++)
	{
		if (c == collectionList[i]) check = true;
	}
	return check;
}

void Member::displayBorrowedList()
{
	for (int i = 0; i < borrowedBook.size(); i++)
	{
		cout << i + 1 << ". Title: " << borrowedBook[i]->getTitle() << "\n   Serial number: " << borrowedBook[i]->getSerialNum() << endl;
	}
}

Book* Member::findBorrow(int index)
{
	for (int i = 0; i < borrowedBook.size(); i++)
	{
		if (i == index-1) return borrowedBook[index-1];
	}
}












