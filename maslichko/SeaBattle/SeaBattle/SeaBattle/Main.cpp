#include "Game.h"
using namespace std;

int main()
{
	SetConsoleCP(1251); //Установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //В поток вывода

	int i1, i2, i3, i4, j1, j2, j3, j4; //Для ввода координат кораблей игрока
	int ctrl_user = 0, ctrl_pc = 0, ctrl_temp = 0; //Контроль игры
	int mass[40] = { 0,0, 0,4, 0,8, 4,0, 2,2, 3,2, 2,8, 3,8, 4,5, 4,6, 6,1, 6,2, 6,3, 6,6, 7,6, 8,6, 9,0, 9,1, 9,2, 9,3 }; //Координаты кораблей компьютера

	CreateField cf_pc(mass); //Расстановка кораблей компьютера
	CreateField cf_user;
	
	system("cls"); //Очищаем консоль
	
	//Расстановка кораблей игрока
	for (int q = 0; q < 4; q++)
	{
		cout << "Введите координаты однопалубного коробля: ";
		cin >> i1 >> j1;
		cf_user.Vessel(i1, j1);
	}

	for (int q = 0; q < 3; q++)
	{
		cout << "Введите координаты двухпалубного коробля: ";
		cin >> i1 >> j1 >> i2 >> j2;
		cf_user.Vessel(i1, j1, i2, j2);
	}

	for (int q = 0; q < 2; q++)
	{
		cout << "Введите координаты трехпалубного коробля: ";
		cin >> i1 >> j1 >> i2 >> j2 >> i3 >> j3;
		cf_user.Vessel(i1, j1, i2, j2, i3, j3);
	}

	cout << "Введите координаты четырехпалубного коробля: ";
	cin >> i1 >> j1 >> i2 >> j2 >> i3 >> j3 >> i4 >> j4;
	cf_user.Vessel(i1, j1, i2, j2, i3, j3, i4, j4);

	Game game(cf_user, cf_pc);
	system("cls"); //Очищаем консоль
	while (ctrl_user != 20 || ctrl_pc != 20) //Пока не будет 20(сумма всех клеток кораблей) попаданий у кого-либо из сторон
	{
		if (ctrl_user == 20)
		{
			system("cls"); //Очищаем консоль
			cout << "Вы выиграли";
			return 0;
		}
		else if (ctrl_pc == 20)
		{
			system("cls"); //Очищаем консоль
			cout << "Выиграл компьютер";
			return 0;
		}

		Sleep(500);
		system("cls"); //Очищаем консоль
		game.Print();

		if (ctrl_user == ctrl_temp)
		{
			cout << endl << "Ход: ";
			cin >> i1 >> j1;
			int t = game.Step_user(i1, j1);
			if (t == 1)
			{
				cout << endl << "Попадание";
				ctrl_user++;
				ctrl_temp = ctrl_user; //Приравниваем для следующего хода

			}
			else if (t == 0)
			{
				cout << endl << "Промах";
				ctrl_temp = -1; //Меняем значение для хода соперника
			}
		}
		else
		{
			int t = game.Step_pc();
			if (t == 1)
			{
				ctrl_pc++;
				ctrl_temp = -1;
				cout << endl << "Попадание";
			}
			else if (t == 0)
			{
				ctrl_temp = ctrl_user;
				cout << endl << "Промах";
			}
		}
	}
	return 0;
}