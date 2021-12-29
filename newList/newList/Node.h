#pragma once
#include "Student.h"
class Node
{
private:
	Student _data;
	Node* _next;
	Node* _prev;
public:
	Node(const Student& d) :_data(d), _next(NULL), _prev(NULL) {}
	
	Node* getNext() const { return this->_next; }
	Node* getPrev() const { return this->_prev; }
	Student getData() const { return this->_data; }

	void setNext(Node* n) { this->_next = n; }
	void setPrev(Node* p) { this->_prev = p; }
	void setData(const Student& other) { this->_data = other; }

	void printNode() const {
		this->getData().printStudent();
	}
};

