#include "ClassDate.h"
#include <cstdlib>
#include<cstdio>
#include <clocale>
#include <iostream>

using namespace std;


Date::Date()// конструктор
{
	d = 0;
	m = 0;
	y = 0;
}

Date Date::TRS(string TRSdate)
{
	Date r;
	string FD = "";
	FD += TRSdate[0];
	FD += TRSdate[1];
	r.d = atoi(FD.c_str());
	FD = "";
	FD += TRSdate[3];
	FD += TRSdate[4];
	r.m = atoi(FD.c_str());
	FD = "";
	FD += TRSdate[6];
	FD += TRSdate[7];
	FD += TRSdate[8];
	FD += TRSdate[9];
	r.y = atoi(FD.c_str());
	return r;
}




Date Date::Plus (const Date& dt,int dp)
{
	Date r;
	r = dt;
	while (dp > 0)
	{
		if ((r.d == 0) || (r.m == 0))
		{
			cout << "Ошибка ввода";
			break;
		}
		r.d = r.d + 1;
		dp = dp - 1;
		if ((r.d == 32) && ((r.m == 1) || (r.m == 3) || (r.m == 5) || (r.m == 7) || (r.m == 8) || (r.m == 10) || (r.m == 12)))
		{
			r.d = 1;
			r.m = r.m + 1;
		}
		if ((r.d == 31) && ((r.m == 4) || (r.m == 6) || (r.m == 9) || (r.m == 11)))
		{
			r.d = 1;
			r.m = r.m + 1;
		}
		if ((r.d == 30) && (r.m == 2) && (r.y % 4 == 0))
		{
			r.d = 1;
			r.m = r.m + 1;
		}
		if ((r.d == 29) && (r.m == 2) && (r.y % 4 != 0))
		{
			r.d = 1;
			r.m = r.m + 1;
		}
		if (r.m == 13)
		{
			r.m = 1;
			r.y = r.y + 1;
		}
	}
	return r;
}

Date Date::Minus(const Date& dt, int dm)
{
	Date r;
	r = dt;
	while (dm > 0)
	{
		if ((r.d == 0) || (r.m == 0))
		{
			cout << "Ошибка ввода";
			break;
		}
		r.d = r.d - 1;
		dm = dm - 1;
		if ((r.d == 0) && ((r.m == 5) || (r.m == 7) || (r.m == 10) || (r.m == 12)))
		{
			r.d = 30;
			r.m = r.m - 1;
		}
		if ((r.d == 0) && ((r.m == 4) || (r.m == 6) || (r.m == 8) ||(r.m == 9) || (r.m == 11) || (r.m == 1)||(r.m == 2)))
		{
			r.d = 31;
			r.m = r.m - 1;
		}
		if ((r.d == 0) && (r.m == 3) && (r.y % 4 == 0))
		{
			r.d = 29;
			r.m = r.m - 1;
		}
		if ((r.d == 0) && (r.m == 3) && (r.y % 4 != 0))
		{
			r.d = 28;
			r.m = r.m - 1;
		}
		if (r.m == 0)
		{
			r.m = 12;
			r.y = r.y - 1;
		}
		if (r.y < 0)
			cout << "Ошибка 2 : нет работы с годами до нашей эры";
	}
	return r;
}

Date Date::operator= (const Date& dt)
{
	
	d = dt.d;
	m = dt.m;
	y = dt.y;
	return *this;
}

void Date::Comparsion(const Date& dt1)
{
	if (dt1.y < y)
	{
		cout << "Дата 1 была раньше, чем дата 2\n";
		return;
	}
	if ((dt1.y == y) && (dt1.m < m))
	{
		cout << "Дата 1 была раньше, чем дата 2\n";
		return;
	}
	if ((dt1.y == y) && (dt1.m == m) && (dt1.d < d))
	{
		cout << "Дата 1 была раньше, чем дата 2\n";
		return;
	}
	if (dt1.y > y)
	{
		cout << "Дата 2 была раньше, чем дата 1\n";
		return;
	}
	if ((dt1.y == y) && (dt1.m > m))
	{
		cout << "Дата 2 была раньше, чем дата 1\n";
		return;
	}
	if ((dt1.y == y) && (dt1.m == m) && (dt1.d > d))
	{
		cout << "Дата 2 была раньше, чем дата 1\n";
		return;
	}
	if ((dt1.y == y) && (dt1.m == m) && (dt1.d == d))
	{
		cout << "Даты одинаковые\n";
		return;
	}
}
	

istream& operator>> (istream& stream, Date& dt)
{
	stream >> dt.d >> dt.m >> dt.y;
	return stream;
}

ostream& operator<< (ostream& stream, const Date& dt)
{
	stream << dt.d <<"."<< dt.m <<"."<< dt.y <<endl;
	return stream;
}

