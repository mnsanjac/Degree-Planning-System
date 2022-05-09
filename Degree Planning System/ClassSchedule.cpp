#include "ClassSchedule.h"
#include "CurrentSchedule.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <map>
using namespace std;

ClassSchedule::ClassSchedule(string courseID)
{
	ifstream inFS;
	int optionNum = 1;

	//gets input from file
	inFS.open(courseID + ".txt");
	//prints error if Course file couldn't be opened
	if (!inFS.is_open()) {
		cout << "Could not open file " << courseID << ".txt." << endl;
		return;
	}

	//makes lines of text from file into class section objects then puts them into list of all sections
	while (!inFS.eof() && inFS.good()) {
		vector<string> sectionInfo;
		string info;

		for (int i = 0; i < 9; ++i) {
			getline(inFS, info);
			sectionInfo.push_back(info);
		}

		ClassSection currentSection(sectionInfo);
		sectionList.emplace(to_string(optionNum), currentSection);
		++optionNum;
	}
	inFS.close();
}

void ClassSchedule::classScheduleMenu()
{
	string userSelect = "";

	while (userSelect != "q") {
		//Displays all sections from course
		cout << sectionList.at("1").GetCourseID() << endl;
		for (auto currentSection = sectionList.begin(); currentSection != sectionList.end(); ++currentSection) {
			cout << currentSection->first << ")" << endl;
			currentSection->second.PrintSectionInfo();
		}
		cout << "q) Go back" << endl << endl;
		cout << "Enter an option to add a class to your schedule: " << endl;

		getline(cin, userSelect);

		//options must be available option number for course or q
		if (userSelect == "q") {
			break;
		}
		else {
			if (sectionList.count(userSelect) == 1) {
				//Adds class section to current schedule
				CurrentSchedule mySchedule;
				mySchedule.addClass(sectionList.at(userSelect));
			}
			else {
				cout << "Please enter one key from the list of options." << endl << endl;
			}
		}
	}
}