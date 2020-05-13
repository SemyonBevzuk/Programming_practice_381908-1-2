//
// Created by Kirill on 13.05.2020.
//

#ifndef TASK6_SUSPICIOUSPOINT_H
#define TASK6_SUSPICIOUSPOINT_H

#include "Ship.h"

class SuspiciousPoint {
public:
    SuspiciousPoint(int row = 0, int col = 0, ShipDirection direction = HORISONTAL);

    inline int getRow() const { return this->row; }

    inline int getCol() const { return this->col; }

    inline ShipDirection getDirection() const { return this->direction; }

    inline pair<int, int> getPoint() const { return pair<int, int>(this->row, this->col); }

private:
    int row;
    int col;
    ShipDirection direction;
};


#endif //TASK6_SUSPICIOUSPOINT_H
