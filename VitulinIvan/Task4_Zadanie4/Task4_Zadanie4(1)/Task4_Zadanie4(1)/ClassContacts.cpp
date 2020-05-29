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
	throw exception("Контакты не найдены");
}

Contact& Contacts::SearchByNumber(string number)
{
	for (int i = 0; i < MyContacts.size(); i++)
	{
		if (number == MyContacts[i].number)
			return MyContacts[i];
	}
	
	throw exception("Контакты не найдены");
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
    res += "\n" + FIO + "\nТелефон: " + number + "\nДата рождения: " + Data::ToString(burthday) + "\n";
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
	cout << "\t -----ТЕЛЕФОННАЯ КНИГА----\t\tВсего контактов: "<< myContacts->GetNumberContacts() <<"\n\n";
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
		"\tГлавное меню:\n" <<
		"1-Создать новый контакт\n" <<
		"2-Найти контакт по ФИО\n" <<
		"3-Изменить контакт по ФИО\n" <<
		"4-Найти контакт по телефону\n" <<
		"5-Выдать все контакты, заданные по начальной букве ФИО\n" <<
		"6-Узнать текущее число контаков\n" <<
		"7-Внести контакт в избранные по ФИО\n" <<
		"8-Удалить контакт из избранных по ФИО\n" <<
		"9-Выдать все избранные контакты\n" <<
		"10-Удалить контакт, выбранный по телефону\n" <<
        "11-Сохранить контакты в файл\n"<<
        "12-Загрузить контакты из файла\n"<<
		"13-Завершение работы\n"
		"\nВыбор опции: ";
}

void MainMenu::IncorrectAnswer()
{
	printHead();
	cout << "\nОшибка: неверная опция";
	Waiting();
}

void MainMenu::Waiting()
{
	cout << "\nНажмите любую клавишу для продолжения...";
	getchar();
	getchar();
}


void MainMenu::AddContact()
{
    printHead();
    cout << "Добавление контакта\n\n";
    string FIO, dataStr;
	string number;
	getchar();
    cout << "Введите Ф.И.О: ";
    getline(cin, FIO);
    cout << "Введите номер: ";
    getline(cin,number);
    cout << "Введите дату рождения: ";
    getline(cin, dataStr);
    myContacts->AddContact(*(new Contact(FIO, number, Data::ParseData(dataStr))));
    cout << "Контакт добавлен успешно!\n";
    Waiting();
}

void MainMenu::SearcheByFIO()
{
	Contact res;
	printHead();
    cout << "Поиск контакта\n\n";
    string FIO;
    getchar();
    cout << "Введите Ф.И.О: ";
    getline(cin, FIO);
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByFIO(FIO);
	}
	catch(exception)
	{
		cout << "Контакт не найден!";
		FoundContact = false;
	}
	
	if (FoundContact) 
		cout << "Контакт найден: " << res.ToString();
    Waiting();
}

void MainMenu::ChangeByFIO()
{
	Contact res;
	printHead();
    cout << "Изменение контакта\n\n";
    string FIO;
    getchar();
    cout << "Введите Ф.И.О: ";
    getline(cin, FIO);
	
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByFIO(FIO);
	}
	catch (exception)
	{
		cout << "Контакт не найден!";
		FoundContact = false;
		Waiting();
	}
	if (FoundContact)
	{
		cout << "Контакт найден: " << res.ToString();
		cout << "Введите новые данные:\n";
		string dataStr;
		cout << "Введите Ф.И.О: ";
		getline(cin, res.FIO);
		cout << "Введите номер: ";
		getline(cin, res.number);
		cout << "Введите дату рождения: ";
		getline(cin, dataStr);
		res.burthday = Data::ParseData(dataStr);
		cout << "Изменено!\n";
		Waiting();
	}
}

void MainMenu::SearcheByNumber()
{
	Contact res;
	printHead();
    cout << "Поиск контакта\n\n";
	string number;
	getchar();
    cout << "Введите номер: ";
    getline(cin , number);
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByNumber(number);
	}
	catch (exception)
	{
		cout << "Контакт не найден!";
		FoundContact = false;
		Waiting();
	}

	if (FoundContact)
	{
		cout << "Контакт найден: " << res.ToString();
		Waiting();
	}
	
}

void MainMenu::GetContactsWhenFirstChar()
{
    printHead();
    cout << "Поиск контактов\n\n";
    char ch;
    getchar();
    cout << "Введите первую букву: ";
    cin >> ch;
    vector<Contact> res = myContacts->SearchBySymbol(ch);
    if (res.size() == 0)
        cout << "Контакты не найден!";
    else {
        cout << "Найдено "<<res.size()<<" контактов: ";
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
    cout << "Всего контактов в базе: " << myContacts->GetNumberContacts()<<"\n";
	getchar();
	Waiting();
}

void MainMenu::AddContactToElectListByFIO()
{
	Contact res;
	printHead();
    getchar();
    cout << "Добавление контакта в избраные\n\n";
    string FIO;
    cout << "Введите Ф.И.О: ";
    getline(cin, FIO);
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByFIO(FIO);
	}
	catch (exception)
	{
		cout << "Контакт не найден!";
		FoundContact = false;
		Waiting();
	}

	if (FoundContact)
	{
		cout << "Контакт найден: " << res.ToString();
		myContacts->AddElect(FIO);
		cout << "\nДобавлен в избраные!\n";
		Waiting();
	}
}

void MainMenu::RemoveContactFromElectListByFIO()
{
	Contact res;
	printHead();
    getchar();
    cout << "Удаление контакта из избраных\n\n";
    string FIO;
    cout << "Введите Ф.И.О: ";
    getline(cin, FIO);
	bool FoundContact = true;
	try
	{
		res = myContacts->SearchByFIO(FIO);;
	}
	catch (exception)
	{
		cout << "Контакт не найден!";
		FoundContact = false;
		Waiting();
	}

	if (FoundContact)
	{
		cout << "Контакт найден: " << res.ToString();
		myContacts->RemoveFromElect(FIO);
		cout << "\nУдален из избраных!\n";
		Waiting();
	}
}

void MainMenu::GetElectContacts()
{
    printHead();
    cout << "Список избранных контактов\n\n";
    vector<Contact> res = myContacts->ShowElect();
    if (res.size() == 0)
        cout << "Нет избраных контактов!";
    else {
        cout << "Всего " << res.size() << " избраных контактов: ";
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
    cout << "Удаление контакта\n\n";
	string number;
    cout << "Введите номер: ";
	getchar();
    getline(cin, number);
    myContacts->RemoveContact(number);
    cout << "\nКонтакт удален!\n";
    Waiting();
}

void MainMenu::SaveContactsToFile()
{
    printHead();
    cout << "Сохранение в файл\n\n";
    string Path;
    getchar();
    cout << "Укажите путь: ";
    getline(cin, Path);
    myContacts->RecordFile(Path);
    cout << "Записанно " + Path;
    Waiting();
}

void MainMenu::ReadContactsFromFile()
{
    printHead();
    getchar();
    cout << "Чтение контактов из файла\n\n";
    string Path;
    cout << "Укажите путь: ";
    getline(cin, Path);
    myContacts->ReadFile(Path);
    cout << "Прочитанно " << myContacts->GetNumberContacts() << " контактов";
    Waiting();
}
