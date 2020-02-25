#include <iostream>
#include "Time.h"
using namespace std;
Time::Time(){
	h = 0;
	m = 0;
	s = 0;
}
Time::Time(const Time& t){
	h = t.h;
	m = t.m;
	s = t.s;
}
Time::Time(const int& hr, const int& min, const int& sec){
	h = hr;
	m = min;
	s = sec;
}
int Time::get_h() {
	return h;
}
int Time::get_m() {
	return m;
}
int Time::get_s() {
	return s;
}
Time& Time::operator=(const Time& t){
	h = t.h;
	m = t.m;
	s = t.s;
	return *this;
}
Time Time::operator+(const Time& t){
	Time res;
	res.s = t.s + s;
	res.m = t.m + m + res.s / 60;
	res.s %= 60;
	res.h = (t.h + h + res.m / 60)%24;
	res.m %= 60;
	return res;
}
Time Time::operator-(const Time& t){
	Time res;
	res.s = s - t.s;
	res.m = m - t.m;
	res.h = h - t.h;
	if (res.s < 0) {
		res.m--;
		res.s += 60;
	}
	if (res.m < 0) {
		res.h--;
		res.m += 60;
	}
	if (res.h < 0) res.h += 24;
	return res;
}
bool Time::operator<(const Time& t){
	return ((h < t.h) || (h == t.h) && (m < t.m) || (h == t.h) && (m == t.m) && (s < t.s))?true:false;
}
bool Time::operator>(const Time& t){
	return ((h > t.h) || (h == t.h) && (m > t.m) || (h == t.h) && (m == t.m) && (s > t.s)) ? true : false;
}
bool Time::operator<=(const Time& t){
	return ((h <= t.h) || (h == t.h) && (m <= t.m) || (h == t.h) && (m == t.m) && (s <= t.s)) ? true : false;
}
bool Time::operator>=(const Time& t){
	return ((h >= t.h) || (h == t.h) && (m >= t.m) || (h == t.h) && (m == t.m) && (s >= t.s)) ? true : false;
}
bool Time::operator==(const Time& t){
	return ((h == t.h) && (m == t.m) && (s == t.s)) ? true:false;
}
bool Time::operator!=(const Time& t) {
	return !(*this == t);
}
Time& Time::operator+=(const Time& t){
	*this = *this + t;
	return *this;
}
Time& Time::operator-=(const Time& t){
	* this = *this - t;
	return *this;
}
///////////////////////////////////////
Time Time::operator+(const int& sec) {
	Time res;
	res = *this;
	res.s += sec;
	res.m += res.s / 60;
	res.h += res.m / 60;
	res.s %= 60;
	res.m %= 60;
	res.h %= 24;
	return res;
}
Time Time::operator-(const int& sec) {
	Time res;
	res = *this;
	res.s -= sec;
	if (res.s < 0) {
		int k = (abs(res.s) / 60 + 1);
		res.m-=k;
		res.s += 60*k;
		if (res.m < 0) {
			int k = (abs(res.m) / 60 + 1);
			res.h -= k;
			res.m += 60 * k;
			if (res.h < 0) {
				int k = (abs(res.h) / 24 + 1);
				res.h += k * 24;
			}
		}
	}
	return res;
}
Time& Time::operator+=(const int& sec) {
	*this = *this + sec;
	return *this;
}
Time& Time::operator-=(const int& sec) {
	* this = *this - sec;
	return *this;
}
istream& operator>>(istream& in, Time& t){
	in >> t.h >> t.m >> t.s;
	while ((t.h < 0) || (t.h > 24) || (t.m < 0) || (t.m > 60) || (t.s < 0) || (t.s > 60)) {
		cout << "Incorrect input. Try again:\n";
		in >> t.h >>t.m >>t.s;
	}
	return in;
}
ostream& operator<<(ostream& out, const Time &t){
	out << t.h << ':' << t.m << ':' << t.s;
	return out;
}
Time::~Time() {}