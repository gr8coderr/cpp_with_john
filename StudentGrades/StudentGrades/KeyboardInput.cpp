#include "KeyboardInput.h"
#include <iostream>
#include <iomanip>

KeyboardInput::KeyboardInput(void)
{
}


KeyboardInput::~KeyboardInput(void)
{
}

//Accessors
//gets a valid integer with out checking for a min or max
//msg is the text displayed to the user
int KeyboardInput::getInt(string msg)
{
   int entry; //Holds the user entered value
   bool invalidEntry = true;

   //Loop until the user enters a valid number
   do
   {
      //Display the Message and Get the user entry
      cout << msg << ": ";
      cin >> entry;

      //Handle invalid input
      invalidEntry=cin.fail();
      if (invalidEntry)
      {
         cout << "Please enter an Integer." << endl;
         cin.clear(); //Clear cin's error flag in case an invalid character was entered
      }

      //clear extra characters from the input buffer
      //This is done at the end since ignore won't be executed if there is an error
      //We also want to clear out an extra characters like .5 if the user entered 1.5 
      cin.ignore (1024,'\n');

   } while (invalidEntry);
   
   return entry;
}

//gets a valid integer greater than min
//msg is the text displayed to the user
int KeyboardInput::getInt(string msg, int min)
{
	int    entry;  //Holds the user entry
	string errMsg; //Used to Hold a Built up Error Message

	//Get a valid integer from the keyboard
	entry=getInt(msg);

	//Loop until entered integer is >= to min
	while (entry < min )
	{
		//Create the error message
		errMsg  = "Please Enter an Integer >= ";
		//use C++11 to_string function to convert int to string
		errMsg += to_string(min);
		entry=getInt(errMsg);
	}
	return entry;
}

//gets a valid integer between min and max
//msg is the text displayed to the user
int KeyboardInput::getInt(string msg, int min, int max)
{
	int    entry;  //Holds the user entry
	string errMsg; //Used to Hold a Built up Error Message

	//Get a valid integer from the keyboard
	entry=getInt(msg);

	//Loop until entered integer is >= to min and <= max
	while (entry < min || entry > max )
	{
		//Create the error message
		errMsg  = "Please Enter an Integer >= ";
		//use C++11 to_string function to convert int to string
		errMsg += to_string(min) + " and <= " + to_string(max);
		entry=getInt(errMsg);
	}
	return entry;
}

//gets a valid float, with no range checking
//msg is the text displayed to the user
float KeyboardInput::getFloat(string msg)
{
   float entry; //Holds the user entered value
   bool invalidEntry = true;

   //Loop until the user enters a valid number
   do
   {
      //Display the Message and Get the user entry
      cout << msg << ": ";
      cin >> entry;

      //Handle invalid input
      invalidEntry=cin.fail();
      if (invalidEntry)
      {
         cout << "Please enter a Floating Point Number." << endl;
         cin.clear(); //Clear cin's error flag in case an invalid character was entered
      }

      //clear extra characters from the input buffer
      //This is done at the end since ignore won't be executed if there is an error
      cin.ignore (1024,'\n');

   } while (invalidEntry);
   
   return entry;
}

//gets a valid float, greater than min
//msg is the text displayed to the user
float KeyboardInput::getFloat(string msg, float min)
{
	float   entry; //Holds the user entry
	string errMsg; //Used to Hold a Built up Error Message

	//Get a valid float from the keyboard
	entry=getFloat(msg);

	//Loop until entered number is >= to min
	while (entry < min )
	{
		//Create the error message
		errMsg  = "Please Enter a Number >= ";
		//use C++11 to_string function to convert float to string
		errMsg += to_string(min);
		entry=getFloat(errMsg);
	}
	return entry;
}

//gets a valid float, between min and max
//msg is the text displayed to the user
float KeyboardInput::getFloat(string msg, float min, float max)
{
	float   entry; //Holds the user entry
	string errMsg; //Used to Hold a Built up Error Message

	//Get a valid float from the keyboard
	entry=getFloat(msg);

	//Loop until entered value is >= to min and <= max
	while (entry < min || entry > max )
	{
		//Create the error message
		errMsg  = "Please Enter a Floating Point Number >= ";
		//use C++11 to_string function to convert float to string
		errMsg += to_string(min) + " and <= " + to_string(max);
		entry=getFloat(errMsg);
	}
	return entry;
}

//gets a valid double, with no range checking
//msg is the text displayed to the user
double KeyboardInput::getDouble(string msg)
{
   double entry; //Holds the user entered value
   bool invalidEntry = true;

   //Loop until the user enters a value valid number
   do
   {
      //Display the Message and Get the user entry
      cout << msg << ": ";
      cin >> entry;

      //Handle invalid input
      invalidEntry=cin.fail();
      if (invalidEntry)
      {
         cout << "Please enter a Floating Point Number." << endl;
         cin.clear(); //Clear cin's error flag in case an invalid character was entered
      }

      //clear extra characters from the input buffer
      //This is done at the end since ignore won't be executed if there is an error
      cin.ignore (1024,'\n');

   } while (invalidEntry);
   
   return entry;
}

//gets a valid double, greater than min
//msg is the text displayed to the user
double KeyboardInput::getDouble(string msg, double min)
{
	double  entry; //Holds the user entry
	string errMsg; //Used to Hold a Built up Error Message
	
	//Get a valid double from the keyboard
	entry=getDouble(msg);

	//Loop until entered number is >= to min
	while (entry < min)
	{
		//Create the error message
		errMsg  = "Please Enter a Number >= ";
		 //use C++11 to_string function to convert double to string
		errMsg += to_string(min);
		entry=getDouble(errMsg);
	}
	return entry;
}

//gets a valid double, between min and max
//msg is the text displayed to the user
double KeyboardInput::getDouble(string msg, double min, double max)
{
	double  entry; //Holds the user entry
	string errMsg; //Used to Hold a Built up Error Message

	//Get a valid float from the keyboard
	entry=getDouble(msg);

	//Loop until entered value is >= to min and <= max
	while (entry < min || entry > max )
	{
		//Create the error message
		errMsg  = "Please Enter a Floating Point Number >= ";
		//use C++11 to_string function to convert float to string
		errMsg += to_string(min) + " and <= " + to_string(max);
		entry=getDouble(errMsg);
	}
	return entry;
}

//gets a character from the keyboard and returns true
//  if the user enters Y or y.  Can be used for Yes/No
//  prompts
bool KeyboardInput::getYesNo(string msg)
{
	//There are no errors to handle with this method.
	//  all keyboard entries are considered valid chars
	char entry;
	cout << endl << msg <<": ";
	cin >> entry; cin.ignore(1024,'\n');
	return (entry == 'Y' || entry == 'y');
}

//gets a string from the keyboard
//msg is the text displayed to the user
string KeyboardInput::getString(string msg)
{
	//There are no errors to handle with this method.
	//  all keyboard entries are considered valid strings
	string entry;
	cout << endl << msg << ": ";
	//use getline method to handle spaces and special chars
	getline(cin, entry);
	return entry;
}
