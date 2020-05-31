#pragma once
#include<iostream>
#include<map>
#include<string>
#include <list>
#include"Session.h"
#include "Film.h"

using namespace std;

class TicketOffice
{
    map<string, Film> myFilmSessionsMap;
public:
    void AddSession(string Name, DateTime time, int Hall);
    vector<Session> GetSessions(string Name);
    vector<Session> GetSessions();
    vector<Ticket> GetTickets(string Film, DateTime data, int ticketCount, int vipTiketCount, double& price);
    void ReturnTickets(vector<Ticket> tickets);
};

