#include "Book.h"

Book::Book()
{
    serialNum = "";
    for (int i = 0; i < 6; i++)
    {
        serialNum += number[rand() % 10];
    }
    title = "";
    author = "";
    pageNum = 0;
    freePageNum = 0;
    category = "";
    visibility = false;
}

Book::Book(string t_, string a_, int p_, int f_, string c_, bool v_)
{
    serialNum = "";
    for (int i = 0; i < 6; i++)
    {
        serialNum += number[rand() % 10];
    }
    title = t_;
    author = a_;
    pageNum = p_;
    freePageNum = f_;
    category = c_;
    visibility = v_;
}

string Book::getSerialNum()
{
    return serialNum;
}

void Book::setSerialNum(string s)
{
    serialNum = s;
}

string Book::getTitle()
{
    return title;
}

void Book::setTitle(string t)
{
    title = t;
}

string Book::getAuthor()
{
    return author;
}

void Book::setAuthor(string a)
{
    author = a;
}

int Book::getPageNum()
{
    return pageNum;
}

void Book::setPageNum(int p)
{
    pageNum = p;
}

int Book::getFreePageNum()
{
    return freePageNum;
}

void Book::setFreePageNum(int f)
{
    freePageNum = f;
}

string Book::getCategory()
{
    return category;
}

void Book::setCategory(string c)
{
    category = c;
}

bool Book::getVisibility()
{
    return visibility;
}

void Book::setVisibility(bool v)
{
    visibility = v;
}

void Book::displayBook()
{
    cout << "Serial number: " << serialNum << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Category: " << category << endl;
    cout << "Free pages: " << freePageNum << endl;
    cout << "Total page: " << pageNum << endl;
    if (visibility == false) cout << "Visibility: Private" << endl;
    else  cout << "Visibility: Public" << endl;
}
