#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#define elif else if
using namespace std;

//Общее
ofstream fp; ifstream fx;
int i, j, temp;

//Данные функции создают связь между h и cpp.
void wopen(string file) { fp.open(file); }
void ropen(string file) { fx.open(file); }
void wclose() { fp.close(); }
void rclose() { fx.close(); }

//Все технические функции задания 1.

//Добавление элементов в файл, а также определение размера будущего массива.
int adding()
{
    int e = 0, size = 0;
    do
    {
        cout << "Введите число: "; cin >> e;
        if (e >= 0) fp << e << endl; size++;
    } while (e != 0);
    return size;
}

//Сортировка по возрастанию.
void sort(int* ar, int size)
{
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (ar[j] > ar[j + 1]) { temp = ar[j]; ar[j] = ar[j + 1]; ar[j + 1] = temp; }
    for (i = 0; i < size; i++) fp << ar[i] << " ";
}

//Чтение данных из файла.
void reading(int* ar, int size) { for (i = 0; i < size; i++) fx >> ar[i]; }

//Объединение a и b в c.
void unite(int* ar1, int* ar2, int* ar, int s1, int size)
{
    for (i = 0; i < s1; i++) ar[i] = ar1[i];
    for (i = s1; i < size; i++) ar[i] = ar2[i - s1];
}

//Все технические функции задания 2.

//Запись в файл
void writing(int* x, int n, int m, int c)
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            fp << *(x + i * m + j) << "   ";
        fp << endl;
    }
    fp << "Количество примыкающих нулей: " << c << endl << endl;
}

//Подсчёт количества примыкающих нулей.
int nulls(int* x, int n, int m, int c)
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {   
            if (*(x + i * m + j) == 0)
            {
                if (*(x + i * m + (j - 1)) == 0 && (j != 0)) c++;
                elif (*(x + i * m + (j + 1)) == 0 && (j != m - 1)) c++;
                     elif (*(x + (i - 1) * m + j) == 0 && (i != 0)) c++;
                          elif (*(x + (i + 1) * m + j) == 0 && (i != n - 1)) c++;
            }
        }
    }
    return c;
}

int randomizer(int* x, int n, int m, int ch)
{
    int e, z, d;
    int i , j;

    //Антиеррор.
    if (ch < 0) ch = 0; if (ch > n * m) ch = n * m;

    //Частные случаи.
    if (ch == 0) for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                    *(x + i * m + j) = 1;
    elif (ch == n * m)
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                *(x + i * m + j) = 0;
    else
    {
        z = ch; e = n * m - ch;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                if (z != 0 && e != 0)
                {
                    d = rand() % 2;
                    if (d == 0) { z--; *(x + i * m + j) = 0; }
                    elif (d == 1) { e--; *(x + i * m + j) = 1; }
                }
                elif (z == 0) *(x + i * m + j) = 1;
                elif (e == 0) *(x + i * m + j) = 0;
            }
    }
    return *x;
}

