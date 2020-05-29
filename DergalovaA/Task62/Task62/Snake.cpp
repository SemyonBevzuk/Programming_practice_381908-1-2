#include "System.h"

// C O N S T R U C T O R S
Snake::Snake()
{
	end = false;
	score = 0;
	frx = 0;
	fry = 0;
	x = w / 2;
	y = h / 2;
	count = 0;
	dir = Move::STOP;
	win = 0;
}

Snake::Snake(const Snake& c)
{
	if (count != 0) {
		count = c.count;
		delete[] tx;
		delete[] ty;
	}
	score = c.score;
	frx = c.frx;
	fry = c.fry;
	x = c.x;
	y = c.y;
	dir = c.dir;
	end = c.end;
	win = c.win;
}

// D E S T R U C T O R
Snake::~Snake()
{
	delete[] tx;
	delete[] ty;
}

// S T A R T   W I N D O W
void Snake::Salut() {
	Position p;
	p.TextPos(27, 6);
	cout << "GAME 'SNAKE'";
	Sleep(1000);
	StartGame();
}

// G A M E
void Snake::StartGame() {
	Position p;
	
	do {
		system("cls");
		p.TextPos(27, 6);
		cout << "GAME 'SNAKE'";
		p.TextPos(27, 8);
		cout << "Fruit to win:";
		win = 0;
		p.TextPos(33, 10);
		cin >> win;
	} while (win < 0 || win > 100);
	Sleep(1000);
	system("cls");
	Setup(); //Spawn
	Frame(); //Design
	Fruit(); //Eat

	while (!end) {
		Body();
		Input();
		Motion();
		if (score == win) end = true;
	}

	system("cls");
	p.TextPos(17, 10);
	cout << "You collected " << score << " / " << win << " fruit";
	if (score == win) {
		p.TextPos(27, 12);
		cout << "WIN!";
	}
	Sleep(2000);
	system("cls");
	Salut();
}

// D E F A U L T   S E T T I N G S
void Snake::Setup() {
	end = false;
	x = w / 2 - 1;
	y = h / 2 - 1;
	score = 0;
	count = 0;
	dir = Move::LEFT;
}

// F R A M E   D R A W I N G
void Snake::Frame() {
	cout << "You collected: " << score << ". Left: " << win - score << "." << endl;
	for (int i = 0; i <= w; i++) {
		cout << "%";
	}
	cout << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= w; j++) {
			if (j == 0 || j == w) {
				cout << "%";
			}
			else cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i <= w; i++) {
		cout << "%";
	}
}

// F R U I T   D R A W I N G
void Snake::Fruit() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Position p;
	do {
		frx = rand() % w + 1;
		fry = rand() % h + 2;
	} while (Myself(frx, fry));
	p.TextPos(frx, fry);
	SetConsoleTextAttribute(handle, 2);
	cout << "X";
	SetConsoleTextAttribute(handle, 7);
}

// S N A K E  D R A W I N G
void Snake::Body() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Position p;
	p.TextPos(x, y);
	SetConsoleTextAttribute(handle, 9);
	cout << "O"; 	// HEAD
	SetConsoleTextAttribute(handle, 7);
	for (int i = 0; i < count; i++) {
		p.TextPos(tx[i], ty[i]);
		SetConsoleTextAttribute(handle, 14);
		cout << "o";	// TAIL
		SetConsoleTextAttribute(handle, 7);
	}
	if (count >= 5) {
		p.TextPos(tail.x, tail.y);
		cout << " ";
	}
	if (count >= 4) {
		tail.x = tx[count - 1];
		tail.y = ty[count - 1];
	}
	if (plus)
		plus = false;
	Sleep(200);
}

// M O T I O N
void Snake::Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 0x4B:
			if (dir != Move::RIGHT || count == 0) {
				dir = Move::LEFT;
			}
			break;
		case 0x4D:
			if (dir != Move::LEFT || count == 0) {
				dir = Move::RIGHT;
			}
			break;
		case 0x48:
			if (dir != Move::DOWN || count == 0) {
				dir = Move::UP;
			}
			break;
		case 0x50:
			if (dir != Move::UP || count == 0) {
				dir = Move::DOWN;
			}
			break;
		}
	}
}

void Snake::Motion() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Position p;
	if (count < 5) count++;
	int ppx, ppy; //pred-pred coords
	int px = tx[0], py = ty[0]; // pred coords
	tx[0] = x;
	ty[0] = y;
	for (int i = 1; i < count; i++) {
		ppx = tx[i];
		ppy = ty[i];
		tx[i] = px;
		ty[i] = py;
		px = ppx;
		py = ppy;
	}

	switch (dir)
	{
	case Move::LEFT:
		x--;
		break;
	case Move::RIGHT:
		x++;
		break;
	case Move::UP:
		y--;
		break;
	case Move::DOWN:
		y++;
		break;
	}
	if (x >= w || x <= 0 || y > h + 1 || y <= 1) {
		end = true;
	}
	if (Myself(x, y)) end = true;
	if (x == frx && y == fry) {
		score++;
		count++;
		plus = true;
		Fruit();
		p.TextPos(0, 0);
		cout << "You collected: " << score << ". Left: " << win - score << "." << endl;
	}
}

// S E L F C R O S S I N G
bool Snake::Myself(int a, int b) {
	for (int i = 0; i < count; i++) {
		if (tx[i] == a && ty[i] == b) {
			return true;
		}
	}
	return false;
}
