#include "Library.h"

Library::Library()
{
	bookList.clear();
	collectionList.clear();
	userList.clear();
}

Library::~Library()
{
	if (bookList.size() == 0)
	{
		for (int i = 0; i < bookList.size(); i++)
		{
			if (bookList[i]) delete bookList[i];
		}
		bookList.clear();
	}

	if (collectionList.size() == 0)
	{
		for (int i = 0; i < collectionList.size(); i++)
		{
			if (collectionList[i]) delete collectionList[i];
		}
		collectionList.clear();
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

RegisteredUser* Library::login()
{
	bool check = false;
	int index=0;
	string username;
	while (check==false)
	{
		cout << "Enter username: ";
		cin >> username;
		try
		{
			if (cin.fail()) throw"Invalid input";
			for (int i = 0; i < userList.size(); i++)
			{
				if (username == userList[i]->getUsername())
				{
					index = i;
					check = true;
				}
			}
			if (check == false) throw"No username available";
		}
		catch (const char* msg)
		{
			cin.clear();
			cin.ignore();
			cout << "Error: " << msg << endl;
		}
	}
	string password;
	check = false;
	while (check==false)
	{
		cout << "Enter password: ";
		cin >> password;
		try
		{
			if (cin.fail()) throw"Invalid input";
			if (password == userList[index]->getPassword()) check = true;
			if (check == false) throw"Wrong password";
		}
		catch (const char* msg)
		{
			cin.clear();
			cin.ignore();
			cout << "Error: " << msg << endl;
		}
	}
	if (userList[index]->getLevel() == 1)	cout << "Login successfully as member" << endl;
	else if (userList[index]->getLevel() == 2) cout << "Login successfully as admin" << endl;
	return userList[index];
}

void Library::logout()
{
	exit(0);
}

void Library::addUser(RegisteredUser* r)
{
	userList.push_back(r);
}

void Library::addCollection(Collection* c)
{
	collectionList.push_back(c);
}

void Library::addBook(Book* b)
{
	bookList.push_back(b);
}

void Library::displayCollection()
{
	for (int i = 0; i < collectionList.size(); i++)
		cout << i + 1 << ". " << collectionList[i]->getCollectionName() << endl;
}

void Library::displayBookList()
{
	for (int i = 0; i < bookList.size(); i++)
		cout << i + 1 << ". " << bookList[i]->getTitle() << endl;
}

Book* Library::findBookByTitle()
{
	string t;
	cout << "Enter title of the book: ";
	cin.clear();
	cin.ignore();
	getline(cin, t);
	Book* b=nullptr;
	for (int i = 0; i < bookList.size(); i++)
	{
		if (t == bookList[i]->getTitle())  b = bookList[i];
	}
	return b;
}

Book* Library::findBookBySeri()
{
	string s;
	cout << "Enter serial number of the book: ";
	cin >> s;
	cin.clear();
	Book* b=nullptr;
	for (int i = 0; i < bookList.size(); i++)
	{
		if (s == bookList[i]->getSerialNum()) b = bookList[i];
	}
	return b;
}

Collection* Library::findCollection(int index)
{
	for (int i = 0; i < collectionList.size(); i++)
	{
		if (i == index - 1) return collectionList[index-1];
	}
}

void Library::removeBook(Book* b)
{
	int index = 0;
	for (int i = 0; i < bookList.size(); i++)
	{
		if (b == bookList[i]) index = i;
	}
	if (index != 0) bookList.erase(bookList.begin() + index);
	for (int i = 0; i < collectionList.size(); i++)
	{
		collectionList[i]->removeBookFromCollection(b);
	}
}

void Library::removeCollection(Collection* c)
{
	int index = 0;
	for (int i = 0; i < collectionList.size(); i++)
	{
		if (c == collectionList[i]) index = i;
	}
	collectionList.erase(collectionList.begin() + index);
}
