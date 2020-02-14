/*
    dequedriver.cpp
    Purpose: Tester file for the deque implementation.
    Invoke methods on deque class read from standard input and write expected output to standard output.

    Author - Neel Patel
    Version 1.0  - 15/01/2020
*/

#include "deque.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	Deque* deque = new Deque();
	string inputLine = "";

	// keep iterating over cin line-by-line until it can no longer find a new line
	while (getline(cin, inputLine)) {
		// check if inputLine contains a space to determine if the command has a parameter or not
		if (inputLine.find(" ") == string::npos) {
			// check for all the possible commands that don't use a parameter
			if (inputLine.compare("dequeue_front") == 0) {
				try {
					deque->dequeue_front();
				}

				catch (const exception& deque_empty) {
					cout << deque_empty.what() << endl;
				}
			}

			else if (inputLine.compare("dequeue_back") == 0) {
				try {
					deque->dequeue_back();
				}

				catch (const exception& deque_empty) {
					cout << deque_empty.what() << endl;
				}
			}

			else if (inputLine.compare("clear") == 0) {
				deque->clear();
			}

			else if (inputLine.compare("empty") == 0) {
				try {
					deque->empty();
				}

				catch (const exception& deque_empty) {
					cout << deque_empty.what() << endl;
				}
			}

			else if (inputLine.compare("size") == 0) {
				deque->size();
			}

			else if (inputLine.compare("print") == 0) {
				deque->print();
			}

			else {
				// should never hit this but just in case, do nothing
			}
		}

		else {
			// check for all the possible commands that use a parameter
			bool invalidArg = false;
			string command = "";
			string numAsString = "";
			int data = 0;

			// try-catch to skip inputs that are invalid and can't be parsed properly
			try {
				command = inputLine.substr(0, inputLine.find(" "));
				numAsString = inputLine.substr(inputLine.find(" ") + 1, inputLine.length());

				// check for any non-digit characters before casting to int to avoid unexpected casts
				for (unsigned int i = 0; i < numAsString.length() - 1; i++) {
					if (i == 0) {
						if (!isdigit(numAsString.at(i)) && numAsString.at(i) != '-') {
							invalidArg = true;
						}
					}
					else {
						if (!isdigit(numAsString.at(i))) {
							invalidArg = true;
						}
					}
				}

				data = stoi(numAsString);
			}

			catch (const exception& ex) {
				invalidArg = true;
			}

			if (!invalidArg) {
				if (command.compare("enqueue_front") == 0) {
					deque->enqueue_front(data);
				}

				else if (command.compare("enqueue_back") == 0) {
					deque->enqueue_back(data);
				}

				else if (command.compare("front") == 0) {
					try {
						deque->front(data);
					}

					catch (const exception& deque_empty) {
						cout << deque_empty.what() << endl;
					}
				}

				else if (command.compare("back") == 0) {
					try {
						deque->back(data);
					}

					catch (const exception& deque_empty) {
						cout << deque_empty.what() << endl;
					}
				}

				else {
					// should never hit this but just in case, do nothing
				}
			}
		}
	}

	// deallocation of memory and prevention of a dangling pointer
	delete deque;
	deque = nullptr;
}
