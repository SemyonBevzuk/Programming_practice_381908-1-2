//
// Created by Kirill on 10.05.2020.
//

#include <iostream>
#include "../include/Ship.h"

Ship::Ship(int row, int col, ShipType type, ShipDirection direction, int field_size) {
    this->row = row;
    this->col = col;
    this->type = type;
    this->direction = direction;
    this->health = type;
    this->field_size = field_size;
    this->setPoints();
    this->setPrimaryPoints();
    this->setSidePoints();
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


void Ship::setSidePoints() {
    this->side_points = this->points;
    //filter primary points
    for (auto &point: this->primary_points) {
        auto iterator = find(this->side_points.begin(), this->side_points.end(), point);
        if (iterator != this->side_points.end()) {
            int index = distance(this->side_points.begin(), iterator);
            this->side_points.erase(this->side_points.begin() + index);
        }
    }

    //filter out of bounds points
    this->side_points.erase(remove_if(this->side_points.begin(), this->side_points.end(),
                                      [this](const pair<int, int> p) {
                                          return p.first < 0 || p.first >= this->field_size
                                                 || p.second < 0 || p.second >= this->field_size;
                                      }), this->side_points.end());

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

bool Ship::containsPrimaryPoint(pair<int, int> point) {
    auto iterator = find_if(this->primary_points.begin(), this->primary_points.end(),
                            [point](pair<int, int> p) { return point.first == p.first && point.second == p.second; });
    return iterator != this->primary_points.end();
}

bool Ship::hit() {
    this->health = this->health - 1;
    return this->health > 0;
}
