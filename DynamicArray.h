#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <cmath>

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    explicit DynamicArray(int n) : data(nullptr), size(n) {
        if (n <= 0) {
            throw std::invalid_argument("Error");
        }
        data = new T[size]();
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other) : data(nullptr), size(other.size) {
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
        if (index < 0 || index >= size) {
            throw std::out_of_range("Error");
        }

        if constexpr (std::is_integral_v<T>) {
            if constexpr (std::is_signed_v<T>) {
                if (value > 100 || value < -100) {
                    throw std::invalid_argument("Error");
                }
            } else {
                if (value > 100) {
                    throw std::invalid_argument("Error");
                }
            }
        }

        data[index] = value;
    }

    const T& get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Error");
        }
        return data[index];
    }

    T& get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Error");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        return get(index);
    }

    T& operator[](int index) {
        return get(index);
    }

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
        os << "[";
        for (int i = 0; i < arr.size; ++i) {
            os << arr.data[i];
            if (i < arr.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    void print() const {
        std::cout << *this << "\n";
    }

    double distance(const DynamicArray<T>& other) const {
        if constexpr (!std::is_arithmetic_v<T>) {
            throw std::bad_typeid();
        } else {
            if (size != other.size) {
                throw std::invalid_argument("Error");
            }
            double sum = 0.0;
            for (int i = 0; i < size; ++i) {
                double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
                sum += diff * diff;
            }
            return std::sqrt(sum);
        }
    }
};

template <typename T>
double distance(const DynamicArray<T>& a, const DynamicArray<T>& b) {
    return a.distance(b);
}

#endif