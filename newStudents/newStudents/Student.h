#pragma once
#include<iostream>
using namespace std;

class Student
{
private:
	int _studentId;
	char* _studentName;
	float _studentGrade;
	bool isValidName(const char* n) const;

public:
	int getId() const { return this->_studentId; }
	char* getName() const { return this->_studentName; }
	float getGrade() const { return this->_studentGrade; }

	void setId(int id=111111111);
	void setName(const char* name = "unknown");
	void setGrade(float grade = 100);

	void setStudent(int id = 111111111, const char* name = "unknown", float grade = 100);

	void printStudent() const;

	Student();
	Student(int id, const char* name, float grade);
	Student(int id);
	Student(const char* name);
	Student(const Student& other);
	

	~Student();//Destructor
};

