#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;


class Book
{
private:
	string serialNum;
	string title;
	string author;
	int pageNum;
	int freePageNum;
	string category;
	bool visibility;
	char number[10] = { '0','1','2','3','4','5','6','7','8','9' };
public:
	Book();
	Book(string t_, string a_, int p_, int f_, string c_, bool v_);

	string getSerialNum();
	void setSerialNum(string s);

	string getTitle();
	void setTitle(string t);

	string getAuthor();
	void setAuthor(string a);

	int getPageNum();
	void setPageNum(int p);

	int getFreePageNum();
	void setFreePageNum(int f);

	string getCategory();
	void setCategory(string c);

	bool getVisibility();
	void setVisibility(bool v);
	
	void displayBook();
};

