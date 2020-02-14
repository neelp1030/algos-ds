/*
    orderedht.cpp
    Purpose: Class to represent a hash table in which collisions resolve using chaining.

    Provides the following services (outputting success/failure/found/not found accordingly):

    	1) Define size of the hash table.
    	2) Insert a phone number and the associated caller name into the hash table as a node, ensuring the chain is sorted in increasing order.
    	3) Search for the node associated with a specific phone number in the hash table.
    	4) Delete the node associated with a specific phone number in the hash table.
    	5) Print the chain of phone numbers associated with the nodes starting at a specific position in the hash table.

    Author - Neel Patel
    Version 1.0  - 11/02/2020
*/

#include "orderedht.h"

#include <iostream>

using namespace std;

/*
	Initializes member variables according to size passed in as a parameter and other appropriate default values.

	Params:
	const unsigned int& size - size of hash table
*/

OrderedHT::OrderedHT(const unsigned int& size) {
	table = new Node*[size]();
	this->size = size;
}

/*
	Initializes member variables according to appropriate default values.
*/

OrderedHT::OrderedHT() {
	table = nullptr;
	size = 0;
}

/*
	Sets member variables back to default values on destruction by:

	1) Traversing through the table (array).
	2) Traversing through each linked list at each position of the table and deallocating each node.
	3) Setting pointers to nullptr to avoid dangling pointers.
*/

OrderedHT::~OrderedHT() {
	for (unsigned int i = 0; i < size; i++) {
		while (table[i] != nullptr) {
			Node* temp = table[i];
			table[i] = table[i]->prev;
			delete temp;
			temp = nullptr;
		}
	}

	delete[] table;
	table = nullptr;
	size = 0;
}

/*
	Hashes a phone number to a position in the hash table.

	Params:
	const long long& phoneNumber - phone number of some caller
*/

unsigned int OrderedHT::hash(const long long& phoneNumber) const {
	return (unsigned int)(phoneNumber % size);
}

/*
	Search for the node associated with a specific phone number in the hash table.

	Params:
	const long long& phoneNumber - phone number of some caller
*/

void OrderedHT::search(const long long& phoneNumber) const {

	unsigned int indexToSearchAt = hash(phoneNumber);
	Node* traversalNode = table[indexToSearchAt];

	// traverse through the doubly linked list until the phone number is found
	while (traversalNode != nullptr) {
		if (traversalNode->phoneNumber == phoneNumber) {
			cout << "found " << traversalNode->callerName << " in " << indexToSearchAt << endl;
			return;
		}

		traversalNode = traversalNode->prev;
	}

	// if the phone number is not found by the end of the doubly linked list, then the phone number isn't in the hash table
	cout << "not found" << endl;
}

/*
	Print the chain of phone numbers associated with the nodes starting at a specific position in the hash table.

	Params:
	const int& index - index of hash table to print the chain of phone numbers at
*/

void OrderedHT::print(const int& index) const {

	Node* traversalNode = table[index];

	// if doubly linked list is empty, there is nothing to print
	if (traversalNode == nullptr) {
		return;
	}

	// traverse through the doubly linked list and print out the phone number corresponding to each node
	while (traversalNode != nullptr) {
		if (traversalNode->prev == nullptr) {
			cout << traversalNode->phoneNumber;
		}

		else {
			cout << traversalNode->phoneNumber << " ";
		}

		traversalNode = traversalNode->prev;
	}

	cout << endl;
}

/*
	Insert a phone number and the associated caller name into the hash table as a node, ensuring the chain is sorted in increasing order.

	Params:
	const long long& phoneNumber - phone number of some caller
	const string& callerName - caller name of some caller
*/

void OrderedHT::insert(const long long& phoneNumber, const string& callerName) {

	unsigned int indexToInsertAt = hash(phoneNumber);
	Node* newNode = new Node(phoneNumber, callerName);

	// if doubly linked list is empty, simply set tail of linked list to the insertion node
	if (table[indexToInsertAt] == nullptr) {
		table[indexToInsertAt] = newNode;

		cout << "success" << endl;
	}

	// in the case where phone number of new node is less than the phone number of the tail, insert to the back and update tail
	else if (newNode->phoneNumber <= table[indexToInsertAt]->phoneNumber) {

		// if phone number is determined to be a duplicate, it's a failure
		if (newNode->phoneNumber == table[indexToInsertAt]->phoneNumber) {
			cout << "failure" << endl;
			delete newNode;
			newNode = nullptr;
			return;
		}

		newNode->prev = table[indexToInsertAt];
		table[indexToInsertAt]->next = newNode;
		table[indexToInsertAt] = newNode;

		cout << "success" << endl;
	}

	// in the case where phone number of new node is greater than the phone number of the tail, find the correct two nodes to insert it between
	else {
		Node* currentNode = table[indexToInsertAt];

		// iterates currentNode through the linked list until currentNode is the predecessor to newNode (in terms of phoneNumber)
		while ((currentNode->prev != nullptr) && (newNode->phoneNumber >= currentNode->prev->phoneNumber)) {

			// if phone number is determined to be a duplicate, it's a failure
			if (currentNode->prev->phoneNumber == newNode->phoneNumber) {
				cout << "failure" << endl;
				delete newNode;
				newNode = nullptr;
				return;
			}

			currentNode = currentNode->prev;
		}

		// modifying pointers to insert the newNode in between its predecessor and successor in the linked list
		newNode->next = currentNode;

		if (currentNode->prev != nullptr) {
			newNode->prev = currentNode->prev;
			currentNode->prev->next = newNode;
		}

		currentNode->prev = newNode;

		cout << "success" << endl;
	}
}

/*
 	 Remove the node associated with a specific phone number in the hash table.

 	 Params:
 	 const long long& phoneNumber - phone number of some caller
*/

void OrderedHT::remove(const long long& phoneNumber) {

	unsigned int indexToRemoveAt = hash(phoneNumber);

	// if doubly linked list is empty, deletion is not possible
	if (table[indexToRemoveAt] == nullptr) {
		cout << "failure" << endl;
	}

	else if (table[indexToRemoveAt]->prev == nullptr) {

		if (table[indexToRemoveAt]->phoneNumber == phoneNumber) {
			delete table[indexToRemoveAt];
			table[indexToRemoveAt] = nullptr;

			cout << "success" << endl;

			return;
		}
	}

	else {
		Node* traversalNode = table[indexToRemoveAt];

		// traverse through the doubly linked list until the phone number is found
		while (traversalNode != nullptr) {
			if (traversalNode->phoneNumber == phoneNumber) {
				// modifying pointers and then deleting the node with the phone number
				if (traversalNode == table[indexToRemoveAt]) {
					table[indexToRemoveAt] = table[indexToRemoveAt]->prev;
				}

				if (traversalNode->next != nullptr) {
					traversalNode->next->prev = traversalNode->prev;
				}

				if (traversalNode->prev != nullptr) {
					traversalNode->prev->next = traversalNode->next;
				}

				delete traversalNode;
				traversalNode = nullptr;

				cout << "success" << endl;

				return;
			}

			traversalNode = traversalNode->prev;
		}

		// if the phone number is not found by the end of the doubly linked list, then the phone number isn't in the hash table
		cout << "failure" << endl;
	}
}
