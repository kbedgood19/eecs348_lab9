CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main

main: main.o matrix.o
	$(CXX) $(CXXFLAGS) main.o matrix.o -o main

main.o: main.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix.cpp

clean:
	rm -f *.o main
