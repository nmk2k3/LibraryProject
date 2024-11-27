#include "Menu.h"

Menu::Menu()
{
    name = "Default name";
    description = "Default description";
    action = -1;
    subMenu.clear();
}

Menu::Menu(string n, string d, int a)
{
    name = n;
    description = d;
    action = a;
    subMenu.clear();
}

Menu::~Menu()
{
    if (subMenu.size() > 0)
    {
        for (int i = 0; i < subMenu.size(); i++)
        {
            if (subMenu[i]) delete subMenu[i];
        }
        subMenu.clear();
    }
}

string Menu::getName()
{
    return name;
}

void Menu::setName(string n_)
{
    name = n_;
}

string Menu::getDescription()
{
    return description;
}

void Menu::setDescription(string d_)
{
    description = d_;
}

int Menu::getAction()
{
    return action;
}

void Menu::setAction(int a_)
{
    action = a_;
}

void Menu::addSubMenu(Menu* m,bool twoWay)
{
    subMenu.push_back(m);
    if(twoWay==1) m->subMenu.push_back(this);
}

Menu* Menu::getSubMenu(int index)
{
    if (index >= 0 && index < subMenu.size())  return subMenu[index];
    else return nullptr;
}

void Menu::displayMenu()
{
    cout << "======" << name << "======" << endl;
    cout << description << endl;
    for (int i = 0; i < subMenu.size(); i++)
    {
        cout << i + 1 << ". " << subMenu[i]->getName() << endl;
    }
}

int Menu::pickOption()
{
    while (true)
    {
        cout << "Pick an option: ";
        int opt;
        cin >> opt;
        try
        {
            if (cin.fail())
            {
                throw "Invalid input";
            }
            else if (opt<1 || opt>subMenu.size())
            {
                throw "Out of range";
            }
            else return opt;
        }
        catch (const char* mess)
        {
            cin.ignore();
            cin.clear();
            cout << "Error: " << mess << endl;
        }
    }
}
