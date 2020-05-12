//
// Created by Kirill on 10.05.2020.
//

#ifndef TASK6_SHIP_H
#define TASK6_SHIP_H

#include "vector"
#include "algorithm"

enum ShipDirection {
    VERTICAL,
    HORISONTAL
};

enum ShipType {
    ONE_DECK = 1,
    TWO_DECK,
    THREE_DECK,
    FOUR_DECK
};
using namespace std;

class Ship {
public:
    Ship(int row = 0, int col = 0, ShipType type = ONE_DECK, ShipDirection direction = VERTICAL);

    inline ShipType getType() const { return this->type; }

    inline ShipDirection getDirection() const { return this->direction; }

    inline int getRow() const { return this->row; }

    inline int getCol() const { return this->col; }

    inline vector<pair<int, int>> getPoints() const { return this->points; };

    inline vector<pair<int, int>> getPrimaryPoints() const { return this->primary_points; };

    inline vector<pair<int, int>> getSidePoints() const { return this->side_points; };

    inline int getHealth() const { return this->health; }

    bool overrides(const Ship &ship);

    bool containsPrimaryPoint(pair<int, int> point);

    bool hit();

private:
    void setPoints();

    void setPrimaryPoints();

    void setSidePoints();

private:
    int row;
    int col;
    int health;
    ShipDirection direction;
    ShipType type;
    vector<pair<int, int>> points;
    vector<pair<int, int>> primary_points;
    vector<pair<int, int>> side_points;

    static const int additional_override_length = 2;
};


#endif //TASK6_SHIP_H
