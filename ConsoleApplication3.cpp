//чуть дошаманить
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int a[100][100];  // Матрица
int n;  // Размер матрицы

// ЗАДАЧА 1: Сумма элементов в столбцах, не содержащих отрицательных чисел
void sumplus() {
    int sum = 0;
    for (int j = 0; j < n; j++) {  // Проходим по каждому столбцу
        int hasNegative = 0;
        for (int i = 0; i < n; i++) {  // Проверяем все элементы столбца
            if (a[i][j] < 0) {  // Если в столбце есть отрицательное число
                hasNegative = 1;
                break;  // Прерываем цикл
            }
        }

        if (!hasNegative) {  // Если в столбце нет отрицательных чисел
            for (int i = 0; i < n; i++)  // Суммируем все элементы столбца
                sum += a[i][j];
        }
    }
    printf("Сумма элементов столбцов без отрицательных: %d\n", sum);
}

// ЗАДАЧА 2: Минимум среди сумм модулей элементов диагоналей, параллельных побочной диагонали
int MinSumDiag() {
    int minSum = 2147483647;  // Инициализируем минимальное значение как максимально возможное
    for (int d = -(n - 1); d <= (n - 1); d++) {  // Проходим по всем диагоналям, параллельным побочной
        int sum = 0, hasElements = 0;
        for (int i = 0; i < n; i++) {
            int j = n - 1 - i + d;  // Вычисляем индекс столбца для диагонали
            if (j >= 0 && j < n) {
                sum += abs(a[i][j]);  // Суммируем модули элементов диагонали
                hasElements = 1;
            }
        }
        if (hasElements && sum < minSum)
            minSum = sum;  // Обновляем минимум, если нашли меньшую сумму
    }
    return minSum;
}

// ЗАДАЧА 3: Проверка на наличие двузначных чисел в строке
int hasTwoDigits(const char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i]) && isdigit(s[i + 1]))  // Если нашли два соседних числа
            return 1;
    }
    return 0;
}

// ЗАДАЧА 3: Вывод строк, содержащих двузначные числа
void PrintLinesWithTwoDigits() {
    const char* filename = "input.txt";  // Путь к файлу
    FILE* file = fopen(filename, "r");  // Открываем файл для чтения
    if (!file) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    char line[300];
    while (fgets(line, sizeof(line), file) != NULL) {  // Читаем строки из файла
        if (hasTwoDigits(line))  // Если строка содержит двузначные числа
            printf("%s", line);  // Выводим строку
    }
    fclose(file);  // Закрываем файл
}

// MAIN
int main() {
    printf("Введите n (размер матрицы): ");
    scanf("%d", &n);  // Вводим размер матрицы

    // Вводим элементы матрицы
    printf("Введите элементы матрицы %dx%d:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    sumplus();  // Выполнение задачи 1

    printf("Минимальная сумма диагоналей: %d\n", MinSumDiag());  // Выполнение задачи 2

    printf("\nСтроки, содержащие двузначные числа:\n");
    PrintLinesWithTwoDigits();  // Выполнение задачи 3

    return 0;
}


//testvar24
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int a[100][100];
int n;

// ЗАДАЧА 1
void sumplus() {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        int hasNegative = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] < 0) {
                hasNegative = 1;
                break;
            }
        }
        if (!hasNegative) {
            for (int i = 0; i < n; i++)
                sum += a[i][j];
        }
    }
    printf("Сумма столбцов без отрицательных: %d\n", sum);
}

// ЗАДАЧА 2
int MinSumDiag() {
    int minSum = 2147483647;
    for (int d = -(n - 1); d <= (n - 1); d++) {
        int sum = 0, hasElements = 0;
        for (int i = 0; i < n; i++) {
            int j = n - 1 - i + d;
            if (j >= 0 && j < n) {
                sum += abs(a[i][j]);
                hasElements = 1;
            }
        }
        if (hasElements && sum < minSum)
            minSum = sum;
    }
    return minSum;
}

// ЗАДАЧА 3
int hasTwoDigits(const char* s) {
    for (int i = 0; s[i] != '\0'; i++)
        if (isdigit((unsigned char)s[i]) && isdigit((unsigned char)s[i + 1]))
            return 1;
    return 0;
}

void PrintLinesWithTwoDigits() {
    const char* filename = "C:\\Users\\askhlyustov\\source\\repos\\ConsoleApplication1\\input.txt";
    FILE* file = fopen(filename, "r");
    if (!file) return;

    char line[300];
    while (fgets(line, 300, file) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        if (hasTwoDigits(line))
            printf("%s\n", line);
    }
    fclose(file);
}

