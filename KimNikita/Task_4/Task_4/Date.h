#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date {
public:
	int day;
	int month;
	int year;
	Date() :day(0), month(0), year(1894) {}//первый фильм вышел в 1895
	void PrintDate()
	{
		string s;
		if (day < 10)
			s += '0';
		s += to_string(day) + '.';
		if (month < 10)
			s += '0';
		s += to_string(month) + '.';
		s += to_string(year);
		cout << s << endl;
	}
	~Date() {}
};