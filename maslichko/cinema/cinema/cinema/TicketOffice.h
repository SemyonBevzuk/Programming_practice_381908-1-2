#ifndef TICKET
#define TICKET

#include "Сinema.h"

class Date //Задание текущей даты и времени
{
public:
	int t_day; //Текущий день
	int t_month; //Текущий месяц
	int t_year; //Текущий год
	int t_hour; //Часы
	int t_min; //Минуты

	Date(int day_m, int month_m, int year_m, int hour_m, int min_m)
	{
		t_day = day_m;
		t_month = month_m;
		t_year = year_m;
		t_hour = hour_m;
		t_min = min_m;
	}
};

class TicketOffice
{
public:
	TicketOffice()
	{
	}
	vector<string> Print(vector<Cinema> temp);
	int Buy(vector<Cinema>& temp, int day, int month, string name_film, int quantity, string zone, Date& date);
	int FindPlaces(vector<Cinema>& temp, int day, int month, string name_film);
	int Reservation(vector<Cinema>& temp, int day, int month, string name_film, int quantity, string zone);
	int Cancel(vector<Cinema>& temp, int day, int month, string name_film, int quantity);
	vector<string> CreateTicket(vector<Cinema>& temp, int day, int month, string name_film);

	int Cost(int price, string zone);
	int Assignment(vector<vector<string>>& temp, int cost, int quantity, string zone);
};


#endif