// MAIN
int main() {
    printf("Введите n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    sumplus();

    printf("Минимальная сумма диагоналей: %d\n", MinSumDiag());

    PrintLinesWithTwoDigits();

    return 0;
}


//1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include <string.h>

int a[100][100];
int n;

int YeDvo(wchar_t* s) {
    int len = wcslen(s);
    for (int i = 0; i < len - 1; i++) {
        if (iswdigit(s[i]) && iswdigit(s[i + 1])) {
            return 1;
        }
    }
    return 0;
}
//3
void LineW2dgnum() {

    const char* filename = "C:\\Users\\askhlyustov\\source\\repos\\ConsoleApplication1\\input.txt";
    FILE* file = fopen(filename, "r");
    wchar_t line[300];
    while (fgetws(line, 300, file) != NULL) {
        size_t len = wcslen(line);
        if (len > 0 && line[len - 1] == L'\n') {
            line[len - 1] = L'\0';
        }

        if (YeDvo(line)) {
            wprintf(L"%ls\n", line);
        }
    }

    fclose(file);
}

void sumplus() {
    int sum = 0;

    for (int j = 0; j < n; j++) {        
        int hasNegative = 0;

        for (int i = 0; i < n; i++) {    
            if (a[i][j] < 0) {
                hasNegative = 1;
                break;
            }
        }

        if (!hasNegative) {              
            for (int i = 0; i < n; i++)
                sum += a[i][j];
        }
    }

    printf("Сумма элементов матрицы: = %d\n", sum);
}

int main() {

    setlocale(LC_ALL, "RU");

    printf("Введите n: ");
    scanf("%d", &n);

    printf("Введите размеры матрицы %dx%d:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    sumplus();

    wprintf(L"\nСтроки, содержащие двузначные числа:\n");
    LineW2dgnum();

    return 0;
}

// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//var 7
//№1
#include <stdio.h>
#include <math.h>
double mySin(double x, double eps) {
    double cn = x;
    double s = cn;
    for (int n = 3; fabs(cn) > eps; n += 2) {
        cn = -cn * x * x / (n * (n - 1));
        s += cn;
    }
    return s;
}

int main()
{
    double x_start = 0.0;
    double x_end = 2.0;
    double dx = 0.2;
    double eps = 0.0001;
    for (double x = x_start; x <= x_end; x += dx) {
        double s = mySin(x, eps);
        printf("%f %f\n", x, s);
    }
    printf("\n%lf %lf", mySin(3.141592 / 3, 0.0000001), sqrt(3) / (2));
    return 0;
}

//№2
#include <stdio.h>
int third(int num) {
    int n = num;
    n = n / 100;
    return n - (n / 10) * 10;
}
int main() 
{
    int num;
    scanf_s("%d", &num);
    int result = third(num);
    printf("%d\n", result);
}
//№3

#include <stdio.h>

int main()
{
    unsigned short n = 80;
    int s = 15;
    while (s >= 0) {
        printf("%d", (n >> s) & 7);
        s -= 3;
    }
    printf("\n");
    printf("%0", n);
}

// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//var№6
//cos of taylor
#include <stdio.h>
#include <math.h>

double myCh(double x, double eps)
{
    double cn = 1;
    double sum = cn;
    for (int n = 2; fabs(cn) > eps; n += 2) {
        cn = cn * x * x / (n * (n - 1));
        sum += n;
    }
    return sum;
}


//funcciya bites
// функция записывает в 3-й, 4-й, 5-й биты параметра value значение newbyte
#include <stdio.h>

typedef unsigned char byte;
typedef unsigned short word;

int checkBit(byte value, byte newbyte) {
    byte a = 7;
    byte mask = ~(a << 3);
    return (value & mask) | (newbyte << 3);
}
void binaryRepresentation(byte value) {
    for (int k = 7; k >= 0; k--) {
        printf("%d", (value >> k) & 1);
    }
    printf("\n");
}
int main() {
    byte a = 100;
    byte value = 253;
    byte rez = checkBit(value, a);

    printf(" value = %x,  %x", value, rez);

    return 0;
}
//Ryad of taylor(not swift)
//file30092025.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= std::sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int nearestPrime(int n)
{
    if (isPrime(n)) return n;
    int d = 1;
    while (true) {
        if (n - d >= 2 && isPrime(n - d))
            return n - d;
        if (isPrime(n + d))
            return n + d;
        d++;
    }
}

int main() {
    double x_nach = 0.0;
    double x_kon = 1.0;
    double dx = 0.1;
    double eps = 0.0001;
    printf(" %lf %lf \n", "x", "sum");
    for (double x = x_nach; x <= x_kon; x += dx) {
        double sum = myCh(x, eps);
    }
    return 0;
}


//ДЛЯ КР!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cmath>

int readSum(const char* fname) {
    FILE* f, * fw;
    fopen_s(&f, fname, "r");
    fopen_s(&fw, "text1.txt", "w");
    if (f == NULL) {
        printf("file not open");
        return -1;
    }
    int sum = 0;
    int a;
    while (fscanf_s(f, "%d", &a) == 1) {
        sum += a;
    }
    return sum;
}
int main() {
    const char* filename = "C:\\Users\\askhlyustov\\source\\repos\\ConsoleApplication1\\input.txt";
    int totalSum = readSum(filename);

if (totalSum != -1) {
    printf("summ of all numbers: %d\n", totalSum);
}
return 0;
}
//№6/\/2
#include <stdio.h>
#include <math.h>

double myCh(double x, double eps)
{
    double cn = 1;
    double sum = cn;
    int n = 2;

    while (fabs(cn) > eps) {
        cn = cn * x * x / (n * (n - 1));
        sum += cn;
        n += 2;
    }
    return sum;
}
typedef unsigned char byte;
typedef unsigned short word;

byte writeBits(byte value, byte newbyte)
{
    newbyte &= 0b00000111;        
    byte mask = ~(0b00000111 << 3);
    return (value & mask) | (newbyte << 3);
}

void binaryRepresentation(byte value) {
    for (int k = 7; k >= 0; k--) {
        printf("%d", (value >> k) & 1);
    }
    printf("\n");
}

bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int nearestPrime(int n)
{
    if (isPrime(n)) return n;
    int d = 1;
    while (1) {
        if (n - d >= 2 && isPrime(n - d))
            return n - d;
        if (isPrime(n + d)) return n + d;
        d++;
    }
}

int main() {
    double x_nach = 0.0;
    double x_kon = 1.0;
    double dx = 0.1;
    double eps = 0.0001;
    for (double x = x_nach; x <= x_kon + 1e-12; x += dx) {
        double sum = myCh(x, eps);
        printf("%7.3lf      %lf\n", x, sum);
    }
}

