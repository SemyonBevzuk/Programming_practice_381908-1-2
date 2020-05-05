#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

struct FullName {
	wstring last, first, patronym;
	bool operator==(FullName name) {
		return (first == name.first && last == name.last && patronym == name.patronym);
	}
	bool operator!=(FullName name) {
		return !(*this == name);
	}
	friend wistream& operator>>(wistream& in, FullName& name);
	friend wostream& operator<<(wostream& out, const FullName& name);
	friend wofstream& operator<<(wofstream& out, const FullName& name);
	friend wifstream& operator>>(wifstream& in, FullName& name);
};
inline bool operator<(FullName a, FullName b) {
	if (a.last < b.last) return true;
	if (a.last == b.last && a.first < b.first) return true;
	if (a.last == b.last && a.first == b.first && a.patronym < b.patronym) return true;
	return false;
}
struct Info {
	wstring number, dob;
	bool isFav = false;
	bool operator<(Info inf) {
		return(number < inf.number || number == inf.number && dob < inf.dob);
	}
	friend wistream& operator>>(wistream& in, Info& c);
	friend wostream& operator<<(wostream& out, const Info& c);
	friend wofstream& operator<<(wofstream& out, const Info& c);
	friend wifstream& operator>>(wifstream& in, Info& c);
};
struct cont {
	FullName name;
	Info info;
	bool operator<(cont a) {
		return (name < a.name);
	}
	friend wistream& operator>>(wistream& in, cont& c);
	friend wostream& operator<<(wostream& out, const cont& c);
	friend wofstream& operator<<(wofstream& out, const cont& c);
	friend wifstream& operator>>(wifstream& in, cont& c);
};

class Contacts {
private:
	map<FullName, Info> contacts;
public: 
	Contacts();
	Contacts(wstring filename);
	Contacts(Contacts &a);
	~Contacts();
	int load(const wstring filename);
	void save(const wstring filename);
	void newContact(cont c1);
	map<FullName, Info>::iterator findFN(FullName name);
	map<FullName, Info>::iterator changeFN(FullName name, cont c1);
	map<FullName, Info>::iterator findNum(wstring num);
	void showbyFL(wchar_t ch);
	int count();
	int fav(FullName name);
	int unfav(FullName name);
	void showfavs();
	int deleteNum(wstring number);
	int del(int ind);
	void print();
	map<FullName, Info>::iterator end();
};