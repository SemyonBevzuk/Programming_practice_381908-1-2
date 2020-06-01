#pragma once
#include "Cinema.h"

class TicketOffice
{
private:
	int day;
	int month;
	int year;
	string film;
	int hour;
	int minut;
	int hall;
	vector<pair<int, int>> seats;
	int price;
	int sumprice;
	int count;           
public:
	TicketOffice();
	~TicketOffice();

	void CreateTickets(int y, int m, int d, string f, int h, int min, int ll, vector<pair<int, int>>& a, int p, int kol);
	bool CheckingTheDate_2(Cinema& a, int thisy, int thism, int thisd, int y, int m, int d);//проверка на покупка не позже чем через 3 дн€ от сегодн€шней даты
	bool CheckingTodayTime(int thisy, int thism, int thisd, int thish, int thismin, int y, int m, int d, int h, int min);
	bool CheckingSeans(Cinema& a, string film, int h, int min);
	vector<pair<int, int>>& ReserveSeats(Cinema& a, int y, int m, int d, string film, int h, int min, string zone, int kol);
	bool CheckingSeats(Cinema& a, int y, int m, int d, string film, int h, int min, string zone, int kol);
	bool DeleteTickets(Cinema& a, int y, int m, int d, string film, int h, int min, int index1, int index2);
	int Price(Cinema& a, string film, string zone, int h, int min);

	vector<pair<int, int>>& operator=(const vector<pair<int, int>>& other);
	friend ostream& operator<< (ostream& stream, const TicketOffice& c);//Overload operator input into the stream

};
bool CheckingTheDate_1(int d, int m, int y);//проверка на праильность введени€ даты