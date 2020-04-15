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
	bool operator<=(const Time& time) const {
		long long sec1 = (long long)(hour * 3600) + min * 60 + sec;
		long long sec2 = (long long)(time.hour * 3600) + time.min * 60 + time.sec;
		return sec1 <= sec2;
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
	CinemaHall(int Number=0, int RowCustom_=0, int CountCustom_=0, int RowVip_=0, int CountVip_=0, int BasV=0);
	CinemaHall(const CinemaHall& hall);
	~CinemaHall() {
		for (int i = 0; i < RowCustom; i++)
			if (CustomPlaces[i] != NULL)
				delete[] CustomPlaces[i];
		if (CustomPlaces != NULL)
			delete[] CustomPlaces;
		for (int i = 0; i < RowVip; i++)
			if (VipPlaces[i] != NULL)
				delete[] VipPlaces[i];
		if (VipPlaces != NULL)
			delete[] VipPlaces;
		RowCustom = 0; CountCustom = 0;
		RowVip = 0; CountVip = 0;
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
	Session(const CinemaHall& hall_, Date date_, Time time_, string name)
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
	~Session() {};
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

