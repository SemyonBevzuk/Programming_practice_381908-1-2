#include "field.h"
//#include "console.cpp"
using namespace std;

Ship::Ship() {
	size = 0;
	hp = 0;
	x = -1;
	y = -1;
}

Ship::Ship(int sz, int xs, int ys, char ori) {
	hp = size = sz;
	x = xs;
	y = ys;
	orientation = ori;
}

istream& operator>>(istream& in, Ship& s) {
	in >> s.size >> s.x >> s.y >> s.orientation;
	s.x--;
	s.y--;
	if (s.size > 4) s.size = 4;
	s.hp = s.size;
	return in;
}
void Ship::set(int xs, int ys, char ori) {
	x = xs;
	y = ys;
	orientation = ori;
}
void Ship::setsize(int sz) {
	hp = size = sz;
}
////////////////////////////////////////////////////

Field::Field() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cgrid[i][j] = '~';
	isOwn = true;
	lastHitX = lastHitY = -1;
}
void Field::set(Field& f, bool isown) {
	if (!isown) {
		for(int i=0;i<10;i++)
			for (int j = 0; j < 10; j++) {
				pgrid[i][j] = f.pgrid[i][j];
				cgrid[i][j] = '~';
			}
	}
	else {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				pgrid[i][j] = f.pgrid[i][j];
				cgrid[i][j] = f.cgrid[i][j];
			}
	}
}
bool Field::placeShip(Ship& s) {
	char ori = s.getori();
	int x = s.X(), y = s.Y();
	if (!checkRange(x, y)) return false;
	if (ori == 'h') {
		int i;
		for (i = x - 1; i < s.getsize() + x + 1; i++) {
			if (i < 0) continue;
			if (i > 9 && i - x < s.getsize()) return false;
			if (i > 9) break;
			for (int j = y - 1; j < y + 2 && j<10; j++) {
				if (j < 0 || j > 9) continue;
				if (cgrid[j][i] != '~') return false;
			}
		}
		for (i = x; i < x + s.getsize(); i++) {
			cgrid[y][i] = '#';
			pgrid[y][i] = &s;
		}
		return true;
	}
	else if (ori == 'v') {
		int i;
		for (i = y - 1; i < s.getsize() + y + 1; i++) {
			if (i < 0) continue;
			if (i > 9 && i - y < s.getsize()) return false;
			if (i > 9) break;
			for (int j = x - 1; j < x + 2; j++) {
				if (j < 0 || j > 9)continue;
				if(cgrid[i][j] != '~') return false;
			}
		}
		for (i = y; i < y + s.getsize(); i++) {
			cgrid[i][x] = '#';
			pgrid[i][x] = &s;
		}
		return true;
	}
	else return false;
}
void Field::print() {
	cout << "  ";
	for (int i = 1; i < 11; i++)
		cout << i<<' ';
	cout << endl;
	for (int i = 1; i < 11; i++) {
		cout << (i == 10) ? "": " ";
		cout << i;
		for (int j = 1; j < 11; j++)
			cout << cgrid[i][j]<<' ';
		cout << endl;
	}
	if (lastHitX >= 0 && lastHitY >= 0) cout <<"Last hit at "<< lastHitX << ' ' << lastHitY << endl;
}
void Field::print(Field& f) {
	//clrscr();
	cout << "  ";
	for (int i = 1; i < 11; i++)
		cout << i<<' ';
	cout << "|     ";
	for (int i = 1; i < 11; i++)
		cout << i<<' ';
	cout << endl;
	for (int i = 1; i < 11; i++) {
		cout << i;
		cout << ((i == 10) ? "\0" : " ");
		for (int j = 0; j < 10; j++)
			cout << cgrid[i - 1][j] << ' ';
		cout << " |   ";
		cout << i;
		cout << ((i == 10) ? "" : " ");
		for (int j = 0; j < 10; j++)
			cout << f.cgrid[i-1][j]<<' ';
		cout << endl;
	}
	if (lastHitX >= 0 && lastHitY >= 0) cout << "Last hit at " << lastHitX +1 << ' ' << lastHitY + 1 << endl;;
}

bool Field::sink(int x, int y, bool isEnemy) {
	Ship* s = pgrid[y][x];
	int size = s->getsize();
	x = s->X();
	y = s->Y();
	if (s == nullptr) return false;
	if (s->getori() == 'h') {
		for(int sx = x - 1; sx < x + size + 1; sx++)
			for (int sy = y - 1; sy < y + 2; sy++) {
				if (checkRange(sx, sy)) {
					if (pgrid[sy][sx] == nullptr) {
						if (isEnemy)
							cgrid[sy][sx] = '.';
					}
					else cgrid[sy][sx] = 'X';
				}
			}
	}
	else {
		for (int sy = y - 1; sy < y + size + 1; sy++)
			for (int sx = x - 1; sx < x + 2; sx++) {
				if (checkRange(sx, sy)) {
					if (pgrid[sy][sx] == nullptr) {
						if (isEnemy)
							cgrid[sy][sx] = '.';
					}
					else cgrid[sy][sx] = 'X';
				}
			}
	}
	return true;
}

bool checkRange(int x, int y) {
	if (x < 0 || y < 0 || x>9 || y>9) return false;
	return true;
}
void Field::setLH(int x, int y) {
	lastHitX = x;
	lastHitY = y;
}