#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int n);
    ~DynamicArray();

    void set(int index, int value);
    int get(int index);
    void print();
};

#endif