//
// Created by Kirill Lakhov on 13.03.2020.
//

#ifndef TASK4_FILM_H
#define TASK4_FILM_H

#include "string"
#include "Date.h"

using namespace std;

class Film {
public:
    Film(string name = "Фильм", string producer = "Пригожин", string screenwriter = "Хелебников",
         string composer = "Уильямс", Date date = Date(), int fees = 100000);
    inline string getName(){ return this->name;}
    inline string getProducer(){ return this->producer;}
    inline string getScreenwriter(){return this->screenwriter;}
    inline string getComposer(){return this->composer;}
    inline int getDay(){ return this->date.getDay();}
    inline int getMonth(){ return this->date.getMonth();}
    inline int getYear(){ return this->date.getYear();}
    inline int getFees(){ return this->fees;}

private:
    string name;
    string producer;
    string screenwriter;
    string composer;
    Date date;
    int fees;
    static bool parser(const string &str);
};


#endif //TASK4_FILM_H
