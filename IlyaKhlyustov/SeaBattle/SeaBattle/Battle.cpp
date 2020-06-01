#include "Battle.h"
#include<algorithm>
#include<stdio.h>
#include<Windows.h>

void Battle::EnterCoordinate(int& x, int& y){
	while(1){
		char X;
		int Y;
		std::cin >> X >> Y;
		if (X >= 'a' && X <= 'a' + 10 && Y >= 1 && Y <= 10) {
			x = X - 'a';
			y = Y - 1;
			break;
		}
		else {
			std::cout << "Try again!\n";
		}
	}
}

bool Battle::canStandShip(const BattleField& qwe, int x, int y){
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	if (x < 0 || x >= 10 || y < 0 || y >= 10) return 0;
	for(int i = 0;i < 8;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10){
			if (qwe[nx][ny] == 1) return 0;
		}
	}
	return 1;
}

void Battle::print(){
	std::cout << "\t\tYOUR FIELD: \t\t\t\t\tENEMY FIELD\n";
	std::cout << '\t';
	for (int i = 1; i <= 10; i++) std::cout << i << "| ";
	std::cout << "\t\t\t";
	for (int i = 1; i <= 10; i++) std::cout << i << "| ";
	std::cout << '\n';
	for(int i = 0;i < 10;i++){
		std::cout << (char)('a' + i) << '\t';
		for(int j = 0;j < 10;j++){
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			if (me1[i][j] == 3){
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
			} else if (me1[i][j] == 1){
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
			} else if (me1[i][j] == 4){
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
			}
			else SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			std::cout << me1[i][j];
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			std::cout << "| ";
		}
		std::cout << "\t\t";
		std::cout << (char)('a' + i) << '\t';
		for (int j = 0; j < 10; j++) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			if (me2[i][j] == 2) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
			}
			else if (me2[i][j] == 1) {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
			}
			else {
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			}
			std::cout << me2[i][j];
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			std::cout << "| ";
		}
		std::cout << "\n\t";
		for(int j = 0;j < 30;j++){
			std::cout << "-";
		}
		std::cout << "\t\t\t";
		for (int j = 0; j < 30; j++) {
			std::cout << "-";
		}
		std::cout << '\n';
	}
	
}

