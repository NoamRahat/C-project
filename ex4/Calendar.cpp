#include "Calendar.h"

// Constructors

Calendar::Calendar()
{
	for (int i = 0; i < SIZE; i++) {
		this->_dates[i] = NULL;
	}
	this->_unAvailableDates = 0;
}

Calendar::Calendar(const Calendar& other)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (other._dates[i] == NULL)
			this->_dates[i] = NULL;
		else
			this->_dates[i] = new MyDate(*(other._dates[i]));
	}
	this->_unAvailableDates = other._unAvailableDates;
}


// Methods

void Calendar::setDate(int num, MyDate& date)
{
	if (num < 0 || num >= SIZE) {
		cout << "Index is out of range" << endl;
		return;
	}
	if (&date == NULL) {
		cout << "You cannot insert an empty date to this calender" << endl;
		return;
	}
	/*if (this->_dates[num]) {
		cout << "There is a event there already" << endl;
		return;
	}*/
	this->_dates[num] = new MyDate(date);
	
	this->_unAvailableDates++;
}

bool Calendar::isFree(int num)
{
	if (this->_dates[num] == NULL)
		return true;
	
	return 0;
}

int Calendar::firstFree()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (this->isFree(i))
			return i;
	}
	
	return -1;
}

bool Calendar::Insert(MyDate& date)
{
	this->setDate(this->firstFree(), date);
	return true;
}

int Calendar::oldest() const
{
	MyDate min;
	int loc = 0;
	for (int i = 0; i < SIZE - 1 && this->_dates[i] != NULL ; i++)
	{
		min = *this->_dates[i];
		break;
	}
	
	for (int i = 0; i < SIZE - 1; i++)
	{
		if ((this->_dates[i + 1]) == NULL) {
			i++;
			continue;
		}
				
		if ((*this->_dates[i + 1]).isBefore(min)){
			//min = (*this->_dates[i + 1]);
			min.setMayDate(this->_dates[i + 1]->getYear(), this->_dates[i + 1]->getMonth(), this->_dates[i + 1]->getDay(), this->_dates[i + 1]->getComment());

			loc = i + 1;
		}
	}
	return loc;
}

int Calendar::datesNum() const
{
	int num = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (this->_dates[i] != NULL)
		{
			num++;
		}

	}
	return num;
}

void Calendar::erase(int num)
{
	if (this->_dates[num] != 0) {
		this->_dates[num] = nullptr;
		this->_unAvailableDates--;
	}
}

void Calendar::deleteAll()
{
	for (int i = 0; i < SIZE; i++)
		this->erase(i);
}

void Calendar::print() const
{
	int flag = 0;
	for (int i = 0; i < SIZE - 1; i++)
	{
		if ((this->_dates[i]) == NULL) {
			flag++;
			continue;
		}
		this->_dates[i]->print(); cout << endl;
	}
	if (flag == SIZE - 1)
		cout << "Empty Calender" << endl;
}
