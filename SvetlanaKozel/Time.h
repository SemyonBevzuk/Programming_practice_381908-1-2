#pragma once
#include <string>
#include <sstream>
typedef unsigned int uint;
class Time
{
public:
	Time(uint hour = 0, uint min = 0, uint sec = 0);
	Time(const std::string&);
	Time(const Time&);
	~Time();

	void SetHour(uint);
	void SetMin(uint);
	void SetSec(uint);
	uint GetHour() const;
	uint GetMin() const;
	uint GetSec() const;

	Time& operator=(const Time&);
	Time operator+(const Time&) const;
	Time operator-(const Time&) const;

	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;
	bool operator>=(const Time&) const;
	bool operator<=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator<(const Time&) const;

	friend std::istream& operator>>(std::istream&, Time&);
	friend std::ostream& operator<<(std::ostream&, const Time&);
private:
	uint hour;
	uint min;
	uint sec;
};

