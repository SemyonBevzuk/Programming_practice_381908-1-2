//
// Created by Kirill on 13.05.2020.
//

#include "../include/Hit.h"

Hit::Hit(int row, int col, HitType type, bool last_hit) {
    this->row = row;
    this->col = col;
    this->type = type;
    this->last_hit = last_hit;
}
