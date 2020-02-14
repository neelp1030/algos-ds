all: openhtdriver
	
openhtdriver: openhttest.cpp openht.cpp entry.cpp
	g++ -std=c++11 -o openhtdriver openhttest.cpp openht.cpp entry.cpp

clean:
	rm -f openhtdriver
