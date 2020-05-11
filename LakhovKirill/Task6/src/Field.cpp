//
// Created by Kirill on 10.05.2020.
//

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
        for (int i = row; i < row + size; ++i) {
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

    //выход за границы поля
    if (ship.getDirection() == VERTICAL) {
        for (int i = row; i < row + size; ++i) {
            if (!this->gettable(i, col))
                return false;
        }
    } else if (ship.getDirection() == HORISONTAL) {
        for (int i = row; i < row + size; ++i) {
            if (!this->gettable(row, i))
                return false;
        }
    }

    for (auto &local_ship : this->ships) {
        if (local_ship.overrides(ship)) {
            return false;
        }
    }

    return true;
}

