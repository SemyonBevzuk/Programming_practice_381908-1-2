#ifndef FILM_CLASS
#define FILM_CLASS

#include "FilmLibrary.h"

class FilmClass : public FilmLibrary   //производный класс
{
public:
    FilmClass() : FilmLibrary()   // конструктор класса FilmClass вызывает конструктор класса FilmLibrary
    {
    }
    void Add(string title, string producer, string screenwriter, string composer, string data, long long fees); //Добавить фильм
	void Change(string title, string producer, string screenwriter, string composer, string data, long long fees); // Изменить данные фильма выбранного по названию
	vector<string> Find(string title, int year); //Найти фильм по названию и году
	vector<string> MovieSearch(string producer); //Выдать все фильмы заданного режиссера
	vector<string> MovieSearch(int year); //Выдать все фильмы, вышедшие в прокат в выбранном году
	vector<string> NumberFilms(int quantity); //Выдать заданное число фильмов с наибольшими сборами
	vector<string> NumberFilms(int quantity, int year); //Выдать заданное число фильмов с наибольшими сборами в выбранном году
	int Total(); //Узнать текущее число фильмов
	void DeleteMovie(string title); //Удаление информации о фильме
	void SaveLibraru(); //Сохранить в файл
	void ReadLibraryr(); //Считать из файла

	string ParseDate(string data); //Получить год из даты
};

#endif