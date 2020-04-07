#include "Film.h"

using namespace std;

Film::Film(string name, string producer, string screenwriter, string composer, Date date, long long value)
{
	_name = name;
	_producer = producer;
	_screenwriter = screenwriter;
	_composer = composer;
	_date = date;
	_value = value;
}

void Film::setName(string name)
{
	_name = name;
}

void Film::setProducer(string producer)
{
	_producer = producer;
}

void Film::setScreenwriter(string screenwriter)
{
	_screenwriter = screenwriter;
}

void Film::setComposer(string composer)
{
	_composer = composer;
}

bool Film::setValue(long long value)
{
	if (value > -1)
	{
		_value = value;
		return true;
	}
	return false;
}

Film& Film:: operator=(const Film& f)
{
	if (this == &f)
		return *this;
	_name = f._name;
	_producer = f._producer;
	_screenwriter = f._screenwriter;
	_composer = f._composer;
	_date = f._date;
	_value = f._value;
	return *this;
}

ostream& operator<<(ostream& stream, const Film& film)
{
	stream << "Название фильма: " << film.getName() << "\n"
		<< "Продюсер: " << film.getProducer() << "\n"
		<< "Сценарист: " << film.getScreenwriter() << "\n"
		<< "Композитор: " << film.getComposer() << "\n"
		<< "Дата выхода: " << film.getDateToString() << "\n"
		<< "Кассовые сборы: " << film.getValue() << " млн$\n";
	return stream;
}

istream& operator>>(istream& stream, Film& film)// она работает, честно, в main пример есть)
{
	string arr[20];
	string name, producer, screenwriter, composer, sdate, svalue;
	stream >> arr[0] >> arr[1] >> name >>
		arr[3] >> producer >>
		arr[4] >> screenwriter >>
		arr[5] >> composer >>
		arr[6] >> arr[7] >> sdate >>
		arr[8] >> arr[9] >> svalue;
	int day, month, year, value=0;
	day = (sdate[0] - '0') * 10 + (sdate[1] - '0');
	month = (sdate[3] - '0') * 10 + (sdate[4] - '0');
	year = (sdate[6] - '0') * 1000 + (sdate[7] - '0') * 100 + (sdate[8] - '0') * 10 + (sdate[9] - '0');
	Date date(day, month, year);
	int k = 1;
	for (int i = 0; i < svalue.size(); i++)// atoi работает только с С-строками
	{
		value += (svalue[svalue.size() - 1 - i] - '0') * k;
		k *= 10;
	}
	Film res(name, producer, screenwriter, composer, date, value);
	film = res;
	return stream;

}