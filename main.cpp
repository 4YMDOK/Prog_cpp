#include <iostream>
#include <string>
#include "DynamicArray.h"

using namespace std;

int main() {
    int n;
    cout << "Введите размер числового массива: ";
    cin >> n;

    DynamicArray<int> a(n);
    cout << "Введите " << n << " чисел (от -100 до 100):\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        a.set(i, val);
    }

    cout << "Массив A: " << a << "\n";

    DynamicArray<int> b(n);
    cout << "Введите еще " << n << " чисел для второго массива:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        b.set(i, val);
    }

    cout << "Массив B: " << b << "\n";
    cout << "Расстояние: " << a.distance(b) << "\n";

    DynamicArray<string> s(2);
    s.set(0, "hello");
    s.set(1, "world");
    cout << "Строковый массив: " << s << "\n";

    return 0;
}