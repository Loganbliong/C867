#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"


class Roster {
    
public:
    ~Roster();
    static const int numStudents = 5;
    Student* classRosterArray[numStudents];
    int lastIndex = -1;
    void parse(string row);
    void add(string sID, string fName, string fLname, string Email, int sAge, int day1, int day2, int day3, DegreeProgram dp);
  
    
    DegreeProgram degreeProgram;
    
    void printAll();
    void printByDegreeProgram(DegreeProgram dp);
    void printInvalidEmails();
    void printAverageDays (string IDnum);
    bool removeStudentByID(string IDnum);
};



#endif
