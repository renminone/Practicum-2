#include <iostream> //Основная библиотека C++
#include <conio.h> //Для _getch().
#include <fstream> //Для работы с файлами
#include "extrafunc.h" //Дополнительные функции.
#include "techfunc.h" //Технические функции для работы программы.
using namespace std;
void Task1()
{
    string f1 = "T11.txt", f2 = "T12.txt", f3 = "T13.txt"; //Файлы
    cout << "Протокол 1 активирован." << endl;
    int* a, * b, * c; //Массивы для заполнения в файл.
    int n = 0, m = 0, s = 0; //Размеры массивов.

    cout << "Создание первого файла с содержимым." << endl;
    wopen(f1); n = adding(); wclose();
    cout << "Успешно!" << endl << endl;

    cout << "Сортировка содержимого и перезапись." << endl;
    ropen(f1);
    a = new int[n]; reading(a, n); rclose();
    wopen(f1); sort(a, n); wclose();
    cout << "Успешно!" << endl << endl;

    cout << "Создание второго файла с содержимым." << endl;
    wopen(f2); m = adding(); wclose();
    cout << "Успешно!" << endl << endl;

    cout << "Сортировка содержимого и перезапись." << endl;
    ropen(f2); b = new int[m]; reading(b, m); rclose();
    wopen(f2); sort(b, m); wclose();
    cout << "Успешно!" << endl << endl;

    cout << "Создание нового массива из имеющихся данных, сортировка и запись." << endl;
    s = n + m; c = new int[s];
    unite(a, b, c, n, s);
    wopen(f3); sort(c, s); wclose();
    cout << "Успешно!" << endl << endl;
}

void Task2()
{
    cout << "Протокол 2 активирован." << endl;
    string ft2 = "T2.txt";
    int k, n, m, d, c = 0; //Кол-во, размеры, счётчик и количество нулей.
    int ch; //Количество нулей в матрице.
    int* x; //Матрица
    wopen(ft2);
    cout << "Введите количество матриц: ";
    cin >> k;
    cout << endl;

    for (d = 0; d < k; d++)
    {
        c = 0;
        cout << "Введите размеры матрицы (сначала n, потом m): ";
        cin >> n; cin >> m;
        cout << "Введите долю нулей (0 <= ch <= n*m): "; cin >> ch;
        x = new int[n*m];
        * x = randomizer(x, n, m, ch); //Создание матрицы с заданным количеством нулей.
        cout << "Матрица создана." << endl;
        c = nulls(x, n, m, c); //Определить кол-во нулей.
        cout << "Количеество примыкающих нулей определено." << endl;
        writing(x, n, m, c); //Вывод в файл.
        cout << "Записано в файл.." << endl << endl;
        delete [] x; //Высвобождение лишней памяти для следующей матрицы.
    }
    wclose();
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int d = 1;
    while (d != 0)
    {
        system("cls");
        cout << "Меню программы: " << endl;
        cout << "1 - задание 1." << endl << "2 - задание 2." << endl;
        cout << "3 - информация по заданиям." << endl << "4 - кастомизация." << endl;
        cout << "0 - выход из программы" << endl << endl;
        switch (_getch())
        {
        case '1': Task1(); break;
        case '2': Task2(); break;
        case '3': info(); break;
        case '4': customize(); break;
        case '0': d = 0; break;
        }
        if (d != 0) _getch(); //Сделано для просмотра результата задания без стирания) Условие для мгновенного выхода.
    }
    return 0;
}
