#include "Film.h"

bool MovieClass::FilmLibrary::operator<(const FilmLibrary& c) const
{
	return cashfees > c.cashfees;
}

void MovieClass::NewStruct(wstring n, wstring p, wstring s, wstring c, int d, int m, int y, int cash)
{
	FilmLibrary NewFilmLibrary;
	NewFilmLibrary.name = n;
	NewFilmLibrary.producer = p;
	NewFilmLibrary.screenwriter = s;
	NewFilmLibrary.composer = c;
	NewFilmLibrary.day = d;
	NewFilmLibrary.month = m;
	NewFilmLibrary.year = y;
	NewFilmLibrary.cashfees = cash;
	list.push_back(NewFilmLibrary);
	int a = list.size();
	ChangeRegistr(a - 1);
}

void MovieClass::Resize(int number)
{
	this->~MovieClass();
	list.resize(number);
}

void MovieClass::PrintListOfFilms(vector<FilmLibrary> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		wcout << i + 1 << ". " << endl;
		wcout << "Name: " << a[i].name << endl;
		wcout << "Producer: " << a[i].producer << " Screenwriter: " << a[i].screenwriter << " Composer: " << a[i].composer << endl;
		wcout << "Date: " << a[i].day << "." << a[i].month << "." << a[i].year << endl;
		wcout << "Cashfees: " << a[i].cashfees << " $" << endl;
	}
}

MovieClass::MovieClass()
{
	this->~MovieClass();
	list.resize(0);
}

MovieClass::MovieClass(wstring n, wstring p, wstring s, wstring c, int d, int m, int y, int cash)
{
	this->~MovieClass();
	NewStruct(n, p, s, c, d, m, y, cash);
}

MovieClass::~MovieClass()
{
	list.clear();
}

bool MovieClass::AddFilm(wstring n, wstring p, wstring s, wstring c, int d, int m, int y, int cash)
{
	bool flag = true;
	for (int i = 0; i < list.size(); i++)
	{
		if (n == list[i].name && p == list[i].producer)
			flag = false;
	}
	if (flag)
	{
		NewStruct(n, p, s, c, d, m, y, cash);
	}
	return flag;
}

bool MovieClass::ChangeInformation(wstring search, wstring n, wstring p, wstring s, wstring c, int d, int m, int y, int cash)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (search == list[i].name)
		{
			list[i].name = n;
			list[i].producer = p;
			list[i].screenwriter = s;
			list[i].composer = c;
			list[i].day = d;
			list[i].month = m;
			list[i].year = y;
			list[i].cashfees = cash;
			ChangeRegistr(i);
			return true;
			break;
		}
	}
	return false;
}

vector<MovieClass::FilmLibrary> MovieClass::SearchFilm(wstring n, int y)
{
	vector<FilmLibrary> v;
	v.resize(0);
	for (int i = 0; i < list.size(); i++)
	{
		if (n == list[i].name && y == list[i].year)
		{
			v.push_back(list[i]);
		}
	}
	return v;
}

vector<MovieClass::FilmLibrary> MovieClass::SearchByProducer(wstring p)
{
	vector<FilmLibrary> v;
	for (int i = 0; i < list.size(); i++)
	{
		if (p == list[i].producer)
		{
			v.push_back(list[i]);
		}
	}
	return v;
}

vector<MovieClass::FilmLibrary> MovieClass::SearchByYear(int y)
{
	vector<FilmLibrary> v;
	for (int i = 0; i < list.size(); i++)
	{
		if (y == list[i].year)
			v.push_back(list[i]);
	}
	return v;
}

vector<MovieClass::FilmLibrary> MovieClass::HighestFees(int sum)
{
	vector<FilmLibrary> v(sum);
	sort(list.begin(), list.end());
	if (sum <= list.size())
		for (int i = 0; i < sum; i++)
			v[i] = list[i];
	else
		for (int i = 0; i < list.size(); i++)
			v[i] = list[i];
	return v;
}

vector<MovieClass::FilmLibrary> MovieClass::HighestFeesPerYear(int sum, int y)
{
	vector<FilmLibrary> v;
	for (int i = 0; i < list.size(); i++)
	{
		if (y == list[i].year)
			v.push_back(list[i]);
	}
	sort(v.begin(), v.end());
	if (sum <= v.size())
	{
		while (v.size() != sum)
			v.pop_back();
		v.shrink_to_fit();
		return v;
	}
	else return v;
}

int MovieClass::NumberOfFilmsInTheLibrary()
{
	return list.size();
}

bool MovieClass::DeleteFilmFromTheLibrary(wstring n)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (n == list[i].name)
		{
			list.erase(list.begin() + i);
			list.shrink_to_fit();
			return true;
			break;
		}
	}
	return false;
}

wistream& operator>>(wistream& wistream, MovieClass& c)
{
	int a = c.list.size();
	wistream >> a;
	for (int i = 0; i < c.list.size(); i++)
	{
		wistream >> c.list[i].name;
		wistream >> c.list[i].producer;
		wistream >> c.list[i].screenwriter;
		wistream >> c.list[i].composer;
		wistream >> c.list[i].day;
		wistream >> c.list[i].month;
		wistream >> c.list[i].year;
		wistream >> c.list[i].cashfees;
	}
	return wistream;
}

wostream& operator<<(wostream& wostream, const MovieClass& c)
{
	wostream << c.list.size();
	wostream << "\n";
	for (int i = 0; i < c.list.size(); i++)
	{
		wostream << c.list[i].name;
		wostream << "\n";
		wostream << c.list[i].producer;
		wostream << " ";
		wostream << c.list[i].screenwriter;
		wostream << " ";
		wostream << c.list[i].composer;
		wostream << "\n";
		wostream << c.list[i].day << " " << c.list[i].month << " " << c.list[i].year;
		wostream << "\n";
		wostream << c.list[i].cashfees;
		wostream << "\n\n";
	}
	return wostream;
}

void MovieClass::ChangeRegistr(int i)
{
	int k = 0, l = 0, m = 0, n = 0;
	while (list[i].name[k])
	{
		list[i].name[k] = tolower(list[i].name[k], locale("rus_rus.866"));
		k++;
	}
	while (list[i].producer[l])
	{
		list[i].producer[l] = tolower(list[i].producer[l], locale("rus_rus.866"));
		l++;
	}
	while (list[i].screenwriter[m])
	{
		list[i].screenwriter[m] = tolower(list[i].screenwriter[m], locale("rus_rus.866"));
		m++;
	}
	while (list[i].composer[n])
	{
		list[i].composer[n] = tolower(list[i].composer[n], locale("rus_rus.866"));
		n++;
	}
}

bool CheckingTheDate(int d, int m, int y)
{
	int m1[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int m2[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (y / 4 != 0)
	{
		if (m >= 1 && m <= 12 && d <= m1[m - 1])
			return true;
		else return false;
	}
	else
	{
		if (y / 100 != 0)
		{
			if (m >= 1 && m <= 12 && d <= m2[m - 1])
				return true;
			else return false;
		}
		else
		{
			if (y / 400 != 0)
			{
				if (m >= 1 && m <= 12 && d <= m1[m - 1])
					return true;
				else return false;
			}
			else
			{
				if (m >= 1 && m <= 12 && d <= m2[m - 1])
					return true;
				else return false;
			}
		}
	}
}