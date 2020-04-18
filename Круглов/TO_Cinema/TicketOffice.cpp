#include "TicketOffice.h"
#include<iostream>
#include<ctime>
#include<string>

using namespace std;

bool TicketOffice::checkCountPlaces(const Cinema& cinema, Date date, Time time, int HallNumber, string ZoneType, int CountPlaces) {
	int SessionNumber = findSession(cinema, date, time, HallNumber);
	if (SessionNumber == -1)//нет такой сессии
		return false;
	return isAvailabilityPlacess(cinema, SessionNumber, CountPlaces, ZoneType);
}

bool TicketOffice::reservePlaces(Cinema& cinema, Date date, Time time, int HallNumber, string ZoneType, int CountPlaces) {
	vector <pair<int, int>> places;
	if (!isCorrectlyTime(date, time))
		return false;
	int SessionNumber = findSession(cinema, date, time, HallNumber);
	if (SessionNumber == -1)//нет такой сессии
		return false;
	if (!isAvailabilityPlacess(cinema, SessionNumber, CountPlaces, ZoneType))
		return false;
	places = findFreePlaces(cinema, ZoneType, SessionNumber);
	if(ZoneType=="VIP")
		for (int i = 0; i < CountPlaces; i++) {
			int ip, jp;
			ip = places[i].first;
			jp = places[i].second;
			cinema.Sessions[SessionNumber].Hall.VipPlaces[ip][jp] = true;
		}
	else
	{
		for (int i = 0; i < CountPlaces; i++) {
			int ip, jp;
			ip = places[i].first;
			jp = places[i].second;
			cinema.Sessions[SessionNumber].Hall.CustomPlaces[ip][jp] = true;
		}
	}
	return true;
}

Ticket TicketOffice::makeTicket(const Date& date_,const Time& time_ , string NameFilm_, string ZonType_, int HallNumber_, int NumRow_, int NumPlace_) {
	Ticket res;
	res.date = date_;
	res.time = time_;
	res.NameFilm = NameFilm_;
	res.ZoneType = ZonType_;
	res.HallNumber = HallNumber_;
	res.NumRow = NumRow_;
	res.NumPlace = NumPlace_;
	return res;
}

bool TicketOffice::cancelOrder(Cinema& cinema, const Ticket& ticket) {
	Date date = ticket.date;
	Time time = ticket.time;
	int HallNumber = ticket.HallNumber;
	int SessionNumber = findSession(cinema, date, time, HallNumber);
	if (SessionNumber == -1)//нет такой сессии
		return false;
	if (ticket.ZoneType=="VIP")
		cinema.Sessions[SessionNumber].Hall.VipPlaces[ticket.NumRow][ticket.NumPlace] = false;
	else
		cinema.Sessions[SessionNumber].Hall.CustomPlaces[ticket.NumRow][ticket.NumPlace] = false;
	return true;
}

int TicketOffice::calculateCost(const Cinema& cinema,  int CountTicket, const Session& session,string ZoneType) {
	int SessionNumber = -1;
	for (int i = 0; i < cinema.Sessions.size(); i++)
	{
		if (session.date == cinema.Sessions[i].date && session.time == cinema.Sessions[i].time && session.Hall.HallNumber == cinema.Sessions[i].Hall.HallNumber) {
			SessionNumber = i;
			break;
		}
	}
	if (SessionNumber == -1)//нет такой сессии
		return -1;
	if (ZoneType == "VIP")
		return CountTicket * session.VipPrice;
	else
		return CountTicket * session.CustomPrice;
}

vector<Ticket> TicketOffice::acceptOrder(Cinema& cinema, Date date, Time time, string NameFilm, int HallNumber, string ZoneType, int CountPlaces)
{
	//проверка времени заказа
	string s = "Time has expired for the order";
	if (!isCorrectlyTime(date, time))
		throw  s;
	vector <Ticket> tickets;
	vector <pair<int, int>> places;
	int SessionNumber = findSession(cinema, date, time, HallNumber);
	s = "Incorrect Data Session";
	if (SessionNumber == -1)//нет такой сессии
		throw s;
	s = "Lack of Places";
	if (!isAvailabilityPlacess(cinema, SessionNumber, CountPlaces, ZoneType))
		throw s;
	places = findFreePlaces(cinema, ZoneType, SessionNumber);
	if (ZoneType == "VIP")
		for (int i = 0; i < CountPlaces; i++) {
			int ip, jp;
			ip = places[i].first;
			jp = places[i].second;
			cinema.Sessions[SessionNumber].Hall.VipPlaces[ip][jp] = true;
			tickets.push_back(makeTicket(date, time, NameFilm, ZoneType, HallNumber, ip, jp));
		}
	else
		for (int i = 0; i < CountPlaces; i++) {
			int ip, jp;
			ip = places[i].first;
			jp = places[i].second;
			cinema.Sessions[SessionNumber].Hall.CustomPlaces[ip][jp] = true;
			tickets.push_back(makeTicket(date, time, NameFilm, ZoneType, HallNumber, ip, jp));
		}
	return tickets;
}

