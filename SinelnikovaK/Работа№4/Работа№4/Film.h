#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
typedef long long ll;

class Film
{
	string name;         // Название
	string producer;     // Режиссер
	string screenwriter; // Сценарист
	string composer;     // Композитор
	int day, mount, year;     // Дата выхода
	ll fundraising;           // Сборы

public:
	Film();                 // По умолчанию
	Film(const Film& film); // Копирования
	~Film();                // Деструктор
	Film& operator= (const Film& film); // Присваивания
	void UpdateFilm(const string _name, const string _producer, const string _screenwriter,
		const string _composer, const int _day, const int _mount, const int _year, const ll _fundraising); // Заполнение информации о фильме
	Film(const string _name, const string _producer, const string _screenwriter,
		const string _composer, const int _day, const int _mount, const int _year, const ll _fundraising); // Инициализация

	Film& Read(); // Считывание информации о фильме с консоли
	bool Write(); // Вывод информации о фильме на консоль
	friend void swap(Film& f1, Film& f2);

	/// Возврат определенной информации о фильме
	friend string Name(const Film& film) { return film.name; }
	friend string Producer(const Film& film) { return film.producer; }
	friend string Screenwriter(const Film& film) { return film.screenwriter; }
	friend string Composer(const Film& film) { return film.composer; }
	friend int Day(const Film& film) { return film.day; }
	friend int Mount(const Film& film) { return film.mount; }
	friend int Year(const Film& film) { return film.year; }
	friend ll Fund(const Film& film) { return film.fundraising; }

	friend istream& operator>> (istream& stream, Film& film);       // Считывание с файла
	friend ostream& operator<< (ostream& stream, const Film& film); // Запись в файл

	bool operator!= (const Film& film);
};

