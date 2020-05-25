#include "Time.h"





Time::Time(const Time &other) : hour(other.hour), min(other.min), sec(other.sec) {}

Time::~Time() {}

void Time::SetHour(uint hour)
{
	this->hour = hour % 24;
}

void Time::SetMin(uint min)
{
	this->hour += min / 60;
	this->hour %= 24;
	this->min = min % 60;
}



uint Time::GetHour() const
{
	return hour;
}

uint Time::GetMin() const
{
	return min;
}

uint Time::GetSec() const
{
	return sec;
}

Time& Time::operator=(const Time& other)
{
	this->hour = other.hour;
	this->min = other.min;
	this->sec = other.sec;
	return *this;
}

Time Time::operator+(const Time& other) const
{
	uint hour = this->hour + other.hour;
	uint min = this->min + other.min;
	uint sec = this->sec + other.sec;
	return Time(hour, min, sec);
}

Time Time::operator-(const Time& other) const
{
	uint hour, min, sec;
	hour = this->hour > other.hour ? this->hour - other.hour : 24 + this->hour - other.hour;
	if (this->min < other.min)
	{
		min = 60 + this->min - other.min;
		hour = hour == 0 ? 23 : hour - 1;
	}
	else min = this->min - other.min;
	if (this->sec < other.sec)
	{
		sec = 60 + this->sec - other.sec;
		if (min == 0)
		{
			min = 59;
			hour = hour == 0 ? 23 : hour - 1;
		}
		else min--;
	}
	return Time(hour, min, sec);
}

bool Time::operator==(const Time& other) const
{
	return this->hour == other.hour && this->min == other.min && this->sec == other.sec;
}

bool Time::operator!=(const Time& other) const
{
	return !(*this == other);
}

bool Time::operator>=(const Time& other) const
{
	return !(*this < other);
}

bool Time::operator<=(const Time& other) const
{
	return !(*this > other);
}

bool Time::operator>(const Time& other) const
{
	if (this->hour > other.hour) return true;
	if (this->hour < other.hour) return false;
	if (this->min > other.min) return true;
	if (this->min < other.min) return false;
	if (this->sec > other.sec) return true;
	return false;
}

bool Time::operator<(const Time& other) const
{
	if (this->hour < other.hour) return true;
	if (this->hour > other.hour) return false;
	if (this->min < other.min) return true;
	if (this->min > other.min) return false;
	if (this->sec < other.sec) return true;
	return false;
}

std::istream& operator>>(std::istream &in, Time &time)
{
	char c;
	in >> time.hour >> c >> time.min >> c >> time.sec;
	return in;
}

std::ostream& operator<<(std::ostream &out, const Time &time)
{
	std::stringstream res;
	res << (time.hour < 10 ? "0" : "") << time.hour;
	res << (time.min < 10 ? ":0" : ":") << time.min;
	res << (time.sec < 10 ? ":0" : ":") << time.sec;
	out << res.str();
	return out;
}