#pragma once
#include <string>
#include <map>
#include "ClassSection.h"
using namespace std;

class CurrentSchedule
{
public:
	CurrentSchedule();
	void currentScheduleMenu();
	void addClass(ClassSection section);
	void removeClass(string sectionOptionNum);

private:
	map<string, ClassSection> mySectionList;
};