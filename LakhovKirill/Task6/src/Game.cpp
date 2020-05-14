//
// Created by Kirill on 10.05.2020.
//

#include <iostream>
#include "../include/Game.h"

Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2) {
    this->turn = 1;
    this->game_over = false;
}

void Game::start() {
    this->player1.init();
    this->player2.init();
    while (!this->game_over) {
        this->player2.viewFields();
        this->player1.viewFields();

        switch (this->turn) {
            case 1: {
                pair<int, int> position = this->player1.getTurn();
                if (this->player2.shipIsOnPosition(position.first, position.second)) {
                    pair<bool, vector<pair<int, int>>> result = this->player2.markOnField(
                            Hit(position.first, position.second, DESTROYED));
                    this->player1.markOnEnemyField(Hit(position.first, position.second, HIT));
                    // result.first = true if ship was killed
                    if (result.first) {
                        this->player1.markOnEnemyField(result.second, MISS);
                        this->player1.viewDestroy();
                    }
                    this->player1.hit(Hit(position.first, position.second, HIT, result.first));
                    this->game_over = !this->player2.haveShips();
                } else {
                    this->player1.markOnEnemyField(Hit(position.first, position.second, MISS));
                    this->player1.miss(Hit(position.first, position.second, MISS));
                    this->turn = 2;
                }
                break;
            }
            case 2: {
                pair<int, int> position = this->player2.getTurn();
                if (this->player1.shipIsOnPosition(position.first, position.second)) {
                    pair<bool, vector<pair<int, int>>> result = this->player1.markOnField(
                            Hit(position.first, position.second, DESTROYED));
                    this->player2.markOnEnemyField(Hit(position.first, position.second, HIT));
                    // result.first = true if ship was killed
                    if (result.first) {
                        this->player2.markOnEnemyField(result.second, MISS);
                        this->player2.viewDestroy();
                    }
                    this->player2.hit(Hit(position.first, position.second, HIT, result.first));
                    this->game_over = !this->player1.haveShips();
                } else {
                    this->player2.markOnEnemyField(Hit(position.first, position.second, MISS));
                    this->player2.miss(Hit(position.first, position.second, MISS));
                    this->turn = 1;
                }
                break;
            }
        }
    }
    this->gameOver();
}

void Game::gameOver() {
    if (this->turn == 1) {
        this->player1.victory();
        this->player2.loss();
    } else if (this->turn == 2) {
        this->player2.victory();
        this->player1.loss();
    }
}
