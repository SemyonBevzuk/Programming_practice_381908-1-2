#include "Cinema.h"
#include <algorithm>

using namespace std;

bool sort_date_time_hall(const Seanñe& a, const Seanñe& b)
{
	if (a.date < b.date)
		return true;
	else
		if (a.date == b.date)
			if (a.time < b.time)
				return true;
			else
				if (a.time == b.time)
					if (a.num_zal < b.num_zal)
						return true;
	return false;
}
Cinema& Cinema::operator=(const Cinema& c)
{
	if (this != &c)
	{
		seanses = c.seanses;
	}
	return *this;
}
ifstream& operator>>(ifstream& in, Cinema& c)
{
	int n;
	in >> n;
	c.seanses.resize(n);
	for (int i = 0; i < n; i++)
	{
		in >> c.seanses[i];
	}
	sort(c.seanses.begin(), c.seanses.end(), sort_date_time_hall);
	return in;
}
ofstream& operator<<(ofstream& out, const Cinema& c)
{
	out << c.seanses.size() << endl;
	for (int i = 0; i < c.seanses.size(); i++)
	{
		out << c.seanses[i] << endl;
	}
	return out;
}
