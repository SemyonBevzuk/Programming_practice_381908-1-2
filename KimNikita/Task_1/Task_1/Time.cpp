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
	if (s.size() != 8 || !isdigit(s[0]) || !isdigit(s[1]) || !isdigit(s[3]) || !isdigit(s[4]) || !isdigit(s[6]) || !isdigit(s[7]) || s[2] != ':' || s[5] != ':')
	{
		cout << "Invalid string";
		exit(13);
	}
	else
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
}
const string Time::get_time()const
{
	string s = "";
	if (hour < 10)
		s += '0';
	s += to_string(hour);
	s += ':';
	if (min < 10)
		s += '0';
	s += to_string(min);
	s += ':';
	if (sec < 10)
		s += '0';
	s += to_string(sec);
	return s;
}
Time& Time::operator=(const Time& t)
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
	return *this;
}
Time& Time:: operator+=(const Time& t)
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
Time& Time:: operator-=(const Time& t)
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
const Time Time::operator+(const Time& t)const
{
	Time t1 = *this;
	t1 += t;
	return t1;
}
const Time Time::operator-(const Time& t)const
{
	Time t1 = *this;
	t1 -= t;
	return t1;
}
bool Time:: operator>(const Time& t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 > t2)
		return true;
	else
		return false;
}
bool Time:: operator<(const Time& t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 < t2)
		return true;
	else
		return false;
}
bool Time::operator<=(const Time& t)const
{
	return !(*this > t);
}
bool Time::operator>=(const Time& t)const
{
	return !(*this < t);
}
bool Time:: operator==(const Time& t)const
{
	int t1 = hour * 3600 + min * 60 + sec;
	int t2 = t.hour * 3600 + t.min * 60 + t.sec;
	if (t1 == t2)
		return true;
	else
		return false;
}
bool Time:: operator!=(const Time& t)const
{
	return !(*this == t);
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