#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time {
private:
	int hour;
	int min;
	int sec;
public:
	Time();
	Time(int, int, int);
	Time(const Time&);
	Time(string);
	~Time() {}
	const string get_time()const;
	Time& operator=(const Time&);
	Time& operator+=(const Time&);
	Time& operator-=(const Time&);
	const Time operator+(const Time&)const;
	const Time operator-(const Time&)const;
	bool operator>(const Time&)const;
	bool operator<(const Time&)const;
	bool operator<=(const Time&)const;
	bool operator>=(const Time&)const;
	bool operator==(const Time&)const;
	bool operator!=(const Time&)const;
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};