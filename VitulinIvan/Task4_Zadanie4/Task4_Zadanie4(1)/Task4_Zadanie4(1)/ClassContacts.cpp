#include "ClassContacts.h"
#include "ClassMainMenu.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Contacts::Contacts()
{
	
}

Contacts::Contacts(const Contacts& copy)
{
	MyContacts = copy.MyContacts;
	MyElectContactsIndex = copy.MyElectContactsIndex;
}

void Contacts::AddContact(Contact& NewContact)
{
	MyContacts.push_back(NewContact);
}

Contact& Contacts::SearchByFIO(string FIO)
{
	for (int i = 0; i < MyContacts.size(); i++)
	{
		if (FIO == MyContacts[i].FIO)
			return MyContacts[i];
		
	}
	throw exception("�������� �� �������");
}

Contact& Contacts::SearchByNumber(string number)
{
	for (int i = 0; i < MyContacts.size(); i++)
	{
		if (number == MyContacts[i].number)
			return MyContacts[i];
	}
	
	throw exception("�������� �� �������");
}


vector<Contact> Contacts::SearchBySymbol(char Symbol)
{
	vector <Contact> tmp;
	for (int i = 0; i < MyContacts.size(); i++)
	{
		if (Symbol == MyContacts[i].FIO[0])
			tmp.push_back(MyContacts[i]);
	}
	return tmp;
}

int Contacts::GetNumberContacts()
{
	return MyContacts.size();
}

void Contacts::AddElect(string FIO)
{
	for (int i = 0; i < MyContacts.size(); i++)
	{

		if ((MyContacts)[i].FIO == FIO)
		{
			if ((find(MyElectContactsIndex.begin(), MyElectContactsIndex.end(), i)) == (MyElectContactsIndex.end()))
				MyElectContactsIndex.push_back(i);
		}

	}
}

void Contacts::RemoveFromElect(string FIO)
{
	for (int i = 0; i < MyContacts.size(); i++)
	{

		if (MyContacts[i].FIO == FIO)
		{
			auto Index = (find(MyElectContactsIndex.begin(), MyElectContactsIndex.end(), i));
			if (Index != (MyElectContactsIndex.end()))
				MyElectContactsIndex.erase(Index);
		}

	}
}

vector <Contact> Contacts::ShowElect()
{
	vector <Contact> tmp;
	for (int i = 0; i < MyElectContactsIndex.size(); i++)
	{
		tmp.push_back(MyContacts[MyElectContactsIndex[i]]);
	}
	return tmp;
}

void Contacts::RemoveContact(string number)
{
	for (int i = 0; i < MyContacts.size(); i++)
	{
		if (MyContacts[i].number == number)
		{
			
			MyContacts.erase(MyContacts.begin() + i);
			for (int j = 0; j < MyElectContactsIndex.size(); j++)
			{
				if (MyElectContactsIndex[j] == i)
				{
					MyElectContactsIndex.erase(MyElectContactsIndex.begin() + j);
					j--;
				}
				else if (MyElectContactsIndex[j] > i)
						MyElectContactsIndex[j]--;
				
			}
		}

	}
}

void Contacts::ReadFile(string path)
{
	string FIO;
	string number;
	string Data;
	string ElectContactsIndexes;

	int numberContacts;
	ifstream fin;
	fin.open(path);
	fin>>numberContacts;
    fin.get();
	MyContacts.clear();
	for (int i = 0; i < numberContacts; i++)
	{
		getline(fin, FIO);
		getline(fin, number);
		getline(fin, Data);
		MyContacts.push_back(*(new Contact(FIO, number, Data::ParseData(Data))));
	}
	getline(fin, ElectContactsIndexes);
	string tmp;
	MyElectContactsIndex.clear();
	for (int i = 0; i < ElectContactsIndexes.size(); i++)
	{
		if ((ElectContactsIndexes[i] == ' '))
		{
			if (tmp != "")
			{
				MyElectContactsIndex.push_back(atoi(tmp.c_str()));
				tmp = "";
			}
		}
		else
			tmp += ElectContactsIndexes[i];
	}
	if(tmp!="")
		MyElectContactsIndex.push_back(atoi(tmp.c_str()));
	fin.close();
}

void Contacts::RecordFile(string path)
{
	ofstream fout;
	fout.open(path);
	fout << MyContacts.size() << endl;
	for (int i = 0; i < MyContacts.size(); i++)
	{
		fout << MyContacts[i].FIO << endl;
		fout << MyContacts[i].number << endl;
		fout << Data::ToString(MyContacts[i].burthday) << endl;
	}
	string ElectContactsString;
	for (int i = 0; i < MyElectContactsIndex.size(); i++)
	{
		ElectContactsString += to_string(MyElectContactsIndex[i]) + " ";
	}
	fout << ElectContactsString << endl;
	fout.close();
}

