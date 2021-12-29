#pragma once
#include "Student.h"
#include<string>

#define SIZE 10
class Classroom
{
private:
	Student* _seats[SIZE];
	string _className;
public:
	Classroom(string n="my_class");
	~Classroom();
	Classroom(const Classroom& other);
	void printClassroom() const;
	string getName() const { return this->_className; }
	Student* getStudentByIndex(int index) const { return this->_seats[index]; }
	void setName(string n) { this->_className = n; }
	void removeStudentByIndex(int index);
	void insertToClassroom(int index, Student* s);
	void insertToClassroom(int index);
};

