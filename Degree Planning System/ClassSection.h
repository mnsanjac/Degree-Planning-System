#pragma once
#include <string>
#include <vector>
using namespace std;

class ClassSection
{
public:
	ClassSection(vector<string> info);
	void PrintSectionInfo();
	vector<string> SectionInfo();
	string GetCourseID();
	string GetClassID();
	string GetSection();
	string GetTime();
	string GetRoom();
	string GetInstructor();
	string GetMeetingDates();
	string GetLocation();
	string GetInstructionMode();

private:
	string courseID;
	string classID;
	string section;
	string time;
	string room;
	string instructor;
	string meetingDates;
	string location;
	string instructionMode;
};