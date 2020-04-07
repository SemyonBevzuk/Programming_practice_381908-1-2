#ifndef FILM_LIBRARY_H
#define FILM_LIBRARY_H

#include"Film.h"
#include"Date.h"
#include<map>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

enum exType { exType0 = 0 };

struct MyExc {
	exType extype_;
	string type_;
	MyExc(exType extype, string type)
	{
		extype_ = extype;
		type_ = type;
	}
};

class FilmLibrary{
private:
	map<pair<string,int>,Film> FilmLib;
	map<pair<string, int>, Film> :: const_iterator cbegin() { return FilmLib.cbegin(); }
public:
	FilmLibrary();
	FilmLibrary(const FilmLibrary& FL);
	void addFilm(const Film& film);
	void deleteFilm(const string& name, const int& year);
	bool changeNameFilm(const string& name_to_change, const int& year, const string& new_name);
	void changeDataFilm(const string& name, const int& year, const Film& film);
	//такие же как changeNameFilm
	//void changeProducerFilm(const string& name, const int& year, const string& producer);
	//void changeScreenwriterFilm(const string& name, const int& year, const string& screenwriter);
	//void changeComposerFilm(const string& name, const int& year, const string& composer);
	Film getDataFilm(const string& name, const int& year) const;
	vector<Film> allProducerFilm(const string& producer);
	vector<Film> allYearFilm(const int& year);
	vector<Film> maxValue(const int& count);
	vector<Film> maxValueSelectedYear(const int& count, const int& year);
	size_t getCount() const;
	FilmLibrary& operator= (const FilmLibrary& FL);
	friend ostream& operator<<(ostream& stream, const FilmLibrary& FL);
	friend istream& operator>>(istream& stream, FilmLibrary& FL);
};

#endif
