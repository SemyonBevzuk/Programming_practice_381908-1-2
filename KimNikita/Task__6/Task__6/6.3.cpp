#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <locale>
#include "GameField.h"
#include "AI.h"

using namespace std;

int translate(string c)
{
	if (c == "10")
		return 9;
	if (c[0] < 58)
		return c[0] - 49;
	char k = tolower(c[0]);
	return k - 97;
}
string translate(Shot shot)
{
	string rez;
	switch (shot.X)
	{
	case 0:rez += 'A'; break;
	case 1:rez += 'B'; break;
	case 2:rez += 'C'; break;
	case 3:rez += 'D'; break;
	case 4:rez += 'E'; break;
	case 5:rez += 'F'; break;
	case 6:rez += 'G'; break;
	case 7:rez += 'H'; break;
	case 8:rez += 'I'; break;
	case 9:rez += 'J'; break;
	}
	rez += ' ' + to_string(shot.Y + 1);
	return rez;
}
bool iscorrectvvod(string s)
{
	int k = 0;
	string num;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			if (num.size() != 0)
			{
				if (atoi(num.c_str()) < 1 || atoi(num.c_str()) > 10)
					return false;
				num = "";
				k++;
			}
			if (!(s[i] > 64 && s[i] < 91 || s[i]>96 && s[i] < 123))
				return false;
			k++;
		}
		else
		{
			num += s[i];
		}
	}
	if (k == 3 || k == 5)
		return true;
	return false;
}
int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russia");
	GameField field;
	AI comp(field);
	string x, y, x1, y1, pass;
	bool f;
	// размещение кораблей
	field.AddAIShip(4);
	field.AddAIShip(3);
	field.AddAIShip(3);
	field.AddAIShip(2);
	field.AddAIShip(2);
	field.AddAIShip(2);
	field.AddAIShip(1);
	field.AddAIShip(1);
	field.AddAIShip(1);
	field.AddAIShip(1);
	cout << field;
	do
	{
		f = true;
		cout << "Введите координаты четырехпалубного корабля (пример A 1 D 1) :" << endl;
		cin >> x >> y >> x1 >> y1;
		if (!field.IsCorrectShip(translate(x), translate(y), translate(x1), translate(y1), 4) || !iscorrectvvod(x + y + x1 + y1 + "v"))
		{
			f = false;
		}
		else
		{
			if (!field.AddUserShip(Ship(translate(x), translate(y), translate(x1), translate(y1))))
				f = false;
		}
		system("cls");
		cout << field;
	} while (!f);
	for (int i = 0; i < 2; i++)
	{
		do
		{
			f = true;
			cout << "Введите координаты трехпалубного корабля (пример A 1 С 1) :" << endl;
			cin >> x >> y >> x1 >> y1;
			if (!field.IsCorrectShip(translate(x), translate(y), translate(x1), translate(y1), 3) || !iscorrectvvod(x + y + x1 + y1 + "v"))
			{
				f = false;
			}
			else
			{
				if (!field.AddUserShip(Ship(translate(x), translate(y), translate(x1), translate(y1))))
					f = false;
			}
			system("cls");
			cout << field;
		} while (!f);
	}
	for (int i = 0; i < 3; i++)
	{
		do
		{
			f = true;
			cout << "Введите координаты двухпалубного корабля (пример A 1 B 1) :" << endl;
			cin >> x >> y >> x1 >> y1;
			if (!field.IsCorrectShip(translate(x), translate(y), translate(x1), translate(y1), 2) || !iscorrectvvod(x + y + x1 + y1 + "v"))
			{
				f = false;
			}
			else
			{
				if (!field.AddUserShip(Ship(translate(x), translate(y), translate(x1), translate(y1))))
					f = false;
			}
			system("cls");
			cout << field;
		} while (!f);
	}
	for (int i = 0; i < 4; i++)
	{
		do
		{
			f = true;
			cout << "Введите координаты однопалубного корабля (пример A 1) :" << endl;
			cin >> x >> y;
			if (!field.IsCorrectShip(translate(x), translate(y), translate(x), translate(y), 1) || !iscorrectvvod(x + y + "v"))
			{
				f = false;
			}
			else
			{
				if (!field.AddUserShip(Ship(translate(x), translate(y), translate(x), translate(y))))
					f = false;
			}
			system("cls");
			cout << field;
		} while (!f);
	}
	//игра
	Shot comp_shot;
	int order = rand() % 2 + 1;
	int rez;
	while (true)
	{
		if (order == 1)
		{
			f = true;
			do
			{
				cout << "Введите координаты выстрела (пример A 1) :" << endl;
				cin >> x >> y;
				getchar();
				if (!field.IsCorrectShot(translate(x), translate(y)) || !iscorrectvvod(x + y + "v"))
				{
					f = false;
				}
				else
				{
					rez = field.ShotResult(Shot(translate(x), translate(y)), 2);
					if (rez == 0)
					{
						f = false;
					}
					if (rez == -1)
					{
						order = 2;
						do
						{
							system("cls");
							cout << field;
							cout << "Промах!" << " (нажмите ""Enter"" для продолжения)" << endl;
						} while (getchar() != 10);
					}
					if (rez == 1)
					{
						int end = field.IsGameOver();
						if (end)
						{
							system("cls");
							cout << field;
							if (end == 1)
								cout << "Вы проиграли :(" << endl;
							else
								cout << "Вы выиграли!" << endl;
							return 0;
						}
						do
						{
							system("cls");
							cout << field;
							cout << "Попадание!" << " (нажмите ""Enter"" для продолжения)" << endl;
						} while (getchar() != 10);
					}
					if (rez == 2)
					{
						int end = field.IsGameOver();
						if (end)
						{
							system("cls");
							cout << field;
							if (end == 1)
								cout << "Вы проиграли :(" << endl;
							else
								cout << "Вы выиграли!" << endl;
							return 0;
						}
						do
						{
							system("cls");
							cout << field;
							cout << "Корабль уничтожен!" << " (нажмите ""Enter"" для продолжения)" << endl;
						} while (getchar() != 10);
					}
				}
				system("cls");
				cout << field;
			} while (!f);
		}
		else
		{
			comp_shot = comp.AIShot(field, rez);
			if (rez == -1)
			{
				order = 1;
				do
				{
					system("cls");
					cout << field;
					cout << "Компьютер промахнулся в " + translate(comp_shot) << " (нажмите ""Enter"" для продолжения)" << endl;
				} while (getchar() != 10);
			}
			if (rez == 1)
			{
				do
				{
					system("cls");
					cout << field;
					cout << "Компьютер попал в " + translate(comp_shot) << " (нажмите ""Enter"" для продолжения)" << endl;
				} while (getchar() != 10);
			}
			if (rez == 2)
			{
				do
				{
					system("cls");
					cout << field;
					cout << "Компьютер уничтожил корабль в " + translate(comp_shot) << " (нажмите ""Enter"" для продолжения)" << endl;
				} while (getchar() != 10);
			}
			system("cls");
			cout << field;
		}
	}
}
