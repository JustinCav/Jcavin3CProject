#pragma once
#include <string>
#include <iostream>
#include "Degree.h"

using namespace std;


	class Student
	{
	public:
		const static int daysArraySize = 3;

		 Student();
		 ~Student();
		 Student(string studentid, string firstname, string lastname, string emailaddr, int age, int duration[], DegreeEnum degreepr);
		 void StudentID(string val);
		void FirstName(string val);
		void LastName(string val);
		void EmailAddr(string val);
		void Age(int val);
		void Duration(int* val);
		void DegreePr(DegreeEnum val);
		bool validEmail();
		void printInvalidEmail();

		int AverageDaysInCourse();

		void printAverageDays();

		string StudentID();
		string FirstName();
		string LastName();
		string EmailAddr();
		int Age();
		int* Duration();
		DegreeEnum DegreePr();

		void Print();

	private:
		string _studentID;
		string _firstName;
		string _lastName;
		string _emailAddr;
		int _age;
		int _duration[daysArraySize];
		DegreeEnum _degreePr;




	};
