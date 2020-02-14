/*
    ECE250
    node.cpp
    Purpose: Class to represent a node for a doubly linked list, to be used by the Deque class to function as a deque.
    Provides basic services of getting and setting the three member variables: data (int), next (pointer to Node), and prev (pointer to Node)

    Author - Neel Patel
    Version 1.0  - 28/01/2020
*/

#include "node.h"

#include <iostream>

using namespace std;

/*
	Initializes member variables according to data passed in as a parameter and other appropriate default values.

	Params:
	int data - data to store in node
*/

Node::Node(int data) {
	this->data = data;
	next = nullptr;
	prev = nullptr;
}

/*
	Initializes member variables according to appropriate default values.
*/

Node::Node() {
	data = 0;
	next = nullptr;
	prev = nullptr;
}

/*
	Fetches the data of the Node class instance. 'const' keyword is used to prevent modification of the 'data' member variable.
*/

int Node::getData() const {
	return data;
}

/*
	Fetches the next node of the Node class instance. 'const' keyword is used to prevent modification of the 'next' member variable.
*/

Node* Node::getNext() const {
	return next;
}

/*
	Fetches the previous node of the Node class instance. 'const' keyword is used to prevent modification of the 'prev' member variable.
*/

Node* Node::getPrev() const {
	return prev;
}

/*
	Sets the data of the Node class instance.

	Params:
	const int& data - data of the node passed by reference with 'const' so it can't be modified.
*/

void Node::setData(const int& data) {
	this->data = data;
}

/*
	Sets the next node of the Node class instance.

	Params:
	Node* next - pointer to the next node of the current node.
*/

void Node::setNext(Node* next) {
	this->next = next;
}

/*
	Sets the previous node of the Entry class instance.

	Params:
	Node* prev - pointer to the previous node of the current node.
*/

void Node::setPrev(Node* prev) {
	this->prev = prev;
}
