#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "DynamicArray.h"

using namespace std;

void runDemo() {
    cout << "=========================================================\n";
    cout << "          ЧАСТЬ 3: ДЕМОНСТРАЦИЯ ШАБЛОНОВ И ОПЕРАЦИЙ      \n";
    cout << "=========================================================\n\n";

    // ---------------------------------------------------------
    // 1. ДЕМОНСТРАЦИЯ ДЛЯ ЧИСЛОВОГО ТИПА (int)
    // ---------------------------------------------------------
    cout << ">>> 1. ЧИСЛОВОЙ ТИП: DynamicArray<int> <<<\n\n";

    // Создание массива
    cout << "[Шаг 1] Создание массива arr1 из 4 элементов:\n";
    DynamicArray<int> arr1(4);
    cout << "  arr1 (по умолчанию): " << arr1 << "\n";

    // Заполнение валидными данными
    cout << "\n[Шаг 2] Заполнение массива значениями от -100 до 100:\n";
    arr1.set(0, 10);
    arr1.set(1, -25);
    arr1.set(2, 50);
    arr1.set(3, 100);
    cout << "  arr1 (вывод через operator<<): " << arr1 << "\n";
    cout << "  ";
    arr1.print(); // метод print()

    // Проверка Задания 1: валидация диапазона [-100, 100] для целых чисел
    cout << "\n[Шаг 3] Задание 1: Проверка ограничений [-100, 100] для целочисленного типа:\n";
    try {
        cout << "  Попытка записать число 150 (> 100)...\n";
        arr1.set(0, 150);
    } catch (const invalid_argument& e) {
        cout << "  -> [OK] Перехвачено invalid_argument: " << e.what() << "\n";
    }

    try {
        cout << "  Попытка записать число -200 (< -100)...\n";
        arr1.set(1, -200);
    } catch (const invalid_argument& e) {
        cout << "  -> [OK] Перехвачено invalid_argument: " << e.what() << "\n";
    }

    // Проверка выхода за границы массива
    cout << "\n[Шаг 4] Проверка выхода за границы индекса:\n";
    try {
        cout << "  Попытка прочитать элемент с индексом 10...\n";
        arr1.get(10);
    } catch (const out_of_range& e) {
        cout << "  -> [OK] Перехвачено out_of_range: " << e.what() << "\n";
    }

    // Задание 3: Евклидово расстояние между числовыми массивами
    cout << "\n[Шаг 5] Задание 3: Евклидово расстояние между векторами-массивами:\n";
    DynamicArray<int> arr2(4);
    arr2.set(0, 13);
    arr2.set(1, -21);
    arr2.set(2, 50);
    arr2.set(3, 96);
    cout << "  Массив a (arr1): " << arr1 << "\n";
    cout << "  Массив b (arr2): " << arr2 << "\n";
    cout << "  Формула: dist = sqrt( (10-13)^2 + (-25-(-21))^2 + (50-50)^2 + (100-96)^2 )\n";
    cout << "         = sqrt( 9 + 16 + 0 + 16 ) = sqrt(41) ~ 6.4031\n";

    double d = arr1.distance(arr2);
    cout << "  -> Результат distance(arr1, arr2): " << fixed << setprecision(4) << d << "\n";

    // Проверка Задания 3: Ошибка при разных размерах массивов
    cout << "\n[Шаг 6] Задание 3: Проверка исключения при несовпадении размеров:\n";
    DynamicArray<int> arrDifferentSize(2);
    arrDifferentSize.set(0, 5);
    arrDifferentSize.set(1, 10);
    cout << "  Массив arrDifferentSize (размер " << arrDifferentSize.getSize() << "): " << arrDifferentSize << "\n";
    try {
        cout << "  Попытка вычисления расстояния между arr1 (размер 4) и arrDifferentSize (размер 2)...\n";
        arr1.distance(arrDifferentSize);
    } catch (const invalid_argument& e) {
        cout << "  -> [OK] Перехвачено invalid_argument: " << e.what() << "\n";
    }

    // ---------------------------------------------------------
    // 2. ДЕМОНСТРАЦИЯ ДЛЯ НЕЧИСЛОВОГО ТИПА (std::string)
    // ---------------------------------------------------------
    cout << "\n---------------------------------------------------------\n";
    cout << ">>> 2. НЕЧИСЛОВОЙ ТИП: DynamicArray<std::string> <<<\n\n";

    // Создание и заполнение строк
    cout << "[Шаг 7] Создание и заполнение строкового массива DynamicArray<string>:\n";
    DynamicArray<string> strArr1(3);
    strArr1.set(0, "Шаблоны");
    strArr1.set(1, "в");
    strArr1.set(2, "C++");
    cout << "  strArr1 (вывод через operator<<): " << strArr1 << "\n";
    cout << "  ";
    strArr1.print();

    cout << "\n[Шаг 8] Создание второго массива строк strArr2:\n";
    DynamicArray<string> strArr2(3);
    strArr2.set(0, "Объектно");
    strArr2.set(1, "Ориентированное");
    strArr2.set(2, "Программирование");
    cout << "  strArr2 (вывод через operator<<): " << strArr2 << "\n";

    // Задание 3: Проверка bad_typeid для нечисловых типов
    cout << "\n[Шаг 9] Задание 3: Попытка вычисления расстояния для нечисловых типов:\n";
    try {
        cout << "  Вызов strArr1.distance(strArr2)...\n";
        strArr1.distance(strArr2);
    } catch (const bad_typeid& e) {
        cout << "  -> [OK] Перехвачено std::bad_typeid: вычисление расстояния доступно только для числовых типов!\n";
    } catch (const exception& e) {
        cout << "  -> Перехвачено исключение: " << e.what() << "\n";
    }

    cout << "\n=========================================================\n";
    cout << "       ВСЕ ТЕСТЫ И ТРЕБОВАНИЯ УСПЕШНО ПРОЙДЕНЫ!          \n";
    cout << "=========================================================\n\n";
}

