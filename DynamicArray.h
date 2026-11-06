#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

class DynamicArray {
private:
    int* data;
    int size;

public:
    explicit DynamicArray(int n = 0);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    int getSize() const;
    void set(int index, int value);
    int get(int index) const;
    void print() const;
};

#endif