/*
    orderedht.h
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

#include "node.h"

#include <iostream>
#include <string>

using namespace std;

class OrderedHT {

    // class variables
	private:
	Node** table;
	unsigned int size;
	unsigned int hash(const long long& phoneNumber) const;

    // class functions
    public:
	OrderedHT(const unsigned int& size);
    OrderedHT();
    ~OrderedHT();

    // accessor functions
    void search(const long long& phoneNumber) const;
	void print(const int& index) const;

	// mutator functions
    void insert(const long long& phoneNumber, const string& callerName);
    void remove(const long long& phoneNumber);
};
