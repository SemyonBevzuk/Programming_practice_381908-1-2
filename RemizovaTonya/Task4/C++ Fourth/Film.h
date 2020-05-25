#pragma once
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <algorithm>
using namespace std;

class MovieClass {
private:
	struct FilmLibrary
	{
		wstring name;
		wstring producer;
		wstring screenwriter;
		wstring composer;
		int day;
		int month;
		int year;
		int cashfees;

		bool operator<(const FilmLibrary& c) const;
	};
	vector<FilmLibrary> list;
public:
	//Constructors and destructor
	MovieClass();
	MovieClass(wstring n, wstring p, wstring s, wstring c, int d, int m, int y, int cash);
	~MovieClass();

	//Secondary functions
	bool AddFilm(wstring n, wstring p, wstring s, wstring c, int d, int m, int y, int cash);
	bool ChangeInformation(wstring search, wstring n, wstring p, wstring s, wstring c, int d, int m, int y, int cash);
	vector<FilmLibrary> SearchFilm(wstring n, int y);
	vector<FilmLibrary> SearchByProducer(wstring p);
	vector<FilmLibrary> SearchByYear(int y);
	vector<FilmLibrary> HighestFees(int sum);
	vector<FilmLibrary> HighestFeesPerYear(int sum, int y);
	int NumberOfFilmsInTheLibrary();
	bool DeleteFilmFromTheLibrary(wstring n);

	//Operator overload

	friend wistream& operator>>(wistream& wistream, MovieClass& c);//Overload operator output from the stream
	friend wostream& operator<<(wostream& wostream, const MovieClass& c);//Overload operator input into the stream

	//Methods
	void NewStruct(wstring n, wstring p, wstring s, wstring c, int d, int m, int y, int cash);
	void Resize(int number);
	void PrintListOfFilms(vector<FilmLibrary> a);
	void ChangeRegistr(int i);
	
};
//Checking that the date was entered correctly
bool CheckingTheDate(int d, int m, int y);