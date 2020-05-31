#pragma once
#include <string>
#include <vector>
#include <fstream>
typedef unsigned int uint;
typedef long long ll;
class Date
{
public:
	Date(uint day = 0, uint month = 0, uint year = 0);
	Date(const Date&);
	~Date();

	void		SetDay(uint);
	void		SetMonth(uint);
	void		SetYear(uint);
	uint		GetDay() const;
	uint		GetMonth() const;
	uint		GetYear() const;

	Date&		operator=(const Date&);

	friend std::istream& operator>>(std::istream&, Date&);
	friend std::ostream& operator<<(std::ostream&, const Date&);
protected:
	uint day;
	uint month;
	uint year;
};

//--------------------------------------------------------------------------------
class Human
{
public:
	Human(const std::string& first_name = std::string(),
		  const std::string& second_name = std::string(),
		  const std::string& last_name = std::string(),
		  const Date& brth = Date());
	Human(const Human&);
	~Human();

	void		SetFName(const std::string& first_name);
	void		SetSName(const std::string& second_name);
	void		SetLName(const std::string& last_name);
	void		SetBrth(const Date&);
	std::string GetFName() const;
	std::string GetSName() const;
	std::string GetLName() const;
	Date		GetBrth() const;

	Human&		operator=(const Human&);

	friend std::istream& operator>>(std::istream&, Human&);
	friend std::ostream& operator<<(std::ostream&, const Human&);
protected:
	std::string first_name;
	std::string second_name;
	std::string last_name;
	Date		brth;
};

//----------------------------------------------------------------------------------
class Contact : public Human
{
public:
	Contact(const std::string& first_name = std::string(),
			const std::string& second_name = std::string(),
			const std::string& last_name = std::string(),
			const Date& brth = Date(),
			const ll& phone = 0);
	Contact(const Contact&);
	~Contact();

	void		SetPhone(const ll&);
	ll			GetPhone() const;

	Contact&	operator=(const Contact&);

	friend std::istream& operator>>(std::istream&, Contact&);
	friend std::ostream& operator<<(std::ostream&, const Contact&);
protected:
	ll phone;
};

//---------------------------------------------------------------------------------
class Contacts
{
public:
	Contacts();
	Contacts(const Contacts&);
	~Contacts();

	void		Save(const std::string& path = "Contacts.txt");
	void		Read(const std::string& path = "Contacts.txt");
	void		Append(const Contact&);
	Contact		Find(const std::string& first_name, const std::string& second_name, const std::string& last_name);
	void		Change(const std::string& first_name, const std::string& second_name, const std::string& last_name, const Contact& new_contact);
	Contact		Find(const ll& phone);
	std::vector<Contact> FirstSymbol(char c);
	size_t		Size();
	void		AppendToFavorites(const std::string& first_name, const std::string& second_name, const std::string& last_name);
	void		DeleteFromFavorites(const std::string& first_name, const std::string& second_name, const std::string& last_name);
	std::vector<Contact*> GetFavorites();
	void		Delete(const ll& phone);
protected:
	std::vector<Contact> contacts;
	std::vector<Contact*> favorites;
};

