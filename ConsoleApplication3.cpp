#include <iostream>
#include <cmath>
#include <iomanip>
#include <bitset>

using namespace std;
void taylorSeries() {
    double x_start, x_end, dx, epsilon;
    
    cout << "Задача 1: Вычисление функции с помощью ряда Тейлора" << endl;
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
        while (fabs(term) >= epsilon) {
            double factorial = 1.0;
            for (int i = 1; i <= 2 * n; i++) {
                factorial *= i;
            }
            term = pow(x, 2 * n) / factorial;
            sum += term;
            n++;
            if (n > 1000) break;
        }
        double exact = (exp(x) + exp(-x)) / 2;
        
        cout << fixed << setprecision(6);
        cout << "| " << setw(10) << x << " | " << setw(10) << sum
            << " | " << setw(10) << exact << " |" << endl;
    }
    cout << "----------------------------------------" << endl;
}

unsigned char setBitsInByte(unsigned char original, int value) {
    if (value < 0 || value > 7) {
        cout << "Ошибка: значение должно быть в диапазоне 0..7" << endl;
        return original;
{
    unsigned char cleared = original & 0xC7;
    unsigned char result = cleared | ((value & 0x07) << 3);
    return result;
}

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

int findNearestPrime(int n) {
    if (n <= 2) return 2;

    if (isPrime(n)) return n;
    int lower = n - 1;
    int upper = n + 1;

    while (true) {
        // Проверяем 
        if (lower >= 2 && isPrime(lower)) {
            return lower;
        }
        if (isPrime(upper)) {
            return upper;
        }

        lower--;
        upper++;
    }
}
void demonstrateBitOperations() {
    cout << "\nЗадача 2: Работа с битами" << endl;

    unsigned char testByte = 0b10101010; // 170 в десятичной
    int valueToSet = 5; // 101 в двоичной

    cout << "Исходный байт: " << bitset<8>(testByte) << " (" << (int)testByte << ")" << endl;
    cout << "Устанавливаем значение " << valueToSet << " в биты 3-5" << endl;

    unsigned char result = setBitsInByte(testByte, valueToSet);
    cout << "Результат:     " << bitset<8>(result) << " (" << (int)result << ")" << endl;
}
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
    setlocale(LC_ALL, "Russian");
    taylorSeries();
    demonstratePrimeSearch();

    return 0;
}
