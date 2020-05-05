#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "dictionary.h"
#include <algorithm>
#include "pss.h"
#define pb push_back
using namespace std;

/////////////////////////////////////////////////
bool sortCriteria(pss a, pss b) {
	return (a[0] < b[0]);
}
////////////////////////////////////////////////
Dict::Dict(){

}
Dict::Dict(const string filename){
	load(filename);
}
Dict::Dict(const Dict& d){
	dict = d.dict;
}
Dict::~Dict(){
	dict.clear();
}
int Dict::seekpos(string word) {
	int l = 0, r = dict.size() - 1, ans = r + 1;
	while (l <= r) {
		int c = (l + r) / 2;
		if (dict[c][0] >= word) {
			ans = c;
			r = c - 1;
		}
		else
			l = c + 1;
	}
	return ans;
}
void Dict::load(const string filename){
	ifstream file;
	file.open(filename);
	while (!file.eof()) {
		pss p;
		file >> p[0] >> p[1];
		dict.pb(p);
	}
	sort_();
	file.close();
	return;
}
void Dict::save(const string filename){
	ofstream file;
	file.open(filename);
	for (pss p : dict)
		file << p[0] << ' ' << p[1]<<endl;
	file.close();
	return;
}
string Dict::translate(const string word){
	pair<int, int> p = seek(word);
	if (p.first > -1)
		return dict[p.first][(p.second+1)%2];
	return "%err";
}
pair<int, int> Dict::seek(const string word){
	pair<int, int > p= {-1, -1};
	for (int i = 0; i < dict.size();i++) {
		if (dict[i][0] == word) p = { i, 0 };
		else if (dict[i][1] == word) p = { i, 1 };
	}
	return p;
}
int Dict::count(){
	return dict.size();
}
int Dict::add(const string word, const string translation){
	pair<int, int> p1 = seek(word), p2 = seek(translation);
	if (p1.first >= 0 && p2.first >= 0) {
		int excep=-1;
		throw excep;
	}
	if ((word[0] >= 'a') && (word[0] <= 'z')) {
		pss elem( word, translation );
		dict.insert(dict.begin()+seekpos(word), elem);
	}
	else if((word[0]>='à')&&(word[0]<='ÿ')) {
		pss elem( translation, word );
		dict.insert(dict.begin()+seekpos(translation), elem);
	}
	return 0;
}
int Dict::changetrans(const string word, const string translation){
	pair<int, int> p = seek(word);
	if (p.first > -1) {
		dict[p.first][(p.second + 1) % 2] = translation;
		if (p.second == 0) {
			sort_();
		}
		return 0;
	}
	return -1;
}
void Dict::print(){
	for (pss x : dict) {
		cout << x[0] << ' ' << x[1] << endl;
	}
	cout << "----------------------------------\n";
	return;
}
Dict& Dict::operator=(const Dict& d){
	dict = d.dict;
	return *this;
}
Dict Dict::operator+(const Dict& d){ 
	Dict res;
	for (pss x : dict) {
		res.dict.pb(x);
	}
	for (pss x : d.dict) {
		pair<int, int> p = res.seek(x[0]);
		if(p.first<0)
			res.dict.pb(x);
	}
	res.sort_();
	return res;
}
Dict& Dict::operator+=(const Dict& d){
	*this = *this + d;
	return *this;
}
Dict& Dict::sort_() {
	sort(dict.begin(), dict.end(), sortCriteria);
	return *this;
}