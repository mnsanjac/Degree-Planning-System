#pragma once
#include "ClassSchedule.h"
#include <vector>
#include <string>
using namespace std;

class Course
{
public:
	Course(string enterCourseID, string enterName, string enterDegrees, double enterCreditHours, string enterPrerequisite, string enterDescription);
	void CourseMenu();
	string GetCourseID();
	string GetName();
	string GetDegrees();
	double GetCreditHours();
	string GetPrerequisite();
	string GetDescription();

private:
	string courseID;
	string name;
	string degrees;
	double creditHours;
	string prerequisite;
	string description;
};