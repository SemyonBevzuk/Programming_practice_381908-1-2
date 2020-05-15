#include <iostream>

#include "./include/Player.h"
#include "./include/Bot.h"
#include "./include/Game.h"

int main() {
    Bot* player = new Bot("bot-one");
//    Player* player = new Player("player");
    Bot* bot = new Bot("bot-two");
    Game game = Game(player, bot);

    game.start();


}