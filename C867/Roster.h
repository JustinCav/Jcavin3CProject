#pragma once
#include <iostream>
#include "Student.h" 
#include <string>
#include "Degree.h"

using namespace std;



class Roster {
private:
	int length=0;


public:
	void printAll();
	Student* classRosterArray[5];
	Student* find(string studentID);
	void LoadData(string studentRecords[], size_t len);
	void add(Student* student);
	Student* ParseStudent(string StudentRecord);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeEnum degreeProgram);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeEnum degreeprogram);
	void remove(string studentID);
	Roster();
	~Roster();
};		

