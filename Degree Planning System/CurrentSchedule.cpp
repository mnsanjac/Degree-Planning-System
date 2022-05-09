#include "CurrentSchedule.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <map>
#include <vector>

CurrentSchedule::CurrentSchedule()
{
	ifstream inFS;

	//gets input from file
	inFS.open("CurrentSchedule.txt");
	//prints error if Courses Schedule file couldn't be opened
	if (!inFS.is_open()) {
		cout << "Could not open file CurrentSchedule.txt." << endl;
		return;
	}

		//makes lines of text from file into class section objects then puts them into list of all your sections
		while (!inFS.eof() && inFS.good()) {
			bool emptyLine = false;
			vector<string> sectionInfo;
			string info;

			for (int i = 0; i < 9; ++i) {
				getline(inFS, info);
				if (info.empty()) {
					emptyLine = true;
					break;
				}
				sectionInfo.push_back(info);
			}
			if (emptyLine == true) {
				break;
			}
			ClassSection currentSection(sectionInfo);
			mySectionList.emplace(currentSection.GetClassID(), currentSection);
		}

	inFS.close();
}

void CurrentSchedule::currentScheduleMenu()
{
	string userSelect = "";

	while (userSelect != "q") {
		//Displays all of your current schedules section information
		if (!mySectionList.empty()) {
			for (auto currentSection = mySectionList.begin(); currentSection != mySectionList.end(); ++currentSection) {
				cout << currentSection->second.GetCourseID() << endl;
				currentSection->second.PrintSectionInfo();
			}
		}
		else {
			cout << "Your schedule is currently empty." << endl;
		}
		cout << "q) Go back" << endl << endl;
		cout << "Enter a class ID to remove the class from your schedule:" << endl;

		getline(cin, userSelect);

		//options must be available course ID or q
		if (userSelect == "q") {
			break;
		}
		else {
			if (mySectionList.count(userSelect) == 1) {
				//Removes selected course from your schedule
				removeClass(userSelect);
			}
			else {
				cout << "Please enter an existing class ID or q to go back" << endl << endl;
			}
		}
	}
}

void CurrentSchedule::addClass(ClassSection section)
{
	bool classExists = false;
	//Checks if selected class already exists in current schedule
	if (!mySectionList.empty()) {
		for (auto currentSection = mySectionList.begin(); currentSection != mySectionList.end(); ++currentSection) {
			if (currentSection->second.GetClassID() == section.GetClassID()) {
				classExists = true;
				break;
			}
		}
	}

	//Does not add class if already in current schedule
	if (classExists == false) {
		ofstream outFS;

		//Writes to CurrentSchedule.txt file
		outFS.open("CurrentSchedule.txt");
		//Error if failed to open file
		if (!outFS.is_open()) {
			cout << "Failed to open CurrentSchedule.txt." << endl;
			return;
		}
		else {
			//Adds class section to current schedule file
			mySectionList.emplace(section.GetClassID(), section);
			for (auto currentSection = mySectionList.begin(); currentSection != mySectionList.end(); ++currentSection) {
				for (unsigned int i = 0; i < currentSection->second.SectionInfo().size(); ++i) {
					outFS << currentSection->second.SectionInfo().at(i) << "\n";
				}
			}			
		}
		outFS.close();
		cout << "Added class to your schedule successfully." << endl << endl;
	}
	else {
		cout << "You have already added that class to your schedule." << endl;
	}
}

//Removes class from current schedule
void CurrentSchedule::removeClass(string sectionOptionNum)
{
	string removedID = mySectionList.at(sectionOptionNum).GetCourseID();
	mySectionList.erase(sectionOptionNum);
	ofstream outFS;

	//Writes to CurrentSchedule.txt file
	outFS.open("CurrentSchedule.txt");
	//Error if failed to open file
	if (!outFS.is_open()) {
		cout << "Failed to open CurrentSchedule.txt." << endl;
		return;
	}
	else {
		//Updates current schedule text file with removal of class
		for (auto currentSection = mySectionList.begin(); currentSection != mySectionList.end(); ++currentSection) {
			for (unsigned int i = 0; i < currentSection->second.SectionInfo().size(); ++i) {
					outFS << currentSection->second.SectionInfo().at(i) << "\n";
			}
		}
		cout << "Successfully removed " << removedID << "." << endl;
	}
}
