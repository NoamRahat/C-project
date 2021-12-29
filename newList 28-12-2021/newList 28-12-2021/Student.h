#pragma once
#include<string>
#include<iostream>
using namespace std;

class Student
{
private:
	string _name;
	string _id;
public:
	Student(string id = "123", string name = "Haim") :_name(name), _id(id) {}
	void printStudent() const {
		cout << "(" << _id << "," << _name << ")";
	}
	string getId() const { return this->_id; }
	bool operator!=(const Student& other) const {
		return (this->_id != other._id || this->_name != other._name);
	}
	bool operator==(const Student& other) const {
		return (!((*this) != other));
	}

};

