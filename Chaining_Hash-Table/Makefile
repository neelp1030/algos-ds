all: orderedhtdriver

orderedhtdriver: orderedhttest.cpp orderedht.cpp node.cpp
	g++ -std=c++11 -o orderedhtdriver orderedhttest.cpp orderedht.cpp node.cpp

clean:
	rm -f orderedhtdriver
