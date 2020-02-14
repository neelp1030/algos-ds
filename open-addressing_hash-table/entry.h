/*
    entry.h
    Purpose: Class to represent an entry in a hash table consisting of two member variables: phoneNumber and callerName.

    Author - Neel Patel
    Version 1.0  - 11/02/2020
*/

#include <iostream>
#include <string>

using namespace std;

class Entry {

    // class variables
	private:
	long long phoneNumber;
	string callerName;

    // class functions
    public:
	Entry(const long long& phoneNumber, const string& callerName);
    Entry();
    ~Entry();

    // declare OpenHT as a friend class
    friend class OpenHT;
};
