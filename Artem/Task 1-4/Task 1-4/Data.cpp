#include"Data.h"

Data::Data() :Data(1, 1, 2001) {}

/*Data::Data(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}*/

Data::Data(const Data& _date)
{
	day = _date.day;
	month = _date.month;
	year = _date.year;
}

Data::Data(string _date)
{
	string FullDate = "";
	FullDate += _date[0];
	FullDate += _date[1];
	day = atoi(FullDate.c_str());
	FullDate = "";
	FullDate += _date[3];
	FullDate += _date[4];
	month = atoi(FullDate.c_str());
	FullDate = "";
	FullDate += _date[6];
	FullDate += _date[7];
	FullDate += _date[8];
	FullDate += _date[9];
	year = atoi(FullDate.c_str());
}


bool Data::leap(int y)const
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}
int Data::maxday()const
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leapyear)days[1] = 29;
	return days[month-1];
}

Data& Data::operator=(const Data& date)
{
	year = date.year;
	month = date.month;
	day = date.day;
	return *this;
}

Data& Data::operator+=(int d)
{
	if (day + d > maxday())
	{
		d -= maxday() - day;
		if (++month > 12)
		{
			month = 1;
			year++;
		}
		while (d / maxday())
		{
			if (++month > 12)
			{
				month = 1;
				year++;
			}
			d -= maxday();
		}
		day = d;
	}
	else
		day += d;
	return *this;
}

Data& Data::operator-=(int d)
{
	if (day - d < 1)
	{
		d -= day;
		if (--month == 0)
		{
			month = 12;
			year--;
		}
		while (d / maxday())
		{
			d -= maxday();
			if (--month == 0)
			{
				month = 12;
				year--;
			}
		}
		day = maxday() - d;
	}
	else day -= d;
	return *this;
}

bool Data::operator>(const Data& date)
{
	return ((year > date.year) || (year == date.year) && (month > date.month) || (year == date.year) && (month == date.month) && (day > date.day)) ? true : false;
}

bool Data::operator<(const Data& date)
{
	return ((year < date.year) || (year == date.year) && (month < date.month) || (year == date.year) && (month == date.month) && (day < date.day)) ? true : false;
}

bool Data::operator>=(const Data& date)
{
	return ((year >= date.year) || (year == date.year) && (month >= date.month) || (year == date.year) && (month == date.month) && (day >= date.day)) ? true : false;
}
bool Data::operator<=(const Data& date)
{
	return ((year <= date.year) || (year == date.year) && (month <= date.month) || (year == date.year) && (month == date.month) && (day <= date.day)) ? true : false;
}

bool Data::operator==(const Data& date) {
	return ((year == date.year) && (month == date.month) && (day == date.day)) ? true : false;
}

bool Data::operator!=(const Data& date) {
	return !(*this == date);
}


istream& operator>> (istream& stream, Data& date)
{
	stream >> date.day >> date.month >> date.year;

	while (((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) && date.day > 31) ||
		((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30) ||
		(date.month == 2 && date.day > 28 && !date.leapyear) ||
		(date.month == 2 && date.day > 29 && date.leapyear)||
		date.month>12|| date.month<0)
	{
		cout << "Error. Try again: ";
		stream >> date.day >> date.month >> date.year;
	}

	return stream;
}

ostream& operator<<(ostream& stream, Data date)
{
	stream << "Date: " << date.day << "." << date.month << "." << date.year << endl;
	return stream;
}

Data::~Data() {}