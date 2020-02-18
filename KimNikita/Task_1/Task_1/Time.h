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
	void get_time()const;
	Time& operator=(Time);
	Time& operator+=(Time);
	Time& operator-=(Time);
	Time operator+(Time)const;
	Time operator-(Time)const;
	bool operator>(Time)const;
	bool operator<(Time)const;
	bool operator<=(Time)const;
	bool operator>=(Time)const;
	bool operator==(Time)const;
	bool operator!=(Time)const;
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};