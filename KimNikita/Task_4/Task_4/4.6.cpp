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
	string n;
	string f;
	string p;
	int y;
	int c;
	cout << "Добро пожаловать в редактор библиотеки фильмов" << endl;
	cout << "Если хотите ознакомиться с её содержимым, у вас есть файл input.txt" << endl;
	int v = -1;
	bool e = false;
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
			if (fb1.FixFilm(n, y))
				cout << "Готово" << endl;
			else
				cout << "Данного фильма нет в библиотеке" << endl;
			break;
		case 3:
			cin.ignore();
			cout << "Введите название фильма" << endl;
			getline(cin, n);
			cout << "Введите год выхода в прокат" << endl;
			cin >> y;
			if (fb1.FindFilm(n, y))
				cout << "Готово" << endl;
			else
				cout << "Данного фильма с данным годом выхода в прокат нет в библиотеке" << endl;
			break;
		case 4:
			cin.ignore();
			cout << "Введите имя режиссера" << endl;
			getline(cin, p);
			if (fb1.PrintFilmsBy(p))
				cout << "Готово" << endl;
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
