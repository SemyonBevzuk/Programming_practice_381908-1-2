#include "Cinema.h"
Cinema::Cinema()
{
	this->~Cinema();
	name_of_films_and_time.resize(0);
	VIP = "VIP";
	STANDART = " STANDART";
	CinemaHalls.resize(0);
	CinemaSeassions.resize(0);
	ThirtyDays.resize(0);
}

Cinema::~Cinema()
{
	start_hour = 0;
	start_min = 0;
	number_of_films = 0;
	number_rows = 0;
	number_seats = 0;
	number_of_seans = 0;
	name_of_films_and_time.clear();
	VIP = "";
	STANDART = "";
	film_price = 0;
	CinemaHalls.clear();
	CinemaSeassions.clear();
	ThirtyDays.clear();
}

void Cinema::CCinema(const string fileName)
{
	ifstream fsin;
	fsin.open(fileName);
	if (fsin.is_open())
	{
		fsin >> *this;	
	}
	fsin.close();
}

void Cinema::CreateCinema(int y, int m, int d)
{
	Date a;
	a.day = d;
	a.month = m;
	a.year = y;
	CinemaHalls.resize(number_of_seans);
	for (int i = 0; i < CinemaHalls.size(); i++)
	{
		CinemaHalls[i] = new int* [number_rows];
		for (int j = 0; j < number_rows; j++)
		{
			CinemaHalls[i][j] = new int[number_seats];
			for (int k = 0; k < number_seats; k++)
				CinemaHalls[i][j][k] = 0;
		}
	}
	CinemaSeassions.resize(number_of_films);
	for (int i = 0; i < CinemaSeassions.size(); i++)
	{
		CinemaSeassions[i].first = name_of_films_and_time[i].first;
		CinemaSeassions[i].second.first =
			CreateTime(
				start_hour,
				start_min,
				name_of_films_and_time[i].second.first,
				name_of_films_and_time[i].second.second,
				number_of_seans);
		CinemaSeassions[i].second.second = CinemaHalls;
	}
	ThirtyDays.resize(30);
	ThirtyDays[0] = make_pair(a, CinemaSeassions);
	for (int i = 1; i < ThirtyDays.size(); i++)
	{
		ThirtyDays[i] = make_pair(CreateDate(d, m, y, 1), CinemaSeassions);
	}
	
}

Cinema::Date Cinema::CreateDate(int y, int m, int d, int plus)
{
	Date date;
	int m1[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };//не високосный
	int m2[] = {0, 31,29,31,30,31,30,31,31,30,31,30,31 };//високосный
	int k = 0; //Перевод введенной даты в дни
	int p = 0, a = 0;
	if (y % 100 %4 == 0)
	{
		for (int i = 1; i <= m; i++)
			k = k + m2[i]; //Какое количество дней прошло с начала високосного года
		k = k + d + plus; //Сумма введенного дня, месяца и количества прибавленных дней
		if (k <= 365)
		{
			for (int i = 1; i <= 12; i++)
			{
				p = k - m2[i]; // Выделение количества дней
				if (p <= m2[i + 1])
				{
					a = i + 1; // Выделение количества месяцев
					break;
				}
				else k = p;
			}
		}
		else
		{
			do
			{
				if (y % 100 % 4 == 0)
					k = k - 366;
				else
					k = k - 365;
				y++;
			} while (k >= 365);
			for (int i = 1; i <= 12; i++)
			{
				p = k - m2[i]; // Выделение количества дней
				if (p <= m2[i + 1])
				{
					a = i + 1; // Выделение количества месяцев
					break;
				}
				else k = p;
			}
		}
		date.day = p;
		date.month = a;
		date.year = y;
		return date;
	}
	else
	{
		for (int i = 1; i <= m; i++)
			k = k + m1[i]; //Какое количество дней прошло с начала обычного года
		k = k + d + plus; //Сумма введенного дня, месяца и количества прибавленных дней
		if (k <= 365)
		{
			for (int i = 1; i <= 12; i++)
			{
				p = k - m1[i]; // Выделение количества дней
				if (p <= m1[i + 1])
				{
					a = i + 1; // Выделение количества месяцев
					break;
				}
				else k = p;
			}
		}
		else
		{
			do
			{
				if (y % 100 % 4 == 0)
					k = k - 366;
				else
					k = k - 365;
				y++;
			} while (k >= 365);
			for (int i = 1; i <= 12; i++)
			{
				p = k - m1[i]; // Выделение количества дней
				if (p <= m1[i + 1])
				{
					a = i + 1; // Выделение количества месяцев
					break;
				}
				else k = p;
			}
		}
		date.day = p;
		date.month = a;
		date.year = y;
		return date;
	}
}

