#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include"Menu.h"
#include"Admin.h"
#include"Book.h"
#include"Collection.h"
#include"Guest.h"
#include"Member.h"
#include"RegisteredUser.h"
#include"User.h"
#include"Library.h"
using namespace std;

enum ACTIONTYPE
{
	LOGIN_AS_MEMBER, EXIT_MENU, GUEST_SEARCH_TITLE, GUEST_SEARCH_SERIAL, GUEST_READ_BOOK, GUEST_COLLECTION_MENU, REGISTER,
	LOGIN_AS_ADMIN, MEMBER_SEARCH_TITLE, MEMBER_SEARCH_SERIAL,MEMBER_COLLECTION_MENU,MEMBER_READ_BOOK,MEMBER_BORROW_BOOK,
	MEMBER_BORROW_LIST, MEMBER_VIEW_COLLECTION, ADMIN_MANAGE_COLLECTION, ADMIN_ADD_BOOK, ADMIN_SEARCH_TITLE, ADMIN_SEARCH_SERIAL,
	ADMIN_ADD_COLLECTION, ADMIN_EDIT_COLLECTION, CREATE_ADMIN

};
int main()
{
	srand(time(0));

	//library predefine

	Book* b1 = new Book("Book #1", "Author #1", 10, 5, "Category #1", true);
	Book* b2 = new Book("Book #2", "Author #2", 15, 10, "Category #2", false);
	Book* b3 = new Book("Book #3", "Author #3", 23, 15, "Category #3", true);
	Book* b4 = new Book("Book #4", "Author #4", 67, 3, "Category #4", true);
	Book* b5 = new Book("Book #5", "Author #5", 84, 9, "Category #5", false);
	Book* b6 = new Book("Book #6", "Author #6", 78, 8, "Category #6", true);
	Book* b7 = new Book("Book #7", "Author #7", 10, 2, "Category #7", false);
	Book* b8 = new Book("Book #8", "Author #8", 91, 30, "Category #8", true);
	Book* b9 = new Book("Book #9", "Author #9", 75, 15, "Category #9", true);
	Book* b10 = new Book("Book #10", "Author #10", 57, 45, "Category #10", false);

	Collection* c0 = new Collection("Sample collection");
	Collection* c1 = new Collection("Collection #1");
	Collection* c2 = new Collection("Collection #2");

	c0->addBookToCollection(b1);
	c0->addBookToCollection(b3);
	c0->addBookToCollection(b4);
	c1->addBookToCollection(b2);
	c1->addBookToCollection(b7);
	c1->addBookToCollection(b10);
	c2->addBookToCollection(b5);
	c2->addBookToCollection(b6);
	c2->addBookToCollection(b8);

	Member* m1 = new Member(2001, 2003, "member1", "pass", "Full name #1", "Phone number #1");
	m1->borrow(b1);
	m1->borrow(b3);
	m1->borrow(b10);

	Member* m2 = new Member(2011, 2023, "member2", "pass", "Full name #2", "Phone number #2");
	m2->borrow(b2);
	m2->borrow(b5);

	Admin* a = new Admin("admin", "pass", "Admin full name", "Admin phone number");

	Library l;
	l.addBook(b1);
	l.addBook(b2);
	l.addBook(b3);
	l.addBook(b4);
	l.addBook(b5);
	l.addBook(b6);
	l.addBook(b7);
	l.addBook(b8);
	l.addBook(b9);
	l.addBook(b10);

	l.addCollection(c0);
	l.addCollection(c1);
	l.addCollection(c2);

	l.addUser(m1);
	l.addUser(m2);
	l.addUser(a);

	//declare menu
	Menu* mainMenu = new Menu("Main menu", "Library main menu");
	Menu* memberLoginMenu = new Menu("Login as member", "Choose your option", LOGIN_AS_MEMBER);
	Menu* adminLoginMenu = new Menu("Login as admin", "Choose your option", LOGIN_AS_ADMIN);
	Menu* guestMenu = new Menu("Guest menu", "Using as guest");
	Menu* exitMenu = new Menu("Exit", "Exit the library", EXIT_MENU);

	mainMenu->addSubMenu(memberLoginMenu,1);
	mainMenu->addSubMenu(adminLoginMenu,1);
	mainMenu->addSubMenu(guestMenu,1);
	mainMenu->addSubMenu(exitMenu,1);
	
	Menu* guestSearchTitle = new Menu("Search book by title", "Choose your option", GUEST_SEARCH_TITLE);
	Menu* guestSearchSerial = new Menu("Search book by serial number", "Choose your option", GUEST_SEARCH_SERIAL);
	Menu* guestReadBook = new Menu("Read", "Choose your option", GUEST_READ_BOOK);
	Menu* guestCollectionMenu = new Menu("Sample collection", "", GUEST_COLLECTION_MENU);
	Menu* registerMenu = new Menu("Register", "Choose your option", REGISTER);

	guestMenu->addSubMenu(guestSearchTitle, 1);
	guestMenu->addSubMenu(guestSearchSerial, 1);
	guestMenu->addSubMenu(guestCollectionMenu, 1);
	guestMenu->addSubMenu(registerMenu);

	guestSearchTitle->addSubMenu(guestReadBook);
	guestSearchSerial->addSubMenu(guestReadBook);

	guestReadBook->addSubMenu(guestMenu);
	guestReadBook->addSubMenu(exitMenu);
	guestReadBook->addSubMenu(mainMenu);

	registerMenu->addSubMenu(mainMenu);

	Menu* memberMenu = new Menu("Member menu", "Using as member");

	Menu* memberSearchTitle = new Menu("Search book by title", "Choose your option", MEMBER_SEARCH_TITLE);
	Menu* memberSearchSerial = new Menu("Search book by serial", "Choose your option", MEMBER_SEARCH_SERIAL);
	Menu* memberCollectionMenu = new Menu("Collection", "Choose your option", MEMBER_COLLECTION_MENU);
	Menu* memberViewCollection = new Menu("View collection", "Choose your option", MEMBER_VIEW_COLLECTION);

	Menu* memberReadBook = new Menu("Read", "Choose your option", MEMBER_READ_BOOK);
	Menu* memberBorrowBook = new Menu("Borrow", "Choose your option", MEMBER_BORROW_BOOK);
	Menu* memberBorrowList = new Menu("Borrowed list", "Choose your option", MEMBER_BORROW_LIST);

	memberLoginMenu->addSubMenu(memberMenu);
	memberMenu->addSubMenu(mainMenu);
	registerMenu->addSubMenu(memberMenu);

	memberMenu->addSubMenu(memberSearchTitle,1);
	memberMenu->addSubMenu(memberSearchSerial,1);
	memberMenu->addSubMenu(memberCollectionMenu,1);
	
	memberCollectionMenu->addSubMenu(memberViewCollection,1);
	memberViewCollection->addSubMenu(memberMenu);

	memberMenu->addSubMenu(memberBorrowList, 1);

	memberSearchTitle->addSubMenu(memberReadBook);
	memberSearchSerial->addSubMenu(memberReadBook);

	memberBorrowBook->addSubMenu(memberReadBook,1);
	memberBorrowBook->addSubMenu(memberMenu);
	memberReadBook->addSubMenu(memberMenu);

	Menu* adminMenu = new Menu("Admin menu", "Using as admin");

	Menu* adminManageBook = new Menu("Manage book", "Choose your option");
	Menu* adminManageCollection = new Menu("Manage collection", "Choose your option", ADMIN_MANAGE_COLLECTION);
	Menu* adminAddBook = new Menu("Add book to library", "Choose your option", ADMIN_ADD_BOOK);
	Menu* adminSearchTitle = new Menu("Search by title", "Choose your option", ADMIN_SEARCH_TITLE);
	Menu* adminSearchSerial = new Menu("Search by serial", "Choose your option", ADMIN_SEARCH_SERIAL);

	Menu* adminAddCollection = new Menu("Create collection", "Choose your option", ADMIN_ADD_COLLECTION);
	Menu* adminEditCollection = new Menu("Edit collection", "Choose your option", ADMIN_EDIT_COLLECTION);

	Menu* adminCreate = new Menu("Create new admin account", "", CREATE_ADMIN);

	adminLoginMenu->addSubMenu(adminMenu);
	adminMenu->addSubMenu(mainMenu);
	adminMenu->addSubMenu(adminManageBook,1);
	adminMenu->addSubMenu(adminManageCollection,1);

	adminManageBook->addSubMenu(adminAddBook, 1);
	adminManageBook->addSubMenu(adminSearchTitle, 1);
	adminManageBook->addSubMenu(adminSearchSerial, 1);

	adminManageCollection->addSubMenu(adminAddCollection, 1);
	adminManageCollection->addSubMenu(adminEditCollection, 1);

	adminMenu->addSubMenu(adminCreate, 1);

//menu switch

	Menu* currMenu = mainMenu;
	Book* currBook = nullptr;
	Member* currMem = nullptr;
	Admin* currAd = nullptr;

	while (true)
	{
		currMenu->displayMenu();
		int opt = currMenu->pickOption();
		currMenu = currMenu->getSubMenu(opt - 1);
		system("cls");
		switch (currMenu->getAction())
		{
		case -1: break;
		case LOGIN_AS_MEMBER: 
		{
			currMem=(Member*)l.login();
			break;
		}
		case LOGIN_AS_ADMIN:
		{
			currAd =(Admin*) l.login();
			break;
		}
		case EXIT_MENU:
		{
			l.logout();
			break;
		}
		case GUEST_SEARCH_TITLE:
		{
			currBook = l.findBookByTitle();
			cout << "Book found. This is the information of the book" << endl;
			currBook->displayBook();
			break;
		}
		case GUEST_READ_BOOK:
		{
			Guest g;
			g.read(currBook);
			break;
		}
		case GUEST_SEARCH_SERIAL:
		{
			currBook = l.findBookBySeri();
			cout << "Book found. This is the information of the book" << endl;
			currBook->displayBook();
			break;
		}
		case GUEST_COLLECTION_MENU:
		{
			l.findCollection(1)->displayCollection();
			break;
		}
		case REGISTER:
		{
			Guest g;
			Member* m=g.signup();
			currMem = m;
			l.addUser(m);
			cout << "Sign up successfully" << endl;
			break;
		}
		case MEMBER_SEARCH_SERIAL:
		{
			currBook = l.findBookBySeri();
			cout << "Book found. This is the information of the book" << endl;
			currBook->displayBook();
			break;
		}
		case MEMBER_SEARCH_TITLE:
		{
			currBook = l.findBookByTitle();
			cout << "Book found. This is the information of the book" << endl;
			currBook->displayBook();
			break;
		}
		case MEMBER_READ_BOOK:
		{
			currMem->read(currBook);
			break;
		}
		case MEMBER_BORROW_BOOK:
		{
			if (currMem->checkBorrow(currBook) == true) cout << "Already borrowed" << endl;
			else
			{
				currMem->borrow(currBook);
				cout << "Borrow successfully" << endl;
			}
			break;
		}
		case MEMBER_COLLECTION_MENU:
		{
			l.displayCollection();
			break;
		}
		case MEMBER_VIEW_COLLECTION:
		{
			cout << "Choose a collection u want to view: ";
			int index;
			cin >> index;
			if(index==1) l.findCollection(1)->displayCollection();
			else
			{
				Collection* tempC = l.findCollection(index);
				if (currMem->checkSubcribe(tempC))
				{
					tempC->displayCollection();
					cout << "Do you want to unsubcribe? 1 for yes 2 for no ";
					int opt;
					cin >> opt;
					if (opt == 1)
					{
						currMem->unsubcribe(tempC);
						cout << "Unsubcribed successfully" << endl;
					}
				}
				else
				{
					cout << "You havent subcribed this collection yet. Do you want to subcribe it? 1 for yes 2 for no ";
					int opt;
					cin >> opt;
					if (opt == 1)
					{
						currMem->subcribe(tempC);
						cout << "Subcribed successfully" << endl;
						tempC->displayCollection();
					}
				}
			}
			break;
		}
		case MEMBER_BORROW_LIST:
		{
			currMem->displayBorrowedList();
			cout << "Choose ur book to read: ";
			int index;
			cin >> index;
			currBook = currMem->findBorrow(index);
			currMem->read(currBook);
			cout << "Do you want to return this book? 1 for yes 2 for no ";
			int opt;
			cin >> opt;
			if (opt == 1)
			{
				currMem->returnBook(currBook);
				cout << "Return successfully" << endl;
			}
			break;
		}
		case ADMIN_ADD_BOOK:
		{
			string title, author,category;
			int pageCnt, freePage;
			bool visibility;
			cout << "Title: ";
			cin.clear();
			cin.ignore();
			getline(cin, title);
			cout << "Author: ";
			cin.clear();
			cin.ignore();
			getline(cin, author);
			cout << "Page count: ";
			cin >> pageCnt;
			cout << "Free pages: ";
			cin >> freePage;
			cout << "Category: ";
			cin.clear();
			cin.ignore();
			getline(cin, category);
			cout << "Visibility: ";
			cin >> visibility;
			Book* b = new Book(title, author, pageCnt, freePage, category, visibility);
			l.addBook(b);
			cout << "Added successfully" << endl;
			break;
		}
		case ADMIN_SEARCH_TITLE:
		{
			currBook = l.findBookByTitle();
			cout << "Book found. This is the information of the book" << endl;
			currBook->displayBook();
			cout << "1. Read" << endl;
			cout << "2. Remove" << endl;
			cout << "3. Edit" << endl;
			cout << "4. Return to previous menu" << endl;
			int opt;
			do
			{
				cout << "Choose ur option: ";
				cin >> opt;
				if (opt == 1) currAd->read(currBook);
				else if (opt == 2)
				{
					l.removeBook(currBook);
					currBook = nullptr;
					cout << "Remove successfully"<<endl;
					break;
				}
				else if (opt == 3) currAd->edit(currBook);
			} while (opt != 4);
			break;
		}
		case ADMIN_SEARCH_SERIAL:
		{
			currBook = l.findBookBySeri();
			cout << "Book found. This is the information of the book" << endl;
			currBook->displayBook();
			cout << "1. Read" << endl;
			cout << "2. Remove" << endl;
			cout << "3. Edit" << endl;
			cout << "4. Return to previous menu" << endl;
			int opt;
			do
			{
				cout << "Choose ur option: ";
				cin >> opt;
				if (opt == 1) currAd->read(currBook);
				else if (opt == 2)
				{
					l.removeBook(currBook);
					currBook = nullptr;
					cout << "Remove successfully" << endl;
					break;
				}
				else if (opt == 3) currAd->edit(currBook);
			} while (opt != 4);
			break;
		}
		case ADMIN_ADD_COLLECTION:
		{
			string name;
			cout << "Collection name: ";
			cin.clear();
			cin.ignore();
			getline(cin, name);
			Collection* tempC = new Collection(name);
			l.addCollection(tempC);
			cout << "Created successfully" << endl;
			int opt;
			do
			{
				cout << "Search for book to add to collection. 1 for title, 2 for serial ";
				cin >> opt;
				if (opt == 1)
				{
					currBook = l.findBookByTitle();
					tempC->addBookToCollection(currBook);
					cout << "Added successfully" << endl;
				}
				else if (opt == 2)
				{
					currBook = l.findBookBySeri();
					tempC->addBookToCollection(currBook);
					cout << "Added successfully" << endl;
				}
			} while (opt == 1 || opt == 2);
			break;
		}
		case ADMIN_EDIT_COLLECTION:
		{
			l.displayCollection();
			cout << "Choose a collection: ";
			int index;
			cin >> index;
			Collection* tempC = l.findCollection(index);
			cout << "1. Add book to collection" << endl;
			cout << "2. Remove book from collection" << endl;
			cout << "3. Remove collection" << endl;
			cout << "4. View collection" << endl;
			cout << "5. Return to previous menu" << endl;
			int opt;
			do
			{
				cout << "Choose ur option: ";
				cin >> opt;
				if (opt == 1)
				{
					int option;
					do
					{
						cout << "Search for book to add to collection. 1 for title, 2 for serial, 3 for return ";
						cin >> option;
						if (option == 1)
						{
							currBook = l.findBookByTitle();
							tempC->addBookToCollection(currBook);
							cout << "Added successfully" << endl;
						}
						else if (option == 2)
						{
							currBook = l.findBookBySeri();
							tempC->addBookToCollection(currBook);
							cout << "Added successfully" << endl;
						}
					} while (option == 1 || option == 2);
				}
				else if (opt == 2)
				{
					tempC->displayCollection();
					int i;
					cout << "Choose book u want to remove: ";
					cin >> i;
					currBook = tempC->findBook(i);
					tempC->removeBookFromCollection(currBook);
					cout << "Removed successfully" << endl;
				}
				else if (opt == 3)
				{
					l.removeCollection(tempC);
					tempC = nullptr;
					cout << "Collection removed successfully" << endl;
					break;
				}
				else if (opt == 4) tempC->displayCollection();
			} while (opt != 5);
			break;
		}
		case CREATE_ADMIN:
		{
			string u, f, p, pN;
			int sY, eY;
			cout << "Enter username: ";
			cin >> u;
			cout << "Enter fullname: ";
			cin >> f;
			cout << "Enter phone number: ";
			cin >> pN;
			cout << "Enter password: ";
			cin >> p;
			Admin* newAd = new Admin(u, p, f, pN);
			l.addUser(newAd);
			cout << "Created successfully" << endl;
			break;
		}
		}
	}
	return 0;
}