#pragma once

#include "Date.h"
#include "Time.h"
#include <string>
#include <vector>

struct Place
{
	bool free;
	bool vip;
};

class Seanñe
{
public:
	Date date;
	Time time;
	string film;
	int num_zal;
	double cost_base;
	vector<vector<Place>> hall;
	Seanñe() :num_zal(0), cost_base(0) {}
	Seanñe(Date, Time, string, int, double);
	Seanñe& operator=(const Seanñe&);
	friend ifstream& operator>>(ifstream&, Seanñe&);
	friend ofstream& operator<<(ofstream&, const Seanñe&);
	~Seanñe() {}
};

