#include "Bulls_Cows.h"
#include <clocale>
using namespace std;

int main()
{
	setlocale(0, "");
	Bulls_Cows game;
	int len, attempt(0);
	do
	{
		cout << "Введите длину числа: ";
		cin >> len;
	} while (!game.newNumber(len));
	cout << "Число загадано!\n\n";

	int bull(0), cow(0);
	string number;
	bool end;
	do
	{
		do
		{
			cout << "Введите число: ";
			cin >> number;
		} while (!game.checkCorrect(number));

		attempt++;
		cout << "Быков: " << bull << "\nКоров: " << cow << '\n';
		end = game.checkBullCow(number, bull, cow);

	} while (!end);
	cout << "\n    Вы выиграли!\n    Количество ходов: " << attempt << '\n';
}