#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include<iostream>
#include"Ship.h"

using namespace std;

class Battlefield {
private:
	string ABC = "ABCDEFGHIJ";
	short UserField[10][10]{};// -2: попадание; -1:промах; 0:с этой клеткой ничего не делали ; 1: корабль ;
	short CompField[10][10]{};
	string printHelpUser(int a) const;
	string printHelpComp(int a) const;
public:
	bool isCorrectlyLocation(int x, int y, int x1, int y1, bool side);
	void addShip(const Ship& ship, bool side);
	void addCompShip(int dec);
	bool userShot(int x, int y);
	int operator()(int x, int y, string side);
	bool isGameOver();
	friend ostream& operator<<(ostream& stream, const Battlefield& field);
	friend class AI;
};

#endif