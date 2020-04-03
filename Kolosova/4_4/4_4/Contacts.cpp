#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include "Contacts.h"
using namespace std;
////////////////////////////////////////////////////////////// FullName
wistream& operator>>(wistream& in, FullName& name){
	in >> name.last >> name.first >> name.patronym;
	return in;
}
wostream& operator<<(wostream& out, const FullName& name){
	out<< name.last << L' ' << name.first << L' ' << name.patronym;
	return out;
}
wofstream& operator<<(wofstream& out, const FullName& name) {
	out << name.last << L' ' << name.first << L' ' << name.patronym;
	return out;
}
wifstream& operator>>(wifstream& in, FullName& name) {
	in >> name.last >> name.first >> name.patronym;
	return in;
}
////////////////////////////////////////////////////////////// Info
wistream& operator>>(wistream& in, Info& c) {
	in  >> c.number >> c.dob;
	return in;
}
wostream& operator<<(wostream& out, const Info& c) {
	out << c.number << L' ' << c.dob;
	if (c.isFav) out << L" *";
	return out;
}
wofstream& operator<<(wofstream& out, const Info& c) {
	out << c.number << L' ' << c.dob;
	if (c.isFav) out << L" *";
	return out;
}
wifstream& operator>>(wifstream& in, Info& c) {
	in >> c.number >> c.dob;
	return in;
}
////////////////////////////////////////////////////////////// cont

wistream& operator>>(wistream& in, cont& c){
	in >> c.name >> c.info;
	return in;
}
wostream& operator<<(wostream& out, const cont& c){
	out << c.name << L' ' << c.info;
	return out;
}
wofstream& operator<<(wofstream& out, const cont& c) {
	out << c.name << L' ' << c.info;
	return out;
}
wifstream& operator>>(wifstream& in, cont& c) {
	in >> c.name >>c. info;
	return in;
}
////////////////////////////////////////////////////////////// Contacts
Contacts::Contacts(){

}
Contacts::Contacts(const wstring filename){
	load(filename);
}
Contacts::Contacts(Contacts& a){
	c = a.c;
}
Contacts::~Contacts(){

}
int Contacts::load(const wstring filename){
	wifstream file;
	file.open(filename);
	//if (file.failbit) return 0;
	while (!file.eof()) {
		cont c1;
		file >> c1;
		if (file.get() == L' ') {
			c1.info.isFav = true;
			file.get();
		}
		c.insert(map<FullName, Info>::value_type(c1.name, c1.info));
	}
	file.close();
	return 1;
}
void Contacts::save(const wstring filename){
	wofstream file;
	file.open(filename);
	for (auto c1 : c) {
		file << c1.first<<L' '<<c1.second << endl;
	}
	file.close();
	return;
}
void Contacts::newContact(cont c1){
	c.insert(map<FullName, Info>::value_type(c1.name, c1.info));
	return;
}
map<FullName, Info>::iterator Contacts::findFN(FullName name){
	map<FullName, Info>::iterator i = c.find(name);
	return i;
}
map<FullName, Info>::iterator Contacts::changeFN(FullName name, cont c1){
	c[name] = c1.info;
	if (name != c1.name) {
		c.erase(name);
		c.insert(map<FullName, Info>::value_type(c1.name, c1.info));
	}
	map<FullName, Info>::iterator i = c.find(c1.name);
	return i;
}
map<FullName, Info>::iterator Contacts::findNum(wstring num){
	map<FullName, Info>::iterator i = c.begin();
	for (; i !=c.end(); i++) {
		if (i->second.number == num) {
			return i;
		}
	}
	return i;
}
void Contacts::showbyFL(wchar_t ch){
	Contacts res;
	map<FullName, Info>::iterator i = c.begin();
	while (i->first.last[0] != ch && i != c.end())
		i++;
	while (i->first.last[0] == ch && i != c.end()) {
		wcout << i->first << L' ' << i->second << endl;
		i++;
	}
	return;
}
int Contacts::count(){
	return c.size();
}
int Contacts::fav(FullName name){
	map<FullName, Info>::iterator i = findFN(name);
	if (i == c.end()) return 0;
	c[name].isFav = true;
	return 1;
}
int Contacts::unfav(FullName name){
	map<FullName, Info>::iterator i = findFN(name);
	if (i == c.end()) return 0;
	c[name].isFav = false;
	return 1;
}
void Contacts::showfavs(){
	map<FullName, Info>::iterator i = c.begin();
	wcout << L"------------------------------------------------------------" << endl;
	while (i != c.end()) {
		if (i->second.isFav) {
			wcout << i->first << L' ' << i->second << endl;
			i++;
		}
	}
	wcout << L"------------------------------------------------------------" << endl;
	return;
}
int Contacts::deleteNum(wstring number){
	map<FullName, Info>::iterator i = findNum(number);
	if (i != c.end()) {
		c.erase(i);
		return 1;
	}
	return 0;
}
int Contacts::del(int ind) {
	map<FullName, Info>::iterator i = c.begin();
	if (ind > c.size()) return 0;
	for (int j = 0; j < ind; j++) i++;
	c.erase(i);
	return 1;
}
void Contacts::print(){
	map<FullName, Info>::iterator i = c.begin();
	wcout << L"------------------------------------------------------------" << endl;
	while (i != c.end()) {
		wcout << i->first << L' ' << i->second << endl;
		i++;
	}
	wcout << L"------------------------------------------------------------" << endl;
	return;
}
map<FullName, Info>::iterator Contacts::end() {
	return c.end();
}