#include "Game.h"
#include <ctime>

void Game::GenerateNumber(int n)
{
	number = "";
	cows = bulls = 0;
	if (n < 1 || n > 10) return;
	int size = 9;
	char mas[] = {'1', '2', '3' , '4' , '5' , '6' , '7' , '8' , '9'};
	srand((unsigned int)time(NULL));
	int i = rand() % size;
	number += mas[i];
	mas[i] = '0';
	while (number.size() < n)
	{
		i = rand() % size;
		number += mas[i];
		size--;
		for (; i < size; i++)
			mas[i] = mas[i + 1];
	}
}

bool Game::VerifyNumber(string _number)
{
	cows = bulls = 0;
	int size = _number.size();
	if (number.size() != size) return false;
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
			if (_number[i] == _number[j]) return false;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			if (_number[i] == number[j])
				if (i == j)
					bulls++;
				else
					cows++;
	return true;
}