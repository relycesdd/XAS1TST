// VaR6_LMS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma once
#include <fstream>
using namespace std;
class WORKER
{
private:
    char name[50];
    char role[50];
    int ICS;    //In Company Since
public://WORKER (Vittorio 19/5/2006)
    WORKER(const char*, const char*, int);
    WORKER();
    WORKER(const WORKER& w);
    ~WORKER();               
    bool operator >(const WORKER& w);
    WORKER& operator = (const WORKER& w);

    int GetICS() const;
    const char* getName() const;


    friend ostream& operator <<(ostream& os, const WORKER& w) {
        return os << w.name << " " << w.role << " " << w.ICS;
    }

};

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
