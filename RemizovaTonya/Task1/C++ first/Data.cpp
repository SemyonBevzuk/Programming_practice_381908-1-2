#include "Data.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
Data::Data():Data(1, 1, 1970 )
{
	//Установленная
}

Data::Data(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}

Data::Data(const Data& _c)
{
	day = _c.day;
	month = _c.month;
	year = _c.year;
}

Data::Data(string _stroka)
{
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int m1[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	{
		string FullDate = "";
		FullDate += _stroka[0];
		FullDate += _stroka[1];
		day = atoi(FullDate.c_str());
		FullDate = "";
		FullDate += _stroka[3];
		FullDate += _stroka[4];
		month = atoi(FullDate.c_str());
		FullDate = "";
		FullDate += _stroka[6];
		FullDate += _stroka[7];
		FullDate += _stroka[8];
		FullDate += _stroka[9];
		year = atoi(FullDate.c_str());
	}
	if (((year % 100 % 4 == 0) && (year / 1000 > 0) && (0 < month <= 12) && (0 < day <= m1[month])) ||
		((year % 100 % 4 != 0) && (year / 1000 > 0) && (0 < month <= 12) && (0 < day <= m[month])))
		Print();
	else cout << "INVALID date" << endl;
}

void Data::Print()
{
	if (day < 10)
		cout << "0";
	cout << day << ".";
	if (month < 10)
		cout << "0";
	cout << month << ".";
	cout << year << endl;
}

Data const Data::operator+(int n)
{
	Data number;
	
	cout << "day ";
	cin >> number.day;
	cout << "month ";
	cin >> number.month;
	cout << "year ";
	cin >> number.year;
	if (number.day == 0 || number.month == 0 || number.year == 0 || number.year < 1000)
		cout << "Date entered incorrectly";
	cout << "Your date is :";
	number.Print();
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int m1[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 }; //Високосный год
	int k = 0; //Перевод введенной даты в дни
	int p = 0, a = 0;
	if (number.year % 100 % 4 == 0)
	{
		for (int i = 0; i < number.month; i++)
			k = k + m1[i]; //Какое количество дней прошло с начала високосного года
		k = k + number.day + n; //Сумма введенного дня, месяца и количества прибавленных дней
		cout << "New date is: ";
		if (k <= 365)
		{
			for (int i = 0; i < 12; i++)
			{
				p = k - m1[i]; // Выделение количества дней
				if (p <= m1[i + 1])
				{
					a = i + 1; // Выделение количества месяцев
					break;
				}
				else k = p;
			}
			cout << p << "." << a << "." << number.year << endl;
		}
		else
		{
			do
			{
				if (number.year % 100 % 4 == 0)
					k = k - 366;
				else
					k = k - 365;
				number.year++;
			} while (k >= 365);
			for (int i = 0; i < 12; i++)
			{
				p = k - m1[i]; // Выделение количества дней
				if (p <= m1[i + 1])
				{
					a = i + 1; // Выделение количества месяцев
					break;
				}
				else k = p;
			}
			cout << p << "." << a << "." << number.year << endl;
		}
	}
	else
	{
		for (int i = 0; i < number.month; i++)
			k = k + m[i]; //Какое количество дней прошло с начала обычного года
		k = k + number.day + n; //Сумма введенного дня, месяца и количества прибавленных дней
		cout << "New date is: ";
		if (k <= 365)
		{
			for (int i = 0; i < 12; i++)
			{
				p = k - m[i]; // Выделение количества дней
				if (p <= m[i + 1])
				{
					a = i + 1; // Выделение количества месяцев
					break;
				}
				else k = p;
			}
			cout << p << "." << a << "." << number.year << endl;
		}
		else
		{
			do
			{
				if (number.year % 100 % 4 == 0)
					k = k - 366;
				else
					k = k - 365;
				number.year++;
			} while (k >= 365);
			for (int i = 0; i < 12; i++)
			{
				p = k - m[i]; // Выделение количества дней
				if (p <= m[i + 1])
				{
					a = i + 1; // Выделение количества месяцев
					break;
				}
				else k = p;
			}
			cout << p << "." << a << "." << number.year << endl;
		}
	}
	return number;
}
Data const Data::operator-(int n)
{
	Data number;

	cout << "day ";
	cin >> number.day;
	cout << "month ";
	cin >> number.month;
	cout << "year ";
	cin >> number.year;
	if (number.day == 0 || number.month == 0 || number.year == 0 || number.year < 1970)
		cout << "Date entered incorrectly";
	cout << "Your date is :";
	number.Print();
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int m1[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 }; //Високосный год
	int k = 0; //Перевод введенной даты в дни
	int p = 0; // days
	int	a = 0; // month
	int	d = 0; // years
	int l = number.year - 1; //Исключаем тот год, который ввели
	while (l >= 1970)
	{
		if (l % 100 % 4 == 0)
			d = d + 366;
		else
			d = d + 365;
		l--;
	}
	l++;

	if (number.year % 100 % 4 == 0)
	{
		for (int i = 0; i < number.month; i++)
			k = k + m1[i]; //Какое количество дней прошло с начала високосного года
	}
	else
	{
		for (int i = 0; i < number.month; i++)
			k = k + m[i]; //Какое количество дней прошло с начала високосного года
	}
	k = k + number.day + d - 1; //Количество дней начиная с 01.01.1970

	if (n <= k)
	{
		cout << "New date is: ";
		k = k - n + 1;
		if (k <= 365)
		{
			if (l % 100 % 4 == 0)
			{
				for (int i = 0; i < 12; i++)
				{
					p = k - m1[i];// Выделение количества дней
					if (p <= m1[i + 1])
					{
						a = i + 1; // Выделение количества месяцев
						break;
					}
					else k = p;
				}
				cout << p << "." << a << "." << l << endl;
			}
			else
			{
				for (int i = 0; i < 12; i++)
				{
					p = k - m[i];// Выделение количества дней
					if (p <= m[i + 1])
					{
						a = i + 1; // Выделение количества месяцев
						break;
					}
					else k = p;
				}
				cout << p << "." << a << "." << l << endl;
			}
		}
		else // if k>365
		{
			do
			{
				if (l % 100 % 4 == 0)
					k = k - 366;
				else
					k = k - 365;
				l++;
			} while (k >= 365);

			if (l % 100 % 4 == 0)
			{
				for (int i = 0; i < 12; i++)
				{
					p = k - m1[i];// Выделение количества дней
					if (p <= m1[i + 1])
					{
						a = i + 1; // Выделение количества месяцев
						break;
					}
					else k = p;
				}
				cout << p << "." << a << "." << l << endl;
			}
			else
			{
				for (int i = 0; i < 12; i++)
				{
					p = k - m[i];// Выделение количества дней
					if (p <= m[i + 1])
					{
						a = i + 1; // Выделение количества месяцев
						break;
					}
					else k = p;
				}
				cout << p << "." << a << "." << l << endl;
			}
		}
	}
	else cout << "ERROR";
	return number;
}
bool operator==(const Data& c1, const Data& c2)
{
	return (c1.day == c2.day && c1.month == c2.month && c1.year == c2.year);
}
bool operator!=(const Data& c1, const Data& c2)
{
	return !(c1 == c2);
}
bool operator>(const Data& c1, const Data& c2)
{
	if (c1.year > c2.year)
		return true;
	else
	{
		if (c1.month > c2.month)
			return true;
		else
		{
			if (c1.day > c2.day)
				return true;
			else
				return false;
		}
	}
}

bool operator<(const Data & c1, const Data & c2)
{
	return !(c1 > c2);
}
istream& operator>> (istream& stream, Data c)
{
	stream >> c.day >> c.month >> c.year;
	return stream;
}
ostream& operator<< (ostream& stream, const Data& c)
{
    stream <<"Date:"<< c.day <<"."<< c.month <<"."<< c.year;
	return stream;
}