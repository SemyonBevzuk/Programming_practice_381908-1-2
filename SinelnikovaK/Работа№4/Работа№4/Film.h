#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
typedef long long ll;

class Film
{
	string name;         // ��������
	string producer;     // ��������
	string screenwriter; // ���������
	string composer;     // ����������
	int day, mount, year;     // ���� ������
	ll fundraising;           // �����

public:
	Film();                 // �� ���������
	Film(const Film& film); // �����������
	~Film();                // ����������
	Film& operator= (const Film& film); // ������������
	void UpdateFilm(const string _name, const string _producer, const string _screenwriter,
		const string _composer, const int _day, const int _mount, const int _year, const ll _fundraising); // ���������� ���������� � ������
	Film(const string _name, const string _producer, const string _screenwriter,
		const string _composer, const int _day, const int _mount, const int _year, const ll _fundraising); // �������������

	Film& Read(); // ���������� ���������� � ������ � �������
	bool Write(); // ����� ���������� � ������ �� �������
	friend void swap(Film& f1, Film& f2);

	/// ������� ������������ ���������� � ������
	friend string Name(const Film& film) { return film.name; }
	friend string Producer(const Film& film) { return film.producer; }
	friend string Screenwriter(const Film& film) { return film.screenwriter; }
	friend string Composer(const Film& film) { return film.composer; }
	friend int Day(const Film& film) { return film.day; }
	friend int Mount(const Film& film) { return film.mount; }
	friend int Year(const Film& film) { return film.year; }
	friend ll Fund(const Film& film) { return film.fundraising; }

	friend istream& operator>> (istream& stream, Film& film);       // ���������� � �����
	friend ostream& operator<< (ostream& stream, const Film& film); // ������ � ����

	bool operator!= (const Film& film);
};