vector<Cinema::Time> Cinema::CreateTime(int starthour, int startmin, int durationhour, int durationmin, int kol)
{
	int pause = 20;//перерыв между фильмами
	Time a;
	vector <Time> seans;
	seans.resize(kol);
	seans[0].hour = starthour;
	seans[0].min = startmin;
	for (int i = 1; i < seans.size(); i++)
	{
		seans[i].hour += seans[i-1].hour + durationhour ;
		seans[i].min += seans[i-1].min + durationmin + pause;
		while (seans[i].min >= 60)
		{
			seans[i].min = seans[i].min - 60;
			seans[i].hour++;
		}
		if (seans[i].hour > 23)
			seans[i].hour = seans[i].hour - 24;
	}
	return seans;
}

int Cinema::GetDay(Date a)
{
	return a.day;
}

int  Cinema::GetMonth(Date a)
{
	return a.month;
}

int  Cinema::GetYear(Date a)
{
	return a.year;
}

bool Cinema::ChSeans(string film, int h, int m)
{
	for (int j = 0; j < ThirtyDays[1].second.size(); j++)
		if (ThirtyDays[1].second[j].first == film)
			for (int k = 0; k < ThirtyDays[0].second[j].second.first.size(); k++)
			{
				if (ThirtyDays[1].second[j].second.first[k].hour == h &&
					ThirtyDays[1].second[j].second.first[k].min == m)
					return true;
				else
				{
					cout << "time";
					return false;
				}
			}
				
		else
		{
			return false;
		}
}

vector<pair<int, int>> Cinema::RSeats(int y, int m, int d, string film, int h, int min, string zone, int kol)
{
	vector<pair<int, int>> seat;
	int index1 = 0;
	int index2 = 0;
	int schetchik = 0;
	for (int i = 0; i < ThirtyDays.size(); i++)
	{
		if (ThirtyDays[i].first.year == y &&
			ThirtyDays[i].first.month == m &&
			ThirtyDays[i].first.day == d)
		{
			for (int j = 0; j < ThirtyDays[i].second.size(); j++)
			{
				if (ThirtyDays[i].second[j].first == film)
				{
					for (int k = 0; k < ThirtyDays[i].second[j].second.first.size(); k++)
					{
						if (ThirtyDays[i].second[j].second.first[k].hour == h &&
							ThirtyDays[i].second[j].second.first[k].min == m)
						{
							if (zone == VIP)
							{
								for (int row = 0; row < number_rows/2; row++)
								{
									for (int s = 0; s < number_seats; s++)
									{
										if (ThirtyDays[i].second[j].second.second[k][row][s] == 0)
										{
											if (schetchik != kol)
											{
												schetchik++;
												ThirtyDays[i].second[j].second.second[k][row][s] = 1;
												index1 = row;
												index2 = s;
												seat.push_back(make_pair(row + 1, s + 1));
											}
											else
											{
												return seat;
												break;
											}
										}
									}
								}
								if (schetchik < kol)
								{
									seat.~vector();
									seat.resize(0);
									return seat;
									for (int row = index1 - schetchik; row < index1; row++)
										for (int s = index2 - schetchik; s < index2; s++)
											if (ThirtyDays[i].second[j].second.second[k][row][s] == 1)
												ThirtyDays[i].second[j].second.second[k][row][s] = 0;
									break;
								}
							}

							if (zone == STANDART)
							{
								for (int row = number_rows/2; row < number_rows; row++)
								{
									for (int s = 0; s < number_seats; s++)
									{
										if (ThirtyDays[i].second[j].second.second[k][row][s] == 0)
										{
											if (schetchik != kol)
											{
												schetchik++;
												ThirtyDays[i].second[j].second.second[k][row][s] = 1;
												index1 = row;
												index2 = s;
												seat.push_back(make_pair(row + 1, s + 1));
											}
											else
											{
												return seat;
												break;
											}
										}
									}
								}
							}
							if (schetchik < kol)
							{
								seat.~vector();
								seat.resize(0);
								return seat;
								for (int row = index1 - schetchik; row < index1; row++)
									for (int s = index2 - schetchik; row < index2; s++)
										if (ThirtyDays[i].second[j].second.second[k][row][s] == 1)
											ThirtyDays[i].second[j].second.second[k][row][s] = 0;
								break;
							}
						}
					}
				}
			}
		}
	}
}

