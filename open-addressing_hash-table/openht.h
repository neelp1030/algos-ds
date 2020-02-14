/*
    openht.h
    Purpose: Class to represent a hash table in which collisions resolve using open addressing with double hashing.

    Provides the following services (outputting success/failure/found/not found accordingly):

    	1) Define size of the hash table.
    	2) Insert a phone number and the associated caller name into the hash table as an entry.
    	3) Search for the entry associated with a specific phone number in the hash table.
    	4) Delete the entry associated with a specific phone number in the hash table.

    Author - Neel Patel
    Version 1.0  - 11/02/2020
*/

#include "entry.h"

#include <iostream>
#include <string>

using namespace std;

class OpenHT {

    // class variables
	private:
	Entry* table;
	unsigned int size;
	unsigned int sizeOccupied;

	// hash functions
	unsigned int primaryHash(const long long& phoneNumber) const;
	unsigned int secondaryHash(const long long& phoneNumber) const;

    // class functions
    public:
	OpenHT(const unsigned int& size);
    OpenHT();
    ~OpenHT();

    // accessor functions
    void search(const long long& phoneNumber) const;

	// mutator functions
    void insert(const long long& phoneNumber, const string& callerName);
    void remove(const long long& phoneNumber);
};
