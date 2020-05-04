#include"Ship.h"

using namespace std;

Ship::Ship(int _x, int _y, int _x1, int _y1) {
	x = _x;
	y = _y;
	x1 = _x1;
	y1 = _y1;
}

Ship::Ship(const Ship& ship) {
	x = ship.x;
	y = ship.y;
	x1 = ship.x1;
	y1 = ship.y1;
}

Ship& Ship::operator=(const Ship& ship) {
	if (this == &ship) {
		return *this;
	}
	x = ship.x;
	y = ship.y;
	x1 = ship.x1;
	y1 = ship.y1;
	return *this;
}