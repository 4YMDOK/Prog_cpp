CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: main

main: main.o DynamicArray.o
	$(CXX) $(CXXFLAGS) main.o DynamicArray.o -o main

main.o: main.cpp DynamicArray.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

DynamicArray.o: DynamicArray.cpp DynamicArray.h
	$(CXX) $(CXXFLAGS) -c DynamicArray.cpp -o DynamicArray.o

clean:
	rm -f *.o main main.exe