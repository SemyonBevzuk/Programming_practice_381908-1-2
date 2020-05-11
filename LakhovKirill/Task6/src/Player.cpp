//
// Created by Kirill on 10.05.2020.
//

#include <iostream>
#include <random>
#include <chrono>
#include "../include/Player.h"

Player::Player(const string &name, PlayerTypes type) {
    this->name = name;
    this->type = type;

    this->field = Field(Field::field_size);
    this->enemy_field = Field(Field::field_size);

    this->view = View(this->name);

    this->randomShips();
    this->view.printField(this->field);
}

void Player::randomShips() {
    int one_deck = 0;
    while (one_deck < Player::one_deck) {
        Ship ship = Ship(Player::rand(0, Field::field_size), Player::rand(0, Field::field_size),
                ONE_DECK, static_cast<ShipDirection>(Player::rand(0, 1)));
        std::cout<<this->field.canSetShip(ship)<<std::endl;
        if(this->field.canSetShip(ship)){
            this->field.setShip(ship);
            one_deck++;
        }
    }
}

int Player::rand(int a, int b) {
    std::mt19937 generator(std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
    std::uniform_int_distribution<> uid(a, b);
    return uid(generator);
}


