//
// Created by Kirill on 10.05.2020.
//

#include <iostream>
#include "../include/Field.h"

Field::Field(int size) : Matrix(size) {

}

bool Field::setShip(Ship ship) {
    int row = ship.getRow();
    int col = ship.getCol();
    int size = ship.getType();

    if (ship.getDirection() == VERTICAL) {
        for (int i = row; i < row + size; ++i) {
            this->set(i, col, 1);
        }
    } else if (ship.getDirection() == HORISONTAL) {
        for (int i = col; i < col + size; ++i) {
            this->set(row, i, 1);
        }
    }
    this->ships.push_back(ship);
    return true;
}

bool Field::canSetShip(const Ship &ship) {
    int row = ship.getRow();
    int col = ship.getCol();
    int size = ship.getType();

    //out of field boundaries
    if (ship.getDirection() == VERTICAL) {
        for (int i = row; i < row + size; ++i) {
            if (!this->gettable(i, col))
                return false;
        }
    } else if (ship.getDirection() == HORISONTAL) {
        for (int i = col; i < col + size; ++i) {
            if (!this->gettable(row, i))
                return false;
        }
    }

    //ship overrides others
    for (auto &local_ship : this->ships) {
        if (local_ship.overrides(ship)) {
            return false;
        }
    }

    return true;
}

pair<bool, Ship> Field::findShipByPoint(pair<int, int> point) {
    for (auto &ship: this->ships) {
        if (ship.containsPrimaryPoint(point)) {
            return pair<bool, Ship>(true, ship);
        }
    }
    Ship s = Ship();
    return pair<bool, Ship>(false, s);
}

