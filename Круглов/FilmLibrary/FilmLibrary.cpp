#include "FilmLibrary.h"
#include<algorithm>

using namespace std;

FilmLibrary::FilmLibrary()
{

}
FilmLibrary::FilmLibrary(const FilmLibrary& FL)
{
	*this = FL;
}

void FilmLibrary::addFilm(const Film& film)
{
	string name = film.getName();
	Date date = film.getDate();
	int year = date.getYear();
	pair<string, int> key;
	key = make_pair(name, year);
	FilmLib[key] = film;
}

void FilmLibrary::deleteFilm(const string& name, const int& year)
{
	pair<string, int> key;
	key = make_pair(name, year);
	FilmLib.erase(key);
}

bool FilmLibrary::changeNameFilm(const string& name_to_change,const int& year, const string& new_name)
{
	map<pair<string, int>, Film> ::iterator it;
	pair<string, int> key;
	key = make_pair(name_to_change, year);
	it = FilmLib.find(key);
	if (it != FilmLib.end())
	{
		Film film = FilmLib[key];
		FilmLib.erase(key);
		film.setName(new_name);
		this->addFilm(film);
		return true;
	}
	return false;
}

void FilmLibrary::changeDataFilm(const string& name, const int& year, const Film& film)
{
	pair<string, int> key;
	key = make_pair(name, year);
	FilmLib.erase(key);
	this->addFilm(film);
}

Film FilmLibrary::getDataFilm(const string& name, const int& year) const
{
	map<pair<string, int>, Film> :: const_iterator it;
	pair<string, int> key;
	key = make_pair(name, year);
	it = FilmLib.find(key);
	if (it != FilmLib.end())
	{
		Film film;
		film = it->second;// film = FilmLib[key] - нельзя, видимо из-за const в определении функции
		return film;
	}
	throw MyExc(exType0,"Has No Inforamtion");
}

vector<Film> FilmLibrary::allProducerFilm(const string& producer)
{
	map<pair<string, int>, Film> ::iterator it;
	vector<Film> list;
	it = FilmLib.begin();
	for (it; it != FilmLib.end(); it++)
	{
		if (it->second.getProducer() == producer)
		{
			list.push_back(it->second);
		}
	}
	return list;
}

vector<Film> FilmLibrary::allYearFilm(const int& year)
{
	map<pair<string, int>, Film> ::iterator it;
	vector<Film> list;
	it = FilmLib.begin();
	for (it; it != FilmLib.end(); it++)
	{
		if (it->first.second == year)//first.second - year в ключе
		{
			list.push_back(it->second);
		}
	}
	return list;
}

bool comporator(Film f1, Film f2)// компоратор для maxValue
{
	if(f1.getValue()!=f2.getValue())
		return f1.getValue() > f2.getValue();
	return f1.getName() >= f2.getName();
}

vector<Film> FilmLibrary::maxValue(const int& count)
{
	map<pair<string, int>, Film> ::iterator it;
	vector<Film> list;
	it = FilmLib.begin();
	for (it; it != FilmLib.end(); it++)
	{
		list.push_back(it->second);
	}
	sort(list.begin(), list.end(), comporator);//отсортировал по убыванию
	if (list.size() > count)
		list.resize(count);// убрать лишние элементы, если они есть
	return list;
}

vector<Film> FilmLibrary::maxValueSelectedYear(const int& count, const int& year)
{
	map<pair<string, int>, Film> ::iterator it;
	vector<Film> list;
	it = FilmLib.begin();
	for (it; it != FilmLib.end(); it++)
	{
		if (it->first.second == year)
			list.push_back(it->second);
	}
	sort(list.begin(), list.end(), comporator);//отсортировал по убыванию
	if (list.size() > count)
		list.resize(count);// убрать лишние элементы, если они есть
	return list;
}

size_t FilmLibrary::getCount()const
{
	return FilmLib.size();
}

FilmLibrary& FilmLibrary:: operator=(const FilmLibrary& FL)
{
	if (this == &FL)
		return *this;
	FilmLib = FL.FilmLib;
	return *this;
}

ostream& operator<<(ostream& stream, const FilmLibrary& FL)
{
	int k = 0;//все ли элементы вывелись
	stream << FL.getCount() << "\n";
	map<pair<string, int>, Film> ::const_iterator it = FL.FilmLib.cbegin();
	map<pair<string, int>, Film> ::const_iterator it1 = FL.FilmLib.cend();
	for (it; it != it1; it++)
	{
		stream << it->second;
	}
	return stream;
}

istream& operator>>(istream& stream, FilmLibrary& FL)
{
	int k;
	stream >> k;
	Film film;
	for (int i = 0; i < k; i++)
	{
		stream >> film;
		FL.addFilm(film);
	}
	return stream;
}