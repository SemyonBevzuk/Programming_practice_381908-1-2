#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Date
{
public:
	int day;
	int month;
	Date() :day(0), month(0) {}
	Date(int, int);
	Date& operator=(const Date&);
	bool operator==(const Date&)const;
	bool operator<(const Date&)const;
	Date& operator+=(const Date&);
	friend ifstream& operator>>(ifstream&, Date&);
	friend ofstream& operator<<(ofstream&, const Date&);
	~Date() {}
};