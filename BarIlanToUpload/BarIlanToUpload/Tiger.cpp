#include "Tiger.h"

Tiger::Tiger() {
	this->_type = 3;
	cout << "(Tiger) Enter the number of souls : ";
	cin >> this->_numOfSouls;
	cout << "(Tiger) Tiger constructed" << endl;
}
Tiger::~Tiger() {
	cout << "(Tiger) Tiger destroyed" << endl;
}
void Tiger::print() const {
	Mammel::print();
	cout << "(Tiger) Tiger's number of souls : " << this->_numOfSouls << endl;
}

void Tiger::makeNoise() const {
	cout << "(Tiger) Tiger noise...zzz..." << endl;
}
