#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include"Admin.h"
#include"Book.h"
#include"Collection.h"
#include"Guest.h"
#include"Member.h"
#include"RegisteredUser.h"
#include"User.h"
using namespace std;

class Library
{
private:
	vector<Book*>bookList;
	vector<Collection*>collectionList;
	vector<RegisteredUser*>userList;
public:
	Library();
	~Library();
	RegisteredUser* login();
	void logout();
	void addUser(RegisteredUser* r);
	void addCollection(Collection* c);
	void addBook(Book* b);
	void displayCollection();
	void displayBookList();
	Book* findBookByTitle();
	Book* findBookBySeri();
	Collection* findCollection(int index);
	void removeBook(Book* b);
	void removeCollection(Collection* c);
};

