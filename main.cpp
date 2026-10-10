#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {
    system("chcp 65001 > nul");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    DynamicArray arr(n);

    cout << "\nВведите " << n << " чисел (от -100 до 100):\n";
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Элемент [" << i << "]: ";
        cin >> val;
        arr.set(i, val);
    }

    cout << "\n";
    arr.print();

    int testIndex;
    cout << "\nВведите индекс элемента, который хотите получить: ";
    cin >> testIndex;
    cout << "Значение по индексу " << testIndex << ": " << arr.get(testIndex) << "\n";

    return 0;
}