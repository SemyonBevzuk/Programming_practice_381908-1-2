#include "Game.h"

void Game::Print()
{
	cout << field_user;
}

int Game::Step_user(int i, int j) //Ход игрока
{
	if (field_pc.field_main[i][j] == "X ") //Если попал
	{
		field_user.field_second[i][j] = "X "; //На своей второй карте отмечаю попадание
		field_pc.field_main[i][j] == "Z "; //На карте соперника отмечаю пробитие
		return 1;
	}
	else
	{
		field_user.field_second[i][j] = "M "; //Если промах, отмечаю это на своей второй карте
		return 0;
	}
}

int Game::Step_pc() //Ход коптьютера
{
	int i = 0, j = 0, q = 0;
	srand(time(NULL)); //Берем системное время за основу генератора
	while (q == 0) //Генерируем, пока не будет получена координата, которая еще не использовалась
	{
		i = rand() % 9; //От 0 до 9
		j = rand() % 9;
		if (field_pc.field_second[i][j] == "O ") //Если в эту точку еще не было хода, то выходим из цикла
		{
			q = 1;
		}
		else //Иначе генерируем новые координаты
		{
			i = rand() % 9;
			j = rand() % 9;
		}
	}

	if (field_user.field_main[i][j] == "X ") // Если попал
	{
		field_pc.field_second[i][j] = "X "; //Отмечаем на второй карте попадание
		field_user.field_main[i][j] = "Z "; //На карте игрока отмечаем пробитие
		return 1;
	}
	else
	{
		field_pc.field_second[i][j] = "M "; //Отмечаем промах
		field_user.field_main[i][j] = "M "; //На карте игрока отмечаем ход
	}
	return 0;
}