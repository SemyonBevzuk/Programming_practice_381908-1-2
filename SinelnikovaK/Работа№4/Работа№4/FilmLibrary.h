#pragma once
#include "Film.h"
using namespace std;
constexpr int BUF = 50;

class FilmLibrary
{
	Film* films;  // ������
	int quantity; // ���������� �������
	int bufsize;  // �����

public:
	FilmLibrary();                           // �� ���������
	FilmLibrary(const FilmLibrary& library); // �����������
	~FilmLibrary();                          // ����������
	FilmLibrary& operator= (const FilmLibrary& library); // ������������

	bool PrintLibrary();
	bool AddFilm();
	bool AddFilm(Film& film);
	bool ChangeFilm(const string name);
	Film SearchFilm(const string name, const int year);
	FilmLibrary ProducerFilms(const string producer);
	FilmLibrary YearFilms(const int year);
	FilmLibrary FundFilms(const int numbers);
	FilmLibrary FundYearFilms(const int numbers, const int year);
	int CountFilms();
	bool DeleteFilm(const string name);

	friend void ReadFilms(FilmLibrary& library, const string str);
	friend void SaveFilms(const FilmLibrary& library, const string str);

private:
	FilmLibrary& newBuf(const int buf);
	FilmLibrary __listfilms(const string producer, const int year);
	int search(const string comment, const string name);
	void fundsort(ll* mas, int first, int last) const; // ���������� ������� �� ������
	FilmLibrary& sortAndAdd(const FilmLibrary& library, ll* mas, const int _size, const int numbers);
	void insert(int position);
	bool operator== (const FilmLibrary& library);
};


