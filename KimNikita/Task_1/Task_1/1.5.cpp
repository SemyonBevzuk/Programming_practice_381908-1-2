#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

class Time {
private:
	int hour;
	int min;
	int sec;
public:
	Time() : hour(0), min(0), sec(0) {}
	Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
	Time(const Time&);
	Time(string);
	~Time() {}
	void get_time()const;
	Time& operator=(Time);
	Time& operator+=(Time);
	Time& operator-=(Time);
	Time operator+(Time)const;
	Time operator-(Time)const;
	bool operator>(Time)const;
	bool operator<(Time)const;
	bool operator<=(Time)const;
	bool operator>=(Time)const;
	bool operator==(Time)const;
	bool operator!=(Time)const;
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
};
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

int main()
{
	Time t1, t2(13, 12, 11), t3(t2), t4("23:45:00");
	cout << "t1: ";
	t1.get_time();
	cout << "t2: ";
	t2.get_time();
	cout << "t3: ";
	t3.get_time();
	cout << "t4: ";
	t4.get_time();
	cout << "t1 += t4 - t3" << endl;
	t1 += t4 - t3;
	cout << "t1: ";
	t1.get_time();
	Time t5;
	cout << "t5: ";
	cin >> t5;
	cout << "t5 -= t1" << endl;
	t5 -= t1;
	cout << "t5: ";
	cout << t5 << endl;
	if (t4 > t5)
	{
		cout << "t4 > t5" << endl;
		cout << "t2+t5: ";
		cout << t2 + t5 << endl;
	}
	else
	{
		cout << "t4 <= t5" << endl;
		cout << "t2-t5: ";
		cout << t2 - t5 << endl;
	}
	return 0;
}