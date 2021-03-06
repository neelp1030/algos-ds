/*
    orderedhttest.cpp
    Purpose: Tester file for the ordered hash table implementation.
    Invoke methods on OrderedHT class read from standard input and write expected output to standard output.

    Author - Neel Patel
    Version 1.0  - 11/02/2020
*/

#include "orderedht.h"

#include <iostream>
#include <string>

using namespace std;

// parses a phone number read from cin as a string to long long
long long parsePhoneNumber (const string& phoneNumber) {
	long long parsedPhoneNumber = 0;
	long long multiplier = 1;

	for (int i = phoneNumber.length() - 1; i >= 0; i--) {
		parsedPhoneNumber += multiplier * (long long)(phoneNumber[i] - '0');
		multiplier *= 10;
	}

	return parsedPhoneNumber;
}

int main()
{
	OrderedHT* orderedHashTable;
	string inputLine = "";
	bool ranOnce = false;

	// keep iterating over cin line-by-line until it can no longer find a new line
	while (getline(cin, inputLine)) {
		char command = inputLine[0];

		if (command == 'n') {
			int size = stoi(inputLine.substr(2, inputLine.length()));

			// make sure to not reset the hash table the first time the 'n' command is called
			if (ranOnce) {
				delete orderedHashTable;
				orderedHashTable = nullptr;
			}

			orderedHashTable = new OrderedHT(size);

			ranOnce = true;

			cout << "success" << endl;
		}

		else if (command == 'i') {
			long long phoneNumber = parsePhoneNumber(inputLine.substr(2, inputLine.find(";") - 2));
			string callerName = inputLine.substr(inputLine.find(";") + 1, inputLine.length() - inputLine.find(";") - 1);

			orderedHashTable->insert(phoneNumber, callerName);
		}

		else if (command == 's') {
			long long phoneNumberToSearchFor = 0;

			if (inputLine.find(";") != string::npos) {
				phoneNumberToSearchFor = parsePhoneNumber(inputLine.substr(2, inputLine.find(";") - 2));
			}

			else {
				phoneNumberToSearchFor = parsePhoneNumber(inputLine.substr(2, inputLine.length() - 2));
			}

			orderedHashTable->search(phoneNumberToSearchFor);
		}

		else if (command == 'd') {
			long long phoneNumberToDelete = parsePhoneNumber(inputLine.substr(2, inputLine.length()));

			orderedHashTable->remove(phoneNumberToDelete);
		}

		else if (command == 'p') {
			int indexToPrintAt = parsePhoneNumber(inputLine.substr(2, inputLine.length()));

			orderedHashTable->print(indexToPrintAt);
		}

		else {
			// should never hit this but just in case, do nothing
		}
	}

	// deallocation of memory and prevention of a dangling pointer
	delete orderedHashTable;
	orderedHashTable = nullptr;
}
