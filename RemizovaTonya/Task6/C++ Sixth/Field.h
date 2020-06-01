#pragma once
#include<iostream>
#include <time.h>
#include <stdlib.h>
#include"Ship.h"
#include <windows.h>
using namespace std;

class field {

protected:
	int** pai;
public:
	field();
	~field();

	void Draw();
	bool CheckSet(int t, int siz, int xx, int yy);
	bool shoot(int xx, int yy);
	void eshoot(int xx, int yy, bool miss);
	bool win(ship s[]);
	bool coincident(int x, int y);
	ship gen(int m);
	void dead(int t, int s, int x, int y)
};