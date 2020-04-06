#include"Date.h"

Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

Date::Date(const Date& date)
{
	*this = date;
}

 string Date::getDateToString () const
{
	string sd = to_string(_day), sm = to_string(_month), sy = to_string(_year);
	return sd + "." + sm + "." + sy;
}


bool Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
	{
		_day = d;
		return true;
	}
	return false;
}

bool Date::setMonth(int m)
{
	if (m>= 1 && m <=12)
	{
		_month = m;
		return true;
	}
	return false;
}

bool Date::setYear(int y)
{
	if (y > 0 )
	{
		_year = y;
		return true;
	}
	return false;
}

bool Date::setDate(int day, int month, int year)
{
	bool res;
	res=this->setDay(day);
	res=this->setMonth(month);
	res=this->setYear(year);
	return res;
}

Date& Date:: operator=(const Date& date)
{
	if (this == &date)
		return *this;
	_day = date._day;
	_month = date._month;
	_year = date._year;
	return *this;
}