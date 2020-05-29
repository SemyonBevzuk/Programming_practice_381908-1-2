#include "Credit.h"
#include "ProcCenter.h"

int main() {
	setlocale(LC_CTYPE, "Russian");
	Credit n;
	ProcCenter center;
	string cash;
	cash =	center.SetPers("Dobrynya", "Hero", "Nikitych", "rysmother", 330246);
	cash = center.SetPers("Iliya", "Hero", "Muroumets", "donotwhistle", 777000);
	cash = center.SetPers("Alex", "Hero", "Popovich", "lyubava", 12345);
	cash = center.SetPers("Yuliy", "Best", "Horse", "tamtigidam", 99999);

	n.SignInOrUp(center);

	getchar();
	getchar();
	return 0;
}