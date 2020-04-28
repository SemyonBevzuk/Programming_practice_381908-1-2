#pragma once
#include "Seanñe.h"

class Cinema
{
private:
	friend bool sort_date_time_hall(const Seanñe&, const Seanñe&);
public:
	vector<Seanñe> seanses;
	Cinema() {}
	Cinema& operator=(const Cinema&);
	friend ifstream& operator>>(ifstream&, Cinema&);
	friend ofstream& operator<<(ofstream&, const Cinema&);
	~Cinema() {}
};

