#include "Game.h"
#include <iostream>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int n;
	cout << "Введите длину загадываемого числа: "; cin >> n;
	while (n < 1 || n > 10)
	{
		cout << "Длина должна быть от 1 до 10!" << endl;
		cin >> n;
	}
	Game game;
	game.GenerateNumber(n);
	string number;
	while (game.GetBulls() != n)
	{
		cout << "--------------------------------------" << endl;
		cout << "Попытайтесь отгадать число: "; cin >> number;
		if (game.VerifyNumber(number))
		{
			cout << "Количество ""коров"": " << game.GetCows() << endl;
			cout << "Количество ""быков"": " << game.GetBulls() << endl;
		}
		else
			cout << "Введите число длины " << n << " с неповторяющимися цифрами!" << endl;
	}
	cout << "Вы отгадали всю последовательность!" << endl;
	system("pause");
}