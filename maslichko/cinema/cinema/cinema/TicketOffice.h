#ifndef TICKET
#define TICKET

#include "Cinema.h"

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
private:
	vector<Cinema> seance;
	int Cost(int price, string zone); //Корректировка цены в зависимости от зоны
	int Assignment(vector<vector<string>>& temp, int cost, int quantity, string zone); //Записывает, какие места заняты
public:
	TicketOffice(vector<Cinema>& seance_m)
	{
		seance = seance_m;
	}
	vector<string> Print(); //Вывод информации о сеансах
	int Buy(int day, int month, string name_film, int quantity, string zone, Date& date); //Продажа
	int FindPlaces(int day, int month, string name_film); //Свободные места
	int Reservation(int day, int month, string name_film, int quantity, string zone); //Бронирование
	int Cancel(int day, int month, string name_film, int quantity); //Отмена покупки
	vector<string> CreateTicket(int day, int month, string name_film); //Формирование билетов
};

class Ticket
{
	vector<Cinema> seance_temp;
	vector<string> ticket;
	int day;
	int month;
	string name_film;
public:
	Ticket(vector<Cinema>& seance_m, int day_m, int month_m, string name_film_m)
	{
		seance_temp = seance_m;
		day = day_m;
		month = month_m;
		name_film = name_film_m;
	}
	vector<string> MakeTicket()
	{
		string t;
		int seance;
		for (int i = 0; i < seance_temp.size(); i++)
		{
			if (seance_temp[i].name_film == name_film)
			{
				for (int k = 0; k < 8; k++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (seance_temp[i].pls[k][j] == "base" || seance_temp[i].pls[k][j] == "vip")
						{
							if (seance_temp[i].pls[k][j] == "vip")
							{
								seance = seance_temp[i].price + 150;
							}

							t = "Ряд: " + to_string(k) + " Место: " + to_string(j) + " Зона: " + seance_temp[i].pls[k][j] + " Цена: " + to_string(seance);
							ticket.push_back(t);

						}
					}
				}
			}
		}
		return ticket;
	}

};
#endif