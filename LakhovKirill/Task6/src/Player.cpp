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
}

void Player::init() {
    if (this->type == BOT) {
        this->randomShips();
    } else if (this->type == PLAYER) {
        //TODO create player's opportunity to choose field
        this->randomShips();
    }
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

void Player::viewEnemyField() {
    this->view.printField(this->enemy_field, true);
}

void Player::setShip(const Ship &ship) {
    if (this->field.canSetShip(ship)) {
        this->field.setShip(ship);
    }
}

pair<int, int> Player::getTurn(){
    this->view.turn();
    if (this->type == PLAYER) {
        int row = View::inputNumber("row", 0, 9);
        int col = View::inputNumber("col", 0, 9);
        return pair<int, int>(row, col);
    } else if (this->type == BOT) {
        while (true) {
            int row = Player::rand(0, 9);
            int col = Player::rand(0, 9);
            if (this->enemy_field(row, col) == 0) {
                return pair<int, int>(row, col);
            }
        }
    }
}

bool Player::shipIsOnPosition(int row, int col) {
    return this->field(row, col) == 1;
}

pair<bool, vector<pair<int, int>>> Player::markOnField(const Hit& hit) {
    if (this->field(hit.getRow(), hit.getCol()) != 0) {
        this->field(hit.getRow(), hit.getCol()) = static_cast<int>(hit.getType());
        Ship ship = this->field.findShipByPoint(hit.getPoint()).second;
        bool shipIsAlive = ship.hit();

        if (shipIsAlive) {
            return pair<bool, vector<pair<int, int>>>(false, vector<pair<int, int>>());
        } else {
            vector<pair<int, int>> points = ship.getSidePoints();
            return pair<bool, vector<pair<int, int>>>(true, points);
        }
    }
}

void Player::markOnEnemyField(const Hit& hit) {
    this->enemy_field(hit.getRow(), hit.getCol()) = static_cast<int>(hit.getType());
}

bool Player::haveShips() {
    return this->field.contains(1);
}

void Player::hit(const Hit& hit) {
    this->view.hit(hit.getRow(), hit.getCol());
    this->hit_history.push_back(hit);
}

void Player::miss(const Hit& hit) {
    this->view.miss(hit.getRow(), hit.getCol());
    this->hit_history.push_back(hit);
}

void Player::viewFields() {
    this->view.printFields(this->field, this->enemy_field);
}

void Player::markOnEnemyField(const vector<pair<int, int>>& points, HitType hit) {
    for (auto &point  : points) {
        this->markOnEnemyField(Hit(point.first, point.second, hit));
    }
}

void Player::viewDestroy() {
    this->view.destroy();
}





