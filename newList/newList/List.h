#pragma once
#include "Node.h"
class List
{
private:
	Node* _head;

public:
	//Create an empty list
	List() :_head(NULL) {}

	List(const List& other) {
		*this = other;
		cout << "Copy constructor" << endl;
	}

	int size() const {
		int size = 0;
		Node* temp = this->_head;
		while (temp) {
			size++;
			temp = temp->getNext();
		}
		return size;
	}
	Node* getTail() const {
		if (this->_head == NULL) return NULL;	//The list is empty
		Node* temp = this->_head;
		while (temp->getNext())
			temp = temp->getNext();
		return temp;
	}
	Node* find(string id) const {
		Node* temp = this->_head;
		while (temp) {
			if (temp->getData().getId() == id)
				return temp;
			temp = temp->getNext();
		}
		return NULL;
	}

	void insertFirst(const Student& newStudent) {
		Node* newNode = new Node(newStudent);
		if (this->_head == NULL) {
			this->_head = newNode;
			cout << "Student "<<newStudent.getId()<<" inserted to the first node..." << endl;
			return;
		}
		newNode->setNext(_head);
		this->_head->setPrev(newNode);
		this->_head = newNode;
		cout << "Student " << newStudent.getId() << " inserted to the first node..." << endl;
	}
	void insertLast(const Student& newStudent) {
		Node* newNode = new Node(newStudent);
		if (this->_head == NULL) {
			this->_head = newNode;
			cout << "Student " << newStudent.getId() << " inserted to the last node..." << endl;
			return;
		}
		Node* tail = this->getTail();
		tail->setNext(newNode);
		newNode->setPrev(tail);
		cout << "Student " << newStudent.getId() << " inserted to the last node..." << endl;
	}
	void remove(string id) {
		Node* temp = this->find(id);
		if (temp == NULL) {
			cout << "Cannot find this student..." << endl;
			return;
		}
		if (this->size() == 1) {
			delete this->_head;
			this->_head = NULL;
			cout << "The student "<<id<<" is deleted from the list..." << endl;
			return;
		}
		if (temp->getPrev() == NULL)
		{
			this->_head = this->_head->getNext();
			this->_head->setPrev(NULL);
			delete temp;
			cout << "The student " << id << " is deleted from the list..." << endl;
			return;
		}
		if (temp->getNext() == NULL) {
			temp->getPrev()->setNext(NULL);
			cout << "The student " << id << " is deleted from the list..." << endl;
			delete temp;
			return;
		}
		temp->getNext()->setPrev(temp->getPrev());
		temp->getPrev()->setNext(temp->getNext());
		cout << "The student " << id << " is deleted from the list..." << endl;
		delete temp;
	}
	void printList() const {
		if (this->size() == 0)
		{
			cout << "The list is empty" << endl;
			return;
		}
		cout << "The size of the list is : " << this->size() << endl;
		cout << "head<-->";
		Node* temp = this->_head;
		while (temp) {
			temp->getData().printStudent();
			cout << "<-->";
			temp = temp->getNext();
		}
		cout << "||" << endl;
	}

	~List() {
		while (this->_head) {
			this->remove(this->_head->getData().getId());
		}
	}

	//	x = (*this = other); num1 = num2 = num3
	List& operator=(const List& other);

	//myList == otherList
	bool operator==(const List& other) const {
		if (this->size() != other.size())
			return false;
		Node* temp1 = this->_head;
		Node* temp2 = other._head;
		while (temp1) {
			if (temp1->getData() != temp2->getData())
				return false;
			temp1 = temp1->getNext();
			temp2 = temp2->getNext();
		}
		return true;
	}
	//myList += st3;
	List& operator += (const Student & other) {
		this->insertLast(other);
		return *this;
	}
	//newList = myList + otherList
	List operator+(const List& other) const
	{
		List newList = *this;
		Node* temp = other._head;
		while (temp) {
			//newList.insertLast(temp->getData());
			newList += (temp->getData());
			temp = temp->getNext();
		}
		return newList;
	}

};

