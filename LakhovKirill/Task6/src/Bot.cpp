//
// Created by Kirill on 13.05.2020.
//

#include "../include/Bot.h"

Bot::Bot(const string &name) : Player(name, BOT) {
    this->isKillingShip = false;
    this->suspicious_points = vector<SuspiciousPoint>();
    this->last_hits = vector<Hit>();
    this->killingDirection = UNDEFINED;
}

pair<int, int> Bot::getTurn() {
    std::cout << "vir" << std::endl;
    if (this->isKillingShip) {
        if (this->lastTurnWasHit() && this->lastTurnWasDestroy()) {
            //  shoot and killed
            this->nullify();
            return randomEmptyPoint();
        } else if (this->lastTurnWasHit() && !this->lastTurnWasDestroy()) {
            this->last_hits.push_back(this->hit_history.back());
            // shoot but not killed
            if (this->killingDirection == UNDEFINED) {
                this->setDirection();
                this->sortByDirection();
            }
            this->createSuspiciousPointsByLastHit();
            return this->hitInSuspiciousPoint();
        } else {
            //  missed but was killing
            //  keep shooting, enemy is alive
            return this->hitInSuspiciousPoint();
        }
    } else {
        if (this->lastTurnWasHit() && !this->lastTurnWasDestroy()) {
            //second successful shot
            this->last_hits.push_back(this->hit_history.back());
            this->isKillingShip = true;
            this->createSuspiciousPointsByLastHit();
        } else {
            //bot was not killing and missed = random
            this->nullify();
            return this->randomEmptyPoint();
        }
    }
    return pair<int, int>(0, 0);
}

pair<int, int> Bot::randomEmptyPoint() {
    while (true) {
        int row = Player::rand(0, 9);
        int col = Player::rand(0, 9);
        if (this->enemy_field(row, col) == 0) {
            return pair<int, int>(row, col);
        }
    }
}

bool Bot::lastTurnWasHit() {
    if (!this->hit_history.empty()) {
        return this->hit_history.back().getType() == HIT;
    }
    return false;
}

bool Bot::lastTurnWasDestroy() {
    if (!this->hit_history.empty()) {
        return this->hit_history.back().getLastHit();
    }
    return false;
}

//  if ship have been shoot, but not killed, there must be points on cross where ship is alive
void Bot::createSuspiciousPointsByLastHit() {
    int row = this->hit_history.back().getRow();
    int col = this->hit_history.back().getCol();

    switch (this->killingDirection) {
        case UNDEFINED: {
            if (row - 1 > 0 && row - 1 < Field::field_size && !this->hasAlreadyShoot(row - 1, col)) {
                this->suspicious_points.emplace_back(SuspiciousPoint(row - 1, col, VERTICAL));
            }
            if (row + 1 > 0 && row + 1 < Field::field_size && !this->hasAlreadyShoot(row + 1, col)) {
                this->suspicious_points.emplace_back(SuspiciousPoint(row + 1, col, VERTICAL));
            }
            if (col - 1 > 0 && col - 1 < Field::field_size && !this->hasAlreadyShoot(row, col - 1)) {
                this->suspicious_points.emplace_back(SuspiciousPoint(row, col - 1, HORISONTAL));
            }
            if (col + 1 > 0 && col + 1 < Field::field_size && !this->hasAlreadyShoot(row, col + 1)) {
                this->suspicious_points.emplace_back(SuspiciousPoint(row, col + 1, HORISONTAL));
            }
            break;
        }
        case HORISONTAL: {
            if (col - 1 > 0 && col - 1 < Field::field_size && !this->hasAlreadyShoot(row, col - 1)) {
                this->suspicious_points.emplace_back(SuspiciousPoint(row, col - 1, HORISONTAL));
            }
            if (col + 1 > 0 && col + 1 < Field::field_size && !this->hasAlreadyShoot(row, col + 1)) {
                this->suspicious_points.emplace_back(SuspiciousPoint(row, col + 1, HORISONTAL));
            }
            break;
        }
        case VERTICAL: {
            if (row - 1 > 0 && row - 1 < Field::field_size && !this->hasAlreadyShoot(row - 1, col)) {
                this->suspicious_points.emplace_back(SuspiciousPoint(row - 1, col, VERTICAL));
            }
            if (row + 1 > 0 && row + 1 < Field::field_size && !this->hasAlreadyShoot(row + 1, col)) {
                this->suspicious_points.emplace_back(SuspiciousPoint(row + 1, col, VERTICAL));
            }
        }
    }
}

pair<int, int> Bot::hitInSuspiciousPoint() {
    if (!this->suspicious_points.empty()) {
        SuspiciousPoint point = this->suspicious_points[0];
        this->suspicious_points.erase(this->suspicious_points.begin());
        return point.getPoint();
    }
    return pair<int, int>();
}

void Bot::nullify() {
    this->isKillingShip = false;
    this->killingDirection = UNDEFINED;
    this->suspicious_points = vector<SuspiciousPoint>();
    this->last_hits = vector<Hit>();
}

void Bot::setDirection() {
    if (this->last_hits.size() >= 2) {
        Hit hit1 = this->last_hits[this->last_hits.size() - 1];
        Hit hit2 = this->last_hits[this->last_hits.size() - 2];
        if (hit1.getRow() == hit2.getRow()) {
            this->killingDirection = HORISONTAL;
        } else if (hit1.getCol() == hit2.getCol()) {
            this->killingDirection = VERTICAL;
        }
    }
    if (this->killingDirection == UNDEFINED)
        throw out_of_range("cant set direction without hits");
}

void Bot::sortByDirection() {
    if (!this->suspicious_points.empty()) {
        this->suspicious_points.erase(remove_if(this->suspicious_points.begin(), this->suspicious_points.end(),
                                                [this](const SuspiciousPoint &p) {
                                                    return p.getDirection() != this->killingDirection;
                                                }), this->suspicious_points.end());
    } else {
        throw out_of_range("cant sort empty");
    }
}

bool Bot::hasAlreadyShoot(int row, int col) {
    auto iterator = find_if(this->last_hits.begin(), this->last_hits.end(),
                            [row, col](const Hit &p) { return row == p.getRow() && col == p.getCol(); });
    return iterator != this->last_hits.end();
}

