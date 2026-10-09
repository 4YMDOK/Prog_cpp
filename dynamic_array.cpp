#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int n) {
        size = n;
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    void set(int index, int value) {
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

    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс " << index << " вне границ!\n";
            return -1;
        }

        return data[index];
    }

    void print() {
        cout << "Массив: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

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