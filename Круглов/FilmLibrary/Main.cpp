#include<iostream>
#include"Date.h"
#include"FilmLibrary.h"
#include<fstream>
#include<locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		Date date(1, 1, 2005);
		Film f("Supernatural", "Singer", "brown", "Singer2", date, 200);
		FilmLibrary FL;
		FL.addFilm(f);
		ofstream fout("Libr.txt");
		fout << f;
		fout.close();
		ifstream fin("Libr.txt");
		fin >> f;
		cout << f;
		fin.close();
	}
	catch (MyExc& exception)
	{
		switch (exception.extype_)
		{
		case exType0:
			cout << exception.type_;
		}
	}
	catch (string s)
	{
		cout << s;
	}
}