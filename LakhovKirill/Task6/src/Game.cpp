//
// Created by Kirill on 10.05.2020.
//

#include <iostream>
#include "../include/Game.h"

Game::Game(Player *player1, Player *player2){
    this->game_over = false;
    this->active_player = player1;
    this->inactive_player = player2;
}

void Game::start() {
    this->active_player->init();
    this->inactive_player->init();
    while (!this->game_over) {
        this->inactive_player->viewFields();
        this->active_player->viewFields();
        pair<int, int> position = this->active_player->getTurn();
        if (this->inactive_player->shipIsOnPosition(position.first, position.second)) {
            pair<bool, vector<pair<int, int>>> result = this->inactive_player->markOnField(
                    Hit(position.first, position.second, DESTROYED));
            this->active_player->markOnEnemyField(Hit(position.first, position.second, HIT));
            // result.first = true if ship was killed
            if (result.first) {
                this->active_player->markOnEnemyField(result.second, MISS);
                this->active_player->viewDestroy();
            }
            this->active_player->hit(Hit(position.first, position.second, HIT, result.first));
            this->game_over = !this->inactive_player->haveShips();
        } else {
            this->active_player->markOnEnemyField(Hit(position.first, position.second, MISS));
            this->active_player->miss(Hit(position.first, position.second, MISS));
            this->switchPlayers();
        }
    }
    this->gameOver();
}

void Game::gameOver() {
    this->active_player->victory();
    this->inactive_player->loss();
}

void Game::switchPlayers() {
    Player* tmp = this->active_player->clone();
    this->active_player = this->inactive_player->clone();
    this->inactive_player = tmp->clone();
}