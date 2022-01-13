#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Joseph,Rhodes,jrhod98@wgu.edu,27,3,7,35,SOFTWARE" };

int main()
{
    // step 1
    std::cout << "Scripting and Programming - Applications - C867" << std::endl;
    std::cout << "C++ programming language" << std::endl;
    std::cout << "Student ID: #005759960" << std::endl;
    std::cout << "Joseph Rhodes" << std::endl;
    cout << endl;

    // step 2
    Roster classRoster;

    // step 3
    DegreeProgram degree;
    for (int i = 0; i < 5; i++)
    {
        stringstream student(studentData[i]);
        string attr;
        vector<string> entry;
        while (getline(student, attr, ','))
        {
            entry.push_back(attr);
        }

        if (entry[8] == "SECURITY")
        {
            degree = DegreeProgram::SECURITY;
        }
        if (entry[8] == "SOFTWARE")
        {
            degree = DegreeProgram::SOFTWARE;
        }
        if (entry[8] == "NETWORK")
        {
            degree = DegreeProgram::NETWORK;
        }
        classRoster.add(entry[0], entry[1], entry[2], entry[3], stoi(entry[4]), stoi(entry[5]), stoi(entry[6]), stoi(entry[7]), degree);
    }

    // step 4
    classRoster.printAll();
    classRoster.printInvalidEmails();

    //loop through classRosterArray and for each element:
    cout << "Average course completion time: " << endl;
    for (int i = 0; i < 5; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    // step 5
    classRoster.~Roster();

    return 0;

}
