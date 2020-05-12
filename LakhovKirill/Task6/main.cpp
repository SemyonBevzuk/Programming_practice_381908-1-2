#include <iostream>

#include "./include/Player.h"
#include "./include/Game.h"
#include "ctime"
int main()
{
    Player player = Player("player", PLAYER);
//    Ship ship = Ship(7,9,ONE_DECK, VERTICAL);
//    Ship ship1 = Ship(7,8,ONE_DECK, VERTICAL);
//    player.setShip(ship);
//    player.setShip(ship1);
    player.randomShips();
    player.viewField();
//    Player bot = Player("bot", BOT);
//    Game game = Game(player, bot);
}