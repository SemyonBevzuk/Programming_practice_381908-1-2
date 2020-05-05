#pragma once
#include <iostream>
#include <fstream>
using namespace std;

extern int Days1[12];
class Time {
public:
	int h;
	int m;
	Time();
	Time(const Time& t);
	Time(const int& hr, const int& min);
	int get_h();
	int get_m();
	Time& operator=(const Time& t);
	Time operator+(const Time& t);
	Time operator-(const Time& t);
	bool operator<(const Time& a);
	bool operator>(const Time& a);
	bool operator>(Time& a) const;
	bool operator<=(const Time& a);
	bool operator>=(const Time& a);
	bool operator==(const Time& a);
	bool operator!=(const Time& a);
	Time& operator+=(const Time& a);
	Time& operator-=(const Time& a);
	friend istream& operator>>(istream& in, Time& a);
	friend ostream& operator<<(ostream& out, const Time& a);
	friend ifstream& operator>>(ifstream& in, Time& a);
	friend ofstream& operator<<(ofstream& out, const Time& a);
	~Time();
};
inline bool operator>(const Time r, Time t) {
	return ((r.h > t.h) || (r.h == t.h) && (r.m > t.m)) ? true : false;
}
class Date {
public:
	int y, m, d;
	Date();
	Date(int y1, int m1, int d1) {
		y = y1;
		m = m1;
		d = d1;
	}
	Date operator+(const int a) const; 
	bool operator<(const Date& d) const{
		return ((y < d.y) || (y == d.y) && (m < d.m) || (y == d.y) && (m == d.m) && (this->d < d.d));
	}
	bool operator==(const Date& d) const{
		return (y == d.y && m == d.m && this->d == d.d);
	}
	bool operator<=(const Date& d) {
		return ((*this < d) || (*this == d));
	}
	bool operator>(const Date& d) {
		return !(*this <= d);
	}
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
	friend ofstream& operator<<(ofstream& out, const Date& d);
	friend ifstream& operator>>(ifstream& in, Date& d);

};