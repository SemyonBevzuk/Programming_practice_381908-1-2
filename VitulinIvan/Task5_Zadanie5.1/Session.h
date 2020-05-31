#pragma once
#include <iostream>
#include <string>
#include "DateTime.h"
#include <vector>
#include <map>
#include "DateTime.h"
#include "Hall.h"

using namespace std;

class Ticket;

class Session
{
    string myFilmName;
    DateTime myDate;
    //true - free
    bool** myTickets;
    bool** myVIPTickets;
    int myTicketsRowCount, myTicketsColumnCount, myVIPTicketsRowCount, myVIPTicketsColumnCount;
    int myFreeTickets, myFreeVIPTickets;
    int myHallNumber;
public:
    Session();
    Session(string Name, int theHall, DateTime theDate);
    Ticket CreateTicket(int Row, int Column, bool VIP);
    int AllocatePlaces(int theTickets, int theVIPTikets, vector<Ticket>& theOutTickets);
    void ReleasePlaces(const vector<Ticket>& theTickets);
    void ReleasePlace(bool theVIP, int theRow, int theColumn);
    DateTime GetData();
    string ToString();
    static int getPrice(DateTime time);
};

using namespace std;

class Ticket
{
public:
    string FilmName;
    int Hall;
    int Row, Column;
    DateTime Date;
    bool VIP;
    Session* mySession;
    int price;
    Ticket();
    Ticket(string Name, int Hall, int Row, int Column, DateTime Date, bool VIP, int price, Session* ses) :
        FilmName(Name), Hall(Hall), Row(Row), Column(Column), Date(Date), VIP(VIP), price(price), mySession(ses) {}
    Ticket(const Ticket& copy);
    string ToString();
};