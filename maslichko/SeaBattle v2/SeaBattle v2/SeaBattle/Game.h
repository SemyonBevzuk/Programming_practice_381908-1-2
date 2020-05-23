#include <ctime>
#include <cstdlib>
#include "CreateField.h"

class Game
{
private:
	CreateField field_user;
	CreateField field_pc;
public:
	Game(CreateField& user, CreateField& pc)
	{
		field_user = user;
		field_pc = pc;
	}

	void Print(); //Вывод полей

	int Step_user(int i, int j); //Ход игрока

	int Step_pc(); //Ход компьютера
};

