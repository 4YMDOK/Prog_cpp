all: main

main: main.o DynamicArray.o
	g++ main.o DynamicArray.o -o main

main.o: main.cpp
	g++ -Iinclude -c main.cpp -o main.o

DynamicArray.o: DynamicArray.cpp
	g++ -Iinclude -c DynamicArray.cpp -o DynamicArray.o