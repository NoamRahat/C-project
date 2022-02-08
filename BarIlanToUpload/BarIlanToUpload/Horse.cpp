#include "Horse.h"


Horse::Horse() {
	this->_type = 5;
	cout << "(Horse) Enter the speed : ";
	cin >> this->_speed;
	cout << "(Horse) Horse constructed" << endl;
}
Horse::~Horse() {
	cout << "(Horse) Horse destroyed" << endl;
}
void Horse::print() const {
	Mammel::print();
	cout << "(Horse) Horse's speed : " << this->_speed << endl;
}

void Horse::makeNoise() const {
	cout << "(Horse) Horse noise...zzz..." << endl;
}

