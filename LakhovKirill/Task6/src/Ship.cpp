//
// Created by Kirill on 10.05.2020.
//

#include <iostream>
#include "../include/Ship.h"

Ship::Ship(int row, int col, ShipType type, ShipDirection direction) {
    this->row = row;
    this->col = col;
    this->type = type;
    this->direction = direction;
    this->setPoints();
    this->setPrimaryPoints();
    // TODO clean logs
//    std::cout << "points" << std::endl;
//    std::cout << this->points.size() << std::endl;
//    for (auto &point : this->points) {
//        std::cout << point.first << " " << point.second << std::endl;
//    }
//    std::cout << "primary points" << std::endl;
//    std::cout << this->primary_points.size() << std::endl;
//    for (auto &point : this->primary_points) {
//        std::cout << point.first << " " << point.second << std::endl;
//    }
}

void Ship::setPoints() {
    this->points = vector<pair<int, int>>();
    int override_col = this->col - 1;
    int override_row = this->row - 1;
    if (this->direction == HORISONTAL) {
        for (int i = override_row; i < override_row + 3; ++i) {
            for (int j = override_col; j < override_col + this->type + Ship::additional_override_length; ++j) {
                this->points.emplace_back(i, j);
            }
        }
    } else if (this->direction == VERTICAL) {
        for (int i = override_col; i < override_col + 3; ++i) {
            for (int j = override_row; j < override_row + this->type + Ship::additional_override_length; ++j) {
                this->points.emplace_back(j, i);
            }
        }
    }
}


void Ship::setPrimaryPoints() {
    this->primary_points = vector<pair<int, int>>();
    if (this->direction == HORISONTAL) {
        for (int i = this->col; i < this->col + this->type; ++i) {
            this->primary_points.emplace_back(this->row, i);
        }
    } else if (this->direction == VERTICAL) {
        for (int i = this->row; i < this->row + this->type; ++i) {
            this->primary_points.emplace_back(i, this->col);
        }
    }
}

bool Ship::overrides(const Ship &ship) {
    vector<pair<int, int>> other_points = ship.getPoints();
    for (auto &point : this->primary_points) {
        if (find(other_points.begin(), other_points.end(), point) != other_points.end()) {
            return true;
        }
    }
    return false;
}