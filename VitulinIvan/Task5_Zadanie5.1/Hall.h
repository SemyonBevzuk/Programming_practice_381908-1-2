#pragma once

class Hall {
public:
    int myTicketsRowCount, myTicketsColumnCount, myVIPTicketsRowCount, myVIPTicketsColumnCount;
};
static class Halls {
public:
    static Hall getHall(int num);
    
};

