#include <iostream>
#include <cmath>
#include <iomanip>
#include <bitset>

using namespace std;

// Задача 1: Вычисление функции с помощью ряда Тейлора
void taylorSeries() {
    double x_start, x_end, dx, epsilon;

    cout << "Задача 1: Вычисление функции (e^x + e^(-x))/2 с помощью ряда Тейлора" << endl;
    cout << "Введите начальное значение x: ";
    cin >> x_start;
    cout << "Введите конечное значение x: ";
    cin >> x_end;
    cout << "Введите шаг dx: ";
    cin >> dx;
    cout << "Введите точность epsilon: ";
    cin >> epsilon;

    cout << "\nТаблица значений:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "|     x     |   Тейлор   |   Точное   |" << endl;
    cout << "----------------------------------------" << endl;

    for (double x = x_start; x <= x_end + 1e-9; x += dx) {
        double sum = 1.0; // первый член ряда (n=0)
        double term = 1.0;
        int n = 1;

        // Вычисление суммы ряда
        while (fabs(term) >= epsilon) {
            // Вычисляем факториал итеративно чтобы избежать переполнения
            double factorial = 1.0;
            for (int i = 1; i <= 2 * n; i++) {
                factorial *= i;
            }
            term = pow(x, 2 * n) / factorial;
            sum += term;
            n++;

            // Защита от бесконечного цикла
            if (n > 1000) break;
        }

        // Точное значение для сравнения
        double exact = (exp(x) + exp(-x)) / 2;

        cout << fixed << setprecision(6);
        cout << "| " << setw(10) << x << " | " << setw(10) << sum
            << " | " << setw(10) << exact << " |" << endl;
    }
    cout << "----------------------------------------" << endl;
}

// Задача 2: Установка битов 3-5 в байте
unsigned char setBitsInByte(unsigned char original, int value) {
    // Проверка корректности входного значения
    if (value < 0 || value > 7) {
        cout << "Ошибка: значение должно быть в диапазоне 0..7" << endl;
        return original;
    }

    // Очищаем биты 3-5 (биты 3,4,5) и устанавливаем новые значения
    // Маска для очистки: 11000111 (0xC7)
    unsigned char cleared = original & 0xC7;

    // Устанавливаем новые значения в биты 3-5
    // Сдвигаем значение на 3 позиции влево и объединяем
    unsigned char result = cleared | ((value & 0x07) << 3);

    return result;
}

// Задача 3: Проверка числа на простоту
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Задача 3: Поиск ближайшего простого числа
int findNearestPrime(int n) {
    if (n <= 2) return 2;

    // Проверяем само число
    if (isPrime(n)) return n;

    // Ищем ближайшее простое число
    int lower = n - 1;
    int upper = n + 1;

    while (true) {
        // Проверяем нижнее число
        if (lower >= 2 && isPrime(lower)) {
            return lower;
        }

        // Проверяем верхнее число
        if (isPrime(upper)) {
            return upper;
        }

        lower--;
        upper++;
    }
}

// Функция для демонстрации работы с битами
void demonstrateBitOperations() {
    cout << "\nЗадача 2: Работа с битами" << endl;

    unsigned char testByte = 0b10101010; // 170 в десятичной
    int valueToSet = 5; // 101 в двоичной

    cout << "Исходный байт: " << bitset<8>(testByte) << " (" << (int)testByte << ")" << endl;
    cout << "Устанавливаем значение " << valueToSet << " в биты 3-5" << endl;

    unsigned char result = setBitsInByte(testByte, valueToSet);
    cout << "Результат:     " << bitset<8>(result) << " (" << (int)result << ")" << endl;
}

// Функция для демонстрации поиска простых чисел
void demonstratePrimeSearch() {
    cout << "\nЗадача 3: Поиск ближайшего простого числа" << endl;

    int numbers[] = { 10, 15, 20, 25, 30, 100 };

    for (int i = 0; i < 6; i++) {
        int n = numbers[i];
        int prime = findNearestPrime(n);
        cout << "Ближайшее простое к " << n << " : " << prime << endl;
    }
}

int main() {
    // Для работы с русским языком в консоли Windows
    setlocale(LC_ALL, "Russian");

    // Задача 1
    taylorSeries();

    // Задача 2
    demonstrateBitOperations();

    // Задача 3
    demonstratePrimeSearch();

    return 0;
}