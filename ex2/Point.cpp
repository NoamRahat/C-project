#include "Point.h"

//bool Point::isValid(int n, const char* msg) {
//	if (n < 0) {
//		cout << msg << endl;
//		return false;
//	}
//	return true;
//}


bool Point::setX(int x) {
	/*if (!isValid(x, "x is updated to 0")) {
		_x = 0; return false;
	}*/
	_x = x;
	//cout << "x is updated to " << _x << endl;
	return true;
}
bool Point::setY(int y) {
	/*if (!isValid(y, "y is updated to 0")) {
		_y = 0;
		return false;
	}*/
	_y = y;
	//cout << "y is updated to " << _y << endl;
	return true;
}
bool Point::setPoint(int x, int y) {
	bool f1 = setX(x);
	bool f2 = setY(y);
	return f1 && f2;

	//return setX(x) && setY(y); DO NOT!
}
void Point::printPoint() {
	cout << "The point is : (" << getX() << "," << getY() << ")" << endl;
}
void Point::shiftX(int sh_x) {
	//_x = _x + sh_x; DO NOT
	setX(getX() + sh_x);
}
void Point::shiftY(int sh_y) {
	setY(getY() + sh_y);
}
void Point::shiftPoint(int sh_x, int sh_y) {
	shiftX(sh_x);
	shiftY(sh_y);
}
double Point::distance() {
	int dis_x = getX() * getX();
	int dis_y = getY() * getY();
	return sqrt(dis_x + dis_y);
}


