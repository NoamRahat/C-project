#include "Insect.h"

Insect::Insect() {
	this->_type = 2;
	cout << "(Insect) Enter the number of legs : ";
	cin >> this->_numOfLegs;
	cout << "(Insect) Insect constructed" << endl;
}
Insect::~Insect() {
	cout << "(Insect) Insect destroyed" << endl;
}
void Insect::print() const {
	Animal::print();
	cout << "(Insect) Insect's number of legs : " << this->_numOfLegs << endl;
}
void Insect::makeNoise() const {
	cout << "(Insect) Insect noise...zzz..." << endl;
}
