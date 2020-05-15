//
// Created by Kirill on 10.05.2020.
//

#ifndef TASK6_PLAYER_H
#define TASK6_PLAYER_H

#include "string"
#include "Hit.h"
#include "Field.h"
#include "View.h"
#include "thread"

enum PlayerTypes {
    PLAYER,
    BOT,
};

using namespace std;

class Player {
public:
    Player(const string &name = "");

    void randomShips();

    void manualShips();

    static int rand(int a, int b);

    void viewField();

    void viewEnemyField();

    void viewFields();

    void viewDestroy();

    void setShip(const Ship &ship);

    void setShipsByType(ShipType shipType, int amount);

    void setRandomShipsByType(ShipType shipType, int amount);

    void init();

    virtual pair<int, int> getTurn();

    bool shipIsOnPosition(int row, int col);

    pair<bool, vector<pair<int, int>>> markOnField(const Hit &hit);

    void markOnEnemyField(const Hit &hit);

    void markOnEnemyField(const vector<pair<int, int>> &points, HitType hit);

    bool haveShips();

    void hit(const Hit &hit);

    void miss(const Hit &hit);

    void victory();

    void loss();

    virtual Player* clone();

    bool operator==(const Player &player) const;

    inline const Field getField() const { return this->field; }

    inline const Field getEnemyField() const { return this->enemy_field; }

    inline PlayerTypes getPlayerType() const { return this->type; }

    inline vector<Hit> getHitHistory() const { return this->hit_history; }

    inline View getView() const { return this->view; }

    inline string getName() const { return this->name; }


protected:
    tuple<int, int, ShipDirection> getRowColDirection();

protected:
    string name;
    PlayerTypes type;
    Field field;
    Field enemy_field;
    View view;
    vector<Hit> hit_history;
    static const int one_deck = 4;
    static const int two_deck = 3;
    static const int three_deck = 2;
    static const int four_deck = 1;
};


#endif //TASK6_PLAYER_H
