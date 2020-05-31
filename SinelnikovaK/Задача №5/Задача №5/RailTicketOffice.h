#pragma once
#include "GorkyRailway.h"
#include "Ticket.h"
#include <ctime>
using namespace std;
class RailTicketOffice
{
	GorkyRailway railway[2][30]; // 0 - ������-��, 1 - ��-������
	int number[2][5];            // ����� ������
	string time[2][2][5];   // ����� �����������-��������

	Ticket ticket;

public:
	RailTicketOffice(const string filename = "TimeTable.txt");
	Ticket newTicket(); // ����� �����
	void clearTicket(); // ������

private:
	void __readTable(const string filename = "TimeTable.txt");  // ���������� �������
	void __printTable(const int route);
	bool payment() { return true; }   // ������
};