Data Data::ParseData(string DataStr)
{
	int i = 0;
	Data res;
	string tmp;
	while (DataStr[i] != '.')
	{
		tmp += DataStr[i];
		i++;
	}
	res.day = atoi(tmp.c_str());
	i++;
    tmp = "";
	while (DataStr[i] != '.')
	{
		tmp += DataStr[i];
		i++;
	}
	res.month = atoi(tmp.c_str());
	i++;
    tmp = "";
	while (DataStr[i] != '\0')
	{
		tmp += DataStr[i];
		i++;
	}
	res.year = atoi(tmp.c_str());
	return res;
}

string Data::ToString(Data Date)
{
	string res = "";
	res += to_string(Date.day) + "." + to_string(Date.month) + "." + to_string(Date.year);
	return res;
}

Contact::Contact()
{
    FIO = "";
    number = "";
    burthday = Data();
}

Contact::Contact(string FIO,string number, Data burthday)
{
    this->FIO = FIO;
    this->number = number;
    this->burthday = burthday;
}

string Contact::ToString()
{
    string res = "";
    res += "\n" + FIO + "\n�������: " + number + "\n���� ��������: " + Data::ToString(burthday) + "\n";
    return res;
}


MainMenu::MainMenu() {
    myContacts = new Contacts();
}

void MainMenu::Start()
{
    MenuHandler();
}

void MainMenu::printHead()
{
	system("cls");
	cout << "\t -----���������� �����----\t\t����� ���������: "<< myContacts->GetNumberContacts() <<"\n\n";
}

void MainMenu::MenuHandler()
{
	bool toContinue = true;
	while (toContinue)
	{
		switch (Menu())
		{
        case 1: AddContact();                       break;
        case 2: SearcheByFIO();                     break;
        case 3: ChangeByFIO();                      break;
        case 4: SearcheByNumber();                  break;
        case 5: GetContactsWhenFirstChar();         break;
        case 6: GetContactsCount();                 break;
        case 7: AddContactToElectListByFIO();       break;
        case 8: RemoveContactFromElectListByFIO();  break;
        case 9: GetElectContacts();                 break;
        case 10: RemoveContactByNumber();           break;
        case 11: SaveContactsToFile();              break;
        case 12: ReadContactsFromFile();            break;
        case 13:toContinue = false;                 break;
		default: IncorrectAnswer();                 break;
		}
	}
}

int MainMenu::Menu()
{
	PrintMainMenu();
	int answer;
	cin >> answer;
	return answer;
}

void MainMenu::PrintMainMenu()
{
	printHead();
	cout <<
		"\t������� ����:\n" <<
		"1-������� ����� �������\n" <<
		"2-����� ������� �� ���\n" <<
		"3-�������� ������� �� ���\n" <<
		"4-����� ������� �� ��������\n" <<
		"5-������ ��� ��������, �������� �� ��������� ����� ���\n" <<
		"6-������ ������� ����� ��������\n" <<
		"7-������ ������� � ��������� �� ���\n" <<
		"8-������� ������� �� ��������� �� ���\n" <<
		"9-������ ��� ��������� ��������\n" <<
		"10-������� �������, ��������� �� ��������\n" <<
        "11-��������� �������� � ����\n"<<
        "12-��������� �������� �� �����\n"<<
		"13-���������� ������\n"
		"\n����� �����: ";
}

void MainMenu::IncorrectAnswer()
{
	printHead();
	cout << "\n������: �������� �����";
	Waiting();
}

void MainMenu::Waiting()
{
	cout << "\n������� ����� ������� ��� �����������...";
	getchar();
	getchar();
}


void MainMenu::AddContact()
{
    printHead();
    cout << "���������� ��������\n\n";
    string FIO, dataStr;
	string number;
	getchar();
    cout << "������� �.�.�: ";
    getline(cin, FIO);
    cout << "������� �����: ";
    getline(cin,number);
    cout << "������� ���� ��������: ";
    getline(cin, dataStr);
    myContacts->AddContact(*(new Contact(FIO, number, Data::ParseData(dataStr))));
    cout << "������� �������� �������!\n";
    Waiting();
}

void MainMenu::SearcheByFIO()
{
	Contact res;
	printHead();
    cout << "����� ��������\n\n";
    string FIO;
    getchar();
    cout << "������� �.�.�: ";
    getline(cin, FIO);
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByFIO(FIO);
	}
	catch(exception)
	{
		cout << "������� �� ������!";
		FoundContact = false;
	}
	
	if (FoundContact) 
		cout << "������� ������: " << res.ToString();
    Waiting();
}

