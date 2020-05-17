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
	int day, month, year; //Дата
	int hour, minute;     //Время
	string name_film;     //Название
	int room;             //Зал
	string zone;          //Зона, обычная/вип
	int price;            //Цена
	int booked_places;	  //Занятые места
	int all_places;		  //Мест всего
	vector<vector<string>> pls; //Места

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
		return stream << "Дата: " << obj.day << "." << obj.month << "." << obj.year <<
			endl << "Время: " << obj.hour << ":" << obj.minute <<
			endl << "Фильм: " << obj.name_film <<
			endl << "Зал: " << obj.room <<
			endl << "Мест занято: " << obj.booked_places <<
			endl << "Мест всего: " << obj.all_places <<
			endl << "Цена: " << obj.price;
	}
};

#endif