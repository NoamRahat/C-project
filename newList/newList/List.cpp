#include "List.h"

List& List::operator=(const List& other) {
	while (this->_head) {
		this->remove(this->_head->getData().getId());
	}
	Node* temp = other._head;
	while (temp) {
		this->insertLast(temp->getData());
		temp = temp->getNext();
	}
	return *this;
}
