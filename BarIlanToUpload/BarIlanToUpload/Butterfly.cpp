#include "Butterfly.h"


Butterfly::Butterfly() {
	this->_type = 6;
	cout << "(Butterfly) Enter the number of colours  : ";
	cin >> this->_numOfColors;
	cout << "(Butterfly) Butterfly constructed" << endl;
}
Butterfly::~Butterfly() {
	cout << "(Butterfly) Butterfly destroyed" << endl;
}
void Butterfly::print() const {
	Insect::print();
	cout << "(Butterfly) Butterfly's number of colours  : " << this->_numOfColors << endl;
}

void Butterfly::makeNoise() const {
	cout << "(Butterfly) Butterfly noise...zzz..." << endl;
}

