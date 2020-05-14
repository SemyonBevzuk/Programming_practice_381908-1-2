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

Player::Player(const Player &player) {
    this->name = player.getName();
    this->field = player.getField();
    this->enemy_field = player.getEnemyField();
    this->view = player.getView();
    this->hit_history = player.getHitHistory();
}

void Player::init() {
    if (this->type == BOT) {
        this->randomShips();
    } else if (this->type == PLAYER) {
        this->view.shipsSetUpCommands();
        int command = this->view.inputNumber("command(1-2)", 1, 2);
        switch (command) {
            case 1: {
                this->manualShips();
                break;
            }
            case 2: {
                this->randomShips();
                break;
            }
        }
    }
}

void Player::randomShips() {
    this->setRandomShipsByType(ONE_DECK, Player::one_deck);
    this->setRandomShipsByType(TWO_DECK, Player::two_deck);
    this->setRandomShipsByType(THREE_DECK, Player::three_deck);
    this->setRandomShipsByType(FOUR_DECK, Player::four_deck);
}

void Player::manualShips() {
    this->setShipsByType(ONE_DECK, Player::one_deck);
    this->setShipsByType(TWO_DECK, Player::two_deck);
    this->setShipsByType(THREE_DECK, Player::three_deck);
    this->setShipsByType(FOUR_DECK, Player::four_deck);
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

void Player::setShipsByType(ShipType shipType, int amount) {
    int i = 0;
    while (i < amount) {
        this->viewField();
        this->view.coords(shipType);
        tuple<int, int, ShipDirection> data = this->getRowColDirection();
        Ship ship = Ship(get<0>(data), get<1>(data), shipType, get<2>(data));
        if (this->field.canSetShip(ship)) {
            this->field.setShip(ship);
            this->view.successfulSet();
            i++;
        } else {
            this->view.cantSetShip();
        }
    }
}

void Player::setRandomShipsByType(ShipType shipType, int amount) {
    int i = 0;
    while (i < amount) {
        Ship ship = Ship(Player::rand(0, Field::field_size - 1), Player::rand(0, Field::field_size - 1),
                         shipType, static_cast<ShipDirection>(Player::rand(0, 1)));
        if (this->field.canSetShip(ship)) {
            this->field.setShip(ship);
            i++;
        }
    }
}

pair<int, int> Player::getTurn() {
    this->view.turn();
    if (this->type == PLAYER) {
        int row = View::inputNumber("row", 0, 9);
        int col = View::inputNumber("col", 0, 9);
        return pair<int, int>(row, col);
    }
    throw out_of_range("turn os not implemented for such player");
}

bool Player::shipIsOnPosition(int row, int col) {
    return this->field(row, col) == 1;
}

pair<bool, vector<pair<int, int>>> Player::markOnField(const Hit &hit) {
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
    return pair<bool, vector<pair<int, int>>>(false, vector<pair<int, int>>());
}

void Player::markOnEnemyField(const Hit &hit) {
    this->enemy_field(hit.getRow(), hit.getCol()) = static_cast<int>(hit.getType());
}

bool Player::haveShips() {
    return this->field.contains(1);
}

void Player::hit(const Hit &hit) {
    this->view.hit(hit.getRow(), hit.getCol());
    this->hit_history.push_back(hit);
}

void Player::miss(const Hit &hit) {
    this->view.miss(hit.getRow(), hit.getCol());
    this->hit_history.push_back(hit);
}

void Player::viewFields() {
    this->view.printFields(this->field, this->enemy_field);
}

void Player::markOnEnemyField(const vector<pair<int, int>> &points, HitType hit) {
    for (auto &point  : points) {
        this->markOnEnemyField(Hit(point.first, point.second, hit));
    }
}

void Player::viewDestroy() {
    this->view.destroy();
}

tuple<int, int, ShipDirection> Player::getRowColDirection() {
    int row = View::inputNumber("row", 0, 9);
    int col = View::inputNumber("col", 0, 9);
    ShipDirection direction = static_cast<ShipDirection>(View::inputNumber(
            "ship direction (vertical = 0, horizontal = 1)",
            0, 1));
    return tuple<int, int, ShipDirection>(row, col, direction);
}

bool Player::operator==(const Player &player) const {
    return this->name == player.getName() && this->field == player.getField();
}

void Player::victory() {
    this->view.victory();
}

void Player::loss() {
    this->view.loss();
}





