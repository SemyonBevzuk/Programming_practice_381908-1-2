#include "Session.h"


Session::Session()
{
}

Session::Session(string Name, int theHall, DateTime theDate)
{
    Hall myHall = Halls::getHall(theHall);
    myHallNumber = theHall;
    myDate = theDate;
    myTickets = new bool* [myTicketsRowCount = myHall.myTicketsRowCount];
    myTicketsColumnCount = myHall.myTicketsColumnCount;
    for (size_t i = 0; i < myTicketsRowCount; i++)
    {
        myTickets[i] = new bool[myTicketsColumnCount];
        for (size_t j = 0; j < myTicketsColumnCount; j++)
        {
            myTickets[i][j] = true;
        }
    }
    myVIPTickets = new bool* [myVIPTicketsRowCount = myHall.myVIPTicketsRowCount];
    myVIPTicketsColumnCount = myHall.myVIPTicketsColumnCount;
    for (size_t i = 0; i < myVIPTicketsRowCount; i++)
    {
        myVIPTickets[i] = new bool[myVIPTicketsColumnCount];
        for (size_t j = 0; j < myVIPTicketsColumnCount; j++)
        {
            myVIPTickets[i][j] = true;
        }
    }
    myFreeTickets = myTicketsColumnCount * myTicketsRowCount;
    myFreeVIPTickets = myVIPTicketsColumnCount * myVIPTicketsRowCount;
    myFilmName = Name;
}

Ticket Session::CreateTicket(int Row, int Column, bool VIP)
{
    return Ticket(myFilmName, myHallNumber, Row, Column, myDate, VIP, Session::getPrice(myDate), this);
}

int Session::AllocatePlaces(int theTickets, int theVIPTikets, vector<Ticket>& theOutTickets)
{
    if (theTickets > myFreeTickets || theVIPTikets > myFreeVIPTickets) return 0;
    int i = 0, j = 0;
    while (theTickets > 0)
    {
        if (myTickets[i][j])
        {
            theOutTickets.push_back(CreateTicket(i, j, false));
            myTickets[i][j] = false;
            myFreeTickets--;
            theTickets--;
        }
        j++;
        if (j == myTicketsColumnCount)
        {
            i++;
            j = 0;
        }
        
    }
    i = 0;
    j = 0;
    while (theVIPTikets > 0)
    {
        if (myVIPTickets[i][j])
        {
            theOutTickets.push_back(CreateTicket(i, j, true));
            myVIPTickets[i][j] = false;
            myFreeVIPTickets--;
            theVIPTikets--;
        }
        j++;
        if (j == myVIPTicketsColumnCount)
        {
            i++;
            j = 0;
        }
        
    }
    return Session::getPrice(myDate) * theOutTickets.size();
}

void Session::ReleasePlaces(const vector<Ticket>& theTickets)
{
    for (size_t i = 0; i < theTickets.size(); i++)
    {
        if (theTickets[i].VIP) { 
            myVIPTickets[theTickets[i].Row][theTickets[i].Column] = true; 
            myFreeVIPTickets++;
        }
        else
        {
            myTickets[theTickets[i].Row][theTickets[i].Column] = true;
            myFreeTickets++;
        }
    }
}

void Session::ReleasePlace(bool theVIP, int theRow, int theColumn)
{
    if (theVIP) {
        myVIPTickets[theRow][theColumn] = true;
        myFreeVIPTickets++;
    }
    else
    {
        myTickets[theRow][theColumn] = true;
        myFreeTickets++;
    }
}

DateTime Session::GetData()
{
    return myDate;
}

string Session::ToString()
{
    string res = "�����: " + myFilmName + "\n����: " + myDate.ToString() + "\n" + "���: " + to_string(myHallNumber) + "\n";
    return res;
}

int Session::getPrice(DateTime time)
{
    if (time.myHour >= 8 && time.myHour < 12) return 150;
    if (time.myHour >= 12 && time.myHour < 18) return 200;
    if (time.myHour >= 18 && time.myHour < 24) return 250;
    return 0;
}

Ticket::Ticket()
{
}

Ticket::Ticket(const Ticket& copy)
{
    FilmName = copy.FilmName;
    Hall = copy.Hall;
    Row = copy.Row;
    Column = copy.Column;
    Date = copy.Date;
    VIP = copy.VIP;
    mySession = copy.mySession;
}

string Ticket::ToString()
{
    string res = "\n����� �� ����� " + FilmName +
        "\n��� �" + to_string(Hall) +
        "\n������ " + ((VIP) ? "VIP" : "�������") +
        "\n��� " + to_string(Row+1) + " ����� " + to_string(Column+1) +
        "\n����-����� " + Date.ToString();
    return res;
}