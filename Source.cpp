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
		std::cout << "1) Сохранить в файл"						<< std::endl;
		std::cout << "2) Считать из файла"						<< std::endl;
		std::cout << "3) Создать новый контакт"					<< std::endl;
		std::cout << "4) Найти контакт по ФИО"					<< std::endl;
		std::cout << "5) Изменить контакт по ФИО"				<< std::endl;
		std::cout << "6) Найти контакт по телефону"				<< std::endl;
		std::cout << "7) Выдать контакты на нач. букву фамилии"	<< std::endl;
		std::cout << "8) Узнать число контактов"				<< std::endl;
		std::cout << "9) Внести в список избранного по ФИО"		<< std::endl;
		std::cout << "10) Удалить из избранного по ФИО"			<< std::endl;
		std::cout << "11) Выдать избранные контакты"			<< std::endl;
		std::cout << "12) Удалить из списка по телефону"		<< std::endl;
		std::cout << "13) Выход"								<< std::endl;
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
				std::cout << "Введите контакт <Имя Отчество Фамилия дд.мм.гггг телефон>" << std::endl;
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
				std::cout << "Введите телефон: ";
				std::cin >> phone;
				std::cout << contacts.Find(phone) << std::endl;
				system("pause");
				break;
			case 7:
				std::cout << "Введите символ: ";
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
				std::cout << "Введите телефон: ";
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
	std::cout << "Введите Имя: ";
	std::cin >> first_name;
	std::cout << "Введите Отчество: ";
	std::cin >> second_name;
	std::cout << "Введите Фамилию: ";
	std::cin >> last_name;
}

void Change(Contact& contact)
{
	int variable;
	std::string name;
	Date date;
	ll phone;
	std::cout << "Что необходимо изменить?" << std::endl;
	std::cout << "1) Имя"					<< std::endl;
	std::cout << "2) Отчество"				<< std::endl;
	std::cout << "3) Фамилию"				<< std::endl;
	std::cout << "4) Дату рождения"			<< std::endl;
	std::cout << "5) Телефон"				<< std::endl;
	std::cin >> variable;
	switch (variable)
	{
	case 1:
		std::cout << "Введите Имя: ";
		std::cin >> name;
		contact.SetFName(name);
		break;
	case 2:
		std::cout << "Введите Отчество: ";
		std::cin >> name;
		contact.SetSName(name);
		break;
	case 3:
		std::cout << "Введите Фамилию: ";
		std::cin >> name;
		contact.SetLName(name);
		break;
	case 4:
		std::cout << "Введите дату <dd.mm.yyyy>: ";
		std::cin >> date;
		contact.SetBrth(date);
		break;
	case 5:
		std::cout << "Введите телефон: ";
		std::cin >> phone;
		contact.SetPhone(phone);
		break;
	}
}