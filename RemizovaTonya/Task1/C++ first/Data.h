#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace ::std;
class Data
{
private:
	int day, month, year;
public:
	Data();//по умолчанию
	Data(int _day, int _month, int _year);//инициализатор
	Data(const Data& _c);//копирование
	Data(string stroka);//преобразоване типа
	//~Data();//деструктор выполняет освобождение использованных объектом ресурсов и удаление нестатических переменных объекта

	void Print();
	const Data operator+(int n);
	const Data operator-(int n);
	friend bool operator==(const Data& c1, const Data& c2);
	friend bool operator!=(const Data& c1, const Data& c2);
	friend bool operator>(const Data& c1, const Data& c2);
	friend bool operator<(const Data& c1, const Data& c2);
	friend istream & operator>> (istream& stream, Data c);
	friend ostream & operator<< (ostream& stream, const Data& c);
	
};