#pragma once
#include "Point.h"
class cRect
{
private:
	Point _lu;
	Point _rd;

public:
	cRect() {
		this->_lu.setPoint(0, 0);
		this->_rd.setPoint(0, 0);
	}
	Point getPoint(int x);
	void setPoint(int loc, Point p);
	void printRect();
	int calcArea();
};

