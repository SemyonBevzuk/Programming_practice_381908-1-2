

#ifndef TASK4_FILMLIBRARY_H
#define TASK4_FILMLIBRARY_H

#include <string>
#include "SQLiteCpp/SQLiteCpp.h"
using namespace std;
using namespace SQLite;
class FilmLibrary {
private:
    string database;
public:
    explicit FilmLibrary(const string& database);
    bool init();
    void start();
private:
    Database connect();
};


#endif //TASK4_FILMLIBRARY_H
