#pragma once
#include"MyDate.h"
#include<string>
#define SIZE 30

class Calendar
{
private:
	MyDate* _dates[SIZE];
	int _unAvailableDates = 0;

public:
	// Constructors
	Calendar();
	Calendar(const Calendar& other);

	// Methods
	void setDate(int num, MyDate& date);
	bool isFree(int num);
	int firstFree();
	bool Insert(MyDate& date);
	int oldest() const;
	int datesNum() const;
	void erase(int num);
	void deleteAll();
	void print() const;
};

