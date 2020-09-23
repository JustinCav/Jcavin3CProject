#include "Student.h"
#include "Degree.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

   Student::Student() {
	
	this->_studentID = "";
	this->_firstName = "";
	this->_lastName = "";
	this->_emailAddr = "";
	this->_age = 0;
	this->_degreePr = DegreeEnum::UNDECIDED;


	for (int i = 0; i < this->daysArraySize; i++)
	{
		this->_duration[i] = 0;
	}
} 
   Student::Student(string studentid, string firstname, string lastname, string emailaddr, int age, int* duration, DegreeEnum degreepr) {
	   for (int x = 0; x < daysArraySize; x++) {
		   this->_duration[x] = duration[x];
	   };
	   this->_studentID = studentid;
	   this->_firstName = firstname;
	   this->_lastName = lastname; 
	   this->_emailAddr = emailaddr;
	   this->_age = age;
	   this->_degreePr = degreepr;
   }

   Student::~Student() {

   }


  void Student::StudentID(string val) {
		this->_studentID = val;
	};
	void Student::FirstName(string val) {
		this->_firstName = val;
	};
	void Student::LastName(string val) {
		this->_lastName = val;
	};
	void Student::EmailAddr(string val) {
		this->_emailAddr = val;
	};
	void Student::Age(int val) {
		this->_age = val;
	}


	bool Student::validEmail() {
		int x = this->_emailAddr.find("@");
		int y = this->_emailAddr.rfind(".");
		int z = this->_emailAddr.find(" ");
		return (z == -1 && y - x > 0 && y > y - x);
	
	}
	
	void Student::printInvalidEmail() {
		char buffer[200];
		string result;
		int x = sprintf_s(buffer, "%s|%s|%s|%s - Email Is Invalid\n",  this->_studentID.c_str(), this->_firstName.c_str(), this->_lastName.c_str(), this->_emailAddr.c_str());
		result = buffer;
		cout << (this->validEmail() ? "" : result);
	}
	
	int Student::AverageDaysInCourse() {
		int z = 0;
		for (int i = 0; i<this->daysArraySize; i++){
			z += this->_duration[i];
		}
		return z / this->daysArraySize;
	}
	
	void Student::printAverageDays() {
		printf("Average Days In Course : %s\n", to_string(this->AverageDaysInCourse()).c_str());
	}

	void Student::Duration(int* val) {
		for (int i = 0; i < daysArraySize; i++) {
			this->_duration[i] = val[i];
		}
	};

	void Student::DegreePr(DegreeEnum val) {
		this->_degreePr = val;
	};

	string Student::StudentID() {
		return this->_studentID;
	};
	string Student::FirstName() {
		return this->_firstName;
	};
	string Student::LastName() {
		return this->_lastName;
	};
	string Student::EmailAddr() {
		return this->_emailAddr;
	};
	int Student::Age() {
		return this->_age;
	};
	int* Student::Duration() {
		return this->_duration;
	};
	DegreeEnum Student::DegreePr() {
		return this->_degreePr;
	};

	void Student::Print() {
		printf("%s\tFirst Name : %s\tLast Name : %s\tEmail : %s\tAge : %s\tdaysInCourse : {%s, %s, %s}\tDegree Program : %s\n", _studentID.c_str(), _firstName.c_str(), _lastName.c_str(), _emailAddr.c_str(), to_string(_age).c_str(), to_string(_duration[0]).c_str(), to_string(_duration[1]).c_str(), to_string(_duration[2]).c_str(), Degree2String[(int)_degreePr].c_str());

	}

