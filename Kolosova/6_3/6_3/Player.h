#pragma once
#include <vector>
#include "field.h"

using namespace std;

class Player {
	Field own, enemy;
	vector<Ship> ships;
public:
	int shipsAlive;
	Player();
	void print();
	void readShips();
	void setOpponent(Player& p);
	bool placeShip(Ship& ship, bool isRand);
	void setRandomShips();
	int shoot(int x, int y); //-1-unable to shoot, 0-no hit, 1-hit, shoot again, 2-ship sunk, shoot again
	char checkHit(int x, int y);
	void registerHit(char ch, int x, int y);
};