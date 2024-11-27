#pragma once
#include "RegisteredUser.h"
#include"Collection.h"
#include"Book.h"
class Member : public RegisteredUser
{
private:
	vector<Collection*> collectionList;
	vector<Book*> borrowedBook;
	int startYear;
	int endYear;
public:
	Member();
	Member(int sY, int eY,string u, string p,string f,string pN);
	~Member();

	void subcribe(Collection* c);
	void unsubcribe(Collection* c);

	void borrow(Book* b);
	void returnBook(Book* b);

	void read(Book* b);
	bool checkBorrow(Book* b);

	bool checkSubcribe(Collection* c);
	void displayBorrowedList();
	Book* findBorrow(int index);

};

