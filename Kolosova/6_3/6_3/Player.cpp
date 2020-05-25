#include "Player.h"
using namespace std;

Player::Player(){
	shipsAlive = 0;
}

void Player::print(){
	own.print(enemy);
}

void Player::readShips(){
	int count[5] = {};
	for (int i = 0; i < 10; i++) {
		Ship s;
		bool isAdded = false;
		bool shipPlaced = false;
		do {
			cin >> s;
			if (count[s.getsize()] >= 5 - s.getsize()) {
				cout << "You cannot place any more ships of this size.\n";
				continue;
			}
			if (isAdded) ships.pop_back();
			ships.push_back(s);
			isAdded = true;
			shipPlaced = placeShip(ships[i], false);
		} while (!shipPlaced);
		count[s.getsize()]++;
		print();
	}
	shipsAlive = 10;
}

void Player::setOpponent(Player& p) {
	enemy.set(p.own, false);
}

bool Player::placeShip(Ship& ship, bool isRand){
	bool res=own.placeShip(ship);
	if (!res&&!isRand) cout << "Invalid input. Try again.\n";
	return res;
}

void Player::setRandomShips(){
	int count[5] = {0, 4, 3, 2, 1};
	int k = 4;
	for(int i=1;i<5;i++)
		for (int j = 0; j < count[i]; j++) {
			Ship s(i, -1, -1, 0);
			ships.push_back(s);
		}
	for (int i = 0; i < 10; i++) {
		do {
			int x = rand() % 10;
			int y = rand() % 10;
			char ori = ((rand() % 2) ? 'h' : 'v');
			ships[i].set(x, y, ori);
		} while (!placeShip(ships[i], true));
	}
	shipsAlive = 10;
}

int Player::shoot(int x, int y){
	if (x < 0 || y < 0 || x>9 || y>9 || enemy(x, y) != '~') return -1;
	char ch = checkHit(x, y);
	if (ch) own.setLH(x, y);
	Ship* s = enemy.getp(x, y);
	switch (ch) {
	case 0:
		return -1;
	case '.':
		enemy(x, y) = '.';
		return 0;
	case '*':
		s->hit();
		enemy(x, y) = '*';
		return 1;
	case 'X':
		s->hit();
		enemy.sink(x, y, true);
		return 2;
	default:
		return -5;
	}
}

char Player::checkHit(int x, int y){
	Ship* s = enemy.getp(x, y);
	if (s == nullptr) return '.';
	if (s->HP() > 1) return '*';
	if (s->HP() < 1) return 0;
	if (s->HP() == 1) return 'X';
	return ' ';
}

void Player::registerHit(char ch, int x, int y){
	if (ch != 'X') {
		own(x, y) = ch;
		own.setLH(x, y);
	}
	else {
		own.sink(x, y, false);
		own.setLH(x, y);
		shipsAlive--;
	}
}
