#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#define elif else if
using namespace std;

void customize()
{
    cout << "Меню настройки внешнего вида" << endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "1 - матрица." << endl << "2 - светлая тема." << endl << "3 - божья коровка." << endl;
    cout << "4 - лунная тема." << endl << "5 - коммунизм." << endl << "6 - осень." << endl;
    cout << "7 - море." << endl << "8 - эфир." << endl << "9 - лесная тема." << endl;
    cout << "0 - исходная." << endl;

    switch (_getch())
    {
    case '1': SetConsoleTextAttribute(h, 10); break;
    case '2': SetConsoleTextAttribute(h, 240); break;
    case '3': SetConsoleTextAttribute(h, 64); break;
    case '4': SetConsoleTextAttribute(h, 179); break;
    case '5': SetConsoleTextAttribute(h, 70); break;
    case '6': SetConsoleTextAttribute(h, 108); break;
    case '7': SetConsoleTextAttribute(h, 16); break;
    case '8': SetConsoleTextAttribute(h, 113); break;
    case '9': SetConsoleTextAttribute(h, 36); break;
    case '0': SetConsoleTextAttribute(h, 15); break;
    }
}

void info()
{
    int d = 1; char r; ifstream info;
    info.open("Info.txt");
    for (;;)
    {
        info >> r;
        if (r == '|') break;
        if (r == '/') cout << endl;
        elif (r == '_') cout << " "; else cout << r;
    }
}
