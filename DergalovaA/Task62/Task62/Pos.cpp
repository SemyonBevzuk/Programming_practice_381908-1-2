#include "System.h"

Position::Position() {
	x = 0;
	y = 0;
}

Position::Position(const Position& c) {
	x = c.x;
	y = c.y;
}

Position::Position(int _x, int _y) {
	x = _x;
	y = _y;
}

void Position::TextPos(int _x, int _y) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos;
	cursorPos.X = _x;
	cursorPos.Y = _y;
	SetConsoleCursorPosition(hStdOut, cursorPos);
}
