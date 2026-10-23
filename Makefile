all: main

main: main.o DynamicArray.o
	g++ main.o DynamicArray.o -o main

main.o: main.cpp
	g++ -c main.cpp

DynamicArray.o: DynamicArray.cpp
	g++ -c DynamicArray.cpp