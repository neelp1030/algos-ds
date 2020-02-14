/*
    node.cpp
    Purpose: Class to represent a node for a doubly linked list, to be used by the OrderedHT class to implement chaining for collision handling.

    Author - Neel Patel
    Version 1.0  - 11/02/2020
*/

#include "node.h"

#include <iostream>

using namespace std;

/*
	Initializes member variables according to phoneNumber and callerName passed in as parameters and other appropriate default values.

	Params:
	const long long& phoneNumber - phone number of some caller
	const string& callerName - caller name of some caller
*/

Node::Node(const long long& phoneNumber, const string& callerName) {
	this->phoneNumber = phoneNumber;
	this->callerName = callerName;
	next = nullptr;
	prev = nullptr;
}

/*
	Initializes member variables according to appropriate default values.
*/

Node::Node() {
	phoneNumber = 0;
	callerName = "";
	next = nullptr;
	prev = nullptr;
}
