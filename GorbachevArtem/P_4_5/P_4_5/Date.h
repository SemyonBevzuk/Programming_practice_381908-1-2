#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;

	friend ostream& operator<<(ostream& out, const Date& D);
	friend istream& operator>>(istream& in, Date& D);
	friend ofstream& operator<<(ofstream& out, const Date& D);
	friend ifstream& operator>>(ifstream& in, Date& D);
};

inline ostream & operator<<(ostream & out, const Date & D)
{
	out << D.day << "." << D.month << "." << D.year;
	return out;
}

inline istream & operator>>(istream & in, Date & D)
{
	char s;
	in >> D.day >> s >> D.month >> s >> D.year;
	return in;
}

inline ofstream& operator<<(ofstream& out, const Date& D)
{
	out << D.day << "." << D.month << "." << D.year;
	return out;
}

inline ifstream& operator>>(ifstream& in, Date& D)
{
	char s;
	in >> D.day >> s >> D.month >> s >> D.year;
	return in;
}