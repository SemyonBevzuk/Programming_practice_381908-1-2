#include "RailTicketOffice.h"
using namespace std;

void RailTicketOffice::clearTicket()
{
	ticket.~Ticket();
}

void RailTicketOffice::__readTable(const string filename)
{
	ifstream fin(filename);
	string bin;
	for (int j = 0; j < 2; j++)
	{
		fin >> bin;
		for (int i = 0; i < 5; i++)
			fin >> number[j][i] >> time[j][0][i] >> time[j][1][i];
	}
	fin.close();
}

void __info(const int x)
{
	switch (x)
	{
	case 0: case 1: case 2:
		cout << "Ласточка\n";
		break;
	case 3:
		cout << "Фирменный\n";
		break;
	case 4:
		cout << "Скорый\n";
		break;
	}
}

RailTicketOffice::RailTicketOffice(const string filename)
{
	for (int i = 0; i < 30; i++)
	{
		railway[0][i] = GorkyRailway();
		railway[1][i] = GorkyRailway();
	}
	__readTable(filename);
}

string getDate(int days)
{
	char buffer[6];
	time_t rawtime;
	tm timeinfo;
	time(&rawtime);
	rawtime += (__int64)days * 3600 * 24;
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 6, "%d.%m", &timeinfo);
	string date = buffer;

	return date;
}

int** __newArr(const int n)
{
	int** arr;

	arr = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		arr[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++)
			arr[i][j] = 0;
	}

	return arr;
}

void __deleteArr(int** arr, const int n)
{
	for (int i = 0; i < n + 1; i++)
		delete[] arr[i];
	delete arr;
}

Ticket RailTicketOffice::newTicket()
{
	ticket.newPassengerInfo();
	int day = -1;
	while (day < 0 || day > 29)
	{
		cout << "Через сколько дней вы планируете ехать(0 - сегодня, максимум - 29): "; // Можно улучшить, добавив обработку времени
		cin >> day;
	}
	string date = getDate(day);

	cout << "Выверите направление:\n1) Москва - Нижний Новгород\n2) Нижний Новгород - Москва\n";
	int roate(0);
	while (roate < 1 || roate > 2)
	{
		cout << "Рейс: ";
		cin >> roate;
	}
	cout << '\n';
	roate--;
	__printTable(roate);

	int train, tmp(-1);
	while (tmp == -1)
	{
		cout << "Выберите номер поезда: ";
		cin >> train;
		for (int i = 0; i < 5; i++)
			if (number[roate][i] == train)
			{
				tmp = i;
				break;
			}
	}
	train = tmp;
	int carriage = railway[roate][day].carReservate(train, ticket.people());
	if (carriage == -1)
	{
		cout << "Нет мест на этот поезд\n";
		return Ticket();
	}
	int** seats = __newArr(ticket.people());
	railway[roate][day].typeCar(train, ticket.people(), carriage, seats);
	ticket.cost(railway[roate][day].price(train, carriage, ticket.people()));
	if (!payment())
	{
		__deleteArr(seats, ticket.people());
		return Ticket();
	}
	string flight1 = "Нижний Новгород", flight2 = "Москва";
	if (roate == 0)
	{
		flight1 = "Москва";
		flight2 = "Нижний Новгород";
	}
	cout << '\n';
	ticket.newSeats(number[roate][train], time[roate][0][train], time[roate][1][train], carriage + 1, seats, flight1, flight2, date);
	__deleteArr(seats, ticket.people());
	return ticket;
}

void RailTicketOffice::__printTable(const int route)
{
	if (route == 0)
		cout << "Рейс: Москва - Нижний Новгород\n";
	else
		cout << "Рейс: Нижний Новгород - Москва\n";
	for (int i = 0; i < 5; i++)
	{
		cout << number[route][i] << ' ' << time[route][0][i] << " - " << time[route][1][i] << ' ';
		__info(i);
	}
	cout << '\n';
}

