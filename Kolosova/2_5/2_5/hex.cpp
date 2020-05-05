#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include "hex.h"
#define pb push_back
using namespace std;

int  min(int a, int b) {
	if (a < b) return a;
	return b;
}
int  max(int a, int b) {
	if (a > b) return a;
	return b;
}
bitset<5> itob(unsigned long n) {
	bitset<5> b;
	for (int i = 0; i < 5; i++) {
		b[i] = n % 2;
		n /= 2;
	}
	return b;
}
Hex stoh(string s) {
	Hex res;
	reverse(s.begin(), s.end());
	int n = s.size();
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
		case 'A':
			res.d.pb(itob(10));
			break;
		case 'B':
			res.d.pb(itob(11));
			break;
		case 'C':
			res.d.pb(itob(12));
			break;
		case 'D':
			res.d.pb(itob(13));
			break;
		case 'E':
			res.d.pb(itob(14));
			break;
		case 'F':
			res.d.pb(itob(15));
			break;
		default:
			res.d.pb(itob(s[i] - '0'));
		}
	}
	return res;
}
bitset<5> operator+(bitset<5> & b, const bitset<5> &c) {
	bitset<5> res=itob(c.to_ulong() + b.to_ulong());
	return res;
}
bitset<5> operator-(bitset<5> & b,const bitset<5> & c) {
	bitset<5> res=itob(b.to_ulong() - c.to_ulong());
	return res;
}

Hex::Hex(){
	
}
Hex::Hex(const Hex& h){
	for (int i = 0; i < h.d.size(); i++)
		d.pb(h.d[i]);
}
Hex::Hex(string s) {
	*this= stoh(s);
}
Hex::~Hex(){

}
vector<bitset<5>> & Hex::get_d() {
	return d;
}
int Hex::get_size() { 
	return d.size(); 
}
Hex& Hex::operator=(const Hex& h){
	d = h.d;
	return *this;
}
Hex& Hex::operator=(const string& s) {
	Hex h = stoh(s);
	d = h.d;
	return *this;
}
Hex Hex::operator+(const Hex& h) {
	Hex res;
	int n = min(d.size(), h.d.size());
	int i;
	for (i = 0; i < n; i++) {
		res.d.pb(d[i] + h.d[i]);
		res.d[i] = res.d[i] + ((i == 0) ? 0 : res.d[i - 1][4]);
		if (i) res.d[i - 1][4] = 0;
	}
	vector<bitset<5>> maxd = (d.size() < h.d.size()) ? h.d : d;
	for (; i < maxd.size(); i++) {
		res.d.pb(maxd[i] + itob(res.d[i - 1][4]));
		res.d[i - 1][4] = 0;
	}
	if (res.d[i - 1][4]) {
		res.d.pb(1);
		res.d[i - 1][4] = 0;
	}
	return res;
}
Hex Hex::operator-(const Hex& h){
	Hex res;
	int i;
	if (*this < h) {
		cout << "error: check values\n";
		res.d.pb(10000);
		return res;
	}
	for (i = 0; i < h.d.size(); i++) {
		res.d.pb(d[i] - h.d[i]);
		res.d[i] = res.d[i] - ((i == 0) ? 0 : res.d[i - 1][4]);
		if(i) res.d[i - 1][4] = 0;
	}
	for (; i < d.size(); i++) {
		res.d.pb(d[i] - itob(res.d[i - 1][4]));
		res.d[i - 1][4] = 0;
	}
	res.d[i - 1][4] = 0;
	while ((res.d.size()>1)&&(*(res.d.end()-1) == 0)) {
		res.d.erase(res.d.end() - 1);
	}
	return res;
}
bool Hex::operator<(const Hex& h) const{
	if (d.size() < h.d.size()) return true;
	if (d.size() > h.d.size()) return false;
	return (toString() < h.toString()) ? true : false;
}
bool Hex::operator>(const Hex& h) const{
	if (d.size() > h.d.size()) return true;
	if (d.size() < h.d.size()) return false;
	return (toString() > h.toString()) ? true : false;
}
bool Hex::operator<=(const Hex& h){
	if (*this < h || *this == h) return true;
	return false;
}
bool Hex::operator>=(const Hex& h){
	if (*this > h || *this == h) return true;
	return false;
}
bool Hex::operator==(const Hex& h){
	if (d == h.d) return true;
	return false;
}
bool Hex::operator!=(const Hex& h){
	return (d == h.d) ? false : true;
}
Hex& Hex::operator+=(const Hex& h){
	*this = *this + h;
	return *this;
}
Hex& Hex::operator-=(const Hex& h) {
	*this = *this - h;
	return *this;
}
string Hex::toString() const {
	string s = "";
	int n = d.size();
	for (int i = 0; i < n; i++) {
		int curr = d[i].to_ulong();
		switch (curr) {
		case 10:
			s += "A";
			break;
		case 11:
			s += "B";
			break;
		case 12:
			s += "C";
			break;
		case 13:
			s += "D";
			break;
		case 14:
			s += "E";
			break;
		case 15:
			s += "F";
			break;
		default:
			s += char(curr + '0');
		}
	}
	reverse(s.begin(),  s.end());
	return s;
}
istream& operator>>(istream& in, Hex& a){
	string s;
	in >> s;
	a = stoh(s);
	return in;
}
ostream& operator<<(ostream& out, const Hex& a){
	out << a.toString();
	return out;
}
ifstream& operator>>(ifstream& in, Hex& a){
	string s;
	in >> s;
	a = stoh(s);
	return in;
}
ofstream& operator<<(ofstream& out, Hex& a){
	out << a.toString();
	return out;
}

bitset<5>& Hex::operator[](const int index) {
	return d[index];
}
