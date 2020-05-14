#include "TicketOffice.h"

vector<string> TicketOffice::Print(vector<Cinema> temp) //Вывод сеансов
{
	vector<string> sessions;
	string temp_string;
	for (int i = 0; i < temp.size(); i++)
	{
		temp_string = temp[i].name_film + "\nДата: " + to_string(temp[i].day) + "." 
			+ to_string(temp[i].month) + "\nВремя: " + to_string(temp[i].hour) + ":" + to_string(temp[i].minute);
		sessions.push_back(temp_string);
	}
	return sessions;
}

int TicketOffice::Buy(vector<Cinema>& temp, int day, int month, string name_film, int quantity, string zone, Date& date) //Покупка билетов
{
	int t = 0;
	int ctrl = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].day == day && temp[i].month == month && temp[i].name_film == name_film) //Находим фильм
		{
			//Проверка условий продажи и наличия мест. Не раньше, чем за 3 дня, и не позже 10 минут от начала фильма
			if (((temp[i].month == date.t_month && (temp[i].day - date.t_day <= 3 && temp[i].day - date.t_day >= 1)) ||
				(temp[i].month == date.t_month && temp[i].day - date.t_day == 0 && temp[i].hour > date.t_hour) ||
				(temp[i].month == date.t_month && temp[i].day - date.t_day == 0 && temp[i].hour == date.t_hour && temp[i].minute - date.t_min <= 10)) &&
				(temp[i].booked_places + quantity <= temp[i].all_places))
			{
				int cost1 = Cost(temp[i].price, zone); //Корректировка цены в зависимости от зоны
				temp[i].booked_places = temp[i].booked_places + quantity;
				t = Assignment(temp[i].pls, cost1, quantity, zone); 
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

int TicketOffice::FindPlaces(vector<Cinema>& temp, int day, int month, string name_film) //Узнать количество свободных мест
{
	int t = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].day == day && temp[i].month == month && temp[i].name_film == name_film) //Находим фильм
		{
			t = temp[i].all_places - temp[i].booked_places;
		}
	}
	return t;
}

int TicketOffice::Reservation(vector<Cinema>& temp, int day, int month, string name_film, int quantity, string zone) //Бронирование
{
	int t = 0;
	int ctrl = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].day == day && temp[i].month == month && temp[i].name_film == name_film) //Находим фильм
		{
			if (temp[i].booked_places + quantity <= temp[i].all_places) //Проверяем наличие мест
			{
				temp[i].booked_places = temp[i].booked_places + quantity;
				Assignment(temp[i].pls, 0, quantity, zone);
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

int TicketOffice::Cancel(vector<Cinema>& temp, int day, int month, string name_film, int quantity) //Отмена покупки/бронирования
{
	int t = 0;
	int ctrl = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].name_film == name_film)
		{
			if (temp[i].booked_places >= quantity)
			{
				t = 1;
				temp[i].booked_places = temp[i].booked_places - quantity;

				for (int k = 0; k < 8; k++)
				{
					for (int j = 0; j < 10; j++)
					{
						if ((temp[i].pls[k][j] == "base" || temp[i].pls[k][j] == "vip") && ctrl != quantity)
						{
							temp[i].pls[k][j] = "free";
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

vector<string> TicketOffice::CreateTicket(vector<Cinema>& temp, int day, int month, string name_film) //Формирование билетов
{
	vector<string> ticket;
	string t;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].name_film == name_film)
		{
			for (int k = 0; k < 8; k++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (temp[i].pls[k][j] == "base" || temp[i].pls[k][j] == "vip")
					{
						int temp1 = Cost(temp[i].price, temp[i].pls[k][j]);
						t = "Ряд: " + to_string(k) + " Место: " + to_string(j) + " Зона: " + temp[i].pls[k][j] + " Цена: " + to_string(temp1);
						ticket.push_back(t);

					}
				}
			}
		}
	}
	return ticket;
}

int TicketOffice::Cost(int price, string zone) //Изменение цены в зависимости от зоны
{
	if (zone == "vip")
	{
		price = price + 150;
	}
	return price;
	
}

int TicketOffice::Assignment(vector<vector<string>>& temp, int cost1, int quantity, string zone) //Пометка мест, что они проданы
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
