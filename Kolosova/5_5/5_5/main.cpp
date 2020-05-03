#include "TicketOffice.h"
using namespace std;
int main() {
	vector<General> f;
	Cinema c("halls.txt", "shows.txt");
	TicketOffice t(c);
	order o;
	string inp;
	cout << "Type 'help' for help\n";
	do {
		cin >> inp;
		if (inp == "help")
			cout << "order \n <title> \n <date(<day> <month> <year>)> \n <time(<hrs> <min>)> \n <hall number>\n <(vip/normal)> \n <amount>\n"<<
			"  - order tickets\n"<<
			"cancel <title> \n <date(<day> <month> <year>)>\n <time(<hours> <minutes>)>\n <hall number>\n <row> <seat>\n"<<
			"  - cancel ticket\n"<<
			"shows - show available shows\n"<<
			"exit - exit application\n";
		else if (inp == "order") {
			cin >> o;
			try {
				vector<Ticket> v = t.takeOrder(o);
				cout << "\nYour tickets\n";
				for (Ticket i : v)
					cout << i << endl;
			}
			catch (excep n) {
				if (n.NoPlaceFound)
					cout << "No tickets left.\n";
				if (n.TimeOut)
					cout << "Too late!\n";
				if (n.WrongInput)
					cout << "Wrong input. Try again\n";
			}
		}
		else if (inp == "cancel") {
			Ticket ti;
			cin >> ti;
			try {
				t.cancelbuy(ti);
				cout << "Successfully cancelled.\n";
			}
			catch (excep n) {
				if (n.NoPlaceFound)
					cout << "Wrong input (place)\n";
				if (n.WrongInput)
					cout << "Wrong input";
			}
		}
		else if (inp == "shows") {
			t.showAll();
		}
	} while (inp != "exit");
}