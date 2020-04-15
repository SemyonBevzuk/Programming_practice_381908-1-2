#include <iostream>
#include <vector>
#include"TicketOffice.h"

using namespace std;

int main()
{
	try 
	{
		Cinema cinema;
		CinemaHall hall1(1, 5, 5, 5, 5, 200);
		Date date1(15, 4, 2020);
		Time time1(0, 0, 15);
		Session session1(hall1, date1, time1, "Stalker");
		cinema.addSession(session1);
		CinemaHall hall2(2, 6, 6, 6, 6, 250);
		Date date2(20, 4, 2020);
		Time time2(0, 0, 19);
		Session session2(hall2, date2, time2, "Metro");
		cinema.addSession(session2);
		TicketOffice::acceptOrder(cinema, date1, time1, "Stalker", 1, "VIP", 200);
	}
	catch (string s) {
		cout << s;
	}
}
