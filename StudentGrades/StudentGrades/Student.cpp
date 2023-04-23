#include "Student.h"
Student::Student(unsigned int i)
{
	//Set attribute id to i and all others to default values
	id = i;
	firstName = "";
	lastName  = "";
	testScore = 0.0;
	maxScore  = 0.0;
}
//Constructor to create a Student with Id, First and Last Name
Student::Student(unsigned int i, string first, string last) : Student(i)
{
	//Set attributes id, firstName and lastName to parameters,
	//and all others to default values
	firstName = first;
	lastName  = last;
}

//Accessors
unsigned int Student::getId() const
{
	return id;
}
string Student::getFullName() const
{
	return firstName+" "+lastName;
}

//Returns the Percentage of the Test Score/Max Score
double Student::getTestAverage() const
{
	double retVal = 0.0;
	//Test for Divide by Zero
	if (maxScore > 0)
	{
		//Be sure to perform floating point division so no truncation of decimals
		retVal = 100.0 * (static_cast<double>(testScore)) / (static_cast<double>(maxScore));
	}
	return retVal;
}

//Returns the letter grade equivalent of the average
string Student::getLetterGrade() const
{
	double avg = getTestAverage();
	//By using else if, only need to test low range
	//	for each letter value.
	if      (avg >= 94.0) return "A";
	else if (avg >= 90.0) return "A-";
	else if (avg >= 87.0) return "B+";
	else if (avg >= 84.0) return "B";
	else if (avg >= 80.0) return "B-";
	else if (avg >= 77.0) return "C+";
	else if (avg >= 74.0) return "C";
	else if (avg >= 70.0) return "C-";
	else if (avg >= 67.0) return "D+";
	else if (avg >= 64.0) return "D";
	else if (avg >= 60.0) return "D-";
	else                  return "F";
}

//Mutators
//Sets the Student's First Name to val
void Student::setFirstName(string val)
{
	firstName = val;
}
//Sets the Student's Last Name to val
void Student::setLastName(string val)
{
	lastName = val;
}

//Sets the Student's Score for the Test
//	score is the Student's Points Earned
//	max is the Maximum number of Points for the Test
//Returns false if either score or max are less than zero,
//	or if max is less than score, otherwise returns true
bool Student::addTestScore(int score, int max)
{
	//No need to test for max > 0.  
	//If score > 0 and max >= score then max > 0 must be true
	if (score > 0 && max >= score)
	{
		testScore = score;
		maxScore  = max;
		return true;
	}
	else
	{
		return false;
	}
}
