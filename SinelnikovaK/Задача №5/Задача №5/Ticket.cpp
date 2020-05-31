#include "Ticket.h"
using namespace std;

Ticket::Ticket(const int quantity, const Passenger* passenger)
{
	this->quantity = quantity;
	if (quantity == 0 || passenger == nullptr)
		return;
	this->passenger = new Passenger[quantity];
	for (int i = 0; i < quantity; i++)
		this->passenger[i] = passenger[i];
}

Ticket::Ticket(const Ticket& ticket)
{
	*this = ticket;
}

Ticket::~Ticket()
{
	if (passenger == nullptr)
		return;
	if (quantity > 0 && passenger != nullptr)
		delete[] passenger;
	quantity = 0;
	price = 0;
}

Ticket& Ticket::operator=(const Ticket& ticket)
{
	if (*this == ticket)
		return *this;
	quantity = ticket.quantity;
	if (quantity > 0)
	{
		passenger = new Passenger[quantity];
		for (int i = 0; i < quantity; i++)
			passenger[i] = ticket.passenger[i];
	}
	price = ticket.price;
	return *this;
}

void Ticket::newPassengerInfo()
{
	quantity = 0;
	while (quantity <= 0)
	{
		cout << "Введите количество пассажиров: ";
		cin >> quantity;
	}

	passenger = new Passenger[quantity];
	for (int i = 0; i < this->quantity; i++)
		cin >> this->passenger[i];
	this->price = 0;
}

void Ticket::newSeats(const int train, const string depTime, const string arrTime, const int carriage,
	int** seats, const string departure, const string arrival, const string date)
{
	int k = 0;
	for (int i = 0; seats[0][i] != 0; i++)
		passenger[k++].newSeatInfo(train, depTime, arrTime, carriage, 0, seats[0][i], departure, arrival, date);
	for (int i = 0; seats[1][i] != 0; i++)
		passenger[k++].newSeatInfo(train, depTime, arrTime, carriage, 1, seats[1][i], departure, arrival, date);
}

bool Ticket::saveTicket(const string filename)
{
	if (quantity == 0)
		return false;
	ofstream fout(filename);
	fout << quantity << '\n';
	for (int i = 0; i < quantity; i++)
		fout << passenger[i];
	fout.close();
	return true;
}

float Ticket::cost(const float price)
{
	if (price != 0)
		this->price = price;
	return this->price;
}

bool Ticket::Print()
{
	if (quantity == 0)
		return false;
	cout << "Количество билетов: " << quantity << '\n';
	for (int i = 0; i < quantity; i++)
		cout << passenger[i];
	cout << "Общая цена билетов: " << price << "р.\n";
	return true;
}

bool Ticket::operator==(const Ticket& ticket)
{
	if (quantity != ticket.quantity || price != ticket.price)
		return false;
	for (int i = 0; i < quantity; i++)
		if (!(passenger[i] == ticket.passenger[i]))
			return false;
	return true;
}

