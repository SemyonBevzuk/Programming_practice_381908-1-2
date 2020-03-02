#include <bitset>
#include <iostream>
#include <string>
#include <fstream>
#include "hex.h"
using namespace std;

int main() {
	Hex a("ABC123"), b(a);
	cout << a << ' ' << b << endl;
	cin >> a;
	b += a;
	cout << b << endl;
	cin >> a >> b;
	cout << a - b << endl;;
	b = "ABF905";
	for (int i = 0; i < 6; i++) {
		cout << b[i] << ' ';
	}
	cout << endl;
	ofstream fout;
	fout.open("file.txt");
	fout << a << ' ' << b;
	fout.close();
	ifstream fin;
	fin.open("file.txt");
	fin >>b >>a;
	fin.close();
	cout << a << ' ' << b << endl;
	a = "FFFFFF";
	b = "EEEEEE";
	cout << (a > b) << ' ' << (a <= b) << ' ' << (a != b) << endl;
	b = "FFFFFF";
	cout << (a == b);
}