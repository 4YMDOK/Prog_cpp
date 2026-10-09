#include <iostream>
#include <stdexcept>
#include <new>

using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int n) {
        if (n <= 0) {
            throw invalid_argument("Размер массива должен быть больше нуля!");
        }

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
            throw out_of_range("Индекс выходит за границы массива!");
        }

        if (value < -100 || value > 100) {
            throw invalid_argument("Значение должно быть в диапазоне от -100 до 100!");
        }

        data[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Индекс выходит за границы массива!");
        }

        return data[index];
    }

    void print() const {
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

    DynamicArray* arr = nullptr;
    try {
        arr = new DynamicArray(n);
    } catch (const bad_alloc& e) {
        cout << "Ошибка выделения памяти (bad_alloc): " << e.what() << "\n";
        return 1;
    } catch (const invalid_argument& e) {
        cout << "Некорректный размер (invalid_argument): " << e.what() << "\n";
        return 1;
    }

    cout << "\nВведите " << n << " чисел (от -100 до 100):\n";
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Элемент [" << i << "]: ";
        cin >> val;
        try {
            arr->set(i, val);
        } catch (const invalid_argument& e) {
            cout << "Ошибка: " << e.what() << "\n";
            i--; 
        }
    }

    cout << "\n";
    arr->print();

    int testIndex;
    cout << "\nВведите индекс элемента: ";
    cin >> testIndex;
    try {
        cout << "Значение: " << arr->get(testIndex) << "\n";
    } catch (const out_of_range& e) {
        cout << "Ошибка (out_of_range): " << e.what() << "\n";
    }

    delete arr;
    return 0;
}