/*
    node.h
    Purpose: Class to represent a node for a doubly linked list, to be used by the OrderedHT class to implement chaining for collision handling.

    Author - Neel Patel
    Version 1.0  - 11/02/2020
*/

#include <iostream>
#include <string>

using namespace std;

class Node {

    // class variables
	private:
	long long phoneNumber;
	string callerName;
	Node* next;
	Node* prev;

    // class functions
    public:
    Node(const long long& phoneNumber, const string& callerName);
    Node();

    // declare OrderedHT as a friend class
    friend class OrderedHT;
};
