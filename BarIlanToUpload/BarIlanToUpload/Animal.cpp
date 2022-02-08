#include "Animal.h"

Animal::Animal() {
	this->_type = 0;
	cout << "(Animal) Enter the animal's name : ";
	cin >> this->_animalName;
	cout << "(Animal) Enter the animal's age : ";
	cin >> this->_age;
	cout << "(Animal) Animal constructed" << endl;
}
Animal::~Animal() {
	cout << "(Animal) Animal destroyed" << endl;
}
void Animal::print() const {
	cout << "(Animal) Animal's name : " << this->_animalName << endl;
	cout << "(Animal) Animal's age : " << this->_age << endl;
}
void Animal::makeNoise() const {
	cout << "(Animal) Animal noise...zzz..." << endl;
}
