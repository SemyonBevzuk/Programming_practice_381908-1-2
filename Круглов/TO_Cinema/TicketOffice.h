#ifndef TICKET_OFFICE_H
#define TICKET_OFFICE_H
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
private:
	//Вспомогательные функции
	static bool isAvailabilityPlacess(const Cinema& cinema, int SessionNumber, int CountPlaces, const string& ZoneType);
	static int findSession(const Cinema& cinema, Date date, Time time, int HallNumber);
	static vector<pair<int, int>> findFreePlaces(const Cinema& cinema, const string& ZoneType, int SessionNumber);
	static bool isCorrectlyTime(const Date& date, const Time& time1);
public:
	static bool checkCountPlaces(const Cinema& cinema, Date date, Time time, int HallNumber, string ZoneType, int CountPlaces);
	static bool reservePlaces(Cinema& cinema, Date date, Time time, int HallNumber, string ZoneType, int CountPlaces);
	static Ticket makeTicket(const Date& date_,const Time& time_ , string NameFilm_, string ZonType_, int HallNumber_, int NumRow_, int NumPlace_);
	static bool cancelOrder(Cinema& cinema, const Ticket& ticket);
	static int calculateCost(const Cinema& cinema, int CountTicket, const Session& session, string ZoneType);
	static vector<Ticket> acceptOrder(Cinema& cinema, Date date, Time time, string NameFilm, int HallNumber, string ZoneType, int CountPlaces);
};
#endif
