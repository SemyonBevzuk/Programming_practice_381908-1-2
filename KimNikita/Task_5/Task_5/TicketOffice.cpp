#include "TicketOffice.h"
#include <algorithm>

using namespace std;

void TicketOffice::SetCurrentDateTime(Date d, Time t)
{
	current_date = d;
	current_time = t;
}
bool TicketOffice::IsSeanceEnabled(Date d, Time t)
{
	Date dt = current_date;
	Time tt = current_time;
	tt += Time(0, 10);
	dt += Date(3, 0);
	if (dt < d || tt < t)
		return false;
	return true;
}
bool TicketOffice::TicketsOrder(int id, Date d, Time t, int num, int count, int zone)
{
	if (!IsSeanceEnabled(d, t))
		throw exception("Вы не можете заказывать билеты на это время и день");
	if (IsFree(d, t, num, count, zone))
	{
		Reserve(id, d, t, num, count, zone);
		CreateTickets(id, d, t, num);
		return true;
	}
	return false;
}
int TicketOffice::SeanceId(Date d, Time t, int num)
{
	for (int i = 0; i < cinema.seanses.size(); i++)
	{
		if (cinema.seanses[i].date == d && cinema.seanses[i].time == t && cinema.seanses[i].num_zal == num)
		{
			return i;
		}
	}
	return -1;
}
bool TicketOffice::IsFree(Date d, Time t, int num, int count, int zone)
{
	int col = -1;
	int sid = SeanceId(d, t, num);
	if (sid != -1)
	{
		col = 0;
		for (int k = 0; k < cinema.seanses[sid].hall.size(); k++)
			for (int j = 0; j < cinema.seanses[sid].hall[k].size(); j++)
			{
				if (!cinema.seanses[sid].hall[k][j].free)
					if (cinema.seanses[sid].hall[k][j].vip == zone)
						col++;
			}
	}
	if (col >= count)
		return true;
	else
		if (col != -1)
			return false;
		else
			throw exception("Такого сеанса не существует");
}
bool TicketOffice::Reserve(int id, Date d, Time t, int num, int count, int zone)
{
	if (!IsSeanceEnabled(d, t))
		throw exception("Вы не можете заказывать билеты на это время и день");
	if (IsFree(d, t, num, count, zone))
	{
		vector<pair<int, int>>index_reserve;
		int sid = SeanceId(d, t, num);
		int c = 0;
		for (int i = 0; i < cinema.seanses[sid].hall.size(); i++)
		{
			if (c >= count)
				break;
			for (int j = 0; j < cinema.seanses[sid].hall[i].size(); j++)
			{
				if (c >= count)
					break;
				if (cinema.seanses[sid].hall[i][j].free)
				{
					cinema.seanses[sid].hall[i][j].free = false;
					index_reserve.push_back(make_pair(i, j));
					c++;
				}
			}
		}
		Order order;
		order.user_id = id;
		order.seance_id = sid;
		order.reserve_place = index_reserve;
		if (zone == 1)
			order.vip = true;
		else
			order.vip = false;
		orders.push_back(order);
		return true;
	}
	return false;
}
double TicketOffice::CalculateCost(int id, Date d, Time t, int num)
{
	double sum = 0;
	for (int i = 0; i < orders.size(); i++)
	{
		if (orders[i].user_id == id)
		{
			if (orders[i].seance_id == SeanceId(d, t, num))
			{
				double total_cost = cinema.seanses[orders[i].seance_id].cost_base;
				if (orders[i].vip)
					total_cost *= 1.5;
				if (cinema.seanses[orders[i].seance_id].time.hour < 12)
					total_cost *= 0.75;
				if (cinema.seanses[orders[i].seance_id].time.hour > 18)
					total_cost *= 1.5;
				sum += total_cost * orders[i].reserve_place.size();
				break;
			}
		}
	}
	return sum;
}
bool TicketOffice::CancelOrder(int id, Date d, Time t, int num)
{
	int sid = SeanceId(d, t, num);
	for (int i = 0; i < orders.size(); i++)
	{
		if (orders[i].user_id == id)
		{
			if (orders[i].seance_id == sid)
			{
				for (int j = 0; j < orders[i].reserve_place.size(); j++)
					cinema.seanses[orders[i].seance_id].hall[orders[i].reserve_place[j].first][orders[i].reserve_place[j].second].free = true;
				orders.erase(orders.begin() + i);
				return true;
			}
		}
	}
	return false;
}
vector<Ticket> TicketOffice::CreateTickets(int id, Date d, Time t, int num)
{
	Ticket ticket;
	vector<Ticket>tickets;
	int sid = SeanceId(d, t, num);
	for (int i = 0; i < orders.size(); i++)
	{
		if (orders[i].user_id == id)
		{
			if (orders[i].seance_id == sid)
			{
				for (int j = 0; j < orders[i].reserve_place.size(); j++)
				{
					ticket.date = d;
					ticket.time = t;
					ticket.film = cinema.seanses[orders[i].seance_id].film;
					ticket.num_zal = num;
					ticket.num_row = orders[i].reserve_place[j].first + 1;
					ticket.num_place = orders[i].reserve_place[j].second + 1;
					tickets.push_back(ticket);
				}
				orders.erase(orders.begin() + i);
				break;
			}
		}
	}
	return tickets;
}
