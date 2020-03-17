

#include "../include/FIlmLibrary.h"
#include "../include/Film.h"

#include <utility>
#include <iostream>
#include <regex>
#include <codecvt>

using namespace std;
using namespace SQLite;

FilmLibrary::FilmLibrary(const string &database) {
    this->database = database;
    this->init();
}

bool FilmLibrary::init() {
    Database db = this->connect();
//    db.exec("DROP TABLE IF EXISTS films");
    db.exec("CREATE TABLE IF NOT EXISTS  films (id INTEGER PRIMARY KEY , name TEXT NOT NULL, producer TEXT NOT NULL, "
            "screenwriter TEXT NOT NULL,  composer TEXT NOT NULL, day INTEGER NOT NULL, month INTEGER NOT NULL, year INTEGER NOT NULL,"
            " fees INTEGER NOT NULL)");
    return true;
}


Database FilmLibrary::connect() {
    Database db = Database(this->database, OPEN_CREATE | OPEN_READWRITE);
    return db;
}

void FilmLibrary::start() {
    std::cout << "Welcome to the app which allows you to interact with your personal Film library" << std::endl;
    std::cout << "Choose next action:" << std::endl;
    std::cout << "1.Add film" << std::endl;
    std::cout << "2.Find film by name and change/delete it" << std::endl;
    string input;
    cin >> input;
    switch (stoi(input)) {
        case 1: {
            this->createNewFilmCommand();
            break;
        }
        case 2: {
            this->findFilmCommand();
            break;
        }
        default: {
            std::cout << "No such command" << std::endl;
        }

    }
}

void FilmLibrary::createNewFilmCommand() {
    std::cout << "Creating new film" << std::endl;
    string name = FilmLibrary::inputName("Film title:", "", false);
    string producer = FilmLibrary::inputName("Producer:", "You need to enter lastname with one word");
    string writer = FilmLibrary::inputName("Screenwriter:", "You need to enter lastname with one word");
    string composer = FilmLibrary::inputName("Composer:", "You need to enter lastname with one word");
    int day = FilmLibrary::inputNumber("Day, when film was released:");
    int month = FilmLibrary::inputNumber("Month, when film was released:");
    int year = FilmLibrary::inputNumber("Year, when film was released:");
    int fees = FilmLibrary::inputNumber("Film fees:");
    Film film = Film(name, producer, writer, composer, Date(day, month, year), fees);
    pair<bool, Film> result = this->getFilm(film.getName(), film.getYear());
    if (result.first) {
        std::cout << "we have that film, rewrite" << std::endl;
    } else {
        std::cout << "creating new film" << std::endl;
        this->createNewFilm(film);
    }
}

void FilmLibrary::createNewFilm(Film film) {
    Database db = this->connect();
    Statement query = Statement(db, "INSERT INTO films VALUES (NULL, :name, :producer, :screenwriter, :composer, "
                                    ":day, :month, :year, :fees)");
    query.bind(":name", film.getName());
    query.bind(":producer", film.getProducer());
    query.bind(":screenwriter", film.getScreenwriter());
    query.bind(":composer", film.getComposer());
    query.bind(":day", film.getDay());
    query.bind(":month", film.getMonth());
    query.bind(":year", film.getYear());
    query.bind(":fees", film.getFees());
    query.exec();
}

void FilmLibrary::findFilmCommand() {
    std::cout << "Searching for film" << std::endl;
    string name = FilmLibrary::inputName("Film's title: ", "", false);
    int year = FilmLibrary::inputNumber("Film's year (if you dont remember, enter 0): ");
    pair<bool, Film> result = this->getFilm(name, year);
    if(result.first){
        std::cout<<"film found, continue working"<<std::endl;
    }else{
        std::cout<<"film is not found, terminate"<<std::endl;
    }
}

pair<bool, Film> FilmLibrary::getFilm(const string &name, int year) {
    Database db = this->connect();

    string line = "SELECT * FROM films WHERE name=:name";
    if (year != 0) line += " AND year=:year";
    Statement query = Statement(db, line);

    query.bind(":name", name);
    if(year!=0) query.bind(":year", year);
    if (query.executeStep()) {
        Film film = Film(query.getColumn("name"), query.getColumn("producer"),
                         query.getColumn("screenwriter"), query.getColumn("composer"),
                         Date(query.getColumn("day"), query.getColumn("month"), query.getColumn("year")),
                         query.getColumn("fees"));
        return pair<bool, Film>(true, film);
    }
    return pair<bool, Film>(false, Film());
}

bool FilmLibrary::parser(const string &str) {
    regex oneWord(R"(^[a-zA-Z]+$)");
    smatch match;
    return regex_search(str, match, oneWord);
}

string FilmLibrary::inputName(const string &who, const string &error, bool strict) {
    string name;
    if (strict) {
        while (true) {
            std::cout << who << std::endl;
            cin >> name;
            if (FilmLibrary::parser(name)) {
                break;
            } else {
                std::cout << error << std::endl;
            }
        }
    } else {
        cin >> name;
    }
    return name;
}

int FilmLibrary::inputNumber(const string &whatNumber) {
    string str;
    int number;
    while (true) {
        std::cout << whatNumber << std::endl;
        cin >> str;
        try {
            number = stoi(str);
            break;
        } catch (invalid_argument &e) {
            std::cout << "You need to enter a number" << std::endl;
        }
    }
    return number;
}


