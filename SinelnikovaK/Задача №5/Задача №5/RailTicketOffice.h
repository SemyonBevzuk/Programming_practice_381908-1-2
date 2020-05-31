#pragma once
#include "GorkyRailway.h"
#include "Ticket.h"
#include <ctime>
using namespace std;
class RailTicketOffice
{
	GorkyRailway railway[2][30]; // 0 - Москва-НН, 1 - НН-Москва
	int number[2][5];            // Номер поезда
	string time[2][2][5];   // Время отправления-прибытия

	Ticket ticket;

public:
	RailTicketOffice(const string filename = "TimeTable.txt");
	Ticket newTicket(); // Новый билет
	void clearTicket(); // Отмена

private:
	void __readTable(const string filename = "TimeTable.txt");  // Расписание поездов
	void __printTable(const int route);
	bool payment() { return true; }   // Оплата
};

