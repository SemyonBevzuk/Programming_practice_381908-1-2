//
// Created by Kirill Lakhov on 13.03.2020.
//

#ifndef TASK4_FILM_H
#define TASK4_FILM_H

#import "string"
#include "Date.h"

using namespace std;

class Film {
public:
    Film(string name = "Фильм", string producer = "Пригожин", string writer = "Хелебников",
         string composer = "Уильямс", Date date = Date(), int fees = 100000);

private:
    string name;
    string producer;
    string writer;
    string composer;
    Date date;
    int fees;
    static bool parser(const string &str);
};


#endif //TASK4_FILM_H
