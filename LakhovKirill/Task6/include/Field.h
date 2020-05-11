//
// Created by Kirill on 10.05.2020.
//

#ifndef TASK6_FIELD_H
#define TASK6_FIELD_H

#include "Matrix.h"
#include "Ship.h"
#include "vector"
class Field : public Matrix{
public:
    Field(int size = 0);
    bool setShip(Ship ship);
    bool canSetShip(const Ship& ship);
    static const int field_size = 10;

private:
    vector<Ship> ships;
};


#endif //TASK6_FIELD_H
