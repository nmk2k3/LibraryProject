#include "Guest.h"
#include"Member.h"
Guest::Guest():User()
{
}

Member* Guest::signup()
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
	cout << "Enter membership start year: ";
	cin >> sY;
	cout << "Enter membership end year: ";
	cin >> eY;
	Member* m=new Member(sY,eY,u,p,f,pN);
	return m;
}
