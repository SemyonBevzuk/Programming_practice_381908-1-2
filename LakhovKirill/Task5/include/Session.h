//
// Created by Kirill on 23.04.2020.
//

#ifndef TASK5_SESSION_H
#define TASK5_SESSION_H

#include "DateTime.h"
#include "Hall.h"

class Session {
public:
    Session(const string& name, Hall& hall, DateTime& date, int price, int vipPrice ,int occupiedPlaces = 0,
            int occupiedVipPlaces = 0);
    inline string getName(){ return this->name;}
    inline Hall getHall(){ return  this->hall;}
    inline DateTime getDateTime(){ return this->date;}
    inline int getPrice(){ return this->price;}
    inline int getVipPrice(){ return this->vipPrice;}
    inline int getOccupiedPlaces(){ return this->occupiedPlaces;}
    inline int getOccupiedVipPlaces(){ return this->occupiedVipPlaces;}
private:
    string name;
    Hall hall;
    DateTime date;
    int price;
    int vipPrice;
    int occupiedPlaces;
    int occupiedVipPlaces;
};


#endif //TASK5_SESSION_H
