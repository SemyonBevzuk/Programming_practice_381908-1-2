#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class DateS
{
public:
	int day;
	int month;
	DateS() :day(0), month(0) {}
	DateS(int, int);
	DateS& operator=(const DateS&);
	bool operator==(const DateS&)const;
	bool operator<(const DateS&)const;
	DateS& operator+=(const DateS&);
	friend ifstream& operator>>(ifstream&, DateS&);
	friend ofstream& operator<<(ofstream&, const DateS&);
	~DateS() {}
};