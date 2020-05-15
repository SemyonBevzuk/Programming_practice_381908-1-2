//
// Created by Kirill on 10.05.2020.
//

#ifndef TASK6_GAME_H
#define TASK6_GAME_H

#include "Player.h"

using namespace std;

class Game {
public:
    Game(Player *player1, Player *player2);

    void start();

    void gameOver();

    void switchPlayers();
private:
    Player *active_player;
    Player *inactive_player;
    bool game_over;
};


#endif //TASK6_GAME_H
