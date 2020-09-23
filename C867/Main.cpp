#include "Roster.h"
#include "Degree.h"
#include <string>

using namespace std;

int main() {
	
	string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Justin,Caviness,jcavin3@wgu.edu,25, 30,10,40,SOFTWARE" };
	int count = 5;
	Roster classRoster = Roster();
	
	classRoster.LoadData(studentData, count);
	
	classRoster.printAll();

	classRoster.printInvalidEmails();



	//loop through classRosterArray and for each element:

	//classRoster.printAverageDaysInCourse(/*current_object's student id*/);
	for (int i = 0; i < count; i++) {
		if (classRoster.classRosterArray[i] != nullptr) {
			classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->StudentID());
		}
	}


	classRoster.printByDegreeProgram(DegreeEnum::SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");
	
	classRoster.~Roster();
	
	return 0;

}