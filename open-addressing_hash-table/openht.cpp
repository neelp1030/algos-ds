/*
    openht.cpp
    Purpose: Class to represent a hash table in which collisions resolve using open addressing with double hashing.

    Provides the following services (outputting success/failure/found/not found accordingly):

    	1) Define size of the hash table.
    	2) Insert a phone number and the associated caller name into the hash table as an entry.
    	3) Search for the entry associated with a specific phone number in the hash table.
    	4) Delete the entry associated with a specific phone number in the hash table.

    Author - Neel Patel
    Version 1.0  - 11/02/2020
*/

#include "openht.h"

#include <iostream>

using namespace std;

/*
	Initializes member variables according to size passed in as a parameter and other appropriate default values.

	Params:
	const unsigned int& size - size of hash table
*/

OpenHT::OpenHT(const unsigned int& size) {
	table = new Entry[size];
	this->size = size;
	this->sizeOccupied = 0;
}

/*
	Initializes member variables according to appropriate default values.
*/

OpenHT::OpenHT() {
	table = nullptr;
	size = 0;
	sizeOccupied = 0;
}

/*
	Sets member variables back to default values on destruction by:

	1) Traversing through the table (array) and setting member variables back to default values for every entry.
*/

OpenHT::~OpenHT() {
	for (int i = 0; i < size; i++) {
		table[i].phoneNumber = 0;
		table[i].callerName = "";
	}

	delete[] table;
	table = nullptr;
	size = 0;
	sizeOccupied = 0;
}

/*
	Hashes a phone number to a position in the hash table (used as the first position to check during insert/search/remove).

	Params:
	const long long& phoneNumber - phone number of some caller
*/

unsigned int OpenHT::primaryHash(const long long& phoneNumber) const {
	return (unsigned int)(phoneNumber % size);
}

/*
	Computes an offset to be added to the result of primaryHash in order to resolve collisions if/when they occur.
*/

unsigned int OpenHT::secondaryHash(const long long& phoneNumber) const {
	unsigned int output = (unsigned int)((phoneNumber / size) % size);

	// if even, add 1 to make it odd
	if (output % 2 == 0) {
		output += 1;
	}

	return output;
}

/*
	Search for the entry associated with a specific phone number in the hash table.

	Params:
	const long long& phoneNumber - phone number of some caller
*/

void OpenHT::search(const long long& phoneNumber) const {

	// if there is no data in the hash table, there is no point in searching
	if (sizeOccupied == 0) {
		cout << "not found" << endl;
	}

	else {
		unsigned int indexToSearchAt = primaryHash(phoneNumber);
		unsigned int originalIndex = indexToSearchAt;
		unsigned int offset = secondaryHash(phoneNumber);

		// recompute index until the phone number is found or an empty entry is found
		while ((table[indexToSearchAt].phoneNumber != phoneNumber) && (table[indexToSearchAt].phoneNumber != 0)) {

			indexToSearchAt = (indexToSearchAt + offset) % size;

			// takes care of a potential infinite loop situation
			if (indexToSearchAt == originalIndex) {
				cout << "not found" << endl;
				return;
			}
		}

		// if the stop was due to the phone number being found, phone number has been found
		if (table[indexToSearchAt].phoneNumber != 0) {
			cout << "found " << table[indexToSearchAt].callerName << " in " << indexToSearchAt << endl;
		}

		// if the stop was due to an empty entry, phone number is not in the hash table
		else {
			cout << "not found" << endl;
		}
	}
}

/*
	Insert a phone number and the associated caller name into the hash table as an entry.

	Params:
	const long long& phoneNumber - phone number of some caller
	const string& callerName - caller name of some caller
*/

void OpenHT::insert(const long long& phoneNumber, const string& callerName) {

	// if the hash table is full, insertion is not possible
	if (sizeOccupied == size) {
		cout << "failure" << endl;
	}

	else {
		unsigned int indexToInsertAt = primaryHash(phoneNumber);
		unsigned int originalIndex = indexToInsertAt;
		unsigned int offset = secondaryHash(phoneNumber);

		// recompute index until an empty entry or deleted entry is found
		while ((table[indexToInsertAt].phoneNumber != 0) && (table[indexToInsertAt].phoneNumber != -1)) {

			// if phone number is determined to be a duplicate, it's a failure
			if (phoneNumber == table[indexToInsertAt].phoneNumber) {
				cout << "failure" << endl;
				return;
			}

			indexToInsertAt = (indexToInsertAt + offset) % size;

			// takes care of a potential infinite loop situation
			if (indexToInsertAt == originalIndex) {
				cout << "failure" << endl;
				return;
			}
		}

		// at this point, the index to insert at has been found, so insertion can be done
		table[indexToInsertAt].phoneNumber = phoneNumber;
		table[indexToInsertAt].callerName = callerName;

		sizeOccupied++;

		cout << "success" << endl;
	}
}

/*
 	 Remove the entry associated with a specific phone number in the hash table.

 	 Params:
 	 const long long& phoneNumber - phone number of some caller
*/

void OpenHT::remove(const long long& phoneNumber) {

	// if there is no data in the hash table, deletion is not possible
	if (sizeOccupied == 0) {
		cout << "failure" << endl;
	}

	else {
		unsigned int indexToRemoveAt = primaryHash(phoneNumber);
		unsigned int originalIndex = indexToRemoveAt;
		unsigned int offset = secondaryHash(phoneNumber);

		// recompute index until the phone number is found or an empty entry is found
		while ((table[indexToRemoveAt].phoneNumber != phoneNumber) && (table[indexToRemoveAt].phoneNumber != 0)) {

			indexToRemoveAt = (indexToRemoveAt + offset) % size;

			// takes care of a potential infinite loop situation
			if (indexToRemoveAt == originalIndex) {
				cout << "not found" << endl;
				return;
			}
		}

		// if the stop was due to the phone number being found, phone number has been found, so delete it
		if (table[indexToRemoveAt].phoneNumber != 0) {
			table[indexToRemoveAt].phoneNumber = -1;
			table[indexToRemoveAt].callerName = "";
			sizeOccupied--;

			cout << "success" << endl;
		}

		// if the stop was due to an empty entry, phone number is not in the hash table
		else {
			cout << "failure" << endl;
		}
	}
}
