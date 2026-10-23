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
    // Конструктор: создает массив заданного размера
    explicit DynamicArray(int n) : data(nullptr), size(n) {
        if (n <= 0) {
            throw std::invalid_argument("Размер массива должен быть больше нуля!");
        }
        data = new T[size]();
    }

    // Деструктор: освобождение памяти
    ~DynamicArray() {
        delete[] data;
    }

    // Конструктор копирования
    DynamicArray(const DynamicArray& other) : data(nullptr), size(other.size) {
        data = new T[size]();
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Оператор присваивания (копирование)
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

    // Конструктор перемещения
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    // Оператор присваивания (перемещение)
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

    // Получение размера массива
    int getSize() const {
        return size;
    }

    // Задание 1: Запись элемента с отдельной проверкой для целочисленных типов
    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс выходит за границы массива!");
        }

        // Проверка для массивов, хранящих целочисленные значения: [-100, 100]
        if constexpr (std::is_integral_v<T>) {
            if constexpr (std::is_signed_v<T>) {
                if (value > 100 || value < -100) {
                    throw std::invalid_argument("Значение должно быть в диапазоне от -100 до 100!");
                }
            } else {
                if (value > 100) {
                    throw std::invalid_argument("Значение должно быть в диапазоне от 0 до 100!");
                }
            }
        }

        data[index] = value;
    }

    // Чтение элемента по индексу
    const T& get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс выходит за границы массива!");
        }
        return data[index];
    }

    T& get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс выходит за границы массива!");
        }
        return data[index];
    }

    // Оператор индексации
    const T& operator[](int index) const {
        return get(index);
    }

    T& operator[](int index) {
        return get(index);
    }

    // Задание 2: Перегрузка операции вывода <<
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

    // Метод print() для совместимости с предыдущими частями
    void print() const {
        std::cout << "Массив: " << *this << "\n";
    }

    // Задание 3: Евклидово расстояние между массивами
    // dist = sqrt(\sum (a[i] - b[i])^2)
    // - только для массивов с числами
    // - для остальных типов данных возвращать ошибку std::bad_typeid
    // - размер массивов должен быть одинаков, иначе возвращать std::invalid_argument
    double distance(const DynamicArray<T>& other) const {
        if constexpr (!std::is_arithmetic_v<T>) {
            throw std::bad_typeid();
        } else {
            if (size != other.size) {
                throw std::invalid_argument("Размеры массивов должны быть одинаковыми!");
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

// Свободная функция вычисления евклидова расстояния
template <typename T>
double distance(const DynamicArray<T>& a, const DynamicArray<T>& b) {
    return a.distance(b);
}

#endif // DYNAMIC_ARRAY_H
