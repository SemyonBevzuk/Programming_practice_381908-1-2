#include "TicketOffice.h"

void TicketOffice::AddSession(string Name, DateTime time, int Hall)
{
    myFilmSessionsMap[Name].AddSession(Name, time, Hall);
}

vector<Session> TicketOffice::GetSessions(string Name)
{
    return myFilmSessionsMap[Name].GetSessions();
}

vector<Session> TicketOffice::GetSessions()
{
    vector<Session> res;
    for (auto anIt = myFilmSessionsMap.begin(); anIt != myFilmSessionsMap.end(); anIt++)
    {
        auto next = *anIt;
        Film film = next.second;
        vector<Session> ses = film.GetSessions();
        for (size_t i = 0; i < ses.size(); i++)
        {
            res.push_back(ses[i]);
        }
        
    }
    return res;
}

vector<Ticket> TicketOffice::GetTickets(string Film, DateTime data, int ticketCount, int vipTiketCount, double& price )
{
    vector<Ticket> out;
    auto& ses = myFilmSessionsMap[Film].getSession(data);
    price = ses.AllocatePlaces(ticketCount, vipTiketCount, out);
    return out;
}

void TicketOffice::ReturnTickets(vector<Ticket> tickets)
{
    if (tickets.size() == 0) return;
    auto aSes = tickets[0].mySession;
    for (size_t i = 0; i < tickets.size(); i++)
    {
        aSes->ReleasePlace(tickets[i].VIP, tickets[i].Row, tickets[i].Column);
    }
}
