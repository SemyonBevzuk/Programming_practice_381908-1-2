#pragma once

#include "Ship.h"
#include "Shot.h"
#include <string>
#include <vector>

using namespace std;

class GameField
{
private:
	string alf;
	int ColUserDecks;
	int ColAIDecks;
	int UserField[10][10];// 0 промах 1 корабль -1 пусто 2 мертвая палуба
	int AIField[10][10];
	bool TryToDestroyShip(int x, int y, int side);
	bool IsAroundClear(int x, int y, int side);
	int& Cell(int x, int y, int side);
	int CellForBool(int x, int y, int side);
	char UserCell(int c)const;
	char AICell(int c)const;
public:
	GameField();
	bool AddUserShip(Ship ship);
	void AddAIShip(int type);
	int ShotResult(Shot shot, int side);// 1 попал -1 промах 2 убил 0 нельзя
	int IsGameOver();
	bool IsCorrectShip(int x, int y, int x1, int y1, int type);
	bool IsCorrectShot(int x, int y);
	friend ostream& operator<<(ostream& out, const GameField& field);
	friend class AI;
};

