#include "Film.h"
using namespace std;

// По умолчанию
Film::Film()
{
	name = "";
	producer = "";
	screenwriter = "";
	composer = "";
	day = mount = year = 0;
	fundraising = 0;
}

// Копирование
Film::Film(const Film& film)
{
	*this = film;
}

// Деструктор
Film::~Film()
{
	name = "";
	producer = "";
	screenwriter = "";
	composer = "";
	day = mount = year = 0;
	fundraising = 0;
}

// Присваивание
Film& Film::operator=(const Film& film)
{
	name = film.name;
	producer = film.producer;
	screenwriter = film.screenwriter;
	composer = film.composer;
	day = film.day;
	mount = film.mount;
	year = film.year;
	fundraising = film.fundraising;
	return *this;
}

// Заполнение информации о фильме
void Film::UpdateFilm(const string _name, const string _producer, const string _screenwriter,
	const string _composer, const int _day, const int _mount, const int _year, const ll _fundraising)
{
	name = _name;
	producer = _producer;
	screenwriter = _screenwriter;
	composer = _composer;
	day = _day;
	mount = _mount;
	year = _year;
	fundraising = _fundraising;
}

// Инициализация
Film::Film(const string _name, const string _producer, const string _screenwriter,
	const string _composer, const int _day, const int _mount, const int _year, const ll _fundraising)
{
	this->UpdateFilm(_name, _producer, _screenwriter, _composer, _day, _mount, _year, _fundraising);
}

// Считывание строки
string readString(const string comment)
{
	string str;
	cout << comment << ": ";
	getline(cin, str);
	return str;
}

// Изменение числовой информации в фильме (если строка не пуста)
ll UpdateNumber(const ll num, const string comment)
{
	string str = readString(comment);
	if (str != "")
		return stoll(str);
	return num;
}

// Изменение текстовой информации о фильме (если строка не пуста)
string UpdateString(const string str, const string comment)
{
	string newStr = readString(comment);
	if (newStr != "")
		return newStr;
	return str;
}

// Считывание информации о фильме с консоли
Film& Film::Read()
{
	name = UpdateString(name, "Название");
	producer = UpdateString(producer, "Режиссёр");
	screenwriter = UpdateString(screenwriter, "Сценарист");
	composer = UpdateString(composer, "Композитор");
	day = (int)UpdateNumber(day, "День выхода");
	mount = (int)UpdateNumber(mount, "Месяц выхода");
	year = (int)UpdateNumber(year, "Год выхода");
	fundraising = UpdateNumber(fundraising, "Сборы");
	return *this;
}

// Вывод информации о фильме в консоль
bool Film::Write()
{
	if (name == "")
		return false;
	cout << "Название:    " << name << "\nРежиссер:    " << producer
		<< "\nСценарист:   " << screenwriter << "\nКомпозитор:  " << composer
		<< "\nДата выхода: " << day << "." << mount << "." << year
		<< "\nСборы:       " << fundraising << "р.\n";
	return true;
}

bool Film::operator!=(const Film& film)
{
	if (name == film.name || producer == film.producer || screenwriter == film.screenwriter || composer == film.composer
		|| day == film.day || mount == film.mount || year == film.year || fundraising == film.fundraising) return false;
	return true;
}

// swap фильмов
void swap(Film& f1, Film& f2)
{
	Film tmp = f1;
	f1 = f2;
	f2 = tmp;
}

// Считывание информации о фильме с файла
istream& operator>> (istream& stream, Film& film)
{
	getline(stream, film.name);
	getline(stream, film.producer);
	getline(stream, film.screenwriter);
	getline(stream, film.composer);
	stream >> film.day >> film.mount >> film.year >> film.fundraising;
	return stream;
}

// Вывод информации о фильме в файл
ostream& operator<< (ostream& stream, const Film& film)
{
	stream << film.name << endl << film.producer
		<< endl << film.screenwriter << endl << film.composer
		<< endl << film.day << ' ' << film.mount << ' ' << film.year
		<< ' ' << film.fundraising << endl;
	return stream;
}
