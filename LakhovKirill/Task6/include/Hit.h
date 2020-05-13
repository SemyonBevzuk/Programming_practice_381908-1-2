//
// Created by Kirill on 13.05.2020.
//

#ifndef TASK6_HIT_H
#define TASK6_HIT_H


#include "Field.h"

class Hit {
public:
    Hit(int row = 0, int col = 0, HitType type = MISS);

    inline int getRow() const { return this->row; }

    inline int getCol() const { return this->col; }

    inline HitType getType() const { return this->type; }

    inline pair<int, int> getPoint() const { return pair<int, int>(this->row, this->col); }

private:
    int row;
    int col;
    HitType type;
};


#endif //TASK6_HIT_H
