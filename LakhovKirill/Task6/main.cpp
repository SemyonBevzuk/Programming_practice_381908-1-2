#include <iostream>

#include "./include/Player.h"
#include "./include/Game.h"
int main()
{
    Player player = Player("player", PLAYER);
    Player bot = Player("bot", BOT);

    Game game = Game(player, bot);

    game.start();
//    Ship ship = Ship(7,6, ONE_DECK, HORISONTAL);
//    vector<pair<int, int>> points = ship.getSidePoints();
//    for (auto &point : points) {
//        std::cout << point.first << " " << point.second << std::endl;
//    }

}