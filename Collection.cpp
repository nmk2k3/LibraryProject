#include "Collection.h"

Collection::Collection()
{
	collectionID = "";
	
	for (int i = 0; i < 4; i++)
	{
		collectionID += number[rand() % 10];
	}
	collectionName = "";
	bookList.clear();
	userList.clear();
}

Collection::Collection(string cN)
{
	collectionID = "";
	
	for (int i = 0; i < 4; i++)
	{
		collectionID += number[rand() % 10];
	}
	collectionName = cN;
	bookList.clear();
	userList.clear();
}

Collection::~Collection()
{
	if (bookList.size() == 0)
	{
		for (int i = 0; i < bookList.size(); i++)
		{
			if (bookList[i]) delete bookList[i];
		}
		bookList.clear();
	}

	if (userList.size() == 0)
	{
		for (int i = 0; i < userList.size(); i++)
		{
			if (userList[i]) delete userList[i];
		}
		userList.clear();
	}

}

string Collection::getCollectionID()
{
	return collectionID;
}


string Collection::getCollectionName()
{
	return collectionName;
}

void Collection::setCollectionName(string cN_)
{
	collectionName = cN_;
}


void Collection::displayCollection()
{
	cout << "Collection ID: " << collectionID << endl;
	cout << "Collection name: " << collectionName << endl;
	for (int i = 0; i < bookList.size(); i++)
	{
		cout << i + 1 << ". Title: " << bookList[i]->getTitle()<<"\n   Serial number: " << bookList[i]->getSerialNum() << endl;
	}
}

void Collection::addUserToCollection(User* u)
{
	userList.push_back(u);
}

void Collection::addBookToCollection(Book* b)
{
	bookList.push_back(b);
}

void Collection::removeBookFromCollection(Book* b)
{
	int index = 0;
	for (int i = 0; i < bookList.size(); i++)
	{
		if (b == bookList[i]) index = i;
	}
	bookList.erase(bookList.begin() + index);
}

Book* Collection::findBook(int index)
{
	return bookList[index - 1];
}

void Collection::removeUserFromCollection(User* u)
{
	int index=0;
	for (int i = 0; i < userList.size(); i++)
	{
		if (u == userList[i]) index=i;
	}
	userList.erase(userList.begin() + index);
}

