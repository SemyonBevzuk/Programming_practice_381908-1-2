//
// Created by Kirill on 10.05.2020.
//

#ifndef TASK6_GAME_H
#define TASK6_GAME_H

#include "Player.h"
class Game {
public:
    Game(Player &player1, Player &player2);
    void start();
private:
    Player& player1;
    Player& player2;
    int turn;
    bool game_over;
};


#endif //TASK6_GAME_H
