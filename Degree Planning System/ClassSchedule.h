#pragma once
#include <string>
#include <map>
#include "ClassSection.h"
using namespace std;

class ClassSchedule {
public:
	ClassSchedule(string courseID);
	void classScheduleMenu();

private:
	map<string, ClassSection> sectionList;
};