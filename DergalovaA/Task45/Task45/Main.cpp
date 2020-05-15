#include <iostream>
#include <clocale>
#include "Songs.h"
#include <fstream>

int main()
{
	setlocale(LC_ALL, "rus");
	string t = ""; //title
	string a = ""; //author
	string c = ""; //composer
	string sr = ""; //singer
	string al = ""; //album
	int d = 0, m = 0, y = 0;

	string txt = "Songs.txt";
	int exit = 0;
	Songs s;
	while (!exit)
	{
		try
		{
			cout << "Выберите действие:" << endl;
			cout << "1  - Добавить песню" << endl;
			cout << "2  - Изменить данные песни" << endl;
			cout << "3  - Искать по названию и исполнителю" << endl;
			cout << "4  - Все песни одного автора" << endl;
			cout << "5  - Все песни одногоо композитора" << endl;
			cout << "6  - Все песни одного исполнителя" << endl;
			cout << "7  - Количество песен" << endl;
			cout << "8  - Удалить песню" << endl;
			cout << "9  - Сохранить коллекцию" << endl;
			cout << "10 - Открыть коллекцию" << endl;
			cout << "0  - Выход" << endl;
			int num;
			cin >> num;

			switch (num)
			{
			case(0):
			{
				exit = 1;
				break;
			}
			case(1):
			{
				cout << endl << "Добавление песни: " << endl;
				cout << "Название песни: ";   cin >> t;
				cout << "Автор стихов: ";     cin >> a;
				cout << "Композитор: ";       cin >> c;
				cout << "Исполнитель: ";      cin >> sr;
				cout << "Название альбома: "; cin >> al;
				cout << "Дата выпуска через пробел: ";     cin >> d >> m >> y;
				s.Add(t, a, c, sr, al, d, m, y);
				system("cls");
				cout << "Песня добавлена" << endl;
				break;
			}
			case(2):
			{
				cout << endl << "Изменение данных песни:" << endl;
				string str = "";
				cout << "Название песни: ";	  cin >> str;
				cout << "Новое название песни: ";   cin >> t;
				cout << "Автор стихов: ";     cin >> a;
				cout << "Композитор: ";       cin >> c;
				cout << "Исполнитель: ";      cin >> sr;
				cout << "Название альбома: "; cin >> al;
				cout << "Дата выпуска через пробел: ";     cin >> d >> m >> y;
				s.Edit(str, t, a, c, sr, al, d, m, y);
				system("cls");
				cout << "Данные песни изменены" << endl;
				break;
			}
			case(3):
			{
				cout << endl << "Поиск песни по названию и исполнителю" << endl;
				cout << "Название песни: ";	  cin >> t;
				cout << "Исполнитель: ";      cin >> sr;
				system("cls");
				cout << "Ваша песня: ";
				Songs ss;
				ss = s.Search(t, sr);
				ss.Save("ppp.txt");


				break;
			}
			case(4):
			{
				cout << endl << "Вывод всех песен заданного автора" << endl;
				cout << "Автор стихов: ";     cin >> a;
				system("cls");
				cout << "Все песени заданного автора:\n";
				s.AllSongAuthor(a).Save("ppp.txt");
				break;
			}
			case(5):
			{
				cout << endl << "Вывод всех песен заданного композитор" << endl;
				cout << "Композитор: ";     cin >> a;
				system("cls");
				cout << "Все песени заданного композитора:" << endl;
				s.AllSongComposer(a).Save("ppp.txt");
				break;
			}
			case(6):
			{
				cout << endl << "Вывод всех песен заданного исполнителя" << endl;
				cout << "Исполнитель: ";     cin >> a;
				system("cls");
				cout << "Все песени заданного исполнитея:\n";
				Songs ss;
				ss = s.AllSongSinger(a);
				ss.Save("ppp.txt");
				break;
			}
			case(7):
			{
				system("cls");
				cout << endl << "Число песен: ";
				cout << s.NumOfSongs();
				cout << endl;
				break;
			}
			case(8):
			{
				cout << endl << "Удалить песню по названию " << endl;
				cout << "Название песни: ";	  cin >> t;
				s.Remove(t);
				system("cls");
				cout << "Песня удалена";
				cout << endl;
				break;
			}
			case(9):
			{
				s.Save(txt);
				system("cls");
				cout << "Песенник сохранён" << endl;
			}
			case(10):
			{
				s.Open(txt);
			}
			default:
			{
				system("cls");
				break;
			}
			}
		}
		catch (ExSong ex)
		{
			switch (ex.type)
			{
			case(notSong):
			{
				system("cls");
				cout << "Такой песни нет" << endl;
				break;
			}
			case(notAuthor):
			{
				system("cls");
				cout << "Такого автора нет" << endl;
				break;
			}
			case(notComposer):
			{
				system("cls");
				cout << "Такого композитора нет" << endl;
				break;
			}
			case(notSinger):
			{
				system("cls");
				cout << "Такого исполнителя нет" << endl;
				break;
			}
			case(outOfArr):
			{
				system("cls");
				cout << "Выход за пределы массива" << endl;
			}
			default:
				break;
			}
		}
	}
	return 0;
}