bool Cinema::ChSeats(int y, int m, int d, string film, int h, int min, string zone, int kol)
{
	int schetchik = 0;
	for (int i = 0; i < ThirtyDays.size(); i++)
	{
		if (ThirtyDays[i].first.year == y &&
			ThirtyDays[i].first.month == m &&
			ThirtyDays[i].first.day == d)
		{
			for (int j = 0; j < ThirtyDays[i].second.size(); j++)
			{
				if (ThirtyDays[i].second[j].first == film)
				{
					for (int k = 0; k < ThirtyDays[i].second[j].second.first.size(); k++)
					{
						if (ThirtyDays[i].second[j].second.first[k].hour == h &&
							ThirtyDays[i].second[j].second.first[k].min == m)
						{
							if (zone == VIP)
							{
								for (int row = 0; row < number_rows/2; row++)
								{
									for (int s = 0; s < number_seats; s++)
									{
										if (ThirtyDays[i].second[j].second.second[k][row][s] == 0)
										{
											if (schetchik != kol)
											{
												schetchik++;
											}
											else
											{
												return true;
												break;
											}
										}
									}
								}
								if (schetchik < kol)
								{
									return false;
									break;
								}
							}

							if (zone == STANDART)
							{
								for (int row = number_rows / 2; row < number_rows; row++)
								{
									for (int s = 0; s < number_seats; s++)
									{
										if (ThirtyDays[i].second[j].second.second[k][row][s] == 0)
										{
											if (schetchik != kol)
											{
												schetchik++;
											}
											else
											{
												return true;
												break;
											}
										}
									}
								}
							}
							if (schetchik < kol)
							{
								return false;
								break;
							}
						}
					}
				}
			}
		}
	}

}

bool Cinema::DelSeats(int y, int m, int d, string film, int h, int min, int index1, int index2)
{
	for (int i = 0; i < ThirtyDays.size(); i++)
		if (ThirtyDays[i].first.year == y &&
			ThirtyDays[i].first.month == m &&
			ThirtyDays[i].first.day == d)
			for (int j = 0; j < ThirtyDays[i].second.size(); j++)
				if (ThirtyDays[i].second[j].first == film)
					for (int k = 0; k < ThirtyDays[i].second[j].second.first.size(); k++)
						if (ThirtyDays[i].second[j].second.first[k].hour == h &&
							ThirtyDays[i].second[j].second.first[k].min == m)
								if (ThirtyDays[i].second[j].second.second[k][index1 - 1][index2 - 1] == 1)
								{
									ThirtyDays[i].second[j].second.second[k][index1 - 1][index2 - 1] = 0;
									return true;
								}
								else return false;
									
}

double* Cinema::GetFilmsPrice()
{
	return film_price;
}

int Cinema::GetHall(string film)
{
	for (int i = 0; i < ThirtyDays.size(); i++)
		for (int j = 0; j < ThirtyDays[i].second.size(); j++)
			if (ThirtyDays[i].second[j].first == film)
				return j + 1;
}

int Cinema::GetStandartPrice(string film, double* price)
{
	int k = -1;
	for (int i = 0; i < ThirtyDays.size(); i++)
		for (int j = 0; j < ThirtyDays[i].second.size(); j++)
			if (ThirtyDays[i].second[j].first == film)
				k = j;
	if (k > -1)
	{
		return price[k];
	}
	else return k;
}

int Cinema:: GetVipPrice(string film, double* price)
{
	int k = -1;
	for (int i = 0; i < ThirtyDays.size(); i++)
		for (int j = 0; j < ThirtyDays[i].second.size(); j++)
			if (ThirtyDays[i].second[j].first == film)
				k = j;
	if (k > -1)
	{
		return price[k] * 1, 5;
	}
	else return k;
}

string Cinema::GetVIP()
{
	return VIP;
}

string Cinema::GetSTANDART()
{
	return STANDART;
}

istream& operator>> (istream& stream, Cinema& c)
{
	stream >> c.start_hour;
	stream >> c.start_min;
	stream >> c.number_of_films;
	stream >> c.number_rows;
	stream >> c.number_seats;
	stream >> c.number_of_seans;
	c.name_of_films_and_time.resize(c.number_of_films);
	for (int i = 0; i < c.number_of_films; i++)
	{
		stream >> c.name_of_films_and_time[i].first;
		stream >> c.name_of_films_and_time[i].second.first;
		stream >> c.name_of_films_and_time[i].second.second;
	}
	c.film_price = new double[c.number_of_films];
	for (int i = 0; i < c.number_of_films; i++)
		stream >> c.film_price[i];
	return stream;
}

ostream& operator<< (ostream& stream, const Cinema& c)
{
	stream << c.ThirtyDays[0].first.year << "/";
	stream << c.ThirtyDays[0].first.month << "/";
	stream << c.ThirtyDays[0].first.day << "\n";
	for (int j = 0; j < c.ThirtyDays[0].second.size(); j++)
	{
		stream << c.ThirtyDays[0].second[j].first << "\n";
		for (int k = 0; k < c.ThirtyDays[0].second[j].second.first.size(); k++)
		{
			stream << c.ThirtyDays[0].second[j].second.first[k].hour << ":";
			stream << c.ThirtyDays[0].second[j].second.first[k].min << "    ";
		}
		stream << "\n";
	}

	return stream;
}
