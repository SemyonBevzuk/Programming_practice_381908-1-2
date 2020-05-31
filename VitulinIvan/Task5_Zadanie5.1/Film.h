#pragma once
#include <iostream>
#include "DateTime.h"
#include "Session.h"


using namespace std;

class Film
{
    string myName;
    vector<Session> mySessions;
public:
    Film();
    void AddSession(string Name, DateTime date, int Hall);
    Film(string Name) : myName(Name) {}
    vector<Session> GetSessions();
    Session& getSession(DateTime time);
};

