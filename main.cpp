#include <iostream>
#include <windows.h>
#include "DynamicArray.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    DynamicArray arr(3);
    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    arr.print();
    cout << "Размер: " << arr.getSize() << "\n";
    cout << "Элемент 1: " << arr.get(1) << "\n";

    DynamicArray copyArr = arr;
    copyArr.print();

    return 0;
}