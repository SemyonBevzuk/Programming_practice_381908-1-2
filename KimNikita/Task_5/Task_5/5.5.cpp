#include "TicketOffice.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russia");
	ifstream fin("input.txt");
	Cinema mycinema;
	fin >> mycinema;
	TicketOffice ticketoffice(mycinema);
	DateS t_date;
	TimeS t_time;
	int day, month, hour, minute;
	cout << "Введите текущую дату и время: " << endl;
	cin >> day >> month >> hour >> minute;
	try
	{
		ticketoffice.SetCurrentDateSTimeS(DateS(day, month), TimeS(hour, minute));
		t_date = DateS(29, 4);
		t_time = TimeS(14, 0);
		if (ticketoffice.IsFree(t_date, t_time, 1, 20, 1))
		{
			cout << "Места свободны" << endl;
			ticketoffice.PrintSeanceHall(t_date, t_time, 1);
			ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1);
			cout << "Места зарезервированы" << endl;
			ticketoffice.PrintSeanceHall(t_date, t_time, 1);
		}
		else
			cout << "Места заняты" << endl;
		double sum = ticketoffice.CalculateCost(1, t_date, t_time, 1);
		cout << "Стоимость билетов на выбранный сеанс: " << sum << endl;
		cout << "Резервируем столько же" << endl;
		if (ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1))
			cout << "Места зарезервированы" << endl;
		else
		{
			cout << "Нет такого кол-ва свободных мест" << endl;
			if (ticketoffice.CancelOrder(1, t_date, t_time, 1))
			{
				cout << "Заказ отменен" << endl;
				ticketoffice.PrintSeanceHall(t_date, t_time, 1);
				if (ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1))
				{
					cout << "Места зарезервированы" << endl;
					ticketoffice.PrintSeanceHall(t_date, t_time, 1);
				}
				else
					cout << "Места не удалось зарезервировать" << endl;
			}
			else
				cout << "Заказ не удалось отменить" << endl;
		}
		vector<Ticket> mytickets = ticketoffice.CreateTickets(1, t_date, t_time, 1);
		cout << "Ваши билеты:" << endl << endl;
		for (int i = 0; i < mytickets.size(); i++)
		{
			mytickets[i].PrintTicket();
		}
		cout << "Автоматический заказ: " << endl << endl;
		t_date = DateS(1, 5);
		t_time = TimeS(10, 59);
		ticketoffice.TicketsOrder(1, t_date, t_time, 4, 12, 0, mytickets);
		cout << "Ваши билеты:" << endl << endl;
		for (int i = 0; i < mytickets.size(); i++)
		{
			mytickets[i].PrintTicket();
		}
	}
	catch (exception exp)
	{
		cout << exp.what();
	}
	return 0;
}