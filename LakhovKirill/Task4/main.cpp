#include "include/FIlmLibrary.h"

int main() {
    FilmLibrary library = FilmLibrary("film_library.db3");
    library.start();
    return 0;
}
