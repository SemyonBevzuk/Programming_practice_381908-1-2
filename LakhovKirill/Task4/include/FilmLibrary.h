

#ifndef TASK4_FILMLIBRARY_H
#define TASK4_FILMLIBRARY_H

#include "SQLiteCpp/SQLiteCpp.h"
#include "Film.h"
#include "Connector.h"
#include "View.h"

using namespace std;
using namespace SQLite;

class FilmLibrary {
private:
    string database="films.db3";
    Connector connector;
    View view;
public:
    FilmLibrary(const string& database="films.db3", const string& title="film-library-1");

    void start();

private:
    Database connect();

    void createNewFilmCommand();

    void findFilmCommand();

    bool printFilmsByQuery(Statement &query, const string &error, int amount = 0);

    void changeFilmCommand(const Film &to_change);

    void allProducerFilmsCommand();

    void allYearFilmsCommand();

    void maxBoxOfficeCommand(bool isYear = false);

    void allFilmsCountCommand();

    int allFilmsCount(int year = 0);

    pair<bool, Film> getFilm(const string &name, int year);


private:
    static bool parser(const string &str);

    static string inputName(const string &who, const string &error, bool strict = true);

    static int inputNumber(const string &whatNumber);

    static Film inputFilm();
};


#endif //TASK4_FILMLIBRARY_H
