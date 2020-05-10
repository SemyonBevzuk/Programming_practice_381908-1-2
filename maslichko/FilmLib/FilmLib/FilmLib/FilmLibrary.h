#ifndef FILM_DATA
#define FILM_DATA

#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class FilmLibrary
{
private:
    vector<string> title_vector;
    vector<string> producer_vector;
    vector<string> screenwriter_vector;
    vector<string> composer_vector;
    vector<string> data_vector;
    vector<long long> fees_vector;
public:
    FilmLibrary()
    {
    }
    //Занесение данных о фильме
	void Add(string title, string producer, string screenwriter, string composer, string data, long long fees);
	void Change(string title, string producer, string screenwriter, string composer, string data, long long fees);
	vector<string> Find(string title, int year);
	vector<string> MovieSearch(string producer);
	vector<string> MovieSearch(int year);
	vector<string> NumberFilms(int quantity);
	vector<string> NumberFilms(int quantity, int year);
	int Total();
	void DeleteMovie(string title);
	void SaveLibrary(); //Сохраняем библиотеку в файл
	void ReadLibrary(); //Читаем из файла
	string ParseDate(string data);
};

#endif