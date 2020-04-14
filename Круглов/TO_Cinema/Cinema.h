#ifndef CINEMA_H
#define CINEMA_H
#include <vector>
#include <string>
#include"Date.h"

using namespace std;

class Time {
	int sec;
	int min;
	int hour;
public:
	Time(int sec_ = 0, int min_ = 0, int hour_ = 0)
	{
		sec = sec_;
		min = min_;
		hour = hour_;
		min += sec / 60;
		sec %= 60;
		hour += min / 60;
		min %= 60;
		hour %= 24;
	}
	Time& operator=(const Time& time) {
		if (this == &time)
			return *this;
		sec = time.sec;
		min = time.min;
		hour = time.hour;
		return *this;
	}
	bool operator==(const Time& time) const{
		return (sec == time.sec && min == time.min && hour == time.hour);
	}
	friend class Session;
};

struct CinemaHall
{
	int HallNumber;
	int RowCustom, CountCustom;
	int RowVip, CountVip;
	bool** CustomPlaces;
	bool** VipPlaces;
	int BasicValue;
	CinemaHall(int Number = 0, int RowCustom_ = 0, int CountCustom_ = 0, int RowVip_ = 0, int CountVip_ = 0, int BasV = 0)
	{
		HallNumber = Number;
		BasicValue = BasV;
		RowCustom = RowCustom_; CountCustom = CountCustom_;
		RowVip = RowVip_; CountVip = CountVip_;
		CustomPlaces = new bool* [RowCustom];
		for (int i = 0; i < RowCustom; i++)
			CustomPlaces[i] = new bool[CountCustom];
		VipPlaces = new bool* [RowVip];
		for (int i = 0; i < RowVip; i++)
			VipPlaces = new bool* [CountVip];
	}
	~CinemaHall() {
		for (int i = 0; i < RowCustom; i++)
			delete[] CustomPlaces[i];
		delete[] CustomPlaces;
		for (int i = 0; i < RowVip; i++)
			delete[] VipPlaces[i];
		delete[] VipPlaces;
	}
};

class Session {
private:
	CinemaHall Hall;
	Date date;
	Time time;
	int CustomPrice,VipPrice;
	string NameFilm;
public:
	Session(CinemaHall hall_, Date date_, Time time_, string name)
	{
		Hall = hall_;
		date = date_;
		time = time_;
		if (time.hour < 12 && time.hour >= 8)
			CustomPrice = Hall.BasicValue * 0.75;
		if (time.hour >= 12 && time.hour < 18)
			CustomPrice = Hall.BasicValue;
		else
			CustomPrice = Hall.BasicValue * 1.5;
		NameFilm = name;
		VipPrice = CustomPrice * 1.5;
	}
	bool operator==(const Session& session) const{
		return(date == session.date && Hall.HallNumber == session.Hall.HallNumber &&
			time == session.time);
	}
	friend class TicketOffice;
};

class Cinema
{
private:
	vector <Session> Sessions;
public:
	void addSession(const Session& session);
	bool deleteSession(const Session& session);
	friend class TicketOffice;
};

#endif

