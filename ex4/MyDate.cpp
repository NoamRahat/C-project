#include "MyDate.h"


// Setters

void MyDate::setDay(int dd)
{
	try {
		if (!this->isValidDay(dd))
			throw "Invalid Day input, re-enter date";
		this->_day = dd;
	}
	catch (const char* e) {
		this->setComment("Setting failed");
		cout << e << endl;
		//this->~MyDate();
	}
}

void MyDate::setMonth(int mm)
{
	try {
		if (mm < 1 || mm>12)
			throw "Invalid Month input, re-enter date";
		this->_month = mm;
	}
	catch (const char* e) {
		this->setComment("Setting failed");
		cout << e << endl;
	}
}

void MyDate::setYear(int yyyy)
{
	try {
		if (yyyy <= 0)
			throw "Invalid Year input, re-enter date";
		this->_year = yyyy;
	}
	catch (const char* e) {
		this->setComment("Setting failed");
		cout << e << endl;
	}
}

void MyDate::setComment(const char* comment)
{
	this->_comment = new char[strlen(comment) + 1];
	strcpy_s(this->_comment, strlen(comment) + 1, comment);
}

void MyDate::setMayDate(int yyyy, int mm, int dd, const char* comment)
{
	this->setComment(comment);
	this->setYear(yyyy);
	this->setMonth(mm);
	this->setDay(dd);
}


// Operational functions: Input Checkes

bool MyDate::isValidComment(const char* n) const {
	for (int i = 0; i < strlen(n); i++)
		if (!(n[i] == ' ' || n[i] >= 'a' && n[i] <= 'z' || n[i] >= 'A' && n[i] <= 'Z'))
			return false;
	return true;
}

bool MyDate::isValidDay(int dd) const
{
	if (dd > 0 && dd <= 31 && (this->getMonth() == 1 || this->getMonth() == 3 || this->getMonth() == 5 || this->getMonth() == 7 || this->getMonth() == 8 || this->getMonth() == 10 || this->getMonth() == 12)) {
		return true;
	}
	if (dd > 0 && dd <= 30 && (this->getMonth() == 4 || this->getMonth() == 6 || this->getMonth() == 9 || this->getMonth() == 11)) {
		return true;
	}
	if (dd > 0 && dd <= 28 && (this->getMonth() == 2)) {
		return true;
	}
	return false;
}


// Cnstructoer & Destructors

MyDate::MyDate()
{
	this->setMayDate(2020, 1, 1, "Default Constructor");
}

MyDate::MyDate(int yyyy, int mm, int dd, const char* comment)
{
	this->setMayDate(yyyy, mm, dd, comment);
}

char* MyDate::getComment() const
{
	if (this->_comment != NULL)
		return this->_comment;
}

MyDate::MyDate(const MyDate& other)
{
	this->setMayDate(other.getYear(), other.getMonth(), other.getDay(), other.getComment());
}

MyDate::~MyDate()
{
	cout << "Object Date " << '"' << this->getComment() << '"' << " will be deleted shortly from address : " << this << endl;
	if (this->_comment != NULL)
		delete[] this->_comment;
	cout << "Date destroyed" << endl;
}


// Other Meothods

void MyDate::inc()
{
	if (this->getDay() < 28){
		this->setDay(this->getDay() + 1);
		return;
	}
	
	if (this->getDay() == 31 && (this->getMonth() == 1 || this->getMonth() == 3 || this->getMonth() == 5 || this->getMonth() == 7 || this->getMonth() == 8 || this->getMonth() == 10)) {
		this->setMonth(this->getMonth() + 1);
		this->setDay(1);
		return;
	}
	if (this->getDay() == 31 && (this->getMonth() == 12)) {
		this->setYear(this->getYear() + 1);
		this->setMonth(1);
		this->setDay(1);
		return;
	}
		
	if (this->getDay() == 30 && (this->getMonth() == 4 || this->getMonth() == 6 || this->getMonth() == 9 || this->getMonth() == 11)) {
		this->setMonth(this->getMonth() + 1);
		this->setDay(1);
		return;
	}

	if (this->getDay() == 28 && (this->getMonth() == 2)) {
		this->setMonth(this->getMonth() + 1);
		this->setDay(1);
		return;
	}
}

void MyDate::init()
{
	this->setMayDate(2021, 12, 19, "init");
}

bool MyDate::isBefore(const MyDate& other)
{
	if (this->getYear() < other.getYear()) {
		cout << this->getComment() << " is before " << other.getComment() << endl;
		return true;
	}
	if (this->getYear() == other.getYear()) {
		if (this->getMonth() < other.getMonth()) {
			cout << this->getComment() << " is before " << other.getComment() << endl;
			return true;
		}
		if (this->getMonth() == other.getMonth()) {
			if (this->getDay() < other.getDay()) {
				cout << this->getComment() << " is before " << other.getComment() << endl;
				return true;
			}
		}	
	}
	cout << other.getComment() << " is before " << this->getComment() << endl;
	return false;
}

void MyDate::changeComment(const char* comment)
{
	this->setComment(comment);
}

void MyDate::print() const
{
	cout << this->getDay() << "/" << this->getMonth() << "/" << this->getYear() << "\t" << this->getComment() << endl;
}