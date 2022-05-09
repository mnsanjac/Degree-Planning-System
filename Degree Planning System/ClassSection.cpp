#include "ClassSection.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

ClassSection::ClassSection(vector<string> info)
{
	courseID = info.at(0);
	classID = info.at(1);
	section = info.at(2);
	time = info.at(3);
	room = info.at(4);
	instructor = info.at(5);
	meetingDates = info.at(6);
	location = info.at(7);
	instructionMode = info.at(8);
}

//Displays section info into table
void ClassSection::PrintSectionInfo()
{
	cout << setfill('-') << setw(177) << "" << setfill(' ');
	cout << "\n";

	cout << left;
	cout << "| ";
	cout << setw(7) << "Class" << " | ";
	cout << setw(17) << "Section" << " | ";
	cout << setw(31) << "Days/Time" << " | ";
	cout << setw(8) << "Room" << " | ";
	cout << setw(20) << "Instructor" << " | ";
	cout << setw(23) << "Meeting Dates" << " | ";
	cout << setw(30) << "Location" << " | ";
	cout << "Instruction Mode |";
	cout << endl;

	cout << setfill('-') << setw(177) << "" << setfill(' ');
	cout << "\n";

	cout << "| ";
	cout << setw(7) << classID << " | ";
	cout << setw(17) << section << " | ";
	cout << setw(31) << time << " | ";
	cout << setw(8) << room << " | ";
	cout << setw(20) << instructor << " | ";
	cout << setw(23) << meetingDates << " | ";
	cout << setw(30) << location << " | ";
	cout << setw(16) << instructionMode;
	cout << " |";
	cout << endl;

	cout << setfill('-') << setw(177) << "" << setfill(' ');
	cout << "\n";

	cout << endl;
}

//Returns all section information
vector<string> ClassSection::SectionInfo()
{
	vector<string> sectionInfo;
	sectionInfo.push_back(courseID);
	sectionInfo.push_back(classID);
	sectionInfo.push_back(section);
	sectionInfo.push_back(time);
	sectionInfo.push_back(room);
	sectionInfo.push_back(instructor);
	sectionInfo.push_back(meetingDates);
	sectionInfo.push_back(location);
	sectionInfo.push_back(instructionMode);
	return sectionInfo;
}

//Gets course ID
string ClassSection::GetCourseID()
{
	return courseID;
}

//Gets class ID
string ClassSection::GetClassID()
{
	return classID;
}

//Gets section number
string ClassSection::GetSection()
{
	return section;
}

//Gets class time and days
string ClassSection::GetTime()
{
	return time;
}

//Gets room number
string ClassSection::GetRoom()
{
	return room;
}

//Gets instructor's name
string ClassSection::GetInstructor()
{
	return instructor;
}

//Gets class meeting dates
string ClassSection::GetMeetingDates()
{
	return meetingDates;
}

//Gets university location
string ClassSection::GetLocation()
{
	return location;
}

//Gets mode of instruction
string ClassSection::GetInstructionMode()
{
	return instructionMode;
}