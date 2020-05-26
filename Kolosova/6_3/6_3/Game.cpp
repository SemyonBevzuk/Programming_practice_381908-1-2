#include "Game.h"
#include <time.h>
#include <cstdlib>
using namespace std;

Game::Game() { }
int Game::play() {
	p[0].print();
	cout << "Enter ships (size, x, y, h/v)\n";
	p[0].readShips();
	//p[0].setRandomShips();
	p[1].setRandomShips();
	p[0].setOpponent(p[1]);
	p[1].setOpponent(p[0]);
	int turn = 0;
	p[0].print();
	//p[1].print();//////////////////////////////
	int fired;
	while (p[0].shipsAlive && p[1].shipsAlive) {
		cout << "-----------Player " << turn + 1 << " turn------------]\n";
		if (turn == 0) {
			do {
				cout << "Enter coordinates to fire: ";
				int x, y;
				cin >> x >> y;
				//x = rand() % 10;
				//y = rand() % 10;
				fired = p[0].shoot(x-1, y-1);
				switch (fired) {
				case -1:
					if (p[1].shipsAlive == 0) return turn;
					cout << "Invalid coordinates. Try again!\n";
					break;
				case 1:
					p[1].registerHit('*', x-1, y-1);
					p[0].print();
					//p[1].print();//////////////////////////////
					cout << "Hit! You can shoot again.\n";
					break;
				case 2:
					p[1].registerHit('X', x-1, y-1);
					p[0].print();
					//p[1].print();//////////////////////////////
					if (p[1].shipsAlive == 0) {
						return turn;
					}
					cout << "Ship destroyed! You can shoot again.\n";
					break;
				case 0:
					p[1].registerHit('.', x-1, y-1);
					p[0].print();
					//p[1].print();//////////////////////////////
					cout << "Miss! Press any key to continue.\n";
					break;
				default:
					cout << "default/////////////////////////\n";
				}
			} while (fired);
			system("pause");
		}
		else {
			int x, y;
			int fired;
			do {
				x = rand() % 10;
				y = rand() % 10;
				fired = p[1].shoot(x, y);
				switch (fired) {
				case 0:
					p[0].registerHit('.', x, y);
					p[0].print();
					//p[1].print();//////////////////////////////
					cout << "Opponent fired at (" << x+1 << ", " << y+1 << ").\n";
					break;
				case 1:
					p[0].registerHit('*', x, y);
					p[0].print();
					//p[1].print();//////////////////////////////
					cout << "Opponent hit your ship at (" << x+1 << ", " << y+1 << ")! Press any key to continue.\n";
					system("pause");
					break;
				case 2:
					p[0].registerHit('X', x, y);
					p[0].print();
					//p[1].print();//////////////////////////////
					cout << "Opponent destroyed your ship at (" << x+1 << ", " << y+1 << ")! Press any key to continue.\n";
					system("pause");
					if (p[0].shipsAlive == 0) {
						return turn;
					}
					break;
				}
			} while (fired);
		}
		turn++;
		turn %= 2;
	}
	return turn;
}

void Game::dispatcher() {
	char ch = 'y';
	while (ch == 'y') {
		p = new Player[2];
		int winner = play() + 1;
		cout << "Player " << winner << " won! Play again? (y/n) ";
		cin >> ch;
	}
	return;
}