void Battle::GenerateEnemyField(){
	for(int i = 0;i < 4;i++){
		while(1){
			int x = (rand() << 15) | rand();
			x %= 10;
			int y = (rand() << 15) | rand();
			y %= 10;
			if (canStandShip(comp1, x, y)) {
				comp1[x][y] = 1;
				break;
			}
		}
	}
	for(int i = 0;i < 3;i++){
		while(1){
			int type = rand();
			if (type & 1) {
				int x = (rand() << 15) | rand();
				x %= 10;
				int y1 = (rand() << 15) | rand();
				y1 %= 10;
				int y2 = y1 + 1;
				if (canStandShip(comp1, x, y1) && canStandShip(comp1, x, y2)) {
					comp1[x][y1] = 1;
					comp1[x][y2] = 1;
					break;
				}
			}
			else {
				int y = (rand() << 15) | rand();
				y %= 10;
				int x1 = (rand() << 15) | rand();
				x1 %= 10;
				int x2 = x1 + 1;
				if (canStandShip(comp1, x1, y) && canStandShip(comp1, x2, y)) {
					comp1[x1][y] = 1;
					comp1[x2][y] = 1;
					break;
				}
			}
		}
	}
	for(int i = 0;i < 2;i++){
		while (1) {
			int type = rand();
			if (type & 1) {
				int x = (rand() << 15) | rand();
				x %= 10;
				int y1 = (rand() << 15) | rand();
				y1 %= 10;
				int y2 = y1 + 1;
				int y3 = y2 + 1;
				if (canStandShip(comp1, x, y1) && canStandShip(comp1, x, y2) && canStandShip(comp1, x, y3)) {
					comp1[x][y1] = 1;
					comp1[x][y2] = 1;
					comp1[x][y3] = 1;
					break;
				}
			}
			else {
				int y = (rand() << 15) | rand();
				y %= 10;
				int x1 = (rand() << 15) | rand();
				x1 %= 10;
				int x2 = x1 + 1;
				int x3 = x2 + 1;
				if (canStandShip(comp1, x1, y) && canStandShip(comp1, x2, y) && canStandShip(comp1, x3, y)) {
					comp1[x1][y] = 1;
					comp1[x2][y] = 1;
					comp1[x3][y] = 1;
					break;
				}
			}
		}
	}
	while (1) {
		int type = rand();
		if (type & 1) {
			int x = (rand() << 15) | rand();
			x %= 10;
			int y1 = (rand() << 15) | rand();
			y1 %= 10;
			int y2 = y1 + 1;
			int y3 = y2 + 1;
			int y4 = y3 + 1;
			if (canStandShip(comp1, x, y1) && canStandShip(comp1, x, y2) && canStandShip(comp1, x, y3) && canStandShip(comp1, x, y4)) {
				comp1[x][y1] = 1;
				comp1[x][y2] = 1;
				comp1[x][y3] = 1;
				comp1[x][y4] = 1;
				break;
			}
		}
		else {
			int y = (rand() << 15) | rand();
			y %= 10;
			int x1 = (rand() << 15) | rand();
			x1 %= 10;
			int x2 = x1 + 1;
			int x3 = x2 + 1;
			int x4 = x3 + 1;
			if (canStandShip(comp1, x1, y) && canStandShip(comp1, x2, y) && canStandShip(comp1, x3, y) && canStandShip(comp1, x4, y)) {
				comp1[x1][y] = 1;
				comp1[x2][y] = 1;
				comp1[x3][y] = 1;
				comp1[x4][y] = 1;
				break;
			}
		}
	}
}

bool Battle::CompTurn(){
	while(1){
		int x = (rand() << 15) | rand();
		int y = (rand() << 15) | rand();
		x %= 10;
		y %= 10;
		if (comp2[x][y] == 0){
			std::cout << "Computer said: " << char('a' + x) << y + 1 << '\n';
			if (me1[x][y] == 1){
				cntAliveMe--;
				std::cout << "Computer hit you!\n";
				comp2[x][y] = 2;
				me1[x][y] = 3;//потоплен
				return true;
			}
			else {
				comp2[x][y] = 1;
				me1[x][y] = 4;
				std::cout << "Computer miss!\n";
				return false;
			}
				
			break;
		} 
	}
}

bool Battle::PersonTurn(){
	std::cout << "Your turn to pick: ";
	int x, y;
	EnterCoordinate(x, y);
	if (comp1[x][y] == 1){
		me2[x][y] = 2;
		cntAliveComp--;
		comp1[x][y] = 3;
		std::cout << "You hit computer!\n";
		return true;
	} else {
		me2[x][y] = 1;
		std::cout << "You miss!\n";
		return false;
	}

}

