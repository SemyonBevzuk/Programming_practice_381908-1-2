#pragma once
#include <iostream>
using namespace std;

class Time {
private:
	int h;
	int m;
	int s;
public:
	Time();
	Time(const Time& t);
	Time(const int& hr, const int& min, const int& sec);
	int get_h();
	int get_m();
	int get_s();
	Time& operator=(const Time& t);
	Time operator+(const Time& t);
	Time operator-(const Time& t);
	bool operator<(const Time& a);
	bool operator>(const Time& a);
	bool operator<=(const Time& a);
	bool operator>=(const Time& a);
	bool operator==(const Time& a);
	bool operator!=(const Time& a);
	Time& operator+=(const Time& a);
	Time& operator-=(const Time& a);
	Time operator+(const int& sec);
	Time operator-(const int& sec);	
	Time& operator+=(const int& sec);
	Time& operator-=(const int& sec);
	friend istream& operator>>(istream& in, Time& a);
	friend ostream& operator<<(ostream& out, const Time& a);
	~Time();
};