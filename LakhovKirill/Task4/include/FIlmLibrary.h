

#ifndef TASK4_FILMLIBRARY_H
#define TASK4_FILMLIBRARY_H

#include "SQLiteCpp/SQLiteCpp.h"
#include "Film.h"

using namespace std;
using namespace SQLite;

class FilmLibrary {
private:
    string database;
public:
    explicit FilmLibrary(const string &database);

    bool init();

    void start();

private:
    Database connect();

    void createNewFilmCommand();
    void createNewFilm(Film film);

    void findFilmCommand();

    pair<bool, Film> getFilm(const string &name, int year);


private:
    static bool parser(const string &str);

    static string inputName(const string &who, const string &error, bool strict = true);

    static int inputNumber(const string &whatNumber);
};


#endif //TASK4_FILMLIBRARY_H
