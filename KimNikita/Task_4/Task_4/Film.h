#pragma once

#include "Date.h"
#include <string>
#include <locale>

using namespace std;

class Film {
public:
	string name;
	string producer;
	string scenarist;
	string composer;
	Date date;
	long long int income;
	Film() :income(0) {}
	void PrintFilm()
	{
		cout << "Название: " << name << endl;
		cout << "Режиссер: " << producer << endl;
		cout << "Сценарист: " << scenarist << endl;
		cout << "Композитор: " << composer << endl;
		cout << "Дата выхода в прокат: ";
		date.PrintDate();
		cout << "Сборы в рублях: " << income << endl;
	}
	void GetFilm()
	{
		cout << "Введите название фильма:" << endl;
		getline(cin, name);
		cout << "Введите имя режиссера:" << endl;
		getline(cin, producer);
		cout << "Введите имя сценариста:" << endl;
		getline(cin, scenarist);
		cout << "Введите имя композитора:" << endl;
		getline(cin, composer);
		date.GetDate();
		cout << "Введите сборы в рублях:" << endl;
		cin >> income;
	}
	Film& operator=(const Film& f)
	{
		setlocale(LC_ALL, "Russian");
		if (this != &f)
		{
			name = f.name;
			producer = f.producer;
			scenarist = f.scenarist;
			composer = f.composer;
			date.day = f.date.day;
			date.month = f.date.month;
			date.year = f.date.year;
			income = f.income;
		}
		return *this;
	}
	~Film() {}
};
