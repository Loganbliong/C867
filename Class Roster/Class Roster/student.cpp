#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student(){
    this -> studentID = "";
    this -> firstName = "";
    this -> lastName = "";
    this -> emailAddress = "";
    this -> age = 0;
    for (int x = 0; x < courseDays; x++) this->days[x] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int Age, int days[], DegreeProgram degreeProgram){
    this -> studentID = studentID;
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> emailAddress = emailAddress;
    this -> age = Age;
    for (int i = 0; i < courseDays; i++) this->days[i] = days[i];
    this -> degreeProgram = degreeProgram;
}
Student::~Student(){}


void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int Age) {
    this->age = Age;
}

void Student::setDays(int Days[]) {
    for (int x = 0; x < 3; x++) this->days[x] = days[x];
}

void Student::setDegreeProgram(DegreeProgram degree) {this ->degreeProgram = degree;}

void Student::printHeader(){
    cout << "Student ID" << '\t' << "First Name" << 't' << "Last Name" << '\t' << "Email" << '\t' << "Age" << 't' << "Days Until Completed" << '\t' << "Degree" << endl;
}


string Student::getStudentID() {
    return this->studentID;
}

string Student::getFirstName() {
    return this->firstName;
}

string Student::getLastName() {
    return this->lastName;
}

string Student::getEmailAddress() {
    return this->emailAddress;
}

int Student::getAge() {
    return this->age;
}

int* Student::getDays() {
    return this->days;
}

DegreeProgram Student::getDegreeProgram(){
    return this -> degreeProgram;
}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << this ->getFirstName() << '\t';
    cout << this ->getLastName() << '\t';
    cout << this ->getEmailAddress() << '\t';
    int* days = getDays();
    cout << "\tDays in course: ";
    for (int x = 0; x < courseDays; ++x){
        cout <<days[x] << " ";
    }
    
    string degrees = "";
    switch (getDegreeProgram()) {
            
        case DegreeProgram::NETWORK:
            degrees = "NETWORK";
            break;
        case DegreeProgram::SECURITY:
            degrees = "SECURITY";
            break;
        case DegreeProgram::SOFTWARE:
            degrees = "SOFTWARE";
            break;
    }
    cout << "\tDegree:" << degrees << endl;
}


