

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
            " box_office INTEGER NOT NULL)");
    return true;
}


Database FilmLibrary::connect() {
    Database db = Database(this->database, OPEN_CREATE | OPEN_READWRITE);
    return db;
}

void FilmLibrary::start() {
    bool isWorking = true;
    std::cout << "Welcome to the app which allows you to interact with your personal Film library" << std::endl;

    while (isWorking) {
        std::cout << "\n";
        std::cout << "Choose next action:" << std::endl;
        std::cout << "1.Add film" << std::endl;
        std::cout << "2.Find film by name and get information/change/delete it" << std::endl;
        std::cout << "3.All producer films" << std::endl;
        std::cout << "4.All films in particular year" << std::endl;
        std::cout << "5.N films with max box office" << std::endl;
        std::cout << "6.N films with max box office in particular year" << std::endl;
        std::cout << "7.Amount of films in library" << std::endl;
        std::cout<<"8.Exit"<<std::endl;
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
            case 3: {
                this->allProducerFilmsCommand();
                break;
            }
            case 4: {
                this->allYearFilmsCommand();
                break;
            }
            case 5: {
                this->maxBoxOfficeCommand();
                break;
            }
            case 6: {
                this->maxBoxOfficeCommand(true);
                break;
            }
            case 7: {
                this->allFilmsCountCommand();
                break;
            }
            case 8:{
                std::cout<<"Exiting"<<std::endl;
                isWorking = false;
                break;
            }
            default: {
                std::cout << "No such command" << std::endl;
            }
        }
    }
}

void FilmLibrary::createNewFilmCommand() {
    std::cout << "Creating new film" << std::endl;
    Film film = FilmLibrary::inputFilm();
    pair<bool, Film> result = this->getFilm(film.getName(), film.getYear());
    if (result.first) {
        std::cout << "That film is already in the library, rewriting" << std::endl;
        this->changeFilm(result.second, film);
    } else {
        std::cout << "creating new film" << std::endl;
        this->createNewFilm(film);
    }
}

void FilmLibrary::createNewFilm(Film film) {
    Database db = this->connect();
    Statement query = Statement(db, "INSERT INTO films VALUES (NULL, :name, :producer, :screenwriter, :composer, "
                                    ":day, :month, :year, :box_office)");
    query.bind(":name", film.getName());
    query.bind(":producer", film.getProducer());
    query.bind(":screenwriter", film.getScreenwriter());
    query.bind(":composer", film.getComposer());
    query.bind(":day", film.getDay());
    query.bind(":month", film.getMonth());
    query.bind(":year", film.getYear());
    query.bind(":box_office", film.getBoxOffice());
    query.exec();
}

void FilmLibrary::findFilmCommand() {
    std::cout << "Searching for film" << std::endl;
    string name = FilmLibrary::inputName("Film's title: ", "", false);
    int year = FilmLibrary::inputNumber("Film's year (if you dont remember, enter 0): ");
    pair<bool, Film> result = this->getFilm(name, year);
    if (result.first) {
        std::cout << "Film was found, what do you want to do?" << std::endl;
        std::cout << "1.Print information" << std::endl;
        std::cout << "2.Change information" << std::endl;
        std::cout << "3.Delete film" << std::endl;
        string input;
        cin >> input;
        switch (stoi(input)) {
            case 1: {
                this->printFilmCommand(result.second);
                break;
            }
            case 2: {
                this->changeFilmCommand(result.second);
                std::cout << "Film changed successfully" << std::endl;
                break;
            }
            case 3: {
                this->deleteFilmCommand(result.second);
                std::cout << "Film deleted successfully" << std::endl;
                break;
            }
            default: {
                std::cout << "No such command" << std::endl;
            }
        }
    } else {
        std::cout << "Film is not found, try again" << std::endl;
    }
}

void FilmLibrary::printFilmCommand(Film film) {
    std::cout << "Film information:" << std::endl;
    std::cout << "Producer: " << film.getProducer() << std::endl;
    std::cout << "Screenwriter: " << film.getScreenwriter() << std::endl;
    std::cout << "Composer: " << film.getComposer() << std::endl;
    std::cout << "Release date: " << film.getDate() << std::endl;
    std::cout << "Box office: " << film.getBoxOffice() << std::endl;
}

void FilmLibrary::changeFilmCommand(Film to_change) {
    Film new_film = FilmLibrary::inputFilm();
    this->changeFilm(to_change, new_film);
}

void FilmLibrary::changeFilm(Film to_change, Film new_film) {
    Database db = this->connect();
    Statement query = Statement(db, "UPDATE films SET name=:name, producer=:producer,"
                                    " screenwriter=:screenwriter, composer=:composer, day=:day, month=:month,"
                                    "year=:year, box_office=:box_office WHERE name=:old_name AND year=:old_year");
    query.bind(":name", new_film.getName());
    query.bind(":producer", new_film.getProducer());
    query.bind(":screenwriter", new_film.getScreenwriter());
    query.bind(":composer", new_film.getComposer());
    query.bind(":day", new_film.getDay());
    query.bind(":month", new_film.getMonth());
    query.bind(":year", new_film.getYear());
    query.bind(":box_office", new_film.getBoxOffice());
    query.bind(":old_name", to_change.getName());
    query.bind(":old_year", to_change.getYear());
    query.exec();
}

