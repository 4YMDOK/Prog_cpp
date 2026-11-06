CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
ASANFLAGS = -fsanitize=address -g

all: main

main: main.o DynamicArray.o
	$(CXX) $(CXXFLAGS) main.o DynamicArray.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

DynamicArray.o: DynamicArray.cpp
	$(CXX) $(CXXFLAGS) -c DynamicArray.cpp

asan:
	$(CXX) $(CXXFLAGS) $(ASANFLAGS) main.cpp DynamicArray.cpp -o main_asan

clean:
	rm -f *.o main main.exe main_asan main_asan.exe