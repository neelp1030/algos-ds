/*
    entry.cpp
    Purpose: Class to represent an entry in a hash table consisting of two member variables: phoneNumber and callerName.

    Author - Neel Patel
    Version 1.0  - 11/02/2020
*/

#include "entry.h"

#include <iostream>
#include <string>

using namespace std;

/*
	Initializes member variables according to phoneNumber and callerName passed in as parameters

	Params:
	const long long& phoneNumber - phone number of some caller
	const string& callerName - caller name of some caller
*/

Entry::Entry(const long long& phoneNumber, const string& callerName) {
	this->phoneNumber = phoneNumber;
	this->callerName = callerName;
}

/*
	Initializes member variables according to appropriate default values.
*/

Entry::Entry() {
	phoneNumber = 0;
	callerName = "";
}

/*
	Sets member variables back to default values on destruction as such:

		1) Sets the values of the two member variables to the appropriate default values (0 for long long, "" for string).
*/

Entry::~Entry() {
	this->phoneNumber = 0;
	this->callerName = "";
}
