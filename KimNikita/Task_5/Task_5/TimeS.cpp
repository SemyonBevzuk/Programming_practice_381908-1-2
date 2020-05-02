#include "TimeS.h"

TimeS::TimeS(int h, int m)
{
	if (m < 0 || m>59)
		throw exception("Некорректные минуты");
	else
		minute = m;
	if (h < 0 || h>24)
		throw exception("Некорректные часы");
	else
		hour = h % 24;
}
TimeS& TimeS::operator=(const TimeS& t)
{
	if (this != &t)
	{
		minute = t.minute;
		hour = t.hour;
	}
	return *this;
}
bool TimeS::operator==(const TimeS& t)const
{
	if (t.hour == hour && t.minute == minute)
		return true;
	return false;
}
bool TimeS::operator<(const TimeS& t)const
{
	if (hour < t.hour)
		return true;
	else
		if (hour == t.hour)
			if (minute < t.minute)
				return true;
	return false;
}
TimeS& TimeS::operator+=(const TimeS& t)
{
	minute += t.minute;
	if (minute > 60)
	{
		hour++;
		if (hour > 23)
			hour = 0;
		minute %= 60;
	}
	return *this;
}
ifstream& operator>>(ifstream& in, TimeS& t)
{
	int h, m;
	in >> h >> m;
	t = TimeS(h, m);
	return in;
}
ofstream& operator<<(ofstream& out, const TimeS& t)
{
	out << t.hour << ' ' << t.minute << endl;
	return out;
}