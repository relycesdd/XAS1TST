// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
