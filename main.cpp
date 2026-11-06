#include <iostream>
#include <vector>
#include <utility>
#include <windows.h>
#include "DynamicArray.h"

using namespace std;

void consumeByValue(DynamicArray<int> arr) {
    cout << "Внутри функции: " << arr << "\n";
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    DynamicArray<int> a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    DynamicArray<int> b(2);
    b[0] = 1;
    b[1] = 2;

    b = a;
    b = b;

    DynamicArray<int> c = std::move(a);
    cout << "После move-конструктора (источник): " << a.getSize() << "\n";
    cout << "После move-конструктора (цель): " << c << "\n";

    DynamicArray<int> d(1);
    d = std::move(c);
    d = std::move(d);
    cout << "После move-оператора (цель): " << d << "\n";

    cout << "Копирование по значению:\n";
    consumeByValue(d);
    cout << "Массив d после копирования: " << d << "\n";

    cout << "Перемещение по значению:\n";
    consumeByValue(std::move(d));
    cout << "Массив d после перемещения: " << d.getSize() << "\n";

    vector<DynamicArray<int>> vec;
    DynamicArray<int> temp(2);
    temp[0] = 99;
    temp[1] = 100;
    vec.push_back(std::move(temp));

    return 0;
}