#include "Contacts.h"
#include <iostream>
#include <windows.h>

void FullName(std::string& first_name, std::string& second_name, std::string& last_name);
void Change(Contact& contact);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Contacts contacts;
	Contact contact;
	ll phone;
	std::string first_name, second_name, last_name;
	std::vector<Contact> res;
	std::vector<Contact*> favorites;
	char c;
	int variable;
	do
	{
		system("cls");
		std::cout << "1) ��������� � ����"						<< std::endl;
		std::cout << "2) ������� �� �����"						<< std::endl;
		std::cout << "3) ������� ����� �������"					<< std::endl;
		std::cout << "4) ����� ������� �� ���"					<< std::endl;
		std::cout << "5) �������� ������� �� ���"				<< std::endl;
		std::cout << "6) ����� ������� �� ��������"				<< std::endl;
		std::cout << "7) ������ �������� �� ���. ����� �������"	<< std::endl;
		std::cout << "8) ������ ����� ���������"				<< std::endl;
		std::cout << "9) ������ � ������ ���������� �� ���"		<< std::endl;
		std::cout << "10) ������� �� ���������� �� ���"			<< std::endl;
		std::cout << "11) ������ ��������� ��������"			<< std::endl;
		std::cout << "12) ������� �� ������ �� ��������"		<< std::endl;
		std::cout << "13) �����"								<< std::endl;
		std::cin >> variable;
		try
		{
			switch (variable)
			{
			case 1:
				contacts.Save();
				break;
			case 2:
				contacts.Read();
				break;
			case 3:
				std::cout << "������� ������� <��� �������� ������� ��.��.���� �������>" << std::endl;
				std::cin >> contact;
				contacts.Append(contact);
				break;
			case 4:
				FullName(first_name, second_name, last_name);
				std::cout << contacts.Find(first_name, second_name, last_name) << std::endl;
				system("pause");
				break;
			case 5:
				FullName(first_name, second_name, last_name);
				contact = contacts.Find(first_name, second_name, last_name);
				Change(contact);
				contacts.Change(first_name, second_name, last_name, contact);
				break;
			case 6:
				std::cout << "������� �������: ";
				std::cin >> phone;
				std::cout << contacts.Find(phone) << std::endl;
				system("pause");
				break;
			case 7:
				std::cout << "������� ������: ";
				std::cin >> c;
				res = contacts.FirstSymbol(c);
				for (auto tmp : res)
					std::cout << tmp << std::endl;
				system("pause");
				break;
			case 8:
				std::cout << contacts.Size() << std::endl;
				system("pause");
				break;
			case 9:
				FullName(first_name, second_name, last_name);
				contacts.AppendToFavorites(first_name, second_name, last_name);
				break;
			case 10:
				FullName(first_name, second_name, last_name);
				contacts.DeleteFromFavorites(first_name, second_name, last_name);
				break;
			case 11:
				favorites = contacts.GetFavorites();
				for (auto pcontact : favorites)
					std::cout << *pcontact << std::endl;
				system("pause");
				break;
			case 12:
				std::cout << "������� �������: ";
				std::cin >> phone;
				contacts.Delete(phone);
				break;
			}
		}
		catch (std::exception ex) { std::cerr << ex.what() << std::endl; system("pause"); }
	} while (variable != 13);
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	return 0;
}

void FullName(std::string& first_name, std::string& second_name, std::string& last_name)
{
	std::cout << "������� ���: ";
	std::cin >> first_name;
	std::cout << "������� ��������: ";
	std::cin >> second_name;
	std::cout << "������� �������: ";
	std::cin >> last_name;
}

void Change(Contact& contact)
{
	int variable;
	std::string name;
	Date date;
	ll phone;
	std::cout << "��� ���������� ��������?" << std::endl;
	std::cout << "1) ���"					<< std::endl;
	std::cout << "2) ��������"				<< std::endl;
	std::cout << "3) �������"				<< std::endl;
	std::cout << "4) ���� ��������"			<< std::endl;
	std::cout << "5) �������"				<< std::endl;
	std::cin >> variable;
	switch (variable)
	{
	case 1:
		std::cout << "������� ���: ";
		std::cin >> name;
		contact.SetFName(name);
		break;
	case 2:
		std::cout << "������� ��������: ";
		std::cin >> name;
		contact.SetSName(name);
		break;
	case 3:
		std::cout << "������� �������: ";
		std::cin >> name;
		contact.SetLName(name);
		break;
	case 4:
		std::cout << "������� ���� <dd.mm.yyyy>: ";
		std::cin >> date;
		contact.SetBrth(date);
		break;
	case 5:
		std::cout << "������� �������: ";
		std::cin >> phone;
		contact.SetPhone(phone);
		break;
	}
}