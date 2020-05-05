
#include "Cinema.h"
using namespace std;

Hall::Hall() {}
Show::Show() {}
General::General() {}
vector<Hall> halls;
Time t12(12, 0), t18(18, 0);
////////////////////////////////////////////////////////////////////
Cinema::Cinema(string hallsfile, string showsfile) {
	loadHalls(hallsfile);
	loadShows(showsfile);
	int n = shows.size();
	map<General, Show>::iterator i = shows.begin();
	for (; i != shows.end(); i++) {
		Show s = i->second;
		General g = i->first;
		s.hall = halls[g.hallnum]; //setting places

		s.n = 0;                   
		s.nvip = 0;
		s.ivip = { -1, -1 };
		s.in = { -1, -1 };
		
		if (g.time < t12) {             //setting price
			s.price = (int)(0.75 * s.price);
			s.pricevip = (int)(0.75 * s.pricevip);
		}
		else if (g.time > t18) {
			s.price = (int)(1.5 * s.price);
			s.pricevip = (int)(1.5 * s.pricevip);
		}
		
		for (unsigned int j = 0; j < s.hall.places.size(); j++) { //free places amount & first unoccupied
			for (unsigned int k = 0; k < s.hall[j].size(); k++) {
				if (s.hall[j][k] == 'N') {
					if (s.in.first == -1)
						s.in = { j, k };
					s.n++;
				}
				else if (s.hall[j][k] == 'V') {
					if (s.ivip.first == -1) 
						s.ivip = { j, k };
					s.nvip++;
				}
			}
		}
		shows.erase(i);
		shows.insert({ g, s });
		i = shows.find(g);
	}
}
void Cinema::loadHalls(string hallsfile) {
	ifstream file;
	file.open(hallsfile);
	while (!file.eof()) {
		Hall h;
		file >> h;
		halls.push_back(h);
	}
	file.close();
	return;
}
void Cinema::loadShows(string showsfile) {
	ifstream file;
	file.open(showsfile);
	Show s;
	General g;
	while (!file.eof()) {
		file >>g;
		s.price = halls[g.hallnum].price;
		s.pricevip = halls[g.hallnum].pricevip;
		shows.insert({ g, s });
	}
	file.close();
	return;
}
//////////////////////////////////////////////////////////////////
ifstream& operator>>(ifstream& in, Hall& h)
{
	string s;
	in >> h.price >> h.pricevip;
	in.ignore(1);
	do {
		in >> s;
		h.places.push_back(s);
	} while (s !="*");
	h.places.pop_back();
	return in;
}
/////////////////////////////////////////////////////////////
ifstream& operator>>(ifstream& in, Show& s)
{
	in >> s.price >> s.pricevip;
	return in;
}
///////////////////////////////////////////////////////////////////
ifstream& operator>>(ifstream& in, General& s)
{
	in >> s.title >> s.date >> s.time >> s.hallnum;
	in.ignore(1);
	return in;
}
istream& operator>>(istream& in, General& s) {
	in >> s.title >> s.date >> s.time >> s.hallnum;
	in.ignore(1);
	return in;
}
ostream& operator<<(ostream& out, const General& s) {
	out << s.title <<'\n'<< s.date<<' ' << s.time<<" Hall " << s.hallnum;
	return out;
}
///////////////////////////////////
istream& operator>>(istream& in, string& s) {
	char c[200];
	in.getline(c, 200);
	s = (string)c;
	return in;
}
ifstream& operator>>(ifstream& in, string& s) {
	getline(in, s);
	return in;
}