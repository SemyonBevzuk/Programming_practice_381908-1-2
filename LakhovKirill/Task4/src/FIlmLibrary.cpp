

#include "../include/FIlmLibrary.h"

#include <utility>

using namespace std;
using namespace SQLite;

FilmLibrary::FilmLibrary(const string& database) {
    this->database = database;
    this->init();
}

bool FilmLibrary::init() {
    Database db = this->connect();
    db.exec("DROP TABLE IF EXISTS films");
    db.exec("CREATE TABLE films (id INTEGER PRIMARY KEY , name TEXT NOT NULL, producer TEXT NOT NULL, "
            "writer TEXT NOT NULL,  composer TEXT NOT NULL, day INTEGER NOT NULL, month INTEGER NOT NULL, year INTEGER NOT NULL,"
            " fees INTEGER NOT NULL)");
}


Database FilmLibrary::connect() {
    try{
        Database db = Database(this->database, OPEN_CREATE | OPEN_READWRITE);
        return db;
    }catch(SQLite::Exception&){}
}

void FilmLibrary::start() {
    
}
