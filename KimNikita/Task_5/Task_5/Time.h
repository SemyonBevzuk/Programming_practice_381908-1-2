#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class Time
{
public:
	int minute;
	int hour;
	Time() : minute(-1), hour(-1) {}
	Time(int, int);
	Time& operator=(const Time&);
	bool operator==(const Time&)const;
	bool operator<(const Time&)const;
	Time& operator+=(const Time&);
	friend ifstream& operator>>(ifstream&, Time&);
	friend ofstream& operator<<(ofstream&, const Time&);
	~Time() {}
};

