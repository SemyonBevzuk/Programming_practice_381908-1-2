#include "Game.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	Game g;
	g.dispatcher();
}