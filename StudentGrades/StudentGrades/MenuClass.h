#pragma once
#include <string>
#include <vector>
using namespace std;

class MenuClass
{
public:
	MenuClass(void);       //Default Constructor
	MenuClass(string msg); //Constructor set attribute menuHeader;

	~MenuClass(void);	   //Destructor

	//Accessors
	//returns true if menu contains items, false otherwise
	bool isEmpty(void);

	//returns the number of menu items in the menu list
	int  numItems(void);

	//displays the menu on the console and gets the menu selection from the user
	//  returns the user selection, or 0 if the menu list is empty
	int  displayMenu(void);

	//Mutators
	//deletes all items from the current menu, making it empty
	void clearMenu(void);

	//adds item to the end of the menu
	void addMenuItem(string item);

private:
	string          menuHeader;  //Holds the Header to Display for the Menu
	vector <string> menuItems;   //Holds the list of menu items
};