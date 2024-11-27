#include "Admin.h"

Admin::Admin():RegisteredUser(2)
{
}

Admin::Admin(string u, string p, string f, string pN):RegisteredUser(u,p,f,pN,2)
{
}

void Admin::edit(Book* b)
{
	b->displayBook();
	int nFP;
	bool nV;
	cout << "Enter new free pages: ";
	cin >> nFP;
	cout << "Enter new visibility: ";
	cin >> nV;
	b->setFreePageNum(nFP);
	b->setVisibility(nV);
	b->displayBook();
}

