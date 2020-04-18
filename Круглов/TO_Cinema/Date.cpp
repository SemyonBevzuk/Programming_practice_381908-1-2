#include"Date.h"

Date::Date(int day, int month, int year)
{
	if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	else
		throw "Date Initialization error";
}

Date::Date(const Date& date)
{
	*this = date;
}

string Date::getDateToString() const
{
	string sday = to_string(_day);
	if (sday.size() == 1)
		sday = "0" + sday;
	string smonth = to_string(_month);
	if (smonth.size() == 1)
		smonth = "0" + smonth;
	string syear = to_string(_year);
	for (auto i = syear.size(); i < 4; i++)
		syear = "0" + syear;
	return sday + "." + smonth + "." + syear;
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
	if (m >= 1 && m <= 12)
	{
		_month = m;
		return true;
	}
	return false;
}

bool Date::setYear(int y)
{
	if (y > 0)
	{
		_year = y;
		return true;
	}
	return false;
}

bool Date::setDate(int day, int month, int year)
{
	bool res;
	res = this->setDay(day);
	res = this->setMonth(month);
	res = this->setYear(year);
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

bool Date::operator==(const Date& date) const {
	return(_day == date._day && _month == date._month && _year == date._year);
}

bool Date::operator<=(const Date& date) const {
	if (_year < date._year)
		return true;
	if (_year == date._year) {
		if (_month < date._month)
			return true;
		if (_month == date._month)
			if (_day <= date._day)
				return true;
		else
			return false;
	}
	else 
		return false;
}