#include <iostream>

#include "./include/Player.h"
#include "./include/Bot.h"
#include "./include/Game.h"

int main() {
    Player player = Player("player", PLAYER);
    Bot bot = Bot("bot");

    Game game = Game(player, bot);

    game.start();
}