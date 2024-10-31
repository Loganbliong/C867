#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;

int main(){
    
    cout << "Course Title: C867 - SCRIPTING AND PROGRAMMING APPLICATIONS" << endl;
    cout << "Language used C++" << endl;
    cout << "Student ID:011559932" << endl;
    cout << "Logan Liong" << endl;
    cout << endl;
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Logan,Liong,lliong@wgu.edu,24,20,50,70,SOFTWARE"
    };
    
    const int studentTable = 5;
    Roster roster;
    
    
    for (int x = 0; x < studentTable; x++) roster.parse(studentData[x]);
    cout << "Display all students:" << endl << endl;
    roster.printAll();
    cout << endl;
    
    
    cout << "Displaying invalid email address:" << endl << endl;
    roster.printInvalidEmails();
    cout << endl;
    
    for (int x = 0; x < studentTable; x++)
    {
        roster.printAverageDays(roster.classRosterArray[x]->getStudentID());
    }
    cout << endl;
    
    
    cout << "Showing students in degree program: SOFTWARE" << endl << endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    cout << "removing A3:\n" << endl;
    roster.removeStudentByID("A3");
    cout << endl;
    
    cout << "removing A3 again\n" << endl;
    roster.removeStudentByID("A3");
    cout << endl << endl;
    
    
}
