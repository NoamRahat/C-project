#include "Student.h"


void Student::setId(int id) {
	if (id < 100000000 || id>999999999) {
		cout << "Error with id..." << endl;
		return;
	}
	this->_studentId = id;
}
void Student::setName(const char* name) {
	if (this->isValidName(name)) {
		this->_studentName = new char[strlen(name) + 1];
		strcpy_s(this->_studentName, strlen(name) + 1, name);
		return;
	}
	cout << "Error with name..." << endl;
}
void Student::setGrade(float grade) {
	if (grade < 0 || grade > 100) {
		cout << "Error with grade..." << endl;
		return;
	}
	this->_studentGrade = grade;
}
bool Student::isValidName(const char* name) const {
	if (name == NULL) return false;
	for (int i = 0; i < strlen(name); i++)
		if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] == ' '))
			return false;
	return true;
}
void Student::setStudent(int id, const char* name, float grade) {
	this->setId(id);
	this->setName(name);
	this->setGrade(grade);
}
void Student::printStudent() const {
	cout << "*****************************************" << endl;
	cout << "Student id : " << this->getId() << endl;
	cout << "Student name : " << this->getName() << endl;
	cout << "Student grade : " << this->getGrade() << endl;
	cout << "*****************************************" << endl;
}
Student::Student() {
	this->setStudent();
	cout << "Student default constructor" << endl;
}
Student::Student(int id, const char* name, float grade) {
	this->setStudent(id, name, grade);
	cout << "Student constructed with arguments" << endl;
}

Student::Student(int id) {
	this->setStudent(id, "Ertzel", 80);
	cout << "Student constructed with arguments" << endl;


}
Student::Student(const char* name) {
	this->setStudent(777777777, name, 70);
}
Student::~Student() {
	//cout << "Object student "<<this->getName()<<" will be deleted shortly from address : " << this << endl;
	delete[] this->_studentName;
	//cout << "Student destroyed" << endl;
}
Student::Student(const Student& other) {
	this->setStudent(other.getId(), other.getName(), other.getGrade());
}
