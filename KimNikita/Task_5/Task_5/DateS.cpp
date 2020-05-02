#include "DateS.h"

DateS::DateS(int d, int m)
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
DateS& DateS::operator=(const DateS& d)
{
	if (this != &d)
	{
		day = d.day;
		month = d.month;
	}
	return *this;
}
bool DateS::operator==(const DateS& d)const
{
	if (d.month == month && d.day == day)
		return true;
	return false;
}
bool DateS::operator<(const DateS& d)const
{
	if (month < d.month)
		return true;
	else
		if (month == d.month)
			if (day < d.day)
				return true;
	return false;
}
DateS& DateS::operator+=(const DateS& d)
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
ifstream& operator>>(ifstream& in, DateS& date)
{
	int d, m;
	in >> d >> m;
	date = DateS(d, m);
	return in;
}
ofstream& operator<<(ofstream& out, const DateS& d)
{
	out << d.day << ' ' << d.month << endl;
	return out;
}