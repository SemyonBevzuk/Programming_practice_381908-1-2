#include "Songs.h"

void main()
{
	setlocale(LC_CTYPE, "Russian");
	Songs S;
	Song song;
	string str, str1;
	ofstream os;
	ifstream is;
	char c;
	while (true)
	{
		cout << "------------------------------------------------" << endl;
		cout << "0 - сохранить песенник в файл" << endl;
		cout << "1 - считать песенник из файла" << endl;
		cout << "2 - добавить песню" << endl;
		cout << "3 - изменить данные песни, выбранной по названию" << endl;
		cout << "4 - найти песню по названию и исполнителю" << endl;
		cout << "5 - выдать все песни заданного поэта" << endl;
		cout << "6 - выдать все песни заданного композитора" << endl;
		cout << "7 - выдать все песни заданного исполнителя" << endl;
		cout << "8 - узнать текущее число песен" << endl;
		cout << "9 - удалить песню по названию" << endl;
		cout << "------------------------------------------------" << endl;
		cin >> c;
		system("cls");
		switch (c)
		{
		case '0':
			cout << "Имя файла: "; cin >> str;
			os.open(str);
			os << S;
			os.close();
			break;
		case '1':
			cout << "Имя файла: "; cin >> str;
			is.open(str);
			is >> S;
			is.close();
			break;
		case '2':
			cout << "Название: "; cin >> song.title;
			cout << "Поэт: "; cin >> song.poet;
			cout << "Композитор: "; cin >> song.composer;
			cout << "Исполнитель: "; cin >> song.singer;
			cout << "Альбом: "; cin >> song.album;
			cout << "Дата выпуска: "; cin >> song.date;
			S.AddSong(song);
			break;
		case '3':
			cout << "Название: "; cin >> str;
			cout << "Что будем менять?" << endl;
			cout << "-----------------" << endl;
			cout << "t - название" << endl;
			cout << "p - поэт" << endl;
			cout << "c - композитор" << endl;
			cout << "s - исполнитель" << endl;
			cout << "a - альбом" << endl;
			cout << "d - дата выпуска" << endl;
			cout << "-----------------" << endl;
			cin >> c;
			cout << "Новое значение: ";  
			if (c == 'd')
			{
				Date date;
				cin >> date;
				S.ChangeSong(str, c, "", date);
			}
			else
			{
				cin >> str1;
				S.ChangeSong(str, c, str1);
			}
			break;
		case '4':
			cout << "Название: "; cin >> str;
			cout << "Исполнитель: "; cin >> str1;
			cout << S.FindSong(str, str1);
			break;
		case '5':
			cout << "Поэт: "; cin >> str;
			S.AllByPoet(str);
			break;
		case '6':
			cout << "Композитор: "; cin >> str;
			S.AllByComposer(str);
			break;
		case '7':
			cout << "Исполнитель: "; cin >> str;
			S.AllBySinger(str);
			break;
		case '8':
			cout << "Всего песен: " << S.Number() << endl;
			break;
		case '9':
			cout << "Название: "; cin >> str;
			S.Delete(str);
			break;
		default:
			return;
		}
		system("pause");
		system("cls");
	}
}