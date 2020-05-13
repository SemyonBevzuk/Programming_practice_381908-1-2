//
// Created by Kirill on 13.05.2020.
//

#include "../include/Bot.h"

Bot::Bot(const string &name) : Player(name, BOT){}

pair<int, int> Bot::getTurn(){
    std::cout<<"im virtual method"<<std::endl;
    return pair<int,int>(0,0);
}

