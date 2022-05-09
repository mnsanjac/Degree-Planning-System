#include "Course.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

Course::Course(string enterCourseID, string enterName, string enterDegrees, double enterCreditHours, string enterPrerequisite, string enterDescription) {
	courseID = enterCourseID;
	name = enterName;
	degrees = enterDegrees;
	creditHours = enterCreditHours;
	prerequisite = enterPrerequisite;
	description = enterDescription;
}

void Course::CourseMenu()
{
	string userSelect = "";

	while (userSelect != "q") {
		//shows course info
		cout << courseID << " - " << name << endl;
		cout << "Credit Hours: " << creditHours << endl;
		cout << "Prerequisites: " << prerequisite << endl;
		cout << "Description: " << description;
		cout << endl << endl;

		cout << "1) View Class Schedules" << endl;
		cout << "q) Go back" << endl << endl;
		cout << "Enter an option: " << endl;

		getline(cin, userSelect);

		//options must be 1 or q
		if (userSelect == "q") {
			break;
		}
		else {
			if (userSelect == "1") {
				//Displays class schedule
				ClassSchedule schedule(courseID);
				schedule.classScheduleMenu();
			}
			else {
				cout << "Please enter one key from the list of options." << endl << endl;
			}
		}
	}
}

//Gets course ID
string Course::GetCourseID()
{
	return courseID;
}

//Gets course name
string Course::GetName()
{
	return name;
}

//Gets degrees course is under
string Course::GetDegrees()
{
	return degrees;
}

//Gets course credit hours
double Course::GetCreditHours()
{
	return creditHours;
}

//Gets course prerequisites
string Course::GetPrerequisite()
{
	return prerequisite;
}

//Gets Course description
string Course::GetDescription()
{
	return description;
}