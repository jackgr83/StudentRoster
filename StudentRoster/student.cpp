#include "student.h"
#include <string>
#include <iostream>
#include <vector>
#include "degree.h"
using namespace std;

//
// getters
//
string Student::getID()
{
    return ID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmail()
{
    return email;
}

int Student::getAge()
{
    return age;
}

vector<int> Student::getNumDays()
{
    return numDays;
}

DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

//
// setters
//
void Student::setID(string input)
{
    ID = input;
}

void Student::setFirstName(string input)
{
    firstName = input;
}

void Student::setLastName(string input)
{
    lastName = input;
}

void Student::setEmail(string input)
{
    email = input;
}

void Student::setAge(int input)
{
    age = input;
}

void Student::setNumDays(vector<int> input)
{
    numDays = input;
}

void Student::setDegreeProgram(DegreeProgram input)
{
    degreeProgram = input;
}
// constructor
Student::Student()
{
}

Student::~Student() 
{
}

Student::Student(string ID, string firstName, string lastName, string email, int age, vector<int> numDays, DegreeProgram degreeProgram)
{
    this->ID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->numDays = numDays;
    this->degreeProgram = degreeProgram;
}

// print
void Student::print()
{
    string studentDegree;
    if (degreeProgram == SECURITY) {
        studentDegree = "SECURITY";
    }
    if (degreeProgram == NETWORK) {
        studentDegree = "NETWORK";
    }
    if (degreeProgram == SOFTWARE) {
        studentDegree = "SOFTWARE";
    }
    cout << ID << "\t"
        << "First name: " << firstName << "\t"
        << "Last Name: " << lastName << "\t"
        << "Age: " << age << "\t"
        << "daysInCourse: "
        << "{" << numDays.at(0) << ", "
        << numDays.at(1) << ", " << numDays.at(2) << "}"
        << " Degree Program: " << studentDegree << "." << endl;
}