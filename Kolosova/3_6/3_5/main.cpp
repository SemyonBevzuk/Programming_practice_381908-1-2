#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include "dictionary.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Dict d1, d2("dict1.txt"), d3(d2);
	d2.print();
	d3.print();
	cout << "-----------Add new words------------\n";
	d2.add("dog", "собака");
	d2.print();
	try {
		d2.add("собака", "dog");
	}
	catch (int) {
		cout << "The word is already in the dictionary.\n";
	}
	d2.print();
	cout << "-----------Saving & loading----------------\n";
	Dict d4(d2), d5;
	d4.add("cat", "кошка");
	d4.print();
	d4.save("dict3.txt");
	d5.load("dict3.txt");
	d5.print();
	cout << "-------------Merging dictionaries-------------\n";
	d1.load("dict2.txt");
	d1.print();
	d3 = d1 + d2;
	d3.print();
	cout << "--------Translation----------" << endl << "fry " << d3.translate("fry") << endl;
	cout << "жар " << d3.translate("жар") << endl;
	cout << "cat " << d1.translate("cat") << endl;
	cout << "-----------Amount of words-------------\n" <<
		"d1: " << d1.count() << endl <<
		"d2: " << d2.count() << endl <<
		"d3: " << d3.count() << endl;
	cout << "-----Check if a word is already in the dictionary-----\n";
	pair<int, int> p = d2.seek("легко");
	cout << "Line: " << p.first << ", position: " << p.second << endl;
	cout << "----------Changing translation------------\n";
	d2.changetrans("card", "карта");
	d2.print();
}