#include"Cinema.h"

using namespace std;

void Cinema::addSession(const Session& session) {
	Sessions.push_back(session);
}

bool Cinema::deleteSession(const Session& session) {
	for (int i = 0; i < Sessions.size(); i++)
	{
		if (Sessions[i] == session)
		{
			Sessions.erase(Sessions.begin() + i);
			return true;
		}
	}
	return false;
}

CinemaHall::CinemaHall(int Number, int RowCustom_, int CountCustom_, int RowVip_, int CountVip_, int BasV)
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
		VipPlaces[i] = new bool[CountVip];
	for (int i = 0; i < RowCustom; i++)
		for (int j = 0; j < CountCustom; j++)
			CustomPlaces[i][j] = false;
	for (int i = 0; i < RowVip; i++)
		for (int j = 0; j < CountVip; j++)
			VipPlaces[i][j] = false;
}

CinemaHall::CinemaHall(const CinemaHall& hall)
{
	HallNumber = hall.HallNumber;
	BasicValue = hall.BasicValue;
	RowCustom = hall.RowCustom; CountCustom = hall.CountCustom;
	RowVip = hall.RowVip; CountVip = hall.CountVip;

	CustomPlaces = new bool* [RowCustom];
	for (int i = 0; i < RowCustom; i++)
		CustomPlaces[i] = new bool[CountCustom];

	VipPlaces = new bool* [RowVip];
	for (int i = 0; i < RowVip; i++)
		VipPlaces[i] = new bool[CountVip];

	for (int i = 0; i < RowCustom; i++)
		for (int j = 0; j < CountCustom; j++)
			CustomPlaces[i][j] = hall.CustomPlaces[i][j];
	for (int i = 0; i < RowVip; i++)
		for (int j = 0; j < CountVip; j++)
			VipPlaces[i][j] = hall.VipPlaces[i][j];
}
