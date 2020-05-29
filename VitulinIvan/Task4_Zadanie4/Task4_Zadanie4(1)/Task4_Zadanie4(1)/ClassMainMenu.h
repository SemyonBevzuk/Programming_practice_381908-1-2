#pragma once
class MainMenu {
public:
	MainMenu();
	void Start();
private:

	void MenuHandler();
	int Menu();

	void printHead();
	void PrintMainMenu();
	void IncorrectAnswer();
	void Waiting();

	void AddContact();
	void SearcheByFIO();
	void ChangeByFIO();
	void SearcheByNumber();
	void GetContactsWhenFirstChar();
	void GetContactsCount();
	void AddContactToElectListByFIO();
	void RemoveContactFromElectListByFIO();
	void GetElectContacts();
	void RemoveContactByNumber();
	void SaveContactsToFile();
	void ReadContactsFromFile();

	Contacts* myContacts;
};