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
	Date date;
	Time time;
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
		cout << "Ряд: " << num_row << " место:" << num_place << endl;
	}
};

class TicketOffice
{
private:
	Date current_date;
	Time current_time;
	Cinema cinema;
	vector<Order> orders;
	int SeanceId(Date d, Time t, int num);
	bool IsSeanceEnabled(Date d, Time t);
	vector<Ticket> CreateTickets(int id, Date d, Time t, int num);
public:
	TicketOffice() {}
	TicketOffice(Cinema c)
	{
		cinema = c;
	}
	void SetCurrentDateTime(Date d, Time t);
	bool TicketsOrder(int id, Date d, Time t, int num, int count, int zone);
	bool IsFree(Date d, Time t, int num, int count, int zone);
	bool Reserve(int id, Date d, Time t, int num, int count, int zone);
	double CalculateCost(int id, Date d, Time t, int num);
	bool CancelOrder(int id, Date d, Time t, int num);
	~TicketOffice() {}
};

