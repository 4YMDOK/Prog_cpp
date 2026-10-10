#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray(int n) {
    size = n;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс " << index << " вне границ!\n";
        return;
    }

    if (value < -100 || value > 100) {
        cout << "Ошибка: значение должно быть от -100 до 100!\n";
        return;
    }

    data[index] = value;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс " << index << " вне границ!\n";
        return -1;
    }

    return data[index];
}

void DynamicArray::print() {
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}