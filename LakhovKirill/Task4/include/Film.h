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
    Film(string name = "Film", string producer = "Cameron", string screenwriter = "Tarantino",
         string composer = "Zimmer", Date date = Date(), int box_office = 100000);
    inline string getName(){ return this->name;}
    inline string getProducer(){ return this->producer;}
    inline string getScreenwriter(){return this->screenwriter;}
    inline string getComposer(){return this->composer;}
    inline int getDay(){ return this->date.getDay();}
    inline int getMonth(){ return this->date.getMonth();}
    inline int getYear(){ return this->date.getYear();}
    inline int getBoxOffice(){ return this->box_office;}
    inline string getDate(){ return this->date.getDate();}

private:
    string name;
    string producer;
    string screenwriter;
    string composer;
    Date date;
    int box_office;
    static bool parser(const string &str);
};


#endif //TASK4_FILM_H
