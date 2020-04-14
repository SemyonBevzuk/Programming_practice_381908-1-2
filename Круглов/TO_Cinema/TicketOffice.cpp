#include "TicketOffice.h"

using namespace std;

bool TicketOffice::checkCountPlaces(Cinema& cinema, Date date, Time time, int HallNumber, string ZoneType, int CountPlaces) {
	int SessionNumber = -1;
	int AvailableCountPlaces = 0;
	for (int i = 0; i < cinema.Sessions.size(); i++)
	{
		if (date == cinema.Sessions[i].date && time == cinema.Sessions[i].time && HallNumber == cinema.Sessions[i].Hall.HallNumber) {
			SessionNumber = i;
			break;
		}
	}
	if (SessionNumber == -1)//нет такой сессии
		return false;
	bool f = false;
	if (ZoneType == "VIP")// тип зоны
		f = true;
	if (f) {
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
bool TicketOffice::reservePlaces(Cinema& cinema, Date date, Time time, int HallNumber, string ZoneType, int CountPlaces) {
	int SessionNumber=-1;
	int AvailableCountPlaces=0;
	vector <pair<int, int>> places;
	for (int i = 0; i < cinema.Sessions.size(); i++)
	{
		if (date == cinema.Sessions[i].date && time == cinema.Sessions[i].time && HallNumber==cinema.Sessions[i].Hall.HallNumber) {
			SessionNumber = i;
			break;
		}
	}
	if (SessionNumber == -1)//нет такой сессии
		return false;
	if (ZoneType=="VIP") {
		for (int i = 0; i < cinema.Sessions[SessionNumber].Hall.RowVip; i++)
			for (int j = 0; j < cinema.Sessions[SessionNumber].Hall.CountVip; j++)
			{
				if (cinema.Sessions[SessionNumber].Hall.VipPlaces[i][j] == false)
				{
					AvailableCountPlaces++;
					places.push_back(make_pair(i, j));
				}
			}
		if (AvailableCountPlaces < CountPlaces)
			return false;
		for (int i = 0; i < CountPlaces; i++) {
			int ip, jp;
			ip = places[i].first;
			jp = places[i].second;
			cinema.Sessions[SessionNumber].Hall.VipPlaces[ip][jp] = true;
		}
	}
	else {
		for (int i = 0; i < cinema.Sessions[SessionNumber].Hall.RowCustom; i++)
			for (int j = 0; j < cinema.Sessions[SessionNumber].Hall.CountCustom; j++)
			{
				if (cinema.Sessions[SessionNumber].Hall.CustomPlaces[i][j] == false)
				{
					AvailableCountPlaces++;
					places.push_back(make_pair(i, j));
				}
			}
		if (AvailableCountPlaces < CountPlaces)
			return false;
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
	int SessionNumber = -1;
	Date date = ticket.date;
	Time time = ticket.time;
	int HallNumber = ticket.HallNumber;
	for (int i = 0; i < cinema.Sessions.size(); i++)
	{
		if (date == cinema.Sessions[i].date && time == cinema.Sessions[i].time && HallNumber == cinema.Sessions[i].Hall.HallNumber) {
			SessionNumber = i;
			break;
		}
	}
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
	vector <Ticket> tickets;
	int SessionNumber = -1;
	int AvailableCountPlaces = 0;
	vector <pair<int, int>> places;
	for (int i = 0; i < cinema.Sessions.size(); i++)
	{
		if (date == cinema.Sessions[i].date && time == cinema.Sessions[i].time && HallNumber == cinema.Sessions[i].Hall.HallNumber) {
			SessionNumber = i;
			break;
		}
	}
	if (SessionNumber == -1)//нет такой сессии
		throw "Неверные данные сессии";
	if (ZoneType=="VIP") {
		for (int i = 0; i < cinema.Sessions[SessionNumber].Hall.RowVip; i++)
			for (int j = 0; j < cinema.Sessions[SessionNumber].Hall.CountVip; j++)
			{
				if (cinema.Sessions[SessionNumber].Hall.VipPlaces[i][j] == false)
				{
					AvailableCountPlaces++;
					places.push_back(make_pair(i, j));
				}
			}
		if (AvailableCountPlaces < CountPlaces)
			throw "Недостаточно мест";
		for (int i = 0; i < CountPlaces; i++) {
			int ip, jp;
			ip = places[i].first;
			jp = places[i].second;
			cinema.Sessions[SessionNumber].Hall.VipPlaces[ip][jp] = true;
			tickets.push_back(makeTicket(date, time, NameFilm, ZoneType, HallNumber, ip, jp));
		}
	}
	else {
		for (int i = 0; i < cinema.Sessions[SessionNumber].Hall.RowCustom; i++)
			for (int j = 0; j < cinema.Sessions[SessionNumber].Hall.CountCustom; j++)
			{
				if (cinema.Sessions[SessionNumber].Hall.CustomPlaces[i][j] == false)
				{
					AvailableCountPlaces++;
					places.push_back(make_pair(i, j));
				}
			}
		if (AvailableCountPlaces < CountPlaces)
			throw "Недостаточно мест";
		for (int i = 0; i < CountPlaces; i++) {
			int ip, jp;
			ip = places[i].first;
			jp = places[i].second;
			cinema.Sessions[SessionNumber].Hall.CustomPlaces[ip][jp] = true;
			tickets.push_back(makeTicket(date, time, NameFilm, ZoneType, HallNumber, ip, jp));
		}
	}
	return tickets;
}