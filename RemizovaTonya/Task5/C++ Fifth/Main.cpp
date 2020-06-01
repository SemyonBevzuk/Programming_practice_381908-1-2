#include "TicketOffice .h"
using namespace std;
int main()
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);//текущая дата выраженная в секундах
	timeinfo = localtime(&rawtime); //текущая дата в нормальной форме
	cout << "Current date/time: " << asctime(timeinfo) << endl;
	int day_ = (timeinfo->tm_mday);
	int month_ = (timeinfo->tm_mon)+1;
	int year_ = (timeinfo->tm_year) + 1900;
	int hour_ = (timeinfo->tm_hour);
	int min_ = (timeinfo->tm_min);
	
	string fileCinema = "Cinema.txt";
	string fileTickets = "Tickets.txt";
	Cinema Cinema;
	Cinema.CCinema(fileCinema);
	Cinema.CreateCinema(year_, month_, day_);
	TicketOffice CinemaCashbox;
	int p_day;
	int p_month;
	int p_year;
	string p_film;
	int p_hour;
	int p_min;
	string p_zone;
	int p_quantity;
	int price;
	int sumprice;
	int p_row;
	int p_seat;
	vector <pair <int, int>> p_seats;

	int dstv;

	cout << "                     CINEMA" << endl;
	cout << "------------------------------------------------------------" << endl;
