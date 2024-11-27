#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Menu
{
private:
	string name;
	string description;
	vector<Menu*> subMenu;
	int action;
public:
	Menu();
	Menu(string n, string d, int a = -1);
	~Menu();

	string getName();
	void setName(string n_);

	string getDescription();
	void setDescription(string d_);

	int getAction();
	void setAction(int a_);

	void addSubMenu(Menu* m,bool twoWay=0);
	Menu* getSubMenu(int index);

	void displayMenu();
	int pickOption();
};