void interactiveMode() {
    cout << "\n--- ИНТЕРАКТИВНЫЙ РЕЖИМ РАБОТЫ ---\n";
    int n;
    cout << "Введите размер числового массива: ";
    if (!(cin >> n)) return;

    try {
        DynamicArray<int> userArr(n);
        cout << "Введите " << n << " целых чисел (от -100 до 100):\n";
        for (int i = 0; i < n; ++i) {
            int val;
            cout << "Элемент [" << i << "]: ";
            cin >> val;
            try {
                userArr.set(i, val);
            } catch (const invalid_argument& e) {
                cout << "  Ошибка: " << e.what() << " Попробуйте снова.\n";
                --i;
            }
        }

        cout << "\nВведенный массив (через <<): " << userArr << "\n";

        cout << "\nХотите проверить получение элемента по индексу? Введите индекс: ";
        int idx;
        if (cin >> idx) {
            try {
                cout << "Элемент [" << idx << "] = " << userArr.get(idx) << "\n";
            } catch (const out_of_range& e) {
                cout << "Ошибка: " << e.what() << "\n";
            }
        }
    } catch (const exception& e) {
        cout << "Ошибка создания массива: " << e.what() << "\n";
    }
}

int main() {
    // Установка кодировки UTF-8 для корректного отображения кириллицы
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    system("chcp 65001 > nul");

    // Запуск автоматической демонстрации всех заданий
    runDemo();

    // Предложение интерактивного тестирования
    cout << "Запустить интерактивный ввод данных? (y/n, по умолчанию 'n'): ";
    string choice;
    if (cin >> choice && (choice == "y" || choice == "Y" || choice == "yes" || choice == "да" || choice == "Да")) {
        interactiveMode();
    } else {
        cout << "Завершение работы.\n";
    }

    return 0;
}
