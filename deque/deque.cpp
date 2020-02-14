/*
    deque.cpp
    Purpose: Class to represent a deque.
    Provides the following services (outputting success/failure accordingly):
    	1) Add an element to the front of the deque.
    	2) Add an element to the back of the deque.
    	3) Remove an element from the front of the deque.
    	4) Remove an element from the back of the deque.
    	5) Clear the content of the deque if the deque isn't already empty.
    	6) Access the first element and compare to data.
    	7) Access the last element and compare to data.
    	8) Test if deque is empty.
    	9) Return the size of the deque.
    	10) Print all the values in the deque two times, once from front to back, and another from back to front.

    Author - Neel Patel
    Version 1.0  - 27/01/2020
*/

#include "deque.h"

#include <iostream>

using namespace std;

// define a custom exception "deque_empty" for the case where the deque is empty.
class deque_empty: public exception
{
  virtual const char* what() const throw()
  {
    return "failure";
  }
} deque_empty;

/*
	Initializes member variables according to appropriate default values.
*/

Deque::Deque() {
	listSize = 0;
	head = nullptr;
	tail = nullptr;
}

/*
	Sets member variables back to default values on destruction by:

	1) Traversing through the deque (linked list).
	2) Deallocating each node.
	3) Setting pointers to nullptr to avoid dangling pointers.
	4) Decrementing listSize per node traversal to appropriately reflect the change in the deque size.
*/

Deque::~Deque() {
	if(listSize != 0) {
		while (head != nullptr) {
			Node* temp = head;
			head = head->getNext();
			delete temp;
			temp = nullptr;
			listSize--;
		}
	}
}

/*
	Print all the values in the deque two times, once from front to back, and another from back to front.
*/

void Deque::print() {
	if (listSize != 0) {
		Node* fwdTraverse = head;
		Node* bwdTraverse = tail;

		while (fwdTraverse != nullptr) {
			if (fwdTraverse->getNext() == nullptr) {
				cout << fwdTraverse->getData();
			}

			else {
				cout << fwdTraverse->getData() << " ";
			}

			fwdTraverse = fwdTraverse->getNext();
		}

		cout << endl;

		while (bwdTraverse != nullptr) {
			if (bwdTraverse->getPrev() == nullptr) {
				cout << bwdTraverse->getData();
			}

			else {
				cout << bwdTraverse->getData() << " ";
			}

			bwdTraverse = bwdTraverse->getPrev();
		}

		cout << endl;
	}
}

/*
	Access the first element and compare to data, if equal, return success, else failure.
*/

void Deque::front(int data) {
	if (listSize == 0) {
		throw deque_empty;
	}

	else if (head->getData() != data) {
		cout << "failure" << endl;
	}

	else {
		cout << "success" << endl;
	}
}

/*
	Access the last element and compare to data, if equal, return success, else failure.
*/

void Deque::back(int data) {
	if (listSize == 0) {
		throw deque_empty;
	}

	else if (tail->getData() != data) {
		cout << "failure" << endl;
	}

	else {
		cout << "success" << endl;
	}
}

/*
	Test if deque is empty, returning success if empty, else failure.
*/

void Deque::empty() {
	if (listSize == 0) {
		cout << "success" << endl;
	}

	else {
		cout << "failure" << endl;
	}

}

/*
	Return the size of the deque.
*/

void Deque::size() {
	cout << "size is " << listSize << endl;
}

/*
	Add element at the front of the deque.
*/

void Deque::enqueue_front(int data) {
	Node* newNode = new Node(data);
	newNode->setPrev(nullptr);

	if (listSize == 0) {
		head = newNode;
		tail = newNode;
	}

	else {
		newNode->setNext(head);
		head->setPrev(newNode);
		head = newNode;
	}

	listSize++;

	cout << "success" << endl;
}

/*
	Add element at the end of the deque.
*/

void Deque::enqueue_back(int data) {
	Node* newNode = new Node(data);
	newNode->setNext(nullptr);

	if (listSize == 0) {
		head = newNode;
		tail = newNode;
	}

	else {
		newNode->setPrev(tail);
		tail->setNext(newNode);
		tail = newNode;
	}

	listSize++;

	cout << "success" << endl;
}

/*
	Remove element from the front of the deque.
*/

void Deque::dequeue_front() {
	if (listSize == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
		listSize--;

		cout << "success" << endl;
	}

	else if (listSize != 0) {
		Node* temp = head;
		head = head->getNext();
		head->setPrev(nullptr);
		delete temp;
		temp = nullptr;
		listSize--;

		cout << "success" << endl;
	}

	else {
		throw deque_empty;
	}
}

/*
	Remove element from the end of the deque.
*/

void Deque::dequeue_back() {
	if (listSize == 1) {
		delete tail;
		tail = nullptr;
		head = nullptr;
		listSize--;

		cout << "success" << endl;
	}

	else if (listSize != 0) {
		Node* temp = tail;
		tail = tail->getPrev();
		tail->setNext(nullptr);
		delete temp;
		temp = nullptr;
		listSize--;

		cout << "success" << endl;
	}

	else {
		throw deque_empty;
	}
}

/*
	Clears the content of the deque if the deque is not already empty.
*/

void Deque::clear() {
	if(listSize != 0) {
		while (head != nullptr) {
			Node* temp = head;
			head = head->getNext();
			delete temp;
			temp = nullptr;
			listSize--;
		}
	}

	cout << "success" << endl;
}
