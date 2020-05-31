#include "Contacts.h"

Date::Date(uint day, uint month, uint year) : day(day), month(month), year(year) {}
Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}
Date::~Date() {}

void		Date::SetDay(uint day) { this->day = day; }
void		Date::SetMonth(uint month) { this->month = month; }
void		Date::SetYear(uint year) { this->year = year; }
uint		Date::GetDay() const { return day; }
uint		Date::GetMonth() const { return month; }
uint		Date::GetYear() const { return year; }

Date&		Date::operator=(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	return *this;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	char c;
	in >> date.day >> c >> date.month >> c >> date.year;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.day << "." << date.month << "." << date.year;
	return out;
}

//--------------------------------------------------------------------------------
Human::Human(const std::string& first_name,
	const std::string& second_name,
	const std::string& last_name,
	const Date& brth) : first_name(first_name), second_name(second_name), last_name(last_name), brth(brth) {}
Human::Human(const Human& other) : first_name(other.first_name), second_name(other.second_name), last_name(other.last_name), brth(other.brth) {}
Human::~Human() {}

void		Human::SetFName(const std::string& first_name) { this->first_name = first_name; }
void		Human::SetSName(const std::string& second_name) { this->second_name = second_name; }
void		Human::SetLName(const std::string& last_name) { this->last_name = last_name; }
void		Human::SetBrth(const Date& brth) { this->brth = brth; }
std::string Human::GetFName() const { return first_name; }
std::string Human::GetSName() const { return second_name; }
std::string Human::GetLName() const { return last_name; }
Date		Human::GetBrth() const { return brth; }

Human&		Human::operator=(const Human& other)
{
	this->first_name = other.first_name;
	this->second_name = other.second_name;
	this->last_name = other.last_name;
	this->brth = other.brth;
	return *this;
}

std::istream& operator>>(std::istream& in, Human& human)
{
	in >> human.first_name >> human.second_name >> human.last_name >> human.brth;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Human& human)
{
	out << human.first_name << " " << human.second_name << " " << human.last_name << " " << human.brth;
	return out;
}

//----------------------------------------------------------------------------------------------------
Contact::Contact(const std::string& first_name,
	const std::string& second_name,
	const std::string& last_name,
	const Date& brth,
	const ll& phone) : Human(first_name, second_name, last_name, brth), phone(phone) {}
Contact::Contact(const Contact& other) : Human(other.first_name, other.second_name, other.last_name, other.brth), phone(other.phone) {}
Contact::~Contact() {}

void		Contact::SetPhone(const ll& phone) { this->phone = phone; }
ll			Contact::GetPhone() const { return phone; }

Contact&	Contact::operator=(const Contact& other)
{
	this->first_name = other.first_name;
	this->second_name = other.second_name;
	this->last_name = other.last_name;
	this->brth = other.brth;
	this->phone = other.phone;
	return *this;
}

std::istream& operator>>(std::istream& in, Contact& contact)
{
	in >> contact.first_name >> contact.second_name >> contact.last_name >> contact.brth >> contact.phone;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Contact& contact)
{
	out << contact.first_name << " " << contact.second_name << " " << contact.last_name << " " << contact.brth << " " << contact.phone;
	return out;
}

//---------------------------------------------------------------------------------------------------------
Contacts::Contacts() {}
Contacts::Contacts(const Contacts& other)
{
	for (auto contact : other.contacts)
		this->contacts.push_back(contact);
	for (auto contact : other.favorites)
		this->favorites.push_back(contact);
}
Contacts::~Contacts() {}

void		Contacts::Save(const std::string& path)
{
	std::fstream file;
	file.open(path, std::fstream::out);
	if (file.is_open())
		for (auto contact : contacts)
			file << contact << std::endl;
	file.close();
}
void		Contacts::Read(const std::string& path)
{
	std::fstream file;
	file.open(path, std::fstream::in);
	if (file.is_open())
	{
		contacts.clear(); favorites.clear();
		while (!file.eof())
		{
			Contact contact;
			file >> contact;
			contacts.push_back(contact);
		}
		contacts.pop_back();
	}
	file.close();
}
void		Contacts::Append(const Contact& contact) { contacts.push_back(contact); }
Contact		Contacts::Find(const std::string& first_name, const std::string& second_name, const std::string& last_name)
{
	for (auto contact : contacts)
		if (contact.GetFName() == first_name && contact.GetSName() == second_name && contact.GetLName() == last_name)
			return contact;
	throw std::exception("Контакта с таким ФИО в списке нет");
}
void		Contacts::Change(const std::string& first_name, const std::string& second_name, const std::string& last_name, const Contact& new_contact)
{
	for (std::vector<Contact>::iterator i = contacts.begin(); i < contacts.end(); i++)
		if (i->GetFName() == first_name && i->GetSName() == second_name && i->GetLName() == last_name)
		{
			*i = new_contact;
			return;
		}
	throw std::exception("Контакта с таким ФИО в списке нет");
}
Contact		Contacts::Find(const ll& phone)
{
	for (auto contact : contacts)
		if (contact.GetPhone() == phone)
			return contact;
	throw std::exception("Контакта с таким ФИО в списке нет");
}
std::vector<Contact> Contacts::FirstSymbol(char c)
{
	std::vector<Contact> res;
	for (auto contact : contacts)
		if (contact.GetLName()[0] == c)
			res.push_back(contact);
	return res;
}
size_t		Contacts::Size() { return contacts.size(); }
void		Contacts::AppendToFavorites(const std::string& first_name, const std::string& second_name, const std::string& last_name)
{
	for (std::vector<Contact>::iterator i = contacts.begin(); i < contacts.end(); i++)
		if (i->GetFName() == first_name && i->GetSName() == second_name && i->GetLName() == last_name)
			favorites.push_back(&(*i));
}
void		Contacts::DeleteFromFavorites(const std::string& first_name, const std::string& second_name, const std::string& last_name)
{
	for (std::vector<Contact*>::iterator i = favorites.begin(); i < favorites.end(); i++)
		if ((*i)->GetFName() == first_name && (*i)->GetSName() == second_name && (*i)->GetLName() == last_name)
			favorites.erase(i);
}
std::vector<Contact*> Contacts::GetFavorites() { return favorites; }
void		Contacts::Delete(const ll& phone)
{
	for (std::vector<Contact>::iterator i = contacts.begin(); i < contacts.end(); i++)
		if (i->GetPhone() == phone)
			contacts.erase(i);
}