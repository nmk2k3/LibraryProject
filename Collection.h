#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Book.h"
#include"User.h"
#include<ctime>
#include<cstdlib>
using namespace std;

class Collection
{
private:
	string collectionID;
	string collectionName;
	vector<Book*> bookList;
	vector<User*> userList;
	char number[10] = { '0','1','2','3','4','5','6','7','8','9' };
public:
	Collection();
	Collection(string cN);
	~Collection();

	string getCollectionID();

	string getCollectionName();
	void setCollectionName(string cN_);

	void displayCollection();
	void addUserToCollection(User* u);
	void removeUserFromCollection(User* u);
	void addBookToCollection(Book* b);
	void removeBookFromCollection(Book* b);
	Book* findBook(int index);
};

