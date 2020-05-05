#include<iostream>
#include<fstream>
#include <vector>

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
	FilmLibrary();

	void Add(string title, string producer, string screenwriter, string composer, string data, long long fees); //Добавить фильм
	void Change(string title); // Изменить данные фильма выбранного по названию
	void Find(string title, int year); //Найти фильм по названию и году
	void MovieSearch(string producer); //Выдать все фильмы заданного режиссера
	void MovieSearch(int year); //Выдать все фильмы, вышедшие в прокат в выбранном году
	void NumberFilms(int quantity); //Выдать заданное число фильмов с наибольшими сборами
	void NumberFilms(int quantity, int year); //Выдать заданное число фильмов с наибольшими сборами в выбранном году
	int Total(); //Узнать текущее число фильмов
	void DeleteMovie(string title); //Удаление информации о фильме
	void SaveLibraru(); //Сохранить в файл
	void ReadLibraryr(); //Считать из файла

	string ParseDate(string data); //Получить год из даты
};