Battle::Battle(){
	me1 = BattleField(Mine);
	me2 = BattleField(Enemy);
	comp1 = BattleField(Mine);
	cntAliveComp = 20;
	cntAliveMe = 20;
	turn = false;
	std::cout << "Set ships\n";
	for(int i = 0;i < 4;i++){
		while(1){
			std::cout << "Enter coordinates 1-deck ships: ";
			int q, w;
			EnterCoordinate(q, w);

			if (canStandShip(me1, q, w)) {
				me1[q][w] = 1;//1 - поле занято кораблем, 2 - корабль потоплен, 0 - свободно	
				break;
			}
			else {
				std::cout << "Try again!\n";
			}
		}
	}
	for(int i = 0;i < 3;i++){
		while(1){
			std::cout << "Enter coordinates 2-deck ships: ";
			int x1, y1, x2, y2;
			EnterCoordinate(x1, y1);
			EnterCoordinate(x2, y2);
			if (abs(x1 - x2) + abs(y1 - y2) != 1) {
				std::cout << "WRONG COORDINATES!";
				std::cout << "Try again!\n";
				return;
			}
			if (canStandShip(me1, x1, y1) && canStandShip(me1, x2, y2)){
				me1[x1][y1] = 1;
				me1[x2][y2] = 1;
				break;
			}
			else {
				std::cout << "Try again!\n";
			}
		}
		
	}
	for(int i = 0;i < 2;i++){
		while(1){
			std::cout << "Enter coordinates 3-deck ships: ";
			std::vector<std::pair<int, int> > a(3);
			for(int j = 0;j < 3;j++){
				EnterCoordinate(a[j].first, a[j].second);
			}
			std::sort(a.begin(), a.end());
			bool ok = 1;
			if (a[1].first == a[0].first){
				if (a[2].first == a[1].first) {
					for(int j = 1;j < 3;j++){
						if (a[j - 1].second + 1 != a[j].second){
							ok = 0;
							break;
						}
					}
				}
				else ok = 0;
			}
			else if (a[1].second == a[0].second) {
				if (a[2].second == a[1].second) {
					for (int j = 1; j < 3; j++) {
						if (a[j - 1].first + 1 != a[j].first) {
							ok = 0;
							break;
						}
					}
				}
				else ok = 0;
			}
			else ok = 0;
			if (ok) for(int i = 0;i < 3;i++){
				if (!canStandShip(me1, a[i].first, a[i].second)){
					ok = 0;
					break;
				}
			}
			if (ok){
				for(int i = 0;i < 3;i++){
					me1[a[i].first][a[i].second] = 1;
				}
				break;
			} else {
				std::cout << "Try again!\n";
			}
		}

	}
	while(1){
		std::cout << "Enter coordinates 4-deck ships: ";
		std::vector<std::pair<int, int> > a(4);
		for (int j = 0; j < 4; j++) {
			EnterCoordinate(a[j].first, a[j].second);
		}
		std::sort(a.begin(), a.end());
		bool ok = 1;
		if (a[1].first == a[0].first) {
			if (a[2].first == a[1].first && a[2].first == a[3].first) {
				for (int j = 1; j < 4; j++) {
					if (a[j - 1].second + 1 != a[j].second) {
						ok = 0;
						break;
					}
				}
			}
			else ok = 0;
		}
		else if (a[1].second == a[0].second) {
			if (a[2].second == a[1].second && a[2].second == a[3].second) {
				for (int j = 1; j < 4; j++) {
					if (a[j - 1].first + 1 != a[j].first) {
						ok = 0;
						break;
					}
				}
			}
			else ok = 0;
		}
		else ok = 0;
		if (ok) for (int i = 0; i < 4; i++) {
			if (!canStandShip(me1, a[i].first, a[i].second)) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			for (int i = 0; i < 4; i++) {
				me1[a[i].first][a[i].second] = 1;
			}
			break;
		}
		else {
			std::cout << "Try again!\n";
		}
	}
	GenerateEnemyField();
	print();
}

Battle::Battle(const Battle& tmp){
	me1 = tmp.me1;
	me2 = tmp.me2;
	comp1 = tmp.comp1;
	cntAliveComp = tmp.cntAliveComp;
	cntAliveMe = tmp.cntAliveMe;
	turn = tmp.turn;
}

Battle& Battle::operator=(const Battle& tmp){
	if (this == &tmp) return *this;
	me1 = tmp.me1;
	me2 = tmp.me2;
	comp1 = tmp.comp1;
	cntAliveComp = tmp.cntAliveComp;
	cntAliveMe = tmp.cntAliveMe;
	turn = tmp.turn;
	return *this;
}

void Battle::startGame(){
	while(1){
		if (cntAliveComp == 0){
			std::cout << "You win! Congratulations!\n";
			return;
		}
		if (cntAliveMe == 0){
			std::cout << "You are loooooser(\n";
			return;
		}
		if (turn) {
			turn ^= CompTurn();
		}
		else {
			turn ^= PersonTurn();
			print();
		}
		turn ^= 1;
		
	}
}
