#include "FilmLibrary.h"
#include <iostream>
#include <algorithm>
#include <locale>

using namespace std;


void FilmLibrary::PrintMenuEditor()
{
	cout << "Выберите параметр для изменения:" << endl;
	cout << "1 - название" << endl;
	cout << "2 - имя режиссера" << endl;
	cout << "3 - имя сценариста" << endl;
	cout << "4 - имя композитора" << endl;
	cout << "5 - дата выхода в прокат" << endl;
	cout << "6 - сборы в рублях" << endl;
	cout << "0 - прекратить изменение" << endl;
	cout << "В любом другом случае будет выведено меню" << endl;
}
bool comp1(const Film& a, const Film& b)
{
	if (a.date.year < b.date.year)
		return true;
	else
		if (a.date.year == b.date.year)
			return a.name < b.name;
		else
			return false;
}
bool comp2(const Film& a, const Film& b)
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
void FilmLibrary::SaveFilm()
{
	setlocale(LC_ALL, "Russian");
	string f;
	cout << "Введите название файла для сохранения" << endl;
	getline(cin, f);
	ofstream fout;
	fout.open(f + ".txt", ios::out);
	string n;
	int y;
	cout << "Введите название фильма, который хотите сохранить" << endl;
	getline(cin, n);
	cout << "Введите год выхода в прокат" << endl;
	cin >> y;
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
			cout << "Готово" << endl;
			fout.close();
			return;
		}
	}
	fout.close();
	cout << "Данного фильма с данным годом выхода в прокат нет в библиотеке" << endl;
}
void FilmLibrary::AddFilm()
{
	Film t;
	t.GetFilm();
	lib.push_back(t);
	sort(lib.begin(), lib.end(), comp1);
	cout << "Готово" << endl;
}
void FilmLibrary::FixFilm()
{
	setlocale(LC_ALL, "Russian");
	string n;
	int y;
	cout << "Введите название фильма, данные которого хотите изменить" << endl;
	getline(cin, n);
	cout << "Введите год выхода в прокат" << endl;
	cin >> y;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			bool e = false;
			int choice = -1;
			while (true)
			{
				switch (choice)
				{
				case 0:
					e = true;
					break;
				case 1:
					cout << "Введите новое название фильма:" << endl;
					cin.ignore();
					getline(cin, lib[i].name);
					cout << "Готово" << endl;
					break;
				case 2:
					cout << "Введите новое имя режиссера:" << endl;
					cin.ignore();
					getline(cin, lib[i].producer);
					cout << "Готово" << endl;
					break;
				case 3:
					cout << "Введите новое имя сценариста:" << endl;
					cin.ignore();
					getline(cin, lib[i].scenarist);
					cout << "Готово" << endl;
					break;
				case 4:
					cout << "Введите новое имя композитора:" << endl;
					cin.ignore();
					getline(cin, lib[i].composer);
					cout << "Готово" << endl;
					break;
				case 5:
					cout << "Введите новую дату выхода в прокат:" << endl;
					lib[i].date.GetDate();
					cout << "Готово" << endl;
					break;
				case 6:
					cout << "Введите сборы в рублях:" << endl;
					cin >> lib[i].income;
					cout << "Готово" << endl;
					break;
				default:
					PrintMenuEditor();
				}
				if (e)
					break;
				cin >> choice;
			}
			cout << "Готово" << endl;
			return;
		}
	}
	cout << "Данного фильма нет в библиотеке" << endl;
}
void FilmLibrary::FindFilm()
{
	setlocale(LC_ALL, "Russian");
	string n;
	int y;
	cout << "Введите название фильма" << endl;
	getline(cin, n);
	cout << "Введите год выхода в прокат" << endl;
	cin >> y;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n && lib[i].date.year == y)
		{
			lib[i].PrintFilm();
			cout << "Готово" << endl;
			return;
		}
	}
	cout << "Данного фильма с данным годом выхода в прокат нет в библиотеке" << endl;
}
void FilmLibrary::PrintFilmsBy()
{
	setlocale(LC_ALL, "Russian");
	string p;
	cout << "Введите имя режиссера" << endl;
	getline(cin, p);
	int f = 1;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].producer == p)
		{
			f = 0;
			cout << lib[i].name << ' ';
			lib[i].date.PrintDate();
		}
	}
	if (f)
	{
		cout << "Фильмов данного режиссера нет в библиотеке" << endl;
	}
	else
		cout << "Готово" << endl;
}
void FilmLibrary::PrintFilmsIn()
{
	int y;
	cout << "Введите год выхода в прокат" << endl;
	cin >> y;
	int f = 1;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].date.year == y)
		{
			f = 0;
			cout << lib[i].name << endl;
		}
	}
	if (f)
	{
		cout << "Фильмов, вышедших в прокат в данном году, нет в библиотеке" << endl;
	}
	else
		cout << "Готово" << endl;
}
void FilmLibrary::PrintColFilmsMaxIncome()
{
	int n;
	cout << "Введите количество фильмов, которые нужно вывести" << endl;
	cin >> n;
	vector<Film>t;
	for (int i = 0; i < lib.size(); i++)
	{
		t.push_back(lib[i]);
	}
	sort(t.begin(), t.end(), comp2);
	int s = t.size();
	s = min(n, s);
	for (int i = 0; i < s; i++)
	{
		cout << t[i].name << endl;
	}
	cout << "Готово" << endl;
}
void FilmLibrary::PrintColFilmsMaxIncomeIn()
{
	int n, y;
	cout << "Введите количество фильмов, которые нужно вывести" << endl;
	cin >> n;
	cout << "Введите год выхода в прокат" << endl;
	cin >> y;
	vector<Film>t;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].date.year == y)
			t.push_back(lib[i]);
	}
	sort(t.begin(), t.end(), comp2);
	int s = t.size();
	s = min(n, s);
	for (int i = 0; i < s; i++)
	{
		cout << t[i].name << endl;
	}
	cout << "Готово" << endl;
}
void FilmLibrary::PrintColFilms()
{
	cout << "Всего фильмов: " << lib.size() << endl;
	cout << "Готово" << endl;
}
void FilmLibrary::DelFilm()
{
	setlocale(LC_ALL, "Russian");
	string n;
	cout << "Введите название фильма, который нужно удалить" << endl;
	getline(cin, n);
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i].name == n)
		{
			lib.erase(lib.begin() + i);
			cout << "Готово" << endl;
			return;
		}
	}
	cout << "Данного фильма нет в библиотеке" << endl;
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
	sort(fl.lib.begin(), fl.lib.end(), comp1);
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