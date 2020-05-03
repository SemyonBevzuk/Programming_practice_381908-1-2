#pragma once
#include "Cinema.h"
#include <ctime>
using namespace std;

inline bool operator<(const pair<int, int>& p1, const pair<int, int>& p2) {
	return (p1.first < p2.first || p1.first == p2.first && p1.second < p2.second);
}
struct excep {
	bool NoPlaceFound;
	bool TimeOut;
	bool WrongInput;
};

struct Ticket{
	General g;
	pair<int, int> place;
	
};
ostream& operator<<(ostream& out, const Ticket& t);
istream& operator>>(istream& in, Ticket& t);

struct order {
	General g;
	bool vip;
	int amount;
	bool operator<(const order ord) {
		return ((g < ord.g) || (g == ord.g) && (amount < ord.amount) || (g == ord.g) && (amount == ord.amount) && (!vip && ord.vip));
	}
};
istream& operator>>(istream& in, order& ord);

class TicketOffice {
private:
	map<General, Show> current;
public:
	TicketOffice(Cinema& c);
	vector<Ticket> takeOrder(order& ord);
	bool checkAm(order& ord);
	vector<pair<int, int>> book(order& ord);
	int bill(order& ord);
	void cancelbuy(Ticket& t);
	vector<Ticket> createTickets(order& ord, vector<pair<int, int>>& v);
	void showAll();
};