#pragma once
#include <vector>
#include <string>
#include "Time.h"
#include <map>
using namespace std;

class General {
public:
	Date date;
	Time time;
	string title;
	int hallnum;
	General();
	General(Date d, Time t, string s, int h) {
		date = d;
		time = t;
		title = s;
		hallnum = h;
	}
	bool operator==(const General& g) {
		return (date == g.date && time == g.time && title == g.title && hallnum == g.hallnum);
	}
};
inline bool const operator<(General g, General s) {
		return ((g.date < s.date) || (g.date == s.date) && (g.time < s.time) || (g.date == s.date) && 
			(g.time == s.time) && (g.title < s.title));
	}
istream& operator>>(istream& in, General& s);
ifstream& operator>>(ifstream& in, General& s);
ostream& operator<<(ostream& out, const General& s);

struct Hall {
	int price, pricevip;
	vector<string> places;
	Hall();
	string& operator[](const int index) {
		return places[index];
	}
};

ifstream& operator>>(ifstream& in, Hall& h);

extern vector<Hall> halls;

struct Show {
	Hall hall;
	int price, pricevip;
	int n, nvip; //free seats amount
	pair<int, int> in, ivip; //first free seat coords
	Show();
};
ifstream& operator>>(ifstream& in, Show& s);

class Cinema {
public:
	map<General, Show> shows;
	Cinema(string hallsfile, string showsfile);
private:
	void loadHalls(string hallsfile);
	void loadShows(string showsfile);
};

istream& operator>>(istream& in, string& s);
ifstream& operator>>(ifstream& in, string& s);