#include <string>
#include "roster.h"
#include "student.h"
using namespace std;

        
        
void Roster::parse(string studentData) {
    string parsedData[9];  // Array to store parsed segments of studentData
    int startPos = 0;
    int endPos = 0;

    for (int i = 0; i < 8; i++) {  //  expect 8 commas, so 9 elements
        endPos = studentData.find(',', startPos);
        parsedData[i] = studentData.substr(startPos, endPos - startPos);
        startPos = endPos + 1;
    }

    // Last element (DegreeProgram) does not have a comma after it
    parsedData[8] = studentData.substr(startPos);

    // Convert parsed strings to the appropriate types
    string sID = parsedData[0];
    string fName = parsedData[1];
    string lName = parsedData[2];
    string email = parsedData[3];
    int sAge = stoi(parsedData[4]);
    int day1 = stoi(parsedData[5]);
    int day2 = stoi(parsedData[6]);
    int day3 = stoi(parsedData[7]);


    DegreeProgram dp = SECURITY;
    if (parsedData[8] == "SOFTWARE") dp = SOFTWARE;
    else if (parsedData[8] == "NETWORK") dp = NETWORK;

   
    add(sID, fName, lName, email, sAge, day1, day2, day3, dp);
}



void Roster::add(string sID, string fName, string Lname, string emailAdd, int sAge, int day1, int day2, int day3, DegreeProgram dp){
    int daysComp[3] = {day1, day2, day3};
    classRosterArray[++lastIndex] = new Student(sID, fName, Lname, emailAdd, sAge, daysComp, dp);
}

bool Roster::removeStudentByID(string IDnum) {
    bool success = false;
    for (int x = 0; x <= Roster::lastIndex; x++) {
        if (classRosterArray[x]->getStudentID() == IDnum) {
            success = true;

        
            if (x < Roster::lastIndex) {
                Student* temp = classRosterArray[x];
                classRosterArray[x] = classRosterArray[Roster::lastIndex];
                classRosterArray[Roster::lastIndex] = temp;
            }

          
            delete classRosterArray[Roster::lastIndex];
            classRosterArray[Roster::lastIndex] = nullptr;
            Roster::lastIndex--;

            
        }
    }

   
    if (success) {
        this->printAll();
    } else {
        cout << "The student with ID " << IDnum << " could not be found." << endl;
    }

    return success;
}

void Roster::printAll(){
    for (int x = 0; x <= Roster::lastIndex; x++) Roster::classRosterArray[x]->print();
}

void Roster::printAverageDays(string IDnum){
    for (int x = 0; x <= Roster::lastIndex; x++)
    {
        if (classRosterArray[x]->getStudentID() == IDnum)
        {
            cout << "Student ID: " << IDnum << ", average days in course is:";
            int avg =(classRosterArray[x] ->getDays()[0]+
                      classRosterArray[x]->getDays()[1]+
                      classRosterArray[x]->getDays()[2])/3;
            cout << avg << endl;
        }
    }
}

void Roster::printInvalidEmails(){
    bool any = false;
    for (int x = 0; x <= Roster::lastIndex; x++)
       {
           string emailAddress = (classRosterArray[x]->getEmailAddress());
           if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos))
           {
                       any = true;
               cout << emailAddress << " - is invalid" << std::endl;
                   }
               }
               if (!any) cout << "NONE" << std::endl;
           }
void Roster::printByDegreeProgram(DegreeProgram dp)
{
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
    }
    
}


Roster::~Roster()
{
    
    for (int x=0; x < numStudents ; x++)
    {
        
        delete classRosterArray[x];
        classRosterArray[x] = nullptr;
    }
}
