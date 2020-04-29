#pragma once
#include "Cinema.h"

struct Order
{
	int user_id;
	int seance_id;
	vector<pair<int, int>>reserve_place;
	bool vip;
};
struct Ticket
{
	DateS date;
	TimeS time;
	string film;
	int num_zal;
	int num_row;
	int num_place;
	void PrintTicket()
	{
		cout << "Дата: ";
		if (date.day < 10)
			cout << 0;
		cout << date.day << '.';
		if (date.month < 10)
			cout << 0;
		cout << date.month << endl;
		cout << "Время: ";
		cout << time.hour << ':';
		if (time.minute < 10)
			cout << 0;
		cout << time.minute << endl;
		cout << "Фильм: " << film << endl;
		cout << "Номер зала: " << num_zal << endl;
		cout << "Ряд: " << num_row << " место: " << num_place << endl;
		cout << endl;
	}
};

class TicketOffice
{
private:
	DateS current_date;
	TimeS current_time;
	Cinema cinema;
	vector<Order> orders;
	int SeanceId(DateS d, TimeS t, int num);
	bool IsSeanceEnabled(DateS d, TimeS t);
public:
	TicketOffice() {}
	TicketOffice(Cinema c)
	{
		cinema = c;
	}
	void SetCurrentDateSTimeS(DateS d, TimeS t);
	bool TicketsOrder(int id, DateS d, TimeS t, int num, int count, int zone, vector<Ticket>& tickets);
	bool IsFree(DateS d, TimeS t, int num, int count, int zone);
	bool Reserve(int id, DateS d, TimeS t, int num, int count, int zone);
	double CalculateCost(int id, DateS d, TimeS t, int num);
	bool CancelOrder(int id, DateS d, TimeS t, int num);
	vector<Ticket> CreateTickets(int id, DateS d, TimeS t, int num);
	void PrintSeanceHall(DateS d, TimeS t, int num);
	~TicketOffice() {}
};

