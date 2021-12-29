#include "Classroom.h"

Classroom::Classroom(string n) {
	this->_className = n;
	for (int i = 0; i < SIZE; i++)
		this->_seats[i] = NULL;

}
Classroom::~Classroom() {
	for (int i = 0; i < SIZE; i++)
		if (this->_seats[i])
			delete this->_seats[i];
}
void Classroom::printClassroom() const {
	bool flag = false;
	cout << "Classroom name  : " << this->_className << endl;
	for (int i = 0; i < SIZE; i++)
		if (this->_seats[i]) {
			cout << "Student at index : " << i << endl;
			this->_seats[i]->printStudent();
			flag = true;
		}
	if (!flag)
		cout << "This classroom is empty" << endl;
}
void Classroom::removeStudentByIndex(int index) {
	if (index < 0 || index >= SIZE) {
		cout << "Index is out of range" << endl;
		return;
	}
	if (this->_seats[index] == NULL) {
		cout << "No stuent there" << endl;
		return;
	}
	delete this->_seats[index];
	this->_seats[index] = NULL;
}
void Classroom::insertToClassroom(int index, Student* s) {
	if (index < 0 || index >= SIZE) {
		cout << "Index is out of range" << endl;
		return;
	}
	if (s == NULL) {
		cout << "You cannot insert an empty student to this classroom" << endl;
		return;
	}
	if (this->_seats[index]) {
		cout << "There is a student there already" << endl;
		return;
	}
	//this->_seats[index] = s;
	this->_seats[index] = new Student(*s);
	
}
void Classroom::insertToClassroom(int index) {
	
	if (index < 0 || index >= SIZE) {
		cout << "Index is out of range" << endl;
		return;
	}
	if(this->_seats[index]){
		cout << "There is a student there already" << endl;
		return;
	}
	cout << "Enter the new student's id : ";
	int id;
	cin >> id;
	cout << "Enter the new student's grade : ";
	float grade;
	cin >> grade;
	cout << "Enter the new student's name : ";
	char name[100];
	cin >> name;
	Student* s = new Student(id, name, grade);
	this->insertToClassroom(index, s);
}

Classroom::Classroom(const Classroom& other) {
	this->_className = other._className;
	for (int i = 0; i < SIZE; i++)
		if (other._seats[i] == NULL)
			this->_seats[i] = NULL;
		else
			this->_seats[i] = new Student(*(other._seats[i]));
}
