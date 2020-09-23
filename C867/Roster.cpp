#include <iostream>
#include "Student.h" 
#include <string>
#include "Degree.h"
#include "Roster.h"
#include <array>
#include <sstream>

using namespace std;


Roster::Roster() {
	for (int i = 0; i < 5; i++)
	{
		this->classRosterArray[i] = nullptr;
	}

}

Roster::~Roster()
{
}

Student* Roster::find(string studentID) { 
	Student* retVal= nullptr;

	for (int i = 0; i < length; i++)
	{
		if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->StudentID() == studentID) {
			retVal= this->classRosterArray[i];
		}
	}
	return retVal;

}


void Roster::LoadData(string studentRecords[], size_t len) {

	size_t i = 0;
	for (i = 0; i < len; i++)
	{
		this->add(
			this->ParseStudent(studentRecords[i])
		);
	}
};


void Roster::add(Student* student)
{

	this->classRosterArray[this->length++] = student;
		
		
}
;
Student* Roster::ParseStudent(string StudentRecord) {
	string studentData[9];

	int durArray[3];

	int i = 0;
	string dataItem;
	istringstream data(StudentRecord);

	while (getline(data, dataItem, ',')) {
		studentData[i++] = dataItem;
	}

	for (int j = 0; j < 3; j++) {
		durArray[j] = stoi(studentData[j + 5]);
	}

	DegreeEnum enumVal = DegreeEnum::UNDECIDED;


	if (studentData[8] == "SECURITY") {
		enumVal = DegreeEnum::SECURITY;
	}
	else if (studentData[8] == "SOFTWARE") {
		enumVal = DegreeEnum::SOFTWARE;
	}
	else if (studentData[8] == "NETWORK") {
		enumVal = DegreeEnum::NETWORK;
	}

	return new Student(
		studentData[0],
		studentData[1],
		studentData[2],
		studentData[3],
		stoi(studentData[4]),
		durArray,
		enumVal
	);

}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeEnum degreeprogram)
{
	int DurArray[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	Student student = Student(studentID, firstName, lastName, emailAddress, age, DurArray, degreeprogram);

}
void Roster::remove(string studentID)
{
	
	for (int i = 0; i < this->length; i++)
	{
		if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->StudentID() == studentID) {
			this->classRosterArray[i] = nullptr;
		}
	}

}
;

void Roster::printAll() {
	printf("Function Roster::printAll()\n");
	for (int i = 0; i < this->length; i++) {
		if (this->classRosterArray[i] != nullptr) {
			this->classRosterArray[i]->Print();
		}
	}
	printf("\n");
}
void Roster::printAverageDaysInCourse(string studentID) {
	printf("Function Roster::printAverageDatesInCourse(%s)\n", studentID.c_str());
	this->find(studentID)->printAverageDays();
	printf("\n");
}
		
void Roster::printInvalidEmails() {
	printf("Function Roster::printInvalidEmails()\n");
	for (int i = 0; i < this->length; i++) {
		if (this->classRosterArray[i] != nullptr) {
			this->classRosterArray[i]->printInvalidEmail();
		}
	}
	printf("\n");
}

void Roster::printByDegreeProgram(DegreeEnum degreeProgram) {
	printf("Function printByDegreeProgram(%s)\n", Degree2String[(int)degreeProgram].c_str());
	for (int i = 0; i < length; i++) {
		if (this->classRosterArray[i] != nullptr) {
			if (this->classRosterArray[i]->DegreePr() == degreeProgram) {
				this->classRosterArray[i]->Print();
			}
		}
	}
	printf("\n");
}



