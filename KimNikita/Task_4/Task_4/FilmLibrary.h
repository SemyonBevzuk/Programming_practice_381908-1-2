#pragma once

#include "Film.h"
#include<vector>
#include <fstream>

class FilmLibrary {
private:
	vector<Film> lib;
	void PrintMenuEditor();
public:
	FilmLibrary() {}
	FilmLibrary(const FilmLibrary&);
	void SaveFilm();
	void AddFilm();
	void FixFilm();
	void FindFilm();
	void PrintFilmsBy();
	void PrintFilmsIn();
	void PrintColFilmsMaxIncome();
	void PrintColFilmsMaxIncomeIn();
	void PrintColFilms();
	void DelFilm();
	friend ifstream& operator>> (ifstream&, FilmLibrary&);
	friend ofstream& operator<<(ofstream&, const FilmLibrary&);
	friend bool comp1(const Film& a, const Film& b);
	friend bool comp2(const Film& a, const Film& b);
	~FilmLibrary() {}
};
