#include "TicketOffice.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russia");
	ifstream fin("input.txt");
	Cinema mycinema;
	fin >> mycinema;
	TicketOffice ticketoffice(mycinema);
	Date t_date;
	Time t_time;
	int day, month, hour, minute;
	cin >> day >> month >> hour >> minute;
met:
	try
	{
		ticketoffice.SetCurrentDateTime(Date(day, month), Time(hour, minute));
		t_date = Date(29, 4);
		t_time = Time(14, 0);
		if (ticketoffice.IsFree(t_date, t_time, 1, 20, 1))
		{
			cout << "Места свободны" << endl;
			ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1);
			cout << "Места зарезервированы" << endl;
		}
		else
			cout << "Места заняты" << endl;
		double sum = ticketoffice.CalculateCost(1, t_date, t_time, 1);
		cout << "Стоимость билетов на выбранный сеанс: " << sum;
		if (ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1))
			cout << "Места зарезервированы" << endl;
		else
		{
			cout << "Нет такого кол-ва свободных мест";
			if (ticketoffice.CancelOrder(1, t_date, t_time, 1))
			{
				cout << "Заказ отменен" << endl;
				if (ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1))
					cout << "Места зарезервированы" << endl;
				else
					cout << "Места не удалось зарезервировать" << endl;
			}
			else
				cout << "Заказ не удалось отменить" << endl;
			vector<Ticket> mytickets = ticketoffice.CreateTickets(1, t_date, t_time, 1);
			cout << "Ваши билеты:" << endl;
			for (int i = 0; i < mytickets.size(); i++)
			{
				mytickets[i].PrintTicket();
			}
		}
	}
	catch (exception exp)
	{
		cout << exp.what();
		goto met;
	}
	return 0;
}