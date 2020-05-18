#include "TicketOffice.h"

vector<string> TicketOffice::Print() //����� �������
{
	vector<string> sessions;
	string temp_string;
	for (int i = 0; i < seance.size(); i++)
	{
		temp_string = seance[i].name_film + "\n����: " + to_string(seance[i].day) + "."
			+ to_string(seance[i].month) + "\n�����: " + to_string(seance[i].hour) + ":" + to_string(seance[i].minute);
		sessions.push_back(temp_string);
	}
	return sessions;
}

int TicketOffice::Buy(int day, int month, string name_film, int quantity, string zone, Date& date) //������� �������
{
	int t = 0;
	int ctrl = 0;
	for (int i = 0; i < seance.size(); i++)
	{
		if (seance[i].day == day && seance[i].month == month && seance[i].name_film == name_film) //������� �����
		{
			//�������� ������� ������� � ������� ����. �� ������, ��� �� 3 ���, � �� ����� 10 ����� �� ������ ������
			if (((seance[i].month == date.t_month && (seance[i].day - date.t_day <= 3 && seance[i].day - date.t_day >= 1)) ||
				(seance[i].month == date.t_month && seance[i].day - date.t_day == 0 && seance[i].hour > date.t_hour) ||
				(seance[i].month == date.t_month && seance[i].day - date.t_day == 0 && seance[i].hour == date.t_hour && seance[i].minute - date.t_min <= 10)) &&
				(seance[i].booked_places + quantity <= seance[i].all_places))
			{
				int cost1 = Cost(seance[i].price, zone); //������������� ���� � ����������� �� ����
				seance[i].booked_places = seance[i].booked_places + quantity;
				t = Assignment(seance[i].pls, cost1, quantity, zone); 
				break;
			}
			else
			{
				break;
			}
		}
	}
	return t;
}

int TicketOffice::FindPlaces(int day, int month, string name_film) //������ ���������� ��������� ����
{
	int t = 0;
	for (int i = 0; i < seance.size(); i++)
	{
		if (seance[i].day == day && seance[i].month == month && seance[i].name_film == name_film) //������� �����
		{
			t = seance[i].all_places - seance[i].booked_places;
		}
	}
	return t;
}

int TicketOffice::Reservation(int day, int month, string name_film, int quantity, string zone) //������������
{
	int t = 0;
	int ctrl = 0;
	for (int i = 0; i < seance.size(); i++)
	{
		if (seance[i].day == day && seance[i].month == month && seance[i].name_film == name_film) //������� �����
		{
			if (seance[i].booked_places + quantity <= seance[i].all_places) //��������� ������� ����
			{
				seance[i].booked_places = seance[i].booked_places + quantity;
				Assignment(seance[i].pls, 0, quantity, zone);
				t = 1;
				break;
			}
			else
			{
				t = 0;
				break;
			}
		}
	}
	return t;
}

int TicketOffice::Cancel(int day, int month, string name_film, int quantity) //������ �������/������������
{
	int t = 0;
	int ctrl = 0;
	for (int i = 0; i < seance.size(); i++)
	{
		if (seance[i].name_film == name_film)
		{
			if (seance[i].booked_places >= quantity)
			{
				t = 1;
				seance[i].booked_places = seance[i].booked_places - quantity;

				for (int k = 0; k < 8; k++)
				{
					for (int j = 0; j < 10; j++)
					{
						if ((seance[i].pls[k][j] == "base" || seance[i].pls[k][j] == "vip") && ctrl != quantity)
						{
							seance[i].pls[k][j] = "free";
							ctrl++;
						}
					}
				}
				break;
			}
		}
	}
	return t;
}

vector<string> TicketOffice::CreateTicket(int day, int month, string name_film) //������������ �������
{
	Ticket ticket(seance, day, month, name_film);
	vector<string> ticket_vec = ticket.MakeTicket();
	return ticket_vec;

}

int TicketOffice::Cost(int price, string zone) //��������� ���� � ����������� �� ����
{
	if (zone == "vip")
	{
		price = price + 150;
	}
	return price;
	
}

int TicketOffice::Assignment(vector<vector<string>>& temp, int cost1, int quantity, string zone) //������� ����, ��� ��� �������
{
	int ctrl = 0;
	int t = 0;
	for (int k = 0; k < temp.size(); k++)
	{
		for (int j = 0; j < temp[0].size(); j++)
		{
			if (temp[k][j] == "free" && ctrl != quantity)
			{
				if (zone == "base")
				{
					temp[k][j] = "base";
					t = t + cost1;
					ctrl++;
				}
				else if (zone == "vip")
				{
					temp[k][j] = "vip";
					t = t + cost1;
					ctrl++;
				}
			}
		}
	}
	return t;
}
