//
// Created by Kirill on 13.05.2020.
//

#ifndef TASK6_HIT_H
#define TASK6_HIT_H


#include "Field.h"

class Hit {
public:
    Hit(int row = 0, int col = 0, HitType type = MISS, bool last_hit = false);

    inline int getRow() const { return this->row; }

    inline int getCol() const { return this->col; }

    inline HitType getType() const { return this->type; }

    inline pair<int, int> getPoint() const { return pair<int, int>(this->row, this->col); }

    inline bool getLastHit() const { return this->last_hit; }

private:
    int row;
    int col;
    HitType type;
    bool last_hit;
};


#endif //TASK6_HIT_H
