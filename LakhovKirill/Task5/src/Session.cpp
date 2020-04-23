//
// Created by Kirill on 23.04.2020.
//

#include "../include/Session.h"

Session::Session(const string &name, Hall &hall, DateTime &date, int price, int vipPrice, int occupiedPlaces,
                 int occupiedVipPlaces) {
    this->name = name;
    this->hall = hall;
    this->date = date;
    this->price = price;
    this->vipPrice = vipPrice;
    this->occupiedPlaces = occupiedPlaces;
    this->occupiedVipPlaces = occupiedVipPlaces;
}
