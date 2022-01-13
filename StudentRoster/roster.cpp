#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Roster::Roster()
{
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int i = stoi(studentID.substr(1)) - 1;
    Student* student = new Student;
    vector<int> numDays;
    numDays.push_back(daysInCourse1);
    numDays.push_back(daysInCourse2);
    numDays.push_back(daysInCourse3);
    student->setID(studentID);
    student->setFirstName(firstName);
    student->setLastName(lastName);
    student->setEmail(emailAddress);
    student->setAge(age);
    student->setNumDays(numDays);
    student->setDegreeProgram(degreeprogram);
    classRosterArray[i] = student;
}

void Roster::remove(string studentID)
{
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            if (i == 4) {
                classRosterArray[i] = classRosterArray[i - 1];
            }
            for (int j = i; j < 4; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            cout << "Removed Student ID: " << studentID << " from roster." << endl;
            cout << endl;
            return;
        }
    }
    cout << "Error: student ID: " << studentID << " not found" << endl;
    cout << endl;
}

void Roster::printAll()
{
    cout << "Student Roster: " << endl;
    for (int i = 0; i < 5; i++)
    {
        string duplicate;
        if (i < 4) {
            if (classRosterArray[i]->getID() == classRosterArray[i+1]->getID()) {
                duplicate = classRosterArray[i]->getID();
            }
        }
        if (classRosterArray[i]->getID() != duplicate) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            int average = (classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2]) / 3;
            cout << "Average number of days for Student ID: " << studentID << " to finish 3 courses: " << average << endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    cout << "Invalid Emails: " << endl;
    for (int i = 0; i < 5; i++)
    {
        bool at = true;
        bool period = true;
        bool space = false;
        string email = classRosterArray[i]->getEmail();
        if (email.find('@') == string::npos)
        {
            at = false;
        }
        if (email.find('.') == string::npos)
        {
            period = false;
        }
        if (email.find(' ') != string::npos)
        {
            space = true;
        }

        if (at == false || period == false || space == true) 
        {
            cout << email << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
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
    cout << studentDegree << " degree program information: " << endl;
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

Roster::~Roster() {
}