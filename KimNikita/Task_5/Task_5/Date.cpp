#include "Date.h"

Date::Date(int d, int m)
{
	if (m > 12 || m < 1)
		throw exception("Некорректный месяц");
	else
		month = m;
	if (d < 1 || d>31 || d > 29 && month == 2)
		throw exception("Некорректный день");
	else
		day = d;
}
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		day = d.day;
		month = d.month;
	}
	return *this;
}
bool Date::operator==(const Date& d)const
{
	if (d.month == month && d.day == day)
		return true;
	return false;
}
bool Date::operator<(const Date& d)const
{
	if (d.month < month)
		return true;
	else
		if (d.month == month)
			if (d.day < day)
				return true;
	return false;
}
Date& Date::operator+=(const Date& d)
{
	day += d.day;
	if (month == 2 && day > 29)
	{
		day %= 30;
		month++;
	}
	if ((month % 2 == 1 || month == 8 || month == 10 || month == 12) && day > 31)
	{
		day %= 32;
		month++;
	}
	if ((month % 2 == 0 || month != 8 || month != 10 || month != 12) && day > 30)
	{
		day %= 31;
		month++;
	}
	return *this;
}
ifstream& operator>>(ifstream& in, Date& date)
{
	int d, m;
	in >> d >> m;
	date = Date(d, m);
	return in;
}
ofstream& operator<<(ofstream& out, const Date& d)
{
	out << d.day << ' ' << d.month << endl;
	return out;
}