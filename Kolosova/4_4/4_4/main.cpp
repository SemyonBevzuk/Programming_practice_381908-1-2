#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include "Contacts.h"
using namespace std;

int main() {
	Contacts a;
	wstring s1, s2, s3;
	cont ct;
	FullName name, tmp;
	wchar_t ch;
	int res, ind;
	map<FullName, Info>::iterator i;
	wcout << L"To show commands, type 'help'\n";
	do {
		wcin >> s3;
		if (s3 == L"help") {
			wcout << L"load (filename.txt) - load from file\n" <<
				L"save (filename.txt) - save to file\n" <<
				L"add (name) (phone number) (date of birth) - new contact\n" <<
				L"show - show all cantacts\n"
				L"findFN (name) - find contact by name\n" <<
				L"changeFN (name) (name|number|dob) (new value 1) ... * - find contact by name and change\n" <<
				L"findNum (number) - find contact by phone number\n" <<
				L"showbyFL (CH) - show all contacts starting with letter CH (capital)\n" <<
				L"count - show amount of contacts\n" <<
				L"fav (name) - add contact to favourites\n" <<
				L"unfav (name) - delete contact from favourites\n" <<
				L"showFavs - show favourite contacts\n" <<
				L"deleteNum (number) - delete contact found by number\n" <<
				L"exit - exit program\n";
		}
		else if(s3==L"load"){
			wcin >> s1;
			int res = a.load(s1);
			if (res) {
				wcout << L"Loaded from file " << s1 << endl;
			}
			else
				wcout << L"Failed to open a file.\n";
		}

		else if(s3==(L"save")){
			wcin >> s1;
			a.save(s1);
			wcout << L"Saved to " << s1 << endl;
		}

		else if(s3==(L"add")){
			wcin >> ct;
			a.newContact(ct);
			cout << "Contact added.\n";
		}

		else if(s3==(L"show")){
			a.print();
		}

		else if(s3==(L"findFN")){
			wcin >> name;
			i = a.findFN(name);
			if(i!=a.end())
				wcout << i->first << ' ' << i->second << endl;
			else
				wcout << L"No contacts found.\n";
		}

		else if(s3==(L"changeFN")){
			wcin >> name;
			ct.name = name;
			i = a.findFN(name);
			if (i != a.end()) {
				ct.info = i->second;
				do {
					wcin >> s2;
					if(s2==(L"name")){
						wcin >> ct.name;
					}
					else if(s2==L"number"){
						wcin >> ct.info.number;
					}
					else if(s2==L"dob"){
						wcin >> ct.info.dob;
					}
				} while (s2 != L"*");
				i = a.changeFN(name, ct);
				wcout << L"Changed: " << i->first << ' ' << i->second << endl;
			}
			else
				wcout << L"No contacts found.\n";
		}

		else if(s3==(L"findNum")){
			wcin >> s1;
			i = a.findNum(s1);
			if (i != a.end())
				wcout << i->first << ' ' << i->second<<endl;
			else
				wcout << L"No contacts found.\n";
		}

		else if(s3==(L"showbyFL")){
			wcin >> ch;
			a.showbyFL(ch);
		}

		else if(s3==(L"count")){
			wcout<<L"Current amount of contacts: "<<a.count()<<endl;
		}

		else if(s3==(L"fav")){
			wcin >> name;
			res=a.fav(name);
			if (res)
				wcout << L"Contact added to favourites.\n";
			else
				wcout << L"No contacts found.\n";
		}

		else if(s3==(L"unfav")){
			wcin >> name;
			res = a.unfav(name);
			if (res)
				wcout << L"Contact removed from favourites.\n";
			else
				wcout << L"No contacts found.\n";
		}

		else if(s3==(L"showFavs")){
			a.showfavs();
		}

		else if(s3==(L"deleteNum")){
			wcin >> s1;
			res = a.deleteNum(s1);
			if (res)
				wcout << L"Contact successfully deleted.\n";
			else
				wcout << L"No comtacts found.\n";
		}

		else if (s3 == L"delete") {
			cin >> ind;
			res = a.del(ind);
			if (res)
				wcout << L"Contact successfully deleted.\n";
			else
				wcout << L"No comtacts found.\n";
		}

		else if(s3==(L"exit")){
			return 0;
		}
			
		else {
			wcout << L"Wrong input!\n";
		}
	} while (1);
}