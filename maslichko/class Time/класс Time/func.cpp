#include"Time.h"

	Time :: Time(string s)
	{
		hour = (s[0] - '0') * 10 + (s[1] - '0');
		min = (s[3] - '0') * 10 + (s[4] - '0');
		sec = (s[6] - '0') * 10 + (s[7] - '0');
	}
	Time :: Time()
	{
		hour = min = sec = 0;
	}
	Time :: Time(const Time& t)
	{
		hour = t.hour;
		min = t.min;
		sec = t.sec;
	}
	Time :: Time(int _hour, int _min, int _sec)
	{
		hour = _hour;
		min = _min;
		sec = _sec;
	}
	Time :: ~Time() { hour = min = sec = 0; }
	void Time::Print()
	{
		cout << endl << hour << ":" << min << ":" << sec << endl;
	}
	void Time :: SetHour(int _hour)
	{
		hour = _hour;
		Print();
	}
	void Time:: SetMin(int _min)
	{
		min = _min;
		Print();
	}
	void Time:: SetSec(int _sec)
	{
		sec = _sec;
		Print();
	}
	void Time:: inPut()
	{
		cout << "Введите количество часов";
		cin >> hour;
		cout << "Введите количество минут";
		cin >> min;
		cout << "Введите количество секунд";
		cin >> sec;
		Print();
	}
	int Time:: GetHour() { return hour; }
	int Time:: GetMin() { return min; }
	int Time:: GetSec() { return sec; }
	Time& Time :: operator=(const Time& t) //пристваивание
	{
		this->hour = t.hour;
		min = t.min;
		sec = t.sec;
		return *this;
	}
	Time Time :: operator+(const Time& t)//сумма 
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
	Time Time :: operator-(const Time& t)//разность
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
	bool Time :: operator==(const Time& t)//сравнение
	{
		if (hour == t.hour && min == t.min && sec == t.sec)
			return 1;
		return 0;
	}
	bool Time :: operator<(const Time& t)//сравнение меньше
	{
		if (hour < t.hour)
			return 1;
		return 0;
	}
	bool Time :: operator<=(const Time& t)//сравнение меньше равно
	{
		if (hour >= t.hour)
		{
			if (hour != t.hour)
				return 1;
			else
			{
				if (min <= t.min)
				{
					if (min != t.min)
						return 1;
					else
					{
						if (sec <= t.sec)
							return 1;
					}
				}
			}
		}
		return 0;
	}
	bool Time :: operator>(const Time& t)//сравнение больше
	{
		if (hour > t.hour)
			return 1;
		return 0;
	}
	bool Time :: operator>=(const Time& t)//сравнение больше равно
	{
		if (hour >= t.hour)
		{
			if (hour != t.hour)
				return 1;
			else
			{
				if (min >= t.min)
				{
					if (min != t.min)
						return 1;
					else
					{
						if (sec >= t.sec)
							return 1;
					}
				}
			}
		}
		return 0;
	}
	bool Time :: operator!=(const Time& t)//сравнение не равно
	{
		if (hour != t.hour || min != t.min || sec != t.sec)
			return 1;
		return 0;
	}
	ostream&  operator<<(ostream& stream, const Time& t)
	{
		stream << t.hour << ":" << t.min << ":" << t.sec << endl;
		return stream;
	}
	istream& operator>>(istream& stream, Time& t)
	{
		stream >> t.hour >> t.min >> t.sec;
		return stream;
	}