#pragma once
#include "Player.h"

using namespace std;

class Game {
	Player* p;
public:
	Game();
	int play();
	void dispatcher();
};