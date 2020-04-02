#include "FilmLibrary.h"
#include <locale>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void PrintMenu()
{
	cout << "Меню" << endl;
	cout << "-------------------" << endl;
	cout << "0 - сохранить фильм в файле" << endl;
	cout << "1 - добавить фильм" << endl;
	cout << "2 - изменить данные фильма по названию" << endl;
	cout << "3 - найти фильм по названию и году" << endl;
	cout << "4 - выдать все фильмы заданного режиссера" << endl;
	cout << "5 - выдать все фильмы, вышедшие в прокат в выбранном году" << endl;
	cout << "6 - выдать заданное число фильмов с наибольшими сборами" << endl;
	cout << "7 - выдать заднее число фильмов с наибольшими сборами в выбранном году" << endl;
	cout << "8 - узнать текущее число фильмов" << endl;
	cout << "9 - удалить фильм по названию" << endl;
	cout << "10 - выйти из программы" << endl;
	cout << "В любом другом случае будет выведено меню" << endl;
}
void PrintMenuEditor()
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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	ifstream fin("input.txt");
	FilmLibrary fb1;
	fin >> fb1;
	FilmLibrary fb2(fb1);
	Film t;
	vector<Film>v_f;
	string n;
	string f;
	string p;
	int y;
	int c;
	cout << "Добро пожаловать в редактор библиотеки фильмов" << endl;
	cout << "Если хотите ознакомиться с её содержимым, у вас есть файл input.txt" << endl;
	int v = -1;
	bool e = false;
	bool vis;
	while (true)
	{
		switch (v)
		{
		case 0:
			cin.ignore();
			cout << "Введите название файла для сохранения" << endl;
			getline(cin, f);
			fout.open(f + ".txt", ios::out);
			cout << "Введите название фильма, который хотите сохранить" << endl;
			getline(cin, n);
			cout << "Введите год выхода в прокат" << endl;
			cin >> y;
			if (fb1.SaveFilm(fout, n, y))
				cout << "Готово" << endl;
			else
				cout << "Данного фильма с данным годом выхода в прокат нет в библиотеке" << endl;
			fout.close();
			break;
		case 1:
			cin.ignore();
			t.GetFilm();
			fb1.AddFilm(t);
			cout << "Готово";
			break;
		case 2:
			cin.ignore();
			cout << "Введите название фильма, данные которого хотите изменить" << endl;
			getline(cin, n);
			cout << "Введите год выхода в прокат" << endl;
			cin >> y;
			if (fb1.IfFixFilm(n, y))
			{
				int choice = -1;
				string new_n, new_p, new_s, new_c;
				int new_d, new_m, new_y, new_i;
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
						getline(cin, new_n);
						fb1.FixName(n, y, new_n);
						cout << "Готово" << endl;
						break;
					case 2:
						cout << "Введите новое имя режиссера:" << endl;
						cin.ignore();
						getline(cin, p);
						fb1.FixProducer(n, y, new_p);
						cout << "Готово" << endl;
						break;
					case 3:
						cout << "Введите новое имя сценариста:" << endl;
						cin.ignore();
						getline(cin, new_s);
						fb1.FixScenarist(n, y, new_s);
						cout << "Готово" << endl;
						break;
					case 4:
						cout << "Введите новое имя композитора:" << endl;
						cin.ignore();
						getline(cin, new_c);
						fb1.FixComposer(n, y, new_c);
						cout << "Готово" << endl;
						break;
					case 5:
						cout << "Введите новую дату выхода в прокат:" << endl;
						do
						{
							cout << "Введите год выхода в прокат:" << endl;
							cin >> new_y;
						} while (new_y < 1895);
						fb1.FixYear(n, y, new_y);
						vis = false;
						if (new_y / 400 > 0 && new_y % 400 == 0 || new_y % 100 != 0 && new_y % 4 == 0)
							vis = true;
						do
						{
							cout << "Введите месяц выхода в прокат:" << endl;
							cin >> new_m;
						} while (new_m > 12 || new_m < 1);
						fb1.FixMonth(n, y, new_m);
						do
						{
							cout << "Введите день выхода в прокат:" << endl;
							cin >> new_d;
						} while (new_d < 1 || new_d>31 || new_d > 29 && new_m == 2 || new_d == 29 && new_m == 2 && !vis);
						fb1.FixDay(n, y, new_d);
						cout << "Готово" << endl;
						break;
					case 6:
						cout << "Введите сборы в рублях:" << endl;
						cin >> new_i;
						fb1.FixIncome(n, y, new_i);
						cout << "Готово" << endl;
						break;
					default:
						PrintMenuEditor();
					}
					if (e)
					{
						e = false;
						break;
					}
					cin >> choice;
				}
				cout << "Готово" << endl;
			}
			else
				cout << "Данного фильма нет в библиотеке" << endl;
			break;
		case 3:
			cin.ignore();
			cout << "Введите название фильма" << endl;
			getline(cin, n);
			cout << "Введите год выхода в прокат" << endl;
			cin >> y;
			t = fb1.FindFilm(n, y);
			if (t.name != "")
			{
				t.PrintFilm();
				cout << "Готово" << endl;
			}
			else
				cout << "Данного фильма с данным годом выхода в прокат нет в библиотеке" << endl;
			break;
		case 4:
			cin.ignore();
			cout << "Введите имя режиссера" << endl;
			getline(cin, p);
			v_f = fb1.PrintFilmsBy(p);
			if (v_f.size() != 0)
			{
				for (int i = 0; i < v_f.size(); i++)
				{
					v_f[i].PrintFilm();
				}
				cout << "Готово" << endl;
			}
			else
				cout << "Фильмов данного режиссера нет в библиотеке" << endl;
			break;
		case 5:
			cout << "Введите год выхода в прокат" << endl;
			cin >> y;
			if (fb1.PrintFilmsIn(y))
				cout << "Готово" << endl;
			else
				cout << "Фильмов, вышедших в прокат в данном году, нет в библиотеке" << endl;
			break;
		case 6:
			cout << "Введите количество фильмов, которые нужно вывести" << endl;
			cin >> c;
			fb1.PrintColFilmsMaxIncome(c);
			cout << "Готово" << endl;
			break;
		case 7:
			cout << "Введите количество фильмов, которые нужно вывести" << endl;
			cin >> c;
			cout << "Введите год выхода в прокат" << endl;
			cin >> y;
			if (fb1.PrintColFilmsMaxIncomeIn(c, y))
				cout << "Готово" << endl;
			else
				cout << "Фильмов, вышедших в прокат в данном году, нет в библиотеке" << endl;
			break;
		case 8:
			cout << "Всего фильмов: " << fb1.ColFilms() << endl;
			cout << "Готово" << endl;
			break;
		case 9:
			cin.ignore();
			cout << "Введите название фильма, который нужно удалить" << endl;
			getline(cin, n);
			if (fb1.DelFilm(n))
				cout << "Готово" << endl;
			else
				cout << "Данного фильма нет в библиотеке" << endl;
			break;
		case 10:
			e = true;
			break;
		default:
			PrintMenu();
		}
		if (e)
			break;
		cin >> v;
	}
	ofstream fout2;
	fout2.open("output.txt", ios::out);
	cout << "Результат вашей деятельности в файле output";
	fout2 << "Было" << endl;
	fout2 << fb2;
	fout2 << "Стало" << endl;
	fout2 << fb1;
	fout2.close();
	return 0;
}
