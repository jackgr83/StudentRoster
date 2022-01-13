#pragma once

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <vector>
#include "degree.h"
using namespace std;

class Student
{
private:
	// student info vars
	string ID;
	string firstName;
	string lastName;
	string email;
	int age;
	vector<int> numDays;
	DegreeProgram degreeProgram;

public:
	// getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	vector<int> getNumDays();
	DegreeProgram getDegreeProgram();

	// setters
	void setID(string input);
	void setFirstName(string input);
	void setLastName(string input);
	void setEmail(string input);
	void setAge(int input);
	void setNumDays(vector<int> input);
	void setDegreeProgram(DegreeProgram input);

	// constructor
	Student();
	~Student();
	Student(string ID, string firstName, string lastName, string email, int age, vector<int> numDays, DegreeProgram degreeProgram);

	// print
	void print();
};

#endif
