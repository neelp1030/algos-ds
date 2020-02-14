/*
    node.h
    Purpose: Class to represent a node for a doubly linked list, to be used by the Deque class to function as a deque.
    Provides basic services of getting and setting the three member variables: data (int), next (pointer to Node), and prev (pointer to Node)

    Author - Neel Patel
    Version 1.0  - 28/01/2020
*/

#include <iostream>

using namespace std;

class Node {

    // class variables
	private:
	int data;
	Node* next;
	Node* prev;

    // class functions
    public:
    Node(int data);
    Node();

    // getter functions for the three member variables. 'const' keyword is used to prevent modification of the member variables.
    int getData() const;
    Node* getNext() const;
    Node* getPrev() const;

    // setter functions for the three member variables
    void setData(const int& data);
    void setNext(Node* next);
    void setPrev(Node* prev);
};
