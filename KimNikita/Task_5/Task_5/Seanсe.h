#pragma once

#include "DateS.h"
#include "TimeS.h"
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
	DateS date;
	TimeS time;
	string film;
	int num_zal;
	double cost_base;
	vector<vector<Place>> hall;
	Seanñe() :num_zal(0), cost_base(0) {}
	Seanñe(DateS, TimeS, string, int, double);
	Seanñe& operator=(const Seanñe&);
	friend ifstream& operator>>(ifstream&, Seanñe&);
	friend ofstream& operator<<(ofstream&, const Seanñe&);
	~Seanñe() {}
};

