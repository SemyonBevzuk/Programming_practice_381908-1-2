#include "Dictionary.h"

void Dictionary::check(string& s, char c) {
	for (int i = 0; i < s.size(); ++i)
	{
		s[i] = tolower(s[i]);
		if (c == 'e')
		{
			if (!(s[i] > 96 && s[i] < 123))
				throw exception("Строка не является английским словом!");
		}
		else
		{
			if (!(s[i] > -33 && s[i] < 0))
				throw exception("Строка не является русским словом!");
		}
	}
}
Dictionary::Dictionary(const Dictionary& d) {
	*this = d;
}
Dictionary::Dictionary(vector<pair<string, string >> sl) {
	for (int i = 0; i < sl.size(); ++i)
	{
		check(sl[i].first, 'e');
		check(sl[i].second, 'r');
		slov.push_back(sl[i]);
	}
	sort(slov.begin(), slov.end());
}
Dictionary& Dictionary::operator=(const Dictionary& d) {
	if (this != &d)
	{
		slov.resize(d.slov.size());
		for (int i = 0; i < d.slov.size(); ++i)
		{
			slov[i] = d.slov[i];
		}
	}
	return *this;
}
Dictionary& Dictionary::operator+=(const Dictionary& d) {
	Dictionary td;
	int ni = slov.size(), nj = d.slov.size();
	int i = 0, j = 0;
	while (i < ni && j < nj)
	{
		if (slov[i].first < d.slov[j].first)
		{
			td.slov.push_back(slov[i]);
			i++;
		}
		else if (slov[i].first > d.slov[j].first)
		{
			td.slov.push_back(d.slov[j]);
			j++;
		}
		else
		{
			td.slov.push_back(slov[i]);
			i++;
			j++;
		}
	}
	for (i; i < ni; ++i)
		td.slov.push_back(slov[i]);
	for (j; j < nj; ++j)
		td.slov.push_back(d.slov[j]);
	*this = td;
	return *this;
}
const Dictionary Dictionary::operator+(const Dictionary& d)const {
	Dictionary dt = *this;
	dt += d;
	return dt;
}
void Dictionary::add(string sa, string sr) {
	check(sa, 'e');
	check(sr, 'r');
	for (int i = 0; i < slov.size(); ++i)
	{
		if (slov[i].first == sa)
			throw exception("Данное слово уже есть в словаре!");
	}
	slov.push_back(make_pair(sa, sr));
	sort(slov.begin(), slov.end());
}
void Dictionary::change_translate(string sa, string sr) {
	check(sa, 'e');
	check(sr, 'r');
	for (int i = 0; i < slov.size(); ++i)
	{
		if (slov[i].first == sa)
		{
			slov[i].second = sr;
			return;
		}
	}
	throw exception("Данного слова нет в словаре!");
}
const string Dictionary::get_translate(string sa){
	check(sa, 'e');
	for (int i = 0; i < slov.size(); ++i)
	{
		if (slov[i].first == sa)
			return slov[i].second;
	}
	throw exception("Данного слова нет в словаре!");
}
bool Dictionary::find(string sa) {
	check(sa, 'e');
	for (int i = 0; i < slov.size(); ++i)
	{
		if (slov[i].first == sa)
			return true;
	}
	return false;
}
const int Dictionary::size()const {
	return slov.size();
}
ifstream& operator>>(ifstream& in, Dictionary& d) {
	int n;
	in >> n;
	d.slov.resize(n);
	for (int i = 0; i < n; ++i)
	{
		in >> d.slov[i].first >> d.slov[i].second;
	}
	sort(d.slov.begin(), d.slov.end());
	return in;
}
ofstream& operator<<(ofstream& out, const Dictionary& d) {
	out << d.slov.size() << endl;
	for (int i = 0; i < d.slov.size(); ++i)
	{
		out << d.slov[i].first << ' ' << d.slov[i].second << endl;
	}
	return out;
}