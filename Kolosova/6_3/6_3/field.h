#pragma once
#include <iostream>

using namespace std;

class Ship {
	int size;
	int hp;
	int x, y;
	char orientation;
public:
	Ship();
	Ship(int sz, int xs, int ys, char ori);
	friend istream& operator>>(istream& in, Ship& ship);
	int getsize() { return size; }
	char getori() { return orientation; }
	int X() { return x; }
	int Y() { return y; }
	int HP() { return hp; }
	void hit() { hp--; }
	void set(int xs, int ys, char ori);
	void setsize(int sz);
};

class Field{
	char cgrid[10][10];
	Ship* pgrid[10][10] = {};
	bool isOwn;
	int lastHitX, lastHitY;
public:
	Field();
	void set(Field& f, bool isown);
	bool placeShip(Ship& s);
	void print();
	void print(Field& f);
	char& operator()(int x, int y) { return cgrid[y][x]; }
	Ship* getp(int x, int y) { return pgrid[y][x]; }
	bool sink(int x, int y, bool isEnemy);
	void setLH(int x, int y);
};
bool checkRange(int x, int y);