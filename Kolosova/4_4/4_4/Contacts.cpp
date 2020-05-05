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
	contacts = a.contacts;
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
		contacts.insert(map<FullName, Info>::value_type(c1.name, c1.info));
	}
	file.close();
	return 1;
}
void Contacts::save(const wstring filename){
	wofstream file;
	file.open(filename);
	for (auto c1 : contacts) {
		file << c1.first<<L' '<<c1.second << endl;
	}
	file.close();
	return;
}
void Contacts::newContact(cont c1){
	contacts.insert(map<FullName, Info>::value_type(c1.name, c1.info));
	return;
}
map<FullName, Info>::iterator Contacts::findFN(FullName name){
	map<FullName, Info>::iterator i = contacts.find(name);
	return i;
}
map<FullName, Info>::iterator Contacts::changeFN(FullName name, cont c1){
	contacts[name] = c1.info;
	if (name != c1.name) {
		contacts.erase(name);
		contacts.insert(map<FullName, Info>::value_type(c1.name, c1.info));
	}
	map<FullName, Info>::iterator i = contacts.find(c1.name);
	return i;
}
map<FullName, Info>::iterator Contacts::findNum(wstring num){
	map<FullName, Info>::iterator i = contacts.begin();
	for (; i !=contacts.end(); i++) {
		if (i->second.number == num) {
			return i;
		}
	}
	return i;
}
void Contacts::showbyFL(wchar_t ch){
	Contacts res;
	map<FullName, Info>::iterator i = contacts.begin();
	while (i->first.last[0] != ch && i != contacts.end())
		i++;
	while (i->first.last[0] == ch && i != contacts.end()) {
		wcout << i->first << L' ' << i->second << endl;
		i++;
	}
	return;
}
int Contacts::count(){
	return contacts.size();
}
int Contacts::fav(FullName name){
	map<FullName, Info>::iterator i = findFN(name);
	if (i == contacts.end()) return 0;
	contacts[name].isFav = true;
	return 1;
}
int Contacts::unfav(FullName name){
	map<FullName, Info>::iterator i = findFN(name);
	if (i == contacts.end()) return 0;
	contacts[name].isFav = false;
	return 1;
}
void Contacts::showfavs(){
	map<FullName, Info>::iterator i = contacts.begin();
	wcout << L"------------------------------------------------------------" << endl;
	while (i != contacts.end()) {
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
	if (i != contacts.end()) {
		contacts.erase(i);
		return 1;
	}
	return 0;
}
int Contacts::del(int ind) {
	map<FullName, Info>::iterator i = contacts.begin();
	if (ind > contacts.size()) return 0;
	for (int j = 0; j < ind; j++) i++;
	contacts.erase(i);
	return 1;
}
void Contacts::print(){
	map<FullName, Info>::iterator i = contacts.begin();
	wcout << L"------------------------------------------------------------" << endl;
	while (i != contacts.end()) {
		wcout << i->first << L' ' << i->second << endl;
		i++;
	}
	wcout << L"------------------------------------------------------------" << endl;
	return;
}
map<FullName, Info>::iterator Contacts::end() {
	return contacts.end();
}