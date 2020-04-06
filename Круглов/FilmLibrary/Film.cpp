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