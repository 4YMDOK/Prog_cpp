#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <cmath>
#include <utility>
#include <type_traits>

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    using iterator = T*;
    using const_iterator = const T*;

    explicit DynamicArray(int n = 0) : data(nullptr), size(n) {
        if (size > 0) {
            data = new T[size]();
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other) : data(nullptr), size(other.size) {
        if (size > 0) {
            data = new T[size]();
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }

        T* newData = nullptr;
        if (other.size > 0) {
            newData = new T[other.size]();
            for (int i = 0; i < other.size; ++i) {
                newData[i] = other.data[i];
            }
        }

        delete[] data;
        data = newData;
        size = other.size;

        return *this;
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

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

    bool operator!=(const DynamicArray<T>& other) const {
        return !(*this == other);
    }

    DynamicArray<T>& operator+=(const DynamicArray<T>& other) {
        int limit = (size < other.size) ? size : other.size;
        for (int i = 0; i < limit; ++i) {
            data[i] += other.data[i];
        }
        return *this;
    }

    DynamicArray<T>& operator-=(const DynamicArray<T>& other) {
        if constexpr (std::is_arithmetic_v<T>) {
            int limit = (size < other.size) ? size : other.size;
            for (int i = 0; i < limit; ++i) {
                data[i] -= other.data[i];
            }
        }
        return *this;
    }

    DynamicArray<T>& operator+=(const T& scalar) {
        for (int i = 0; i < size; ++i) {
            data[i] += scalar;
        }
        return *this;
    }

    DynamicArray<T>& operator-=(const T& scalar) {
        if constexpr (std::is_arithmetic_v<T>) {
            for (int i = 0; i < size; ++i) {
                data[i] -= scalar;
            }
        }
        return *this;
    }

    iterator begin() {
        return data;
    }

    iterator end() {
        return data + size;
    }

    const_iterator begin() const {
        return data;
    }

    const_iterator end() const {
        return data + size;
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
        if constexpr (std::is_arithmetic_v<T>) {
            double sum = 0.0;
            for (int i = 0; i < size; ++i) {
                double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
                sum += diff * diff;
            }
            return std::sqrt(sum);
        } else {
            return 0.0;
        }
    }
};

template <typename T>
double distance(const DynamicArray<T>& a, const DynamicArray<T>& b) {
    return a.distance(b);
}

#endif