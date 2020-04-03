#include "FilmLibrary.h"
#include <iostream>
#include <algorithm>
#include <locale>

using namespace std;


bool sort_year_name(const Film& a, const Film& b)
{
	if (a.date.year < b.date.year)
		return true;
	else
		if (a.date.year == b.date.year)
			return a.name < b.name;
		else
			return false;
}
bool sort_income(const Film& a, const Film& b)
{
	return a.income > b.income;
}
FilmLibrary::FilmLibrary(const FilmLibrary& fl)
{
	for (int i = 0; i < fl.lib.size(); i++)
	{
		lib.push_back(fl.lib[i]);
	}
}
bool FilmLibrary::SaveFilm(ofstream& fout, string n, int y)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			fout << lib[i].name << endl;
			fout << lib[i].producer << endl;
			fout << lib[i].scenarist << endl;
			fout << lib[i].composer << endl;
			fout << lib[i].date.day << ' ' << lib[i].date.month << ' ' << lib[i].date.year << endl;
			fout << lib[i].income << endl;
			return true;
		}
	}
	return false;
}
void FilmLibrary::AddFilm(Film t)
{
	lib.push_back(t);
	sort(lib.begin(), lib.end(), sort_year_name);
}
bool FilmLibrary::IsExist(string n, int y)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			return true;
		}
	}
	return false;
}
bool FilmLibrary::FixName(string n, int y, string new_n)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].name = new_n;
			return true;
		}
	}
	return false;
}
bool FilmLibrary::FixProducer(string n, int y, string new_p)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].producer = new_p;
			return true;
		}
	}
	return false;
}
bool FilmLibrary::FixScenarist(string n, int y, string new_s)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].scenarist = new_s;
			return true;
		}
	}
	return false;
}
bool FilmLibrary::FixComposer(string n, int y, string new_c)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].composer = new_c;
			return true;
		}
	}
	return false;
}
bool FilmLibrary::FixYear(string n, int y, int new_y)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].date.year = new_y;
			return true;
		}
	}
	return false;
}
bool FilmLibrary::FixMonth(string n, int y, int new_m)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].date.month = new_m;
			return true;
		}
	}
	return false;
}
bool FilmLibrary::FixDay(string n, int y, int new_d)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].date.day = new_d;
			return true;
		}
	}
	return false;
}
bool FilmLibrary::FixIncome(string n, int y, int new_i)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].income = new_i;
			return true;
		}
	}
	return false;
}
Film FilmLibrary::FindFilm(string n, int y)
{
	Film t;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			t = lib[i];
		}
	}
	return t;
}
vector<Film> FilmLibrary::GetFilmsBy(string p)
{
	vector<Film>vf;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].producer == p)
		{
			vf.push_back(lib[i]);
		}
	}
	return vf;
}
vector<Film> FilmLibrary::GetFilmsIn(int y)
{
	vector<Film>vf;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].date.year == y)
		{
			vf.push_back(lib[i]);
		}
	}
	return vf;
}
vector<Film> FilmLibrary::GetFilmsMaxIncome(int c)
{
	vector<Film>vf;
	for (int i = 0; i < lib.size(); i++)
	{
		vf.push_back(lib[i]);
	}
	sort(vf.begin(), vf.end(), sort_income);
	int s = vf.size();
	s = min(c, s);
	vf.resize(s);
	return vf;
}
vector<Film> FilmLibrary::GetFilmsMaxIncomeIn(int c, int y)
{
	vector<Film>vf;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].date.year == y)
			vf.push_back(lib[i]);
	}
	sort(vf.begin(), vf.end(), sort_income);
	int s = vf.size();
	s = min(c, s);
	vf.resize(s);
	return vf;
}
int FilmLibrary::Size()
{
	return lib.size();
}
bool FilmLibrary::DelFilm(string n)
{
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n)
		{
			lib.erase(lib.begin() + i);
			return true;
		}
	}
	return false;
}
ifstream& operator>>(ifstream& in, FilmLibrary& fl)
{
	int n;
	string s;
	in >> n;
	in.ignore();
	fl.lib.resize(n);
	for (int i = 0; i < n; i++)
	{
		getline(in, fl.lib[i].name);
		getline(in, fl.lib[i].producer);
		getline(in, fl.lib[i].scenarist);
		getline(in, fl.lib[i].composer);
		in >> fl.lib[i].date.day >> fl.lib[i].date.month >> fl.lib[i].date.year;
		in >> fl.lib[i].income;
		in.ignore();
		in.ignore();
	}
	sort(fl.lib.begin(), fl.lib.end(), sort_year_name);
	return in;
}
ofstream& operator<<(ofstream& out, const FilmLibrary& fl)
{
	out << fl.lib.size() << endl;
	for (int i = 0; i < fl.lib.size(); i++)
	{
		out << fl.lib[i].name << endl;
		out << fl.lib[i].producer << endl;
		out << fl.lib[i].scenarist << endl;
		out << fl.lib[i].composer << endl;
		out << fl.lib[i].date.day << ' ' << fl.lib[i].date.month << ' ' << fl.lib[i].date.year << endl;
		out << fl.lib[i].income << endl;
		out << endl;
	}
	return out;
}