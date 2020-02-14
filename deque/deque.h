/*
    deque.h
    Purpose: Class to represent a deque.
    Provides the following services (outputting success/failure accordingly):
    	1) Add an element to the front of the deque.
    	2) Add an element to the back of the deque.
    	3) Remove an element from the front of the deque.
    	4) Remove an element from the back of the deque.
    	5) Clear the content of the deque if the deque isn't already empty.
    	6) Access the first element and compare to data.
    	7) Access the last element and compare to data.
    	8) Test if deque is empty.
    	9) Return the size of the queue.
    	10) Print all the values in the deque two times, once from front to back, and another from back to front.

    Author - Neel Patel
    Version 1.0  - 27/01/2020
*/

#include "node.h"

#include <iostream>

using namespace std;

class Deque {

    // class variables
	private:
	unsigned int listSize;
	Node* head;
	Node* tail;

    // class functions
    public:
    Deque();
    ~Deque();

    // print function
	void print();

    // accessor functions
	void front(int data);
	void back(int data);
	void empty();
	void size();

	// mutator functions
	void enqueue_front(int data);
	void enqueue_back(int data);
	void dequeue_front();
	void dequeue_back();
	void clear();
};
