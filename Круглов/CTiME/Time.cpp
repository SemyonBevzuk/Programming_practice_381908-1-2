#include "Time.h"

using namespace std;

// Конструкторы и деструкторы ----------------------------------------------------------------------
Time::Time()
{
	hour = min = sec = 0;
}
Time::Time(const Time& _d)
{
	hour = _d.hour;
	min = _d.min;
	sec = _d.sec;
}
Time::Time(int _hour, int _min, int _sec)
{
	hour = _hour;
	min = _min;
	sec = _sec;
}

Time::Time(string s)
{
	int i = 0;
	hour = (s[0] - '0') * 10 + (s[1] - '0');
	min = (s[3] - '0') * 10 + (s[4] - '0');
	sec = (s[6] - '0') * 10 + (s[7] - '0');
}

Time::~Time()
{
	hour = min = sec = 0;
}

//Установление и возвращение значений ----------------------------------------------------------------------
void Time::setHour(int _hour)
{
	hour = _hour;
}

void Time::setMin(int _min)
{
	min = _min;
}

void Time::setSec(int _sec)
{
	sec = _sec;
}

void Time::setTime(int _hour, int _min, int _sec)
{
	hour = _hour;
	sec = _sec;
	min = _min;
}

Time Time::getTime()
{
	Time res;
	res.hour = hour;
	res.min = min;
	res.sec = sec;
	return res;
}

// Присваивание ------------------------------------------------------------------------------
Time& Time::operator=(const Time& _d)
{
	hour = _d.hour;
	min = _d.min;
	sec = _d.sec;
	return *this;
}

//арифметические операции ---------------------------------------------------------------------

Time Time::operator+(const Time& _d)
{
	Time res;
	if (sec + _d.sec >= 60)//переполнение секунд
		min++;
	res.sec = (sec + _d.sec) % 60;//подсчёт секунд

	if (min + _d.min >= 60)//переполнение минут
		hour++;
	res.min = (min + _d.min) % 60; //подсчёт минут

	res.hour = (hour + _d.hour) % 24;// подсчёт часов
	return res;
}

Time Time::operator+(string s)
{
	Time res, _d(s);

	if (sec + _d.sec >= 60)//переполнение секунд
		min++;
	res.sec = (sec + _d.sec) % 60;//подсчёт секунд

	if (min + _d.min >= 60)//переполнение минут
		hour++;
	res.min = (min + _d.min) % 60; //подсчёт минут

	res.hour = (hour + _d.hour) % 24;// подсчёт часов
	return res;
}

//Time Time::operator-(const Time& _d)
//{
//	Time res;
//	if (sec < _d.sec)
//	{
//		min--;
//		res.sec = 60 + sec - _d.sec;
//	}
//	else
//		res.sec = sec - _d.sec;
//
//	if (min < _d.min)
//	{
//		hour--;
//		res.min = 60 + min - _d.min;
//	}
//	else
//		res.min = min - _d.min;
//
//	if (hour < _d.hour)
//	{
//		res.hour = 24 + hour - _d.hour;
//	}
//	else
//		res.hour = hour - _d.hour;
//	return res;
//}
//
//Time Time:: operator-(string s)
//{
//	Time res, _d(s);
//	if (sec < _d.sec)
//	{
//		min--;
//		res.sec = 60 + sec - _d.sec;
//	}
//	else
//		res.sec = sec - _d.sec;
//
//	if (min < _d.min)
//	{
//		hour--;
//		res.min = 60 + min - _d.min;
//	}
//	else
//		res.min = min - _d.min;
//
//	if (hour < _d.hour)
//	{
//		res.hour = 24 + hour - _d.hour;
//	}
//	else
//		res.hour = hour - _d.hour;
//	return res;
//}

Time Time::operator*(const Time& _d)
{
	Time res;
	res.sec = sec * _d.sec;//
	res.min += res.sec / 60;//
	res.sec %= 60;//
	res.min += min * _d.min;
	res.hour += res.min / 60;
	res.min %= 60;
	res.hour += (hour * _d.hour) % 24;
	return res;
}

Time Time::operator*(string s)
{
	Time res, _d(s);
	res.sec = sec * _d.sec;//
	res.min += res.sec / 60;//
	res.sec %= 60;//
	res.min += min * _d.min;
	res.hour += res.min / 60;
	res.min %= 60;
	res.hour += (hour * _d.hour) % 24;
	return res;
}

Time Time::addSec(int _sec)
{
	sec += _sec;
	if (sec >= 60)
	{
		min += sec / 60;
		sec %= 60;
	}
	if (min >= 60)
	{
		hour += min / 60;
		min %= 60;
	}
	hour %= 24;
	return *this;
}

Time Time::addMin(int _min)
{
	min += _min;
	if (min >= 60)
	{
		hour += min / 60;
		min %= 60;
	}
	hour %= 24;
	return *this;
}

Time Time::addHour(int _hour)
{
	hour += _hour;
	hour %= 24;
	return *this;
}


//Ввод и вывод -------------------------------------------------------------------------------------
void Time::outPut()
{
	cout << hour << ":" << min << ":" << sec;
}
void Time::inPut()
{
	cout << "Введите часы: ";
	cin >> hour;
	cout << "Введите минуты: ";
	cin >> min;
	cout << "Введите секунды: ";
	cin >> sec;
}

ostream& operator<<(ostream& stream, const Time& _d)
{
	stream << _d.hour << " " << _d.min << " " << _d.sec << endl;
	return stream;
}

istream& operator>>(istream& stream, Time& _d)
{
	stream >> _d.hour >> _d.min >> _d.sec;
	return stream;
}

//Сравнивание ----------------------------------------------------------
bool Time::operator==(const Time& _d)
{
	bool res;
	res = (hour == _d.hour && min == _d.min && sec == _d.sec);
	return res;
}