
//#include "Cinema.h"
//#include "Time.h"
#include "TicketOffice.h"
using namespace std;
Time m10(0, 10);
ostream& operator<<(ostream& out, const Ticket& t) {
	out << t.g<< " Row " << t.place.first << " Seat " << t.place.second;
	return out;
}
istream& operator>>(istream& in, Ticket& t) {
	in >> t.g >> t.place.first >> t.place.second;
	return in;
}
istream& operator>>(istream& in, order& ord) {
	string zone;
	in >> ord.g >> zone >> ord.amount;
	ord.vip = (zone == "vip") ? true : false;
	return in;
}

TicketOffice::TicketOffice(Cinema& c) {
	map<General, Show>::iterator it = c.shows.begin();
	time_t now = time(0);
	tm ct;
	localtime_s(&ct, &now);
	Date d(ct.tm_year+1900, ct.tm_mon+1, ct.tm_mday);
	Time t(ct.tm_hour, ct.tm_min);
	while (it->first.date < d + 3 && (it->first.date==d && it->first.time>t-m10 || it->first.date<d)) {
		current.insert(*it);
		it++;
	}
}
vector<Ticket> TicketOffice::takeOrder(order& ord){
	if (current.find(ord.g) == current.end()) {
		excep n{ false, false, false };
		n.WrongInput = true;
		throw n;
	}
	time_t now = time(0);
	tm ct;
	localtime_s(&ct, &now);
	Time t(ct.tm_hour, ct.tm_min);
	Date d(ct.tm_year+1900, ct.tm_mon+1, ct.tm_mday);
	if (checkAm(ord) && (t - ord.g.time < m10 && d == ord.g.date || d < ord.g.date )){
		vector<pair<int, int>> v = book(ord);
		vector<Ticket> res = createTickets(ord, v);
		cout << "Total cost: " << bill(ord);
		return res;
	}
	else  {
		excep n{ false, false, false};
		if (!checkAm(ord))
			n.NoPlaceFound = true;
		else
			n.TimeOut = true;
		throw n;
	}
}
bool TicketOffice::checkAm(order& ord){
	if (ord.vip) {
		if (current[ord.g].nvip >= ord.amount)
			return true;
	}
	else if (current[ord.g].n >= ord.amount)
		return true;
	return false;
}
vector<pair<int, int>> TicketOffice::book(order& ord){
	Show &s = current[ord.g];
	vector<pair<int, int>> res;
	int a = ord.amount;
	if (ord.vip) {
		if (s.nvip <= 0) {
			excep n;
			n.NoPlaceFound = true;
			throw n;
		}
		int n = s.hall.places.size();
		int m = s.hall.places[0].size();
		for(int i=s.ivip.first;i<n;i++)
			for (int j = s.ivip.second; j < m && s.nvip>0 && a>0; j++) {
				if (s.hall.places[i][j] == 'V') {
					s.hall.places[i][j] = 'v';
					s.nvip--;
					a--;
					res.push_back({ i, j });
				}
			}
	}
	else {
		if (s.n <= 0) {
			excep n;
			n.NoPlaceFound = true;
			throw n;
		}
		int n = s.hall.places.size();
		int m = s.hall.places[0].size();
		for (int i = s.in.first; i < n; i++)
			for (int j = s.in.second; j < m && s.n>0 && a > 0; j++) {
				if (s.hall.places[i][j] == 'N') {
					s.hall.places[i][j] = 'n';
					s.n--;
					a--;
					res.push_back({ i, j });
				}
			}
	}
	return res;
}
int TicketOffice::bill(order& ord){
	return (ord.amount *((ord.vip) ? current[ord.g].pricevip : current[ord.g].price));
}
void TicketOffice::cancelbuy(Ticket& t){
	if (current.find(t.g) == current.end()) {
		excep n{ false, false, false };
		n.WrongInput = true;
		throw n;
	}
	char ch = current[t.g].hall[t.place.first][t.place.second];
	if (ch == 'v') {
		current[t.g].hall[t.place.first][t.place.second] -= 26;
		if(t.place<current[t.g].ivip)
			current[t.g].ivip = { t.place.first, t.place.second };
		current[t.g].nvip--;
	}
	else if (ch == 'n') {
		current[t.g].hall[t.place.first][t.place.second] -= 26;
		if (t.place < current[t.g].in)
			current[t.g].in = { t.place.first, t.place.second };
		current[t.g].n--;
	}
	else {
		excep n{ false, false, false };
		n.NoPlaceFound = true;
		throw n;
	}
}
vector<Ticket> TicketOffice::createTickets(order& ord, vector<pair<int, int>>& v){
	Ticket t;
	vector<Ticket> res;
	for (pair<int, int> p : v) {
		t.place = p;
		t.g = ord.g;
		res.push_back(t);
	}
	return res;
}
void TicketOffice::showAll() {
	map<General, Show>::iterator i = current.begin();
	cout << "////////////////////////////////////////////\n";
	for (; i != current.end(); i++) {
		cout << i->first << endl << "Unbooked seats: vip " << i->second.nvip << " normal " << i->second.n << endl;
	}
	cout << "////////////////////////////////////////////////\n";
}