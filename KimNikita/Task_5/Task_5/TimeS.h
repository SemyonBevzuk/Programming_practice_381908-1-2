#pragma once
#include <iostream>
#include <fstream>

using namespace std;
class TimeS
{
public:
	int minute;
	int hour;
	TimeS() : minute(-1), hour(-1) {}
	TimeS(int, int);
	TimeS& operator=(const TimeS&);
	bool operator==(const TimeS&)const;
	bool operator<(const TimeS&)const;
	TimeS& operator+=(const TimeS&);
	friend ifstream& operator>>(ifstream&, TimeS&);
	friend ofstream& operator<<(ofstream&, const TimeS&);
	~TimeS() {}
};

