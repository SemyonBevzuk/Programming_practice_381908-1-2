#pragma once
#include "Passenger.h"
using namespace std;

class Ticket
{
	Passenger* passenger; // ���������
	int quantity;         // ����������
	float price;          // ����� ����� �������

public:
	Ticket(const int quantity = 0, const Passenger* passenger = nullptr);
	Ticket(const Ticket& ticket);
	~Ticket();

	Ticket& operator= (const Ticket& ticket);
	void newPassengerInfo();
	void newSeats(const int train, const string depTime, const string arrTime, const int carriage,
		int** seats, const string departure, const string arrival, const string date); // ���������� ����
	bool saveTicket(const string filename = "ticket.txt");
	int people() { return quantity; }
	float cost(const float price = 0.0f);
	bool Print(); // ����� ���������� �� �������
	bool operator== (const Ticket& ticket);
};

