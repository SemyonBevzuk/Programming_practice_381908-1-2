#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(string s);
	Time();
	Time(const Time& t);
	Time(int _hour, int _min, int _sec);
	~Time() { hour = min = sec = 0;	}
	void Print() 
	{
		cout << endl << hour << ":" << min << ":" << sec << endl;
	}
	void SetHour(int _hour) 
	{
		hour = _hour;
		Print();
	}
	void SetMin(int _min)
	{
		min = _min;
		Print();
	}
	void SetSec(int _sec)
	{
		sec = _sec;
		Print();
	}
	void inPut()
	{
		cout << "Введите количество часов";
		cin >> hour;
		cout << "Введите количество минут";
		cin >> min;
		cout << "Введите количество секунд";
		cin >> sec;
		Print();
	}
	int GetHour() { return hour; }
	int GetMin() { return min; }
	int GetSec() { return sec; }
	Time& operator=(const Time& t);//пристваивание
	Time operator+(const Time& t);//сумма 
	Time operator-(const Time& t);//разность
	bool operator==(const Time& t);//сравнение
	friend ostream& operator<<(ostream& stream, const Time& t);
	friend istream& operator>>(istream& stream, Time& t);

};
Time::Time(string s)
{
	hour = (s[0] - '0') * 10 + (s[1] - '0');
	min = (s[3] - '0') * 10 + (s[4] - '0');
	sec = (s[6] - '0') * 10 + (s[7] - '0');
}
Time::Time() 
{
	hour = min = sec = 0;
}
Time::Time(const Time& t)
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
}
Time::Time(int _hour, int _min, int _sec) 
{
	hour = _hour;
	min = _min;
	sec = _sec;
}
Time& Time::operator=(const Time& t) 
{
	this->hour =t.hour;
	min = t.min;
	sec = t.sec;
	return *this;
}
bool Time::operator==(const Time& t)
{
	if (hour == t.hour && min == t.min && sec == t.sec)
		return 1;
	return 0;
}
Time Time::operator+(const Time& t)
{
	Time res;
	res.sec = sec + t.sec;
	if (res.sec >= 60)
	{
		res.min += res.sec / 60;
		res.sec = res.sec % 60;
	}
	res.min += min + t.min;
	if (res.min >= 60)
	{
		res.hour += res.min / 60;
		res.min = res.min % 60;
	}
	res.hour += hour + t.hour;
	if (res.sec >= 60)
	{
		res.hour = res.hour % 60;
	}
	return res;
}
Time Time::operator-(const Time& t)
{
	Time res;
	int v;
	if (t.hour > hour)
	{
		int sec1 = 0, sec2 = 0;
		sec1 = (t.hour * 3600) + (t.min * 60) + t.sec;
		sec2 = (hour * 3600) + (min * 60) + sec;
		v = sec1 - sec2;
	}
	else
	{
		int sec1 = 0, sec2 = 0;
		sec1 = (hour * 3600) + (min * 60) + sec;
		sec2 = (t.hour * 3600) + (t.min * 60) + t.sec;
		v = sec1 - sec2;
	}
	res.hour = v / 3600;
	res.min = (v % 3600) / 60;
	res.sec = (v % 3600) % 60;
	return res;
}
ostream& operator<<(ostream& stream, const Time& t)
{
	stream << t.hour << ":" << t.min << ":" << t.sec << endl;
	return stream;
}
istream& operator>>(istream& stream, Time& t) 
{
	stream >> t.hour >> t.min >> t.sec;
	return stream;
}
int main()
{
	setlocale(LC_ALL, "rus");
	string s;
	cout << "Введите время в формате ЧЧ:ММ:СС" << endl;
	cin >> s;
	Time a(s);
	a.Print();
	Time b = { "01:21:10"};
	Time c;
	c = (a - b);
	c.Print();
	Time d;
	d = (a + b);
	cout << d;
	bool f;
	f = (a == b);
	cout << f << endl;
	cout << "exit";
}