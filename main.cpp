#include <iostream>
#include <string>
#include "DynamicArray.h"

using namespace std;

int main() {
    DynamicArray<int> a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    cout << "A: " << a << "\n";

    DynamicArray<int> b(3);
    b[0] = 10;
    b[1] = 20;
    b[2] = 30;

    cout << "a == b: " << (a == b) << "\n";
    cout << "a != b: " << (a != b) << "\n";

    a += 5;
    cout << "A += 5: " << a << "\n";

    a += b;
    cout << "A += B: " << a << "\n";

    a -= 2;
    cout << "A -= 2: " << a << "\n";

    cout << "for-range: ";
    for (const auto& x : a) {
        cout << x << " ";
    }
    cout << "\n";

    for (auto& x : a) {
        x += 1;
    }
    cout << "after iterator: " << a << "\n";

    return 0;
}