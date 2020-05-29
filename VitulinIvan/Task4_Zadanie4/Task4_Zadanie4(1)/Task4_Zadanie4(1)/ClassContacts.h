#pragma once
#include <vector>
#include <string>

using namespace std;

struct Data
{
	int day;
	int month;
	int year;
    static Data ParseData(string Data);
    static string ToString(Data Date);
};

struct Contact
{
	string FIO;
	string number;
	Data burthday;
	Contact();
	Contact(string FIO, string number, Data burthday);
    string ToString();
	
};

class Contacts
{
private:
	vector <Contact> MyContacts;
	vector <int> MyElectContactsIndex; //для экономии памяти
public:
	Contacts();
	Contacts(const Contacts& copy);
	void AddContact(Contact& NewContact);
	Contact& SearchByFIO(string FIO);
	Contact& SearchByNumber(string number);
	vector<Contact> SearchBySymbol(char Symbol);
	int GetNumberContacts();
	void AddElect(string FIO);
	void RemoveFromElect(string FIO);
	vector <Contact> ShowElect();
	void RemoveContact(string number);
	void ReadFile(string path);
	void RecordFile(string path);
	
};


