#ifndef FILM_CLASS
#define FILM_CLASS

#include "FilmLibrary.h"

class Creature
{
private:
	FilmLibrary f1;
public:
	Creature()
	{
	}

	void Add(string title, string producer, string screenwriter, string composer, string data, long long fees)
	{
		f1.Add(title, producer, screenwriter, composer, data, fees);
	}
	void Change(string title, string producer, string screenwriter, string composer, string data, long long fees)
	{
		f1.Change(title, producer, screenwriter, composer, data, fees);
	}
	vector<string> Find(string title, int year)
	{
		vector<string> temp = f1.Find(title, year);
		return temp;
	}
	vector<string> MovieSearch(string producer)
	{
		vector<string> temp = f1.MovieSearch(producer);
		return temp;
	}

	vector<string> MovieSearch(int year)
	{
		vector<string> temp = f1.MovieSearch(year);
		return temp;
	}
	vector<string> NumberFilms(int quantity)
	{
		vector<string> temp = f1.NumberFilms(quantity);
		return temp;
	}

	vector<string> NumberFilms(int quantity, int year)
	{
		vector<string> temp = f1.NumberFilms(quantity, year);
		return temp;
	}

	int Total()
	{
		return f1.Total();
	}

	void DeleteMovie(string title)
	{
		f1.DeleteMovie(title);
	}

	void SaveLibrary() //Сохраняем библиотеку в файл
	{
		f1.SaveLibrary();
	}

	void ReadLibrary()
	{
		f1.ReadLibrary();
	}
};

#endif