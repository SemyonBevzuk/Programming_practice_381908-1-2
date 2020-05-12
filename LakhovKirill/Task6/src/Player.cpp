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

//    this->randomShips();
//    this->view.printField(this->field);
}

void Player::randomShips() {
    int four_deck_ship = 0;
    while (four_deck_ship < Player::four_deck) {
        Ship ship = Ship(Player::rand(0, Field::field_size - 1), Player::rand(0, Field::field_size - 1),
                         FOUR_DECK, static_cast<ShipDirection>(Player::rand(0, 1)));
        if (this->field.canSetShip(ship)) {
            this->field.setShip(ship);
            four_deck_ship++;
        }
    }
    int three_deck_ship = 0;
    while (three_deck_ship < Player::three_deck) {
        Ship ship = Ship(Player::rand(0, Field::field_size - 1), Player::rand(0, Field::field_size - 1),
                         THREE_DECK, static_cast<ShipDirection>(Player::rand(0, 1)));
        if (this->field.canSetShip(ship)) {
            this->field.setShip(ship);
            three_deck_ship++;
        }
    }
    int two_deck_ship = 0;
    while (two_deck_ship < Player::two_deck) {
        Ship ship = Ship(Player::rand(0, Field::field_size - 1), Player::rand(0, Field::field_size - 1),
                         TWO_DECK, static_cast<ShipDirection>(Player::rand(0, 1)));
        if (this->field.canSetShip(ship)) {
            this->field.setShip(ship);
            two_deck_ship++;
        }
    }
    int one_deck_ship = 0;
    while (one_deck_ship < Player::one_deck) {
        Ship ship = Ship(Player::rand(0, Field::field_size - 1), Player::rand(0, Field::field_size - 1),
                         ONE_DECK, static_cast<ShipDirection>(Player::rand(0, 1)));
        if (this->field.canSetShip(ship)) {
            this->field.setShip(ship);
            one_deck_ship++;
        }
    }
}

int Player::rand(int a, int b) {
    //random is based on system time, so it can be too fast and give the same numbers
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::mt19937 generator(std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
    std::uniform_int_distribution<> uid(a, b);
    return uid(generator);
}

void Player::viewField() {
    this->view.printField(this->field);
}

void Player::setShip(const Ship &ship) {
    if (this->field.canSetShip(ship)) {
        this->field.setShip(ship);
    }
}


