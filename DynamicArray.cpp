#include "DynamicArray.h"

DynamicArray::DynamicArray(int n) : data(nullptr), size(n) {
    if (size > 0) {
        data = new int[size]();
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

DynamicArray::DynamicArray(const DynamicArray& other) : data(nullptr), size(other.size) {
    if (size > 0) {
        data = new int[size]();
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this == &other) {
        return *this;
    }

    int* newData = nullptr;
    if (other.size > 0) {
        newData = new int[other.size]();
        for (int i = 0; i < other.size; ++i) {
            newData[i] = other.data[i];
        }
    }

    delete[] data;
    data = newData;
    size = other.size;

    return *this;
}

int DynamicArray::getSize() const {
    return size;
}

void DynamicArray::set(int index, int value) {
    data[index] = value;
}

int DynamicArray::get(int index) const {
    return data[index];
}

void DynamicArray::print() const {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}