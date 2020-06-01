#pragma once

#include"BattleField.h"

class Battle{
private:
	BattleField me1, me2;//своё поле, поле врага(которое видит игрок)
	BattleField comp1, comp2;//поле врага
	int cntAliveMe;//кол-во моих оставшихся клеток
	int cntAliveComp;
	void EnterCoordinate(int& x, int& y);
	bool canStandShip(const BattleField & qwe, int x, int y);
	void print();
	bool turn;
	void GenerateEnemyField();
	bool CompTurn();
	bool PersonTurn();
public:
	Battle();
	Battle(const Battle& tmp);
	Battle& operator=(const Battle& tmp);
	void startGame();
};

