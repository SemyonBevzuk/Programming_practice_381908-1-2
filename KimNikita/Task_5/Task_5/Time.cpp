#include "Time.h"

Time::Time(int h, int m)
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
Time& Time::operator=(const Time& t)
{
	if (this != &t)
	{
		minute = t.minute;
		hour = t.hour;
	}
	return *this;
}
bool Time::operator==(const Time& t)const
{
	if (t.hour == hour && t.minute == minute)
		return true;
	return false;
}
bool Time::operator<(const Time& t)const
{
	if (t.hour < hour)
		return true;
	else
		if (t.hour == hour)
			if (t.minute < minute)
				return true;
	return false;
}
Time& Time::operator+=(const Time& t)
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
ifstream& operator>>(ifstream& in, Time& t)
{
	int h, m;
	in >> h >> m;
	t = Time(h, m);
	return in;
}
ofstream& operator<<(ofstream& out, const Time& t)
{
	out << t.hour << ' ' << t.minute << endl;
	return out;
}