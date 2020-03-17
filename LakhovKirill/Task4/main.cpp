#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include "regex"
#include "include/FIlmLibrary.h"

int main() {
//    Database db = Database("film_library.db3", OPEN_CREATE | OPEN_READWRITE);
//    Statement query = Statement(db, "SELECT * FROM films WHERE name=:name");
//    query.bind(":name", "g");
//    query.bind(":year", 1);
    FilmLibrary library = FilmLibrary("film_library.db3");
    library.start();
    return 0;
}
