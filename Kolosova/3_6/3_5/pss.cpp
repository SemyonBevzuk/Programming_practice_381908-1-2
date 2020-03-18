#include <string>
#include <vector>
#include "pss.h"

using namespace std;

pss::pss() {

}
pss::pss(string str1, string str2) {
	s[0] = str1;
	s[1] = str2;
}
pss& pss::operator=(const pss& p) {
	s[0] = p.s[0];
	s[1] = p.s[1];
	return *this;
}
pss& pss::operator=(initializer_list<string> str) {
	int i = 0;
	for (string a : str) {
		s[i] = a;
		i++;
	}
	return *this;
}
string& pss::operator[](const int index) {
	return s[index];
}
pss::~pss() {
}