#include "TicketOffice .h"
TicketOffice::TicketOffice()
{
	this->~TicketOffice();
	seats.resize(0);
}

TicketOffice::~TicketOffice()
{
	day = 0;
	month = 0;
	year = 0;
	film = "";
	hour = 0;
	minut = 0;
	hall = 0;
	seats.clear();
	price = 0;
	sumprice = 0;
	count = 0;
}

void TicketOffice::CreateTickets(int y, int m, int d, string f, int h, int min, int ll, vector<pair<int, int>>& a, int p, int kol)
{
	day = d;
	month = m;
	year = y;
	film = f;
	hour = h;
	minut = min;
	hall = ll;
	seats.resize(a.size());
	seats = a;
	price = p;
	sumprice = p * kol;
	count = kol;
}


bool TicketOffice::CheckingTheDate_2(Cinema& a, int thisy, int thism, int thisd, int y, int m, int d)
{
	if (y > a.GetYear(a.CreateDate(thisd, thism, thisy, 3)))
		return true;
	else if (m > a.GetMonth(a.CreateDate(thisd, thism, thisy, 3)))
		return true;
	else if (d >= a.GetDay(a.CreateDate(thisd, thism, thisy, 3)))
		return true;
	else return false;
}

bool TicketOffice::CheckingTodayTime(int thisy, int thism, int thisd, int thish, int thismin, int y, int m, int d, int h, int min)
{
	int sum_min = thism - 10;
	int sum_hour = thish;
	if (sum_min <= 0)
	{
		sum_min = sum_min + 60;
		sum_hour--;
	}
	if (sum_hour < 0)
		sum_hour = sum_hour + 24;
	if (thisd == d && thism == m && thisy == y)
	{
		if (h < sum_hour || (h == sum_hour && m <= sum_min))
			return false;
		else return true;
	}
	else return true;
}

bool TicketOffice::CheckingSeans(Cinema& a, string film, int h, int min)
{
	if (a.ChSeans(film, h, min))
		return true;
	else return false;
}

vector<pair<int, int>>& TicketOffice::ReserveSeats(Cinema& a, int y, int m, int d, string film, int h, int min, string zone, int kol)
{
	seats = a.RSeats(y, m, d, film, h, min, zone, kol);
	return seats;
}

bool TicketOffice::CheckingSeats(Cinema& a, int y, int m, int d, string film, int h, int min, string zone, int kol)
{
	if (a.ChSeats(y, m, d, film, h, min, zone, kol))
		return true;
	else return false;
}

bool TicketOffice::DeleteTickets(Cinema& a, int y, int m, int d, string film, int h, int min, int index1, int index2)
{
	if (a.DelSeats(y, m, d, film, h, min, index1, index2))
		return true;
	else return false;
}

int TicketOffice::Price(Cinema& a, string film, string zone, int h, int min)
{
	if (zone == a.GetVIP())
		if (a.GetVipPrice(film, a.GetFilmsPrice()) <= -1)
			return -1;
		else
		{
			if (h<12||(h==12 && min ==0))
			    return a.GetVipPrice(film, a.GetFilmsPrice()) * 0,75;
			if (h > 12 || (h == 18 && min >= 0))
				return a.GetVipPrice(film, a.GetFilmsPrice()) * 1,5;
			else return a.GetVipPrice(film, a.GetFilmsPrice());
		}

	if (zone == a.GetSTANDART())
		if (a.GetStandartPrice(film, a.GetFilmsPrice()) <= -1)
			return -1;
		else
		{
			if (h < 12 || (h == 12 && min == 0))
			    return a.GetStandartPrice(film, a.GetFilmsPrice()) * 0,75;
			if (h > 12 || (h == 18 && min >= 0))
				return a.GetStandartPrice(film, a.GetFilmsPrice()) * 1,5;
			else return a.GetStandartPrice(film, a.GetFilmsPrice());
		}
	else return -1;
}

vector<pair<int, int>>& TicketOffice::operator=(const vector<pair<int, int>>& other)
{
	vector<pair<int, int>> a;
	a.resize(other.size());
	for (int i = 0; i < a.size(); i++)
	{
		a[i].first = other[i].first;
		a[i].second = other[i].second;
	}
	return a;
}

ostream& operator<< (ostream& stream, const TicketOffice& c)
{
	for (int i = 0; i < c.count; i++)
	{
		stream << "Date: " << c.day << "." << c.month << "." << c.year << "\n";
		stream << "Film: " << c.film << "\n";
		stream << "Time: " << c.hour << ":" << c.minut << "\n";
		stream << "Hall: " << c.hall << "\n";
		stream << "Row  " << c.seats[i].first << "     Seat  " << c.seats[i].second;
		stream << "Price: " << c.price << "\n\n";
		stream << "-------------------------------------------------\n\n";
	}
	stream << "Sum Price: " << c.sumprice;
	return stream;
}

bool CheckingTheDate_1(int d, int m, int y)
{
	int m1[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int m2[] = {0, 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (y / 4 != 0)
	{
		if (m >= 1 && m <= 12 && d <= m1[m - 1])
			return true;
		else return false;
	}
	else
	{
		if (y / 100 != 0)
		{
			if (m >= 1 && m <= 12 && d <= m2[m - 1])
				return true;
			else return false;
		}
		else
		{
			if (y / 400 != 0)
			{
				if (m >= 1 && m <= 12 && d <= m1[m - 1])
					return true;
				else return false;
			}
			else
			{
				if (m >= 1 && m <= 12 && d <= m2[m - 1])
					return true;
				else return false;
			}
		}
	}
}