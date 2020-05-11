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
    explicit Ship(int row = 0, int col = 0, ShipType type = ONE_DECK, ShipDirection direction = VERTICAL);

    inline ShipType getType() const { return this->type; }

    inline ShipDirection getDirection() const { return this->direction; }

    inline int getRow() const { return this->row; }

    inline int getCol() const { return this->col; }

    inline vector<pair<int, int>> getPoints() const { return this->points; };

    inline vector<pair<int, int>> getPrimaryPoints() const { return this->primary_points; };

    bool overrides(const Ship& ship);

private:
    void setPoints();
    void setPrimaryPoints();

private:
    int row;
    int col;
    ShipDirection direction;
    ShipType type;
    vector<pair<int, int>> points;
    vector<pair<int, int>> primary_points;

    static const int additional_override_length = 2;
};


#endif //TASK6_SHIP_H
