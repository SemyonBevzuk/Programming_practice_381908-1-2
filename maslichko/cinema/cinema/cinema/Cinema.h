#ifndef CINEMA
#define CINEMA

#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class Cinema
{
public:
	int day, month, year; //����
	int hour, minute;     //�����
	string name_film;     //��������
	int room;             //���
	string zone;          //����, �������/���
	int price;            //����
	int booked_places;	  //������� �����
	int all_places;		  //���� �����
	vector<vector<string>> pls; //�����

	Cinema(int day_m, int month_m, int year_m, int hour_m, int min_m, string name_m, int room_m, int price_m)
	{
		day = (day_m);
		month = (month_m);
		year = (year_m);
		hour = (hour_m);
		minute = (min_m);
		name_film = (name_m);
		room = (room_m);
		zone = "base";
		booked_places = 0;
		all_places = Places(room, all_places);
		price = PriceChange(hour_m, price_m);
	}
	int PriceChange(int hour, int price);
	int Places(int room, int places);

	friend ostream& operator<<(ostream& stream, const Cinema& obj)
	{
		return stream << "����: " << obj.day << "." << obj.month << "." << obj.year <<
			endl << "�����: " << obj.hour << ":" << obj.minute <<
			endl << "�����: " << obj.name_film <<
			endl << "���: " << obj.room <<
			endl << "���� ������: " << obj.booked_places <<
			endl << "���� �����: " << obj.all_places <<
			endl << "����: " << obj.price;
	}
};

#endif