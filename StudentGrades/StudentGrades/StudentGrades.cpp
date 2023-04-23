// StudentGrades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include "KeyboardInput.h"
#include "MenuClass.h"
#include "Student.h"
using namespace std;
//Global Object for getting Keyboard Input
KeyboardInput keyboard;

//This function will process the user's menu selection
//  Inputs:  selection is the user entered menu selection
void processMenuSelection(int selection, Student* student);

int main()
{
	int const QUIT_PROGRAM   = 3; //Outer Menu Quit Selection
	int const CHANGE_STUDENT = 5; //Inner Menu Quit Selection
	
	//Local Variables
	int selectedStudent;
	int selectedAction;

	//Create the two Student Objects
	Student student1(0);
	Student student2(1, "John", "Smith");

	//Create the Menu Objects
	MenuClass StudentSelectionMenu("Select Student to Work With");
	MenuClass StudentActionsMenu("What Would You Like to Do?");

	//Create the menus
	StudentSelectionMenu.addMenuItem("Student Id: " + to_string(student1.getId()));
	StudentSelectionMenu.addMenuItem("Student Id: " + to_string(student2.getId()));
	StudentSelectionMenu.addMenuItem("End Program");

	StudentActionsMenu.addMenuItem("Change First Name");
	StudentActionsMenu.addMenuItem("Change Last Name");
	StudentActionsMenu.addMenuItem("Add Test Information");
	StudentActionsMenu.addMenuItem("Display Student's Information");
	StudentActionsMenu.addMenuItem("Select a Different Student");

	//Set the display formats for floating point numbers
	cout << fixed << setprecision(2) << showpoint;
	//Loop until user is done making entries
	do
	{
		//Get the student to work with
		selectedStudent = StudentSelectionMenu.displayMenu();

		//Only process inner loop if user selects a student
		if (selectedStudent != QUIT_PROGRAM)
		{
			//Loop until the user wants to Change student to work with
			do
			{
				selectedAction = StudentActionsMenu.displayMenu();
				if (selectedStudent == 1)
				{
					//Process Selection for Student 1
					processMenuSelection(selectedAction, &student1);
				}
				else if (selectedStudent == 2)
				{
					//Process Selection for Student 2
					processMenuSelection(selectedAction, &student2);
				}
				//No need for else, final selection is Change Student
			} while (selectedAction != CHANGE_STUDENT);
		}
	} while (selectedStudent != QUIT_PROGRAM);
}

void processMenuSelection(int selection, Student* student)
{
	//Local Variables to Handle User Inputs
	double points, maxPoints;

	//Process the User's Menu Selection
	switch (selection)
	{
	case 1:
		//Ask user for the Student's First Name
		student->setFirstName(keyboard.getString("Enter Student's First Name: "));
		break;
	case 2:
		//Ask user for the Student's Last Name
		student->setLastName(keyboard.getString("Enter Student's Last Name: "));
		break;
	case 3:
		//Ask user for Maximum Points for the Test, must be >= 1
		maxPoints = keyboard.getInt("How many points is the test worth? ", 1);
		//Ask user for the Student's Test Score, must be >=0 and <=maxPoints
		points = keyboard.getInt("What is the student's test score? ", 0, maxPoints);
		//Update the objects information
		if (!student->addTestScore(points, maxPoints))
		{
			//Should never fail since all errors were caught with keyboard input
			//  Place holder in case future errors could occur, change to specific error
			//  in future
			cout << "Unknown error adding test, try again!" << endl;
		}
		break;
	case 4:
		//Display the Student's Id and Full Name
		cout << "Student " << setw(3) << student->getId() << ":" << student->getFullName() << endl;
		//Display the Student's Test Average
		cout << "Test Average: " << student->getTestAverage() << endl;
		//Display the Student's Letter Grade
		cout << "Letter Grade: " << student->getLetterGrade() << endl;
		break;
	//No need to test for Change Selected Student
	}
}