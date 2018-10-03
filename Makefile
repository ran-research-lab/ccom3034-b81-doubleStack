all: doubleStackAll

doubleStackAll: doubleStackAll.cpp
	g++ -o doubleStackAll doubleStackAll.cpp -std=c++11

clean:
	rm doubleStackAll