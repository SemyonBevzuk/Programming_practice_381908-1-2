#pragma once
#include"TicketOffice.h"

class Cinema
{
public:
    Cinema(TicketOffice to);
    void Start();
private:

    void MenuHandler();
    int Menu();

    void printHead();
    void PrintMainMenu();
    void IncorrectAnswer();
    void Waiting();

    void ShowAllSession();
    void ShowAllSessionByFilm();
    void BuyTickets();
    void Cancle();

    TicketOffice myOffice;
    vector<Ticket> myLastPurchase;
};