met:
	cout << "                 Available Actions" << endl;
	cout << "1.  Buy a ticket: (enter the date, time of the session, movie name, room number, type of zone, number of people)" << endl;
	cout << "2.  Check the availability of the required number of free places in the selected zone" << endl;
	cout << "3.  Reserve the required number of seats in the selected zone" << endl;
	cout << "4.  Calculate the total cost of tickets" << endl;
	cout << "5.  Cancel ticket order" << endl;
	cout << "6.  Generate tickets (each ticket includes: date, session time, movie title, room number, row number, seat number in a row)." << endl << endl;

	cout << Cinema << endl;
	cout << "Select the number of the required action: ";
	wcin >> dstv;
	switch (dstv)
	{
	case 1:
	{
		cout << "1.  Buy a ticket: (enter the date, time of the session, movie name, room number, type of zone, number of people)" << endl;
		
		cout << "Enter session date" << endl;
		cout << "Year: ";
		cin >> p_year;
		cout << "Month: ";
		cin >> p_month;
		cout << "Day: ";
		cin >> p_day;
		cout << "Enter a movie from the list of proposed" << endl;
		cin >> p_film;
		cout << "Select a session time from the list of suggested" << endl;
		cout << "Hour: ";
		cin >> p_hour;
		cout << "Minut: ";
		cin >> p_min;
		cout << "Choose zone type VIP or STANDART: " << endl;
		cin >> p_zone;
		cout << "Enter the number of persons:" << endl;
		cin >> p_quantity;
		if (CheckingTheDate_1(p_day, p_month, p_year))
			if (CinemaCashbox.CheckingTheDate_2(Cinema, year_, month_, day_, p_year, p_month, p_day))
				if (CinemaCashbox.CheckingTodayTime( year_, month_, day_, hour_, min_, p_year, p_month, p_day, p_hour, p_min))
					if (CinemaCashbox.CheckingSeats(Cinema, p_year, p_month, p_day, p_film, p_hour, p_min, p_zone, p_quantity))
						if (CinemaCashbox.CheckingSeans(Cinema, p_film, p_hour, p_min))
						{
							CinemaCashbox.CreateTickets(p_year, p_month, p_day, p_film, p_hour, p_min, Cinema.GetHall(p_film),
								CinemaCashbox.ReserveSeats(Cinema, p_year, p_month, p_day, p_film, p_hour, p_min, p_zone, p_quantity),
								CinemaCashbox.Price(Cinema, p_film, p_zone, p_hour, p_min), p_quantity);
							cout << "Ticket successfully formed" << endl;

						}
						else cout << "Incorrectly entered movie name or start session time" << endl;
					else cout << "There are not enough seats in the selected zone" << endl;
				else cout << "Unable to issue a ticket for this date, the session began more than 10 minutes ago" << endl;
			else cout << "It is not possible to issue a ticket later than three days from today's date inclusive" << endl;
		else cout << "The date entered incorrectly" << endl;
	}
	wcout << "Back to the cinema?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 2:
	{
		cout << "2.  Check the availability of the required number of free places in the selected zone" << endl;
		
		cout << "Enter session date" << endl;
		cout << "Year: ";
		cin >> p_year;
		cout << "Month: ";
		cin >> p_month;
		cout << "Day: ";
		cin >> p_day;
		cout << "Enter a movie from the list of proposed" << endl;
		cin >> p_film;
		cout << "Select a session time from the list of suggested" << endl;
		cout << "Hour: ";
		cin >> p_hour;
		cout << "Minut: ";
		cin >> p_min;
		cout << "Choose zone type VIP or STANDART: " << endl;
		cin >> p_zone;
		cout << "Enter the number of persons:" << endl;
		cin >> p_quantity;
		if (!CinemaCashbox.CheckingSeats(Cinema, p_year, p_month, p_day, p_film, p_hour, p_min, p_zone, p_quantity))
			cout << "Sorry, there are no free spots on this movie in the selected zone" << endl;
		else cout << "At this session, there are free places in the selected area for a given number of people" << endl;
	}
	wcout << "Back to the cinema?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 3:
	{
		cout << "3.  Reserve the required number of seats in the selected zone" << endl;
		
		cout << "Enter session date" << endl;
		cout << "Year: ";
		cin >> p_year;
		cout << "Month: ";
		cin >> p_month;
		cout << "Day: ";
		cin >> p_day;
		cout << "Enter a movie from the list of proposed" << endl;
		cin >> p_film;
		cout << "Select a session time from the list of suggested" << endl;
		cout << "Hour: ";
		cin >> p_hour;
		cout << "Minut: ";
		cin >> p_min;
		cout << "Choose zone type VIP or STANDART: " << endl;
		cin >> p_zone;
		cout << "Enter the number of persons:" << endl;
		cin >> p_quantity;
		if (CinemaCashbox.ReserveSeats(Cinema, p_year, p_month, p_day, p_film, p_hour, p_min, p_zone, p_quantity).size() == 0)
			cout << "Sorry, there are no free spots on this movie in the selected zone" << endl;
		else
		{
			p_seats.resize(p_quantity);
			p_seats = CinemaCashbox.ReserveSeats(Cinema, p_year, p_month, p_day, p_film, p_hour, p_min, p_zone, p_quantity);
			for (int i = 0; i < p_seats.size(); i++)
				cout << i + 1 << " Person: row " << p_seats[i].first << " seat " << p_seats[i].second << endl;
		}

	}
	wcout << "Back to the cinema?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 4:
	{
		cout << "4.  Calculate the total cost of tickets" << endl;

		cout << "Enter a movie from the list of proposed" << endl;
		cin >> p_film;
		cout << "Choose zone type VIP or STANDART: " << endl;
		cin >> p_zone;
		cout << "Select a session time from the list of suggested" << endl;
		cout << "Hour: ";
		cin >> p_hour;
		cout << "Minut: ";
		cin >> p_min;
		cout << "Enter the number of persons:" << endl;
		cin >> p_quantity;
		if (CinemaCashbox.Price(Cinema, p_film, p_zone, p_hour, p_min) <= -1)
			cout << "Sorry, we cannot calculate the costs of tickets" << endl;
		else cout << "Total cost of " << p_quantity << "tickets is: " << p_quantity * CinemaCashbox.Price(Cinema, p_film, p_zone, p_hour, p_min);
	}
	wcout << "Back to the cinema?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 5:
	{
		cout << "5.  Cancel ticket order" << endl;
		
		cout << "Enter session date" << endl;
		cout << "Year: ";
		cin >> p_year;
		cout << "Month: ";
		cin >> p_month;
		cout << "Day: ";
		cin >> p_day;
		cout << "Enter a movie from the list of proposed" << endl;
		cin >> p_film;
		cout << "Select a session time from the list of suggested" << endl;
		cout << "Hour: ";
		cin >> p_hour;
		cout << "Minut: ";
		cin >> p_min;
		cout << "Enter Row and Seat" << endl;
		cout << "Row: ";
		cin >> p_row;
		cout << "Seat: ";
		cin >> p_seat;

		if (CinemaCashbox.DeleteTickets(Cinema, p_year, p_month, p_day, p_film, p_hour, p_min, p_row, p_seat))
			cout << "Your ticket has been cleared successfully" << endl;
		else cout << "Sorry, we cannot clear your ticket" << endl;

	}
	wcout << "Back to the cinema?" << endl;
	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	case 6:
	{
		cout << "6.  Generate tickets (each ticket includes: date, session time, movie title, room number, row number, seat number in a row)." << endl;
		ofstream fsout;
		fsout.open(fileTickets);
		if (fsout.is_open())
		{
			fsout << CinemaCashbox;
			fsout.close();
			cout << "Tickets successfully written to file" << endl;
		}
		else cout << "Unable to open file" << endl;
	}
	wcout << "Back to the cinema?" << endl;

	wcout << "Enter  1  to answer positively or  any number  to answer negative" << endl;
	wcin >> dstv;
	if (dstv == 1)
		goto met;
	else
		break;
	default: break;
	}
}