void MainMenu::ChangeByFIO()
{
	Contact res;
	printHead();
    cout << "��������� ��������\n\n";
    string FIO;
    getchar();
    cout << "������� �.�.�: ";
    getline(cin, FIO);
	
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByFIO(FIO);
	}
	catch (exception)
	{
		cout << "������� �� ������!";
		FoundContact = false;
		Waiting();
	}
	if (FoundContact)
	{
		cout << "������� ������: " << res.ToString();
		cout << "������� ����� ������:\n";
		string dataStr;
		cout << "������� �.�.�: ";
		getline(cin, res.FIO);
		cout << "������� �����: ";
		getline(cin, res.number);
		cout << "������� ���� ��������: ";
		getline(cin, dataStr);
		res.burthday = Data::ParseData(dataStr);
		cout << "��������!\n";
		Waiting();
	}
}

void MainMenu::SearcheByNumber()
{
	Contact res;
	printHead();
    cout << "����� ��������\n\n";
	string number;
	getchar();
    cout << "������� �����: ";
    getline(cin , number);
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByNumber(number);
	}
	catch (exception)
	{
		cout << "������� �� ������!";
		FoundContact = false;
		Waiting();
	}

	if (FoundContact)
	{
		cout << "������� ������: " << res.ToString();
		Waiting();
	}
	
}

void MainMenu::GetContactsWhenFirstChar()
{
    printHead();
    cout << "����� ���������\n\n";
    char ch;
    getchar();
    cout << "������� ������ �����: ";
    cin >> ch;
    vector<Contact> res = myContacts->SearchBySymbol(ch);
    if (res.size() == 0)
        cout << "�������� �� ������!";
    else {
        cout << "������� "<<res.size()<<" ���������: ";
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i].ToString() << "\n";
        }
    }
    getchar();
    Waiting();
}

void MainMenu::GetContactsCount()
{
    printHead();
    cout << "����� ��������� � ����: " << myContacts->GetNumberContacts()<<"\n";
	getchar();
	Waiting();
}

void MainMenu::AddContactToElectListByFIO()
{
	Contact res;
	printHead();
    getchar();
    cout << "���������� �������� � ��������\n\n";
    string FIO;
    cout << "������� �.�.�: ";
    getline(cin, FIO);
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByFIO(FIO);
	}
	catch (exception)
	{
		cout << "������� �� ������!";
		FoundContact = false;
		Waiting();
	}

	if (FoundContact)
	{
		cout << "������� ������: " << res.ToString();
		myContacts->AddElect(FIO);
		cout << "\n�������� � ��������!\n";
		Waiting();
	}
}

void MainMenu::RemoveContactFromElectListByFIO()
{
	Contact res;
	printHead();
    getchar();
    cout << "�������� �������� �� ��������\n\n";
    string FIO;
    cout << "������� �.�.�: ";
    getline(cin, FIO);
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByFIO(FIO);;
	}
	catch (exception)
	{
		cout << "������� �� ������!";
		FoundContact = false;
		Waiting();
	}

	if (FoundContact)
	{
		cout << "������� ������: " << res.ToString();
		myContacts->RemoveFromElect(FIO);
		cout << "\n������ �� ��������!\n";
		Waiting();
	}
}

void MainMenu::GetElectContacts()
{
    printHead();
    cout << "������ ��������� ���������\n\n";
    vector<Contact> res = myContacts->ShowElect();
    if (res.size() == 0)
        cout << "��� �������� ���������!";
    else {
        cout << "����� " << res.size() << " �������� ���������: ";
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i].ToString() << "\n";
        }
    }
    Waiting();
}

void MainMenu::RemoveContactByNumber()
{
    printHead();
    cout << "�������� ��������\n\n";
	string number;
    cout << "������� �����: ";
	getchar();
    getline(cin, number);
    myContacts->RemoveContact(number);
    cout << "\n������� ������!\n";
    Waiting();
}

void MainMenu::SaveContactsToFile()
{
    printHead();
    cout << "���������� � ����\n\n";
    string Path;
    getchar();
    cout << "������� ����: ";
    getline(cin, Path);
    myContacts->RecordFile(Path);
    cout << "��������� " + Path;
    Waiting();
}

void MainMenu::ReadContactsFromFile()
{
    printHead();
    getchar();
    cout << "������ ��������� �� �����\n\n";
    string Path;
    cout << "������� ����: ";
    getline(cin, Path);
    myContacts->ReadFile(Path);
    cout << "���������� " << myContacts->GetNumberContacts() << " ���������";
    Waiting();
}
