#pragma once
#include<iostream>
#include<string>
using namespace std;

class MyDate
{
private:
	// Object Fields
	int _day = 1;
	int _month = 1;
	int _year = 2020;
	char* _comment;

	// Operational functions: Input Checkes
	bool isValidComment(const char* n) const;
	bool isValidDay(int dd) const;

public:
	// Set & Get Mothods
	void setDay(int dd);
	void setMonth(int mm);
	void setYear(int yyyy);
	void setComment(const char* comment);
	void setMayDate(int yyyy, int mm, int dd, const char* comment);
	
	int getDay() const { return this->_day; }
	int getMonth() const { return this->_month; }
	int getYear() const { return this->_year; }
	char* getComment() const;
	
	// Constructors & Destructors
	MyDate();
	MyDate(int yyyy, int mm, int dd, const char* comment);
	MyDate(const MyDate& other);
	~MyDate();

	// Other Methods
	void inc();
	void init();
	bool isBefore(const MyDate& other);
	void changeComment(const char* comment);
	void print() const;
};

