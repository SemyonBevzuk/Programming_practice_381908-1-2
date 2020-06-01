#pragma once

#include"BattleField.h"

class Battle{
private:
	BattleField me1, me2;//��� ����, ���� �����(������� ����� �����)
	BattleField comp1, comp2;//���� �����
	int cntAliveMe;//���-�� ���� ���������� ������
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

