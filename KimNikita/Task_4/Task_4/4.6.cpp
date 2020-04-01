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
	fout.open("output.txt", ios::out);
	ifstream fin("input.txt");
	FilmLibrary fb1;
	fin >> fb1;
	FilmLibrary fb2(fb1);
	cout << "Добро пожаловать в редактор библиотеки фильмов" << endl;
	cout << "Если хотите ознакомиться с её содержимым, у вас есть файл input.txt" << endl;
	int v = -1;
	bool e = false;
	while (true)
	{
		switch (v)
		{
		case 0:
			fb1.SaveFilm();
			break;
		case 1:
			fb1.AddFilm();
			break;
		case 2:
			fb1.FixFilm();
			break;
		case 3:
			fb1.FindFilm();
			break;
		case 4:
			fb1.PrintFilmsBy();
			break;
		case 5:
			fb1.PrintFilmsIn();
			break;
		case 6:
			fb1.PrintColFilmsMaxIncome();
			break;
		case 7:
			fb1.PrintColFilmsMaxIncomeIn();
			break;
		case 8:
			fb1.PrintColFilms();
			break;
		case 9:
			fb1.DelFilm();
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
		cin.ignore();
	}
	cout << "Результат вашей деятельности в файле output";
	fout << "Было" << endl;
	fout << fb2;
	fout << "Стало" << endl;
	fout << fb1;
	return 0;
}
