#include <iostream>
#include "Snake.h"

using namespace std;

int main()
{
    int w, h;
    cin >> w >> h;
    Game game(w,h);
    game.run();
}