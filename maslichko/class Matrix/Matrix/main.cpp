#include <iostream>
#include <fstream>
#include "matrix.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int q, w, t;
    string file = "matrix.txt";
    Matrix m1(file), m2(4, 6), m3(4), m4(4);  //m1 read from file
    m3 = m1; //Присваивание
    cout << m3 << endl;
    cout << "Результат умножения матриц: " << endl;
    m3 = m1 * m2; //Умножение матриц
    cout << m3 << endl;
    cout << "Результат сложения матриц: " << endl;
    m4 = m1 + m2; //Сложение
    cout << m4 << endl;
    cout << "Результат умножения матрицы на число 15: " << endl;
    m4 = m1 * 15; //Умножение на число
    cout << m4 << endl;
    
    cout << "Создание матрицы" << endl;
    cout << "Введите ранг матрицы: ";
    cin >> t; 
    Matrix m5(t);
    cin >> m5; //Создание матрицы

    cout << endl;
    cout << "Транспонированная матрица" << endl;
    cout << m5.Transpos() << endl; //Транспонирование

    cout << "Диагональное преобладание: ";
    cout << m5.IsDiagonal() << endl; //Диагональное преобладание
  
    cout << "Введите индексы искомого элемента: "; 
    cin >> q >> w; //Ввод индексов элемента
    cout << m3(q, w); //Поиск элемента с контролем
  
    system("pause");
}