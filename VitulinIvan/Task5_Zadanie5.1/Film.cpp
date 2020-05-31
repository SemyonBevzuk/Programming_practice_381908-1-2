#include "Film.h"


Film::Film()
{
}

void Film::AddSession(string Name, DateTime date, int Hall)
{
    Session aNewSession(Name, Hall,date);
    mySessions.push_back(aNewSession);
}

vector<Session> Film::GetSessions()
{
    return mySessions;
}

Session& Film::getSession(DateTime time)
{
    for (size_t i = 0; i < mySessions.size(); i++)
    {
        if (mySessions[i].GetData() == time) return mySessions[i];
    }
    throw - 1;
}
