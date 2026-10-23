#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <cmath>

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    using iterator = T*;
    using const_iterator = const T*;

    explicit DynamicArray(int n) : size(n) {
        data = new T[size]();
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new T[size]();
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            T* newData = new T[other.size]();
            for (int i = 0; i < other.size; ++i) {
                newData[i] = other.data[i];
            }
            delete[] data;
            data = newData;
            size = other.size;
        }
        return *this;
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    int getSize() const {
        return size;
    }

    void set(int index, const T& value) {
        data[index] = value;
    }

    const T& get(int index) const {
        return data[index];
    }

    T& get(int index) {
        return data[index];
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    bool operator==(const DynamicArray<T>& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const DynamicArray<T>& other