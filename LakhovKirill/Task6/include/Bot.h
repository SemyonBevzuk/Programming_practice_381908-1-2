//
// Created by Kirill on 13.05.2020.
//

#ifndef TASK6_BOT_H
#define TASK6_BOT_H

#include <iostream>
#include "string"
#include "Player.h"
#include "SuspiciousPoint.h"

using namespace std;

class Bot : public Player {
public:
    Bot(const string &name = "");

    pair<int, int> getTurn() override;

    Bot *clone() override;

private:
    pair<int, int> randomEmptyPoint();

    bool lastTurnWasHit();

    bool lastTurnWasDestroy();

    void createSuspiciousPointsByLastHit();

    void setDirection();

    void sortByDirection();

    bool hasAlreadyShoot(int row, int col);

    pair<int, int> hitInSuspiciousPoint();

    void nullify();

private:
    vector<SuspiciousPoint> suspicious_points;
    bool isKillingShip;
    ShipDirection killingDirection;
    vector<Hit> last_hits;
};


#endif //TASK6_BOT_H
