#ifndef TICKET
#define TICKET

#include "Cinema.h"

class Date //������� ������� ���� � �������
{
public:
	int t_day; //������� ����
	int t_month; //������� �����
	int t_year; //������� ���
	int t_hour; //����
	int t_min; //������

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
	int Cost(int price, string zone); //������������� ���� � ����������� �� ����
	int Assignment(vector<vector<string>>& temp, int cost, int quantity, string zone); //����������, ����� ����� ������
public:
	TicketOffice(vector<Cinema>& seance_m)
	{
		seance = seance_m;
	}
	vector<string> Print(); //����� ���������� � �������
	int Buy(int day, int month, string name_film, int quantity, string zone, Date& date); //�������
	int FindPlaces(int day, int month, string name_film); //��������� �����
	int Reservation(int day, int month, string name_film, int quantity, string zone); //������������
	int Cancel(int day, int month, string name_film, int quantity); //������ �������
	vector<string> CreateTicket(int day, int month, string name_film); //������������ �������
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

							t = "���: " + to_string(k) + " �����: " + to_string(j) + " ����: " + seance_temp[i].pls[k][j] + " ����: " + to_string(seance);
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