void FilmLibrary::deleteFilmCommand(Film film) {
    Database db = this->connect();
    Statement query = Statement(db, "DELETE FROM films WHERE name=:name AND year=:year");
    query.bind(":name", film.getName());
    query.bind(":year", film.getYear());
    query.exec();
}

bool FilmLibrary::printFilmsByQuery(Statement &query, const string &error, int amount) {
    if (!query.executeStep()) {
        std::cout << error << std::endl;
        return false;
    } else {
        if (!amount) {
            do {
                std::cout << query.getColumn("name") << " " << "year:" << query.getColumn("year")
                          << "  box office:" << query.getColumn("box_office") << std::endl;
            } while (query.executeStep());
        } else {
            int times = 1;
            do {
                std::cout << query.getColumn("name") << " " << "year:" << query.getColumn("year")
                          << "  box office:" << query.getColumn("box_office") << std::endl;
                times++;
            } while (query.executeStep() && times <= amount);
        }
        return true;
    }
}

void FilmLibrary::allProducerFilmsCommand() {
    string producer = FilmLibrary::inputName("Producer", "Input producer's lastname as one word");
    Database db = this->connect();
    Statement query = Statement(db, "SELECT * FROM films WHERE producer=:producer");
    query.bind(":producer", producer);
    this->printFilmsByQuery(query, "There are no films of that producer");
}

void FilmLibrary::allYearFilmsCommand() {
    int year = FilmLibrary::inputNumber("Year, when films were released: ");
    Database db = this->connect();
    Statement query = Statement(db, "SELECT * FROM films WHERE year=:year");
    query.bind(":year", year);
    this->printFilmsByQuery(query, "There are no films in that year");
}

void FilmLibrary::maxBoxOfficeCommand(bool isYear) {
    int filmAmount = FilmLibrary::inputNumber("Amount of films: ");
    int allFilms = this->allFilmsCount();
    bool tooMuch = filmAmount > allFilms;
    filmAmount = tooMuch ? allFilms : filmAmount;
    string lineQuery = "SELECT * FROM films";
    if (isYear) {
        int year = FilmLibrary::inputNumber("Year:");
        lineQuery += " WHERE year=" + to_string(year);
    }
    lineQuery += " ORDER BY box_office DESC";
    Database db = this->connect();
    Statement query = Statement(db, lineQuery);
    bool result = this->printFilmsByQuery(query, "No box office films", filmAmount);
    if (tooMuch && result) std::cout << "There are fewer films in library than you requested" << std::endl;
}

void FilmLibrary::allFilmsCountCommand() {
    std::cout << "There are " << this->allFilmsCount() << " films in library" << std::endl;
}

int FilmLibrary::allFilmsCount(int year) {
    Database db = this->connect();
    string line;
    if (year) {
        line = "SELECT COUNT(*) FROM films WHERE year=" + to_string(year);
    } else {
        line = "SELECT COUNT(*) FROM films";
    }
    Statement query(db, line);
    query.executeStep();
    return query.getColumn("COUNT(*)");
}

pair<bool, Film> FilmLibrary::getFilm(const string &name, int year) {
    Database db = this->connect();

    string line = "SELECT * FROM films WHERE name=:name";
    if (year != 0) line += " AND year=:year";
    Statement query = Statement(db, line);

    query.bind(":name", name);
    if (year != 0) query.bind(":year", year);
    if (query.executeStep()) {
        Film film = Film(query.getColumn("name"), query.getColumn("producer"),
                         query.getColumn("screenwriter"), query.getColumn("composer"),
                         Date(query.getColumn("day"), query.getColumn("month"), query.getColumn("year")),
                         query.getColumn("box_office"));
        return pair<bool, Film>(true, film);
    }
    return pair<bool, Film>(false, Film());
}

bool FilmLibrary::parser(const string &str) {
    regex oneWord(R"(^[a-zA-Z]+$)");
    smatch match;
    return regex_search(str, match, oneWord);
}

Film FilmLibrary::inputFilm() {
    string name = FilmLibrary::inputName("Film title:", "", false);
    string producer = FilmLibrary::inputName("Producer:", "You need to enter lastname with one word");
    string writer = FilmLibrary::inputName("Screenwriter:", "You need to enter lastname with one word");
    string composer = FilmLibrary::inputName("Composer:", "You need to enter lastname with one word");
    int day = FilmLibrary::inputNumber("Day, when film was released:");
    int month = FilmLibrary::inputNumber("Month, when film was released:");
    int year = FilmLibrary::inputNumber("Year, when film was released:");
    int box_office = FilmLibrary::inputNumber("Film box office:");
    return Film(name, producer, writer, composer, Date(day, month, year), box_office);
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
        std::cout << who << std::endl;
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



