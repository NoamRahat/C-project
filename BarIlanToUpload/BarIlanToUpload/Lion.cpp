#include "Lion.h"

Lion::Lion() {
	this->_type = 4;
	cout << "(Lion) Enter the volume : ";
	cin >> this->_volume;
	cout << "(Lion) Lion constructed" << endl;
}
Lion::~Lion() {
	cout << "(Lion) Tiger destroyed" << endl;
}
void Lion::print() const {
	Mammel::print();
	cout << "(Lion) Lion's volume : " << this->_volume << endl;
}

void Lion::makeNoise() const {
	cout << "(Lion) Lion noise...zzz..." << endl;
}
