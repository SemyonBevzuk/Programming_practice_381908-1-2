#include "Seanñe.h"

using namespace std;

Seanñe::Seanñe(DateS d, TimeS t, string f, int num, double cost)
{
	int n, m;
	date = d;
	time = t;
	film = f;
	switch (num)
	{
	case 1:
		n = 10;
		m = 10;
		break;
	case 2:
	case 3:
		n = 15;
		m = 12;
		break;
	case 4:
		n = 20;
		m = 15;
		break;
	default:
		throw exception("Òàêîãî çàëà íå ïğåäóñìîòğåíî");
		break;
	}
	num_zal = num;
	cost_base = cost;
	hall.resize(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || i == n / 2 || n > 2 && i == n / 2 + 1)
				hall[i].push_back({ true,true });
			else
				hall[i].push_back({ true,false });
		}
	}
}
Seanñe& Seanñe::operator=(const Seanñe& s)
{
	if (this != &s)
	{
		date = s.date;
		time = s.time;
		film = s.film;
		num_zal = s.num_zal;
		cost_base = s.cost_base;
		hall = s.hall;
	}
	return *this;
}
ifstream& operator>>(ifstream& in, Seanñe& s)
{
	DateS d;
	TimeS t;
	string f;
	int num;
	double cost;
	in >> d;
	in >> t;
	in.ignore();
	getline(in, f);
	in >> num;
	in >> cost;
	s = Seanñe(d, t, f, num, cost);
	return in;
}
ofstream& operator<<(ofstream& out, const Seanñe& s)
{
	out << s.date << endl;
	out << s.time << endl;
	out << s.film << endl;
	out << s.num_zal << endl;
	out << s.cost_base << endl;
	return out;
}