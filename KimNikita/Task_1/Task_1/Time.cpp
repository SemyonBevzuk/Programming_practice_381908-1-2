#include "Time.h"

Time::Time() : hour(0), min(0), sec(0) {}
Time::Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
Time::Time(const Time& t)
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
}
Time::Time(string s)
{
	string st = "";
	st += s[0];
	st += s[1];
	hour = atoi(st.c_str());
	st = "";
	st += s[3];
	st += s[4];
	min = atoi(st.c_str());
	st = "";
	st += s[6];
	st += s[7];
	sec = atoi(st.c_str());

}
void Time::get_time()const
{
	if (hour < 10)
		cout << "0";
	cout << hour;
	cout << ":";
	if (min < 10)
		cout << "0";
	cout << min;
	cout << ":";
	if (sec < 10)
		cout << "0";
	cout << sec << endl;
}
Time& Time::operator=(Time t)
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
	return *this;
}
Time& Time:: operator+=(Time t)
{
	sec += t.sec;
	min += sec / 60;
	sec %= 60;
	min += t.min;
	hour += min / 60;
	min %= 60;
	hour += t.hour;
	hour %= 24;
	return *this;
}
Time& Time:: operator-=(Time t)
{
	sec -= t.sec;
	if (sec < 0)
	{
		min--;
		sec += 60;
	}
	min -= t.min;
	if (min < 0)
	{
		hour--;
		min += 60;
	}
	hour -= t.hour;
	hour = (hour + 24) % 24;
	return *this;
}
Time Time::operator+(Time t)const
{
	int s = (sec + t.sec) % 60;
	int m = (min + t.min + (sec + t.sec) / 60) % 60;
	int h = (hour + t.hour + (min + t.min + (sec + t.sec) / 60) / 60) % 24;
	return Time(h, m, s);
}
Time Time::operator-(Time t)const
{
	int s, m = 0, h = 0;
	s = sec - t.sec;
	if (s < 0)
	{
		m--;
		s += 60;
	}
	m += min - t.min;
	if (m < 0)
	{
		h--;
		m += 60;
	}
	h += (hour + 24 - t.hour) % 24;
	return Time(h, m, s);
}
bool Time:: operator>(Time t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 > t2)
		return true;
	else
		return false;
}
bool Time:: operator<(Time t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 < t2)
		return true;
	else
		return false;
}
bool Time::operator<=(Time t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 <= t2)
		return true;
	else
		return false;
}
bool Time::operator>=(Time t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 >= t2)
		return true;
	else
		return false;
}
bool Time:: operator==(Time t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 == t2)
		return true;
	else
		return false;
}
bool Time:: operator!=(Time t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 != t2)
		return true;
	else
		return false;
}
istream& operator>>(istream& in, Time& t)
{
	in >> t.hour;
	in >> t.min;
	in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t)
{
	out << "Time(" << t.hour << ", " << t.min << ", " << t.sec << ")";
	return out;
}