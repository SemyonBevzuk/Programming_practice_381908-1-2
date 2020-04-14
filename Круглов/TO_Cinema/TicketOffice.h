#include"Cinema.h"
#include<string>
#include"Date.h"
#include<vector>
using namespace std;


struct Ticket {
	Date date;
	Time time;
	string NameFilm;
	string ZoneType;
	int HallNumber;
	int NumRow, NumPlace;
};

class TicketOffice {
	bool checkCountPlaces(Cinema& cinema, Date date, Time time, int HallNumber, string ZoneType, int CountPlaces);
	bool reservePlaces(Cinema& cinema, Date date, Time time, int HallNumber, string ZoneType, int CountPlaces);
	Ticket makeTicket(const Date& date_,const Time& time_ , string NameFilm_, string ZonType_, int HallNumber_, int NumRow_, int NumPlace_);
	bool cancelOrder(Cinema& cinema, const Ticket& ticket);
	int calculateCost(const Cinema& cinema, int CountTicket, const Session& session, string ZoneType);
	vector<Ticket> acceptOrder(Cinema& cinema, Date date, Time time, string NameFilm, int HallNumber, string ZoneType, int CountPlaces);
};
