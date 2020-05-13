//
// Created by Kirill on 13.05.2020.
//

#ifndef TASK6_BOT_H
#define TASK6_BOT_H

#include <iostream>
#include "string"
#include "Player.h"
using namespace std;
class Bot : public Player{
public:
    Bot(const string &name="");
    virtual pair<int,int> getTurn();
};


#endif //TASK6_BOT_H
