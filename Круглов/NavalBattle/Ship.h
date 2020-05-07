#ifndef SHIP_H
#define SHIP_H
#include<iostream>

using namespace std;

class Ship {
private:
	int x, y, x1, y1;
public:
	Ship(int _x, int _y, int _x1, int _y1);
	Ship(const Ship& ship);
	int getX() const { return x; }
	int getY() const { return y; }
	int getX1() const { return x1; }
	int getY1() const { return y1; }
	Ship& operator=(const Ship& ship);
};
#endif