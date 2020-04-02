#pragma once

#include "Film.h"
#include<vector>
#include <fstream>

class FilmLibrary {
private:
	vector<Film> lib;
	void PrintMenuEditor();
	friend bool sort_year_name(const Film& a, const Film& b);
	friend bool sort_income(const Film& a, const Film& b);
public:
	FilmLibrary() {}
	FilmLibrary(const FilmLibrary&);
	bool SaveFilm(ofstream&, string, int);
	void AddFilm(Film);
	bool FixFilm(string, int);
	bool FindFilm(string, int);
	bool PrintFilmsBy(string);
	bool PrintFilmsIn(int);
	void PrintColFilmsMaxIncome(int);
	bool PrintColFilmsMaxIncomeIn(int, int);
	int ColFilms();
	bool DelFilm(string);
	friend ifstream& operator>> (ifstream&, FilmLibrary&);
	friend ofstream& operator<<(ofstream&, const FilmLibrary&);
	~FilmLibrary() {}
};
