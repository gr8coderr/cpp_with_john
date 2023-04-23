#include "MenuClass.h"
#include "KeyboardInput.h"
#include <iostream>
#include <iomanip>

//Default Constructor
MenuClass::MenuClass(void)
{
	menuHeader = "";
}

//Constructor for setting menu's header
MenuClass::MenuClass(string msg)
{
	menuHeader=msg;
}

//Destructor
MenuClass::~MenuClass(void)
{
	//Since vectors dynamically allocate memory, return it to the OS
	menuItems.clear();  //Clear will delete all items from a vector
	                    //  and return its size to 0
}

//Accessors
//returns true if menu contains items, false otherwise
bool MenuClass::isEmpty(void)
{
  return menuItems.empty();  //Use vector empty to determine if size=0
}

//returns the number of menu items in the menu list
int  MenuClass::numItems(void)
{
  return menuItems.size();  //Use vector size to return the number of elements
}

//displays the menu on the console and gets the menu selection from the user
//  returns the user selection, or 0 if the menu list is empty
int  MenuClass::displayMenu(void)
{
	KeyboardInput keyboard;  //Create class to get input from the keyboard
	int entry=0;             //Holds the user entered menu selection

	cout << endl << menuHeader << endl << endl;
	if (isEmpty())
	{
		//Then user has not created a menu yet
		cout << "*** Error - Menu is Empty ***" << endl;
	}
	else
	{
		for (int index=0; index < numItems(); index++)
		{
			cout << setw(2) << index+1 << ". " << menuItems[index] << endl;
		}
		entry = keyboard.getInt("Enter Your Selection", 1, numItems());
	}
	return entry;
}

//Mutators
//deletes all items from the current menu, making it empty
void MenuClass::clearMenu(void)
{
	menuItems.clear();      //Use vector clear to remove all elements, size=0
}

//adds item to the end of the menu
void MenuClass::addMenuItem(string item)
{
	menuItems.push_back(item); //Use vector push_back to add to the end of the menu  
}