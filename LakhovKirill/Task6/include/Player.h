//
// Created by Kirill on 10.05.2020.
//

#ifndef TASK6_PLAYER_H
#define TASK6_PLAYER_H

#include "string"
#include "Field.h"
#include "View.h"
enum PlayerTypes  {
    PLAYER,
    BOT,
};

using namespace std;

class Player {
public:
    Player(const string &name="", PlayerTypes type=PLAYER);
    void randomShips();
    static int rand(int a, int b);

private:

private:
    string name;
    PlayerTypes type;
    Field field;
    Field enemy_field;
    View view;
    static const int one_deck = 4;
    static const int two_deck = 3;
    static const int three_deck = 2;
    static const int four_deck = 1;
};


#endif //TASK6_PLAYER_H
