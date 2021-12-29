#pragma once
#include<iostream>
using namespace std;

class Point
{
private:
	int _x;
	int _y;

	bool isValid(int n, const char* msg);

public:
	int getX() { return _x; }//inline
	int getY() { return _y; }//inline
	bool setX(int x=0);
	bool setY(int y=0);
	bool setPoint(int x = 0, int y = 0);
	void printPoint();
	void shiftX(int sh_x = 1);
	void shiftY(int sh_y = 1);
	void shiftPoint(int sh_x = 1, int sh_y = 1);

	double distance();

};

