#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class Data
{
private:
	bool leapyear;
	int day;
	int month;
	int year;
	bool leap(int)const;
	int maxday()const;
public:
	Data();//Конструктор по умолчанию
	Data(const Data& _date);//Копирование
	Data(string _date);//Преобразование типа
	Data(int _day, int _month, int _year) : leapyear(leap(_year)), day(_day), month(_month), year(_year) {};  //Констркутор инициализатор
	~Data();
	Data& operator+=(int d);
	Data& operator-=(int d);
	Data& operator=(const Data& date);

	bool operator>(const Data& date);
	bool operator<(const Data& date);
	bool operator<=(const Data& a);
	bool operator>=(const Data& a);
	bool operator==(const Data& a);
	bool operator!=(const Data& a);



	friend std::istream& operator>> (istream& stream, Data& date);
	friend std::ostream& operator<< (ostream& stream, Data date);

};