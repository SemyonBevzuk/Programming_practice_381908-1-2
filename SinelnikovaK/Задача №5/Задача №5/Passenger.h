#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
class Passenger
{
	string surname;    // Фамилия
	string name;       // Имя
	string patronymic; // Отчество
	string date;       // Дата отправления
	string depTime;    // Время отправления
	string arrTime;    // Время прибытия
	int train;         // Номер поезда
	int carriage;      // Номер вагона
	int typeCar;       // Тип вагона
	int seat;          // Место
	string departure;  // Станция отправления
	string arrival;    // Станция прибытия

public:
	Passenger(const string surname = "", const string name = "", const string patronymic = "");
	Passenger(const Passenger& passenger);

	Passenger& operator= (const Passenger& passenger);
	bool operator== (const Passenger& passenger);
	void newSeatInfo(const int train, const string depTime, const string arrTime, const int carriage, const int typeCar,
		const int seat, const string departure, const string arrival, const string date);

	// Ввод-вывод консоли
	friend istream& operator>> (istream& stream, Passenger& passenger);
	friend ostream& operator<< (ostream& stream, const Passenger& passenger);
};
