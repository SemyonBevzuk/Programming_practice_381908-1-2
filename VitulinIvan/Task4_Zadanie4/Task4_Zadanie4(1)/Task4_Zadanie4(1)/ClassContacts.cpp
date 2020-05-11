#include "ClassContacts.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

Contacts::Contacts()
{
	MyContacts = new std::vector <Contact>();
	MyElectContactsIndex = new std::vector <int>();
}

Contacts::Contacts(const Contacts& copy)
{
	MyContacts = new std::vector <Contact>(*copy.MyContacts);
	MyElectContactsIndex = new std::vector <int>(*copy.MyElectContactsIndex);
}

void Contacts::AddContact(Contact& NewContact)
{
	MyContacts->push_back(NewContact);
}

Contact& Contacts::SearchByFIO(std::string FIO)
{
	for (int i = 0; i < MyContacts->size(); i++)
	{
		if (FIO == (*MyContacts)[i].FIO)
			return (*MyContacts)[i];
		
	}
	return (*new Contact());
}

Contact& Contacts::SearchByNumber(std::string number)
{
	for (int i = 0; i < MyContacts->size(); i++)
	{
		if (number == (*MyContacts)[i].number)
			return (*MyContacts)[i];
	}
	return (*new Contact());
}


std::vector<Contact>& Contacts::Search(char Symbol)
{
	std::vector <Contact>* tmp = new std::vector<Contact>();
	for (int i = 0; i < MyContacts->size(); i++)
	{
		if (Symbol == (*MyContacts)[i].FIO[0])
			(*tmp).push_back((*MyContacts)[i]);
	}
	return *tmp;
}

int Contacts::GetNumberContacts()
{
	return (*MyContacts).size();
}

void Contacts::AddElect(std::string FIO)
{
	for (int i = 0; i < MyContacts->size(); i++)
	{

		if ((*MyContacts)[i].FIO == FIO)
		{
			if ((std::find(MyElectContactsIndex->begin(), MyElectContactsIndex->end(), i)) == (MyElectContactsIndex->end()))
				(*MyElectContactsIndex).push_back(i);
		}

	}
}

void Contacts::RemoveFromElect(std::string FIO)
{
	for (int i = 0; i < MyContacts->size(); i++)
	{

		if ((*MyContacts)[i].FIO == FIO)
		{
			auto Index = (std::find(MyElectContactsIndex->begin(), MyElectContactsIndex->end(), i));
			if (Index != (MyElectContactsIndex->end()))
				(*MyElectContactsIndex).erase(Index);
		}

	}
}

std::vector <Contact>& Contacts::ShowElect()
{
	std::vector <Contact>* tmp = new std::vector <Contact>;
	for (int i = 0; i < MyElectContactsIndex->size(); i++)
	{
		tmp->push_back((*MyContacts)[(*MyElectContactsIndex)[i]]);
	}
	return *tmp;
}

void Contacts::RemoveContact(std::string number)
{
	for (int i = 0; i < (*MyContacts).size(); i++)
	{
		if ((*MyContacts)[i].number == number)
		{
			
			(*MyContacts).erase(MyContacts->begin() + i);
			for (int j = 0; j < (*MyElectContactsIndex).size(); j++)
			{
				if ((*MyElectContactsIndex)[j] == i)
				{
					(*MyElectContactsIndex).erase(MyElectContactsIndex->begin() + j);
					j--;
				}
				else if ((*MyElectContactsIndex)[j] > i)
						(*MyElectContactsIndex)[j]--;
				
			}
		}

	}
}

void Contacts::ReadFile(std::string path)
{
	std::string FIO;
	std::string number;
	std::string Data;
	std::string ElectContactsIndexes;

	int numberContacts;
	std::ifstream fin;
	fin.open(path);
	fin>>numberContacts;
    fin.get();
	MyContacts->clear();
	for (int i = 0; i < numberContacts; i++)
	{
		std::getline(fin, FIO);
		std::getline(fin, number);
		std::getline(fin, Data);
		MyContacts->push_back(*(new Contact(FIO, number, Data::ParseData(Data))));
	}
	std::getline(fin, ElectContactsIndexes);
	std::string tmp;
	MyElectContactsIndex->clear();
	for (int i = 0; i < ElectContactsIndexes.size(); i++)
	{
		if ((ElectContactsIndexes[i] == ' '))
		{
			if (tmp != "")
			{
				MyElectContactsIndex->push_back(atoi(tmp.c_str()));
				tmp = "";
			}
		}
		else
			tmp += ElectContactsIndexes[i];
	}
	if(tmp!="")
		MyElectContactsIndex->push_back(atoi(tmp.c_str()));
	fin.close();
}

