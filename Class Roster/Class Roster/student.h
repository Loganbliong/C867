#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include "string.h"
#include <string>
using std::string;
using std::cout;

class Student {
public:
    const static int courseDays = 3;
private:
    
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[courseDays];
    DegreeProgram degreeProgram;

public:
    
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress,  int age, int days[], DegreeProgram degreeProgram);
    ~Student();
    
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    static void printHeader();
    
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();

    
    

        
    void printStudentID();
    void printFirstName();
    void printLastName();
    void printEmailAddress();
    void printAge();
    void printDay();
    void printDegreeProgram();
    void print();

};

#endif
