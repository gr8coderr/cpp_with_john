#pragma once
#include <string>
using namespace std;
class Student
{
public:
	//Constructor to create a Student, must provide Id
	Student(unsigned int i);
	//Constructor to create a Student with Id, First and Last Name
	Student(unsigned int i, string first, string last);

	//Accessors
	unsigned int getId() const;
	string getFullName() const;
	double getTestAverage() const; //Returns the Percentage of the Test Score/Max Score
	string getLetterGrade() const; //Returns the letter grade equivalent of the average

	//Mutators
	//Sets the Student's First Name to val
	void setFirstName(string val);
	//Sets the Student's Last Name to val
	void setLastName(string val);

	//Sets the Student's Score for the Test
	//	score is the Student's Points Earned
	//	max is the Maximum number of Points for the Test
	//Returns false if either score or max are less than zero,
	//	or if max is less than score, otherwise returns true
	bool addTestScore(int score, int max);
private:
	unsigned int id;  //Positive Integer assigned to the student
	string firstName; //Student's First Name
	string lastName;  //Student's Last Name
	int testScore;    //The Student's test Score
	int maxScore;     //The Maximum Number of Points for the Test
};