void Contacts::RecordFile(std::string path)
{
	std::ofstream fout;
	fout.open(path);
	fout << MyContacts->size() << std::endl;
	for (int i = 0; i < MyContacts->size(); i++)
	{
		fout << (*MyContacts)[i].FIO << std::endl;
		fout << (*MyContacts)[i].number << std::endl;
		fout << Data::ToString((*MyContacts)[i].burthday) << std::endl;
	}
	std::string ElectContactsString;
	for (int i = 0; i < MyElectContactsIndex->size(); i++)
	{
		ElectContactsString += std::to_string((*MyElectContactsIndex)[i]) + " ";
	}
	fout << ElectContactsString << std::endl;
	fout.close();
}

Data Data::ParseData(std::string DataStr)
{
	int i = 0;
	Data res;
	std::string tmp;
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

std::string Data::ToString(Data Date)
{
	std::string res = "";
	res += std::to_string(Date.day) + "." + std::to_string(Date.month) + "." + std::to_string(Date.year);
	return res;
}

Contact::Contact()
{
    FIO = "";
    number = "";
    burthday = Data();
}

Contact::Contact(std::string FIO,std::string number, Data burthday)
{
    this->FIO = FIO;
    this->number = number;
    this->burthday = burthday;
}

std::string Contact::ToString()
{
    std::string res = "";
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
	std::cout << "\t -----���������� �����----\t\t����� ���������: "<< myContacts->GetNumberContacts() <<"\n\n";
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
	std::cin >> answer;
	return answer;
}

void MainMenu::PrintMainMenu()
{
	printHead();
	std::cout <<
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
	std::cout << "\n������: �������� �����";
	Waiting();
}

void MainMenu::Waiting()
{
	std::cout << "\n������� ����� ������� ��� �����������...";
	getchar();
	getchar();
}


void MainMenu::AddContact()
{
    printHead();
    std::cout << "���������� ��������\n\n";
    std::string FIO, dataStr;
	std::string number;
	getchar();
    std::cout << "������� �.�.�: ";
    std::getline(std::cin, FIO);
    std::cout << "������� �����: ";
    std::getline(std::cin,number);
    std::cout << "������� ���� ��������: ";
    std::getline(std::cin, dataStr);
    myContacts->AddContact(*(new Contact(FIO, number, Data::ParseData(dataStr))));
    std::cout << "������� �������� �������!\n";
    Waiting();
}

void MainMenu::SearcheByFIO()
{
    printHead();
    std::cout << "����� ��������\n\n";
    std::string FIO;
    getchar();
    std::cout << "������� �.�.�: ";
    std::getline(std::cin, FIO);
    Contact res = myContacts->SearchByFIO(FIO);
    if (res.number == "" && res.FIO == "")
        std::cout << "������� �� ������!";
    else
        std::cout << "������� ������: " << res.ToString();
    Waiting();
}

void MainMenu::ChangeByFIO()
{
    printHead();
    std::cout << "��������� ��������\n\n";
    std::string FIO;
    getchar();
    std::cout << "������� �.�.�: ";
    std::getline(std::cin, FIO);
    Contact& res = myContacts->SearchByFIO(FIO);
	if (res.number == "" && res.FIO == "")
	{
		std::cout << "������� �� ������!";
		Waiting();
	}
    else
        std::cout << "������� ������: " << res.ToString();
    std::cout << "������� ����� ������:\n";
    std::string dataStr;
    std::cout << "������� �.�.�: ";
    std::getline(std::cin, res.FIO);
    std::cout << "������� �����: ";
    std::getline(std::cin,res.number);
    std::cout << "������� ���� ��������: ";
    std::getline(std::cin, dataStr);
    res.burthday = Data::ParseData(dataStr);
    std::cout << "��������!\n";
    Waiting();
}

void MainMenu::SearcheByNumber()
{
    printHead();
    std::cout << "����� ��������\n\n";
	std::string number;
	getchar();
    std::cout << "������� �����: ";
    std::getline(std::cin , number);
    Contact res = myContacts->SearchByNumber(number);
    if (res.number == "" && res.FIO == "")
        std::cout << "������� �� ������!";
    else
        std::cout << "������� ������: " << res.ToString();
    Waiting();
}

void MainMenu::GetContactsWhenFirstChar()
{
    printHead();
    std::cout << "����� ���������\n\n";
    char ch;
    getchar();
    std::cout << "������� ������ �����: ";
    std::cin >> ch;
    std::vector<Contact> res = myContacts->Search(ch);
    if (res.size() == 0)
        std::cout << "�������� �� ������!";
    else {
        std::cout << "������� "<<res.size()<<" ���������: ";
        for (int i = 0; i < res.size(); i++)
        {
            std::cout << res[i].ToString() << "\n";
        }
    }
    getchar();
    Waiting();
}

void MainMenu::GetContactsCount()
{
    printHead();
    std::cout << "����� ��������� � ����: " << myContacts->GetNumberContacts()<<"\n";
	getchar();
	Waiting();
}

void MainMenu::AddContactToElectListByFIO()
{
    printHead();
    getchar();
    std::cout << "���������� �������� � ��������\n\n";
    std::string FIO;
    std::cout << "������� �.�.�: ";
    std::getline(std::cin, FIO);
    Contact res = myContacts->SearchByFIO(FIO);
    if (res.number == "" && res.FIO == "")
        std::cout << "������� �� ������!";
    else {
        std::cout << "������� ������: " << res.ToString();
        myContacts->AddElect(FIO);
        std::cout << "\n�������� � ��������!\n";
    }
    Waiting();
}

void MainMenu::RemoveContactFromElectListByFIO()
{
    printHead();
    getchar();
    std::cout << "�������� �������� �� ��������\n\n";
    std::string FIO;
    std::cout << "������� �.�.�: ";
    std::getline(std::cin, FIO);
    Contact res = myContacts->SearchByFIO(FIO);
    if (res.number == "" && res.FIO == "")
        std::cout << "������� �� ������!";
    else {
        std::cout << "������� ������: " << res.ToString();
        myContacts->RemoveFromElect(FIO);
        std::cout << "\n������ �� ��������!\n";
    }
    Waiting();
}

void MainMenu::GetElectContacts()
{
    printHead();
    std::cout << "������ ��������� ���������\n\n";
    std::vector<Contact> res = myContacts->ShowElect();
    if (res.size() == 0)
        std::cout << "��� �������� ���������!";
    else {
        std::cout << "����� " << res.size() << " �������� ���������: ";
        for (int i = 0; i < res.size(); i++)
        {
            std::cout << res[i].ToString() << "\n";
        }
    }
    Waiting();
}

void MainMenu::RemoveContactByNumber()
{
    printHead();
    std::cout << "�������� ��������\n\n";
	std::string number;
    std::cout << "������� �����: ";
	getchar();
    std::getline(std::cin, number);
    myContacts->RemoveContact(number);
    std::cout << "\n������� ������!\n";
    Waiting();
}

void MainMenu::SaveContactsToFile()
{
    printHead();
    std::cout << "���������� � ����\n\n";
    std::string Path;
    getchar();
    std::cout << "������� ����: ";
    std::getline(std::cin, Path);
    myContacts->RecordFile(Path);
    std::cout << "��������� " + Path;
    Waiting();
}

void MainMenu::ReadContactsFromFile()
{
    printHead();
    getchar();
    std::cout << "������ ��������� �� �����\n\n";
    std::string Path;
    std::cout << "������� ����: ";
    std::getline(std::cin, Path);
    myContacts->ReadFile(Path);
    std::cout << "���������� " << myContacts->GetNumberContacts() << " ���������";
    Waiting();
}
