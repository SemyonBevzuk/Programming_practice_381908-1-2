#include <iostream>

#include "./include/Player.h"
#include "./include/Game.h"

int main()
{
//    Player player = Player("player", PLAYER);
//    Player bot = Player("bot", BOT);
//    Game game = Game(player, bot);
    for (int i = 0; i < 10; ++i) {
        std::cout<<Player::rand(1,10)<<std::endl;
    }
}