ostream& operator<<(ostream& stream, const Ticket& ticket) {
	stream << ticket.date.getDateToString() << " ";
	stream << ticket.time<<"\n";
	stream << "Name: " << ticket.NameFilm << "\n"
		<< "Zone's type:" << ticket.ZoneType << "\n";
	stream << "Hall's number: " << ticket.HallNumber <<"\n";
	stream << "Row:" << ticket.NumRow << " Place:" << ticket.NumPlace;
	return stream;
}

// ¬—ѕќћќ√ј“≈Ћ№Ќџ≈ ‘”Ќ ÷»»-------------------------------------------------------------------------------------------------------
//
//
bool TicketOffice::isAvailabilityPlacess(const Cinema& cinema, int SessionNumber, int CountPlaces, const string& ZoneType) {
	int AvailableCountPlaces = 0;
	if (ZoneType == "VIP") {
		for (int i = 0; i < cinema.Sessions[SessionNumber].Hall.RowVip; i++)
			for (int j = 0; j < cinema.Sessions[SessionNumber].Hall.CountVip; j++)
			{
				if (cinema.Sessions[SessionNumber].Hall.VipPlaces[i][j] == false)
					AvailableCountPlaces++;
			}
	}
	else {
		for (int i = 0; i < cinema.Sessions[SessionNumber].Hall.RowCustom; i++)
			for (int j = 0; j < cinema.Sessions[SessionNumber].Hall.CountCustom; j++)
			{
				if (cinema.Sessions[SessionNumber].Hall.CustomPlaces[i][j] == false)
					AvailableCountPlaces++;
			}
	}
	if (AvailableCountPlaces < CountPlaces)
		return false;
	return true;
}

int TicketOffice::findSession(const Cinema& cinema, Date date, Time time, int HallNumber) {
	int SessionNumber = -1;
	for (int i = 0; i < cinema.Sessions.size(); i++)
	{
		if (date == cinema.Sessions[i].date && time == cinema.Sessions[i].time && HallNumber == cinema.Sessions[i].Hall.HallNumber) {
			SessionNumber = i;
			break;
		}
	}
	return SessionNumber;
}

vector <pair<int, int>> TicketOffice::findFreePlaces(const Cinema& cinema, const string& ZoneType, int SessionNumber) {
	vector<pair<int, int>> places;
	if (ZoneType == "VIP") {
		for (int i = 0; i < cinema.Sessions[SessionNumber].Hall.RowVip; i++)
			for (int j = 0; j < cinema.Sessions[SessionNumber].Hall.CountVip; j++)
			{
				if (cinema.Sessions[SessionNumber].Hall.VipPlaces[i][j] == false)
				{
					places.push_back(make_pair(i, j));
				}
			}
	}
	else {
		for (int i = 0; i < cinema.Sessions[SessionNumber].Hall.RowCustom; i++)
			for (int j = 0; j < cinema.Sessions[SessionNumber].Hall.CountCustom; j++)
			{
				if (cinema.Sessions[SessionNumber].Hall.CustomPlaces[i][j] == false)
				{
					places.push_back(make_pair(i, j));
				}
			}
	}
	return places;
}

bool TicketOffice::isCorrectlyTime(const Date& date, const Time& time1) {
	bool f = false;
	time_t t = time(NULL);
	struct tm* t_m;//кака€-то классна€ структура из ctime
	t_m = localtime(&t);
	Date date_(t_m->tm_mday, t_m->tm_mon+1, t_m->tm_year+1900);
	Time time_(t_m->tm_sec, t_m->tm_min - 10, t_m->tm_hour);
	if (date_ <= date)
		f = true;
	return f;
}
