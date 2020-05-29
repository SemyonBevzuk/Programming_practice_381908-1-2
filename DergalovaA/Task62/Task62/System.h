#pragma once
#include <iostream>
#include <clocale>
#include <Windows.h>
#include <conio.h>

using namespace std;

// M O V I N G
class Position {

private:
	//COORDINATES
	int x;
	int y;

public:
	friend class Snake;

	Position();
	Position(const Position& c);
	Position(int _x, int _y);

	void TextPos(int _x, int _y);

	friend bool operator==(const Position& left, const Position& right) {
		bool res = false;
		if (left.x == right.x && left.y == right.y) {
			res = true;
		}
		else {
			res = false;
		}
		return res;
	}
};

// C O N S O L E
enum class Move { STOP = 0, LEFT, RIGHT, UP, DOWN };

// P L A Y E R
class Snake {
private:
	bool end;
	Move dir;
	Position tail;
	const int w = 60; //width
	const int h = 20; //height
	int score = 0;
	int frx, fry; //fruit coords
	int x, y; //head
	int* tx = new int[101]; //new tail x
	int* ty = new int[101]; //new tail y
	int count = 0; //length
	int win = 0;
	bool plus; //ate fruit
public:
	Snake();
	~Snake();
	Snake(const Snake& c);

	void Salut();
	void StartGame();
	void Setup();
	void Body();
	void Frame();
	void Fruit();
	void Input();
	void Motion();
	bool Myself(int a, int b);

	friend bool operator==(const Snake& left, const Snake& right) {
		bool res = false;
		if (left.score == right.score && left.frx == right.frx && left.fry == right.fry &&
			left.x == right.x && left.y == right.y && left.count == right.count && left.win == right.win) {
			res = true;
		}
		else {
			res = false;
		}
		return res;
	}
};