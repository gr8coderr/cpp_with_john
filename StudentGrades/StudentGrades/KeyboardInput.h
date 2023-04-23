#pragma once
//This class contains standard for obtaining numeric input
//  with error detection/correction from the keyboard using
//  standard C++ I/O
#include <string>
using namespace std;

class KeyboardInput
{
public:
	KeyboardInput(void);
	~KeyboardInput(void);
	
	//Mutators
	//This is a utility only class and has no attributes, 
	//  therefore there are no Mutators

	//Accessors
	//gets a valid integer with out checking for a min or max
    //msg is the text displayed to the user
    int getInt(string msg);

    //gets a valid integer greater than min
    //msg is the text displayed to the user
    int getInt(string msg, int min);

	//gets a valid integer between min and max
    //msg is the text displayed to the user
    int getInt(string msg, int min, int max);

	//gets a valid float, with no range checking
    //msg is the text displayed to the user
    float getFloat(string msg);

	//gets a valid float, greater than min
    //msg is the text displayed to the user
    float getFloat(string msg, float min);

    //gets a valid float, between min and max
    //msg is the text displayed to the user
    float getFloat(string msg, float min, float max);

	//gets a valid double, with no range checking
    //msg is the text displayed to the user
    double getDouble(string msg);

	//gets a valid double, greater than min
    //msg is the text displayed to the user
    double getDouble(string msg, double min);

    //gets a valid double, between min and max
    //msg is the text displayed to the user
    double getDouble(string msg, double min, double max);

	//gets a character from the keyboard and returns true
	//  if the user enters Y or y.  Can be used for Yes/No
	//  prompts
	bool getYesNo(string msg);

	//gets a string from the keyboard
	//msg is the text displayed to the user
	string getString(string msg);
};

