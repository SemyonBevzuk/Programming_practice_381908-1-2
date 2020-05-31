#include "Passenger.h"
using namespace std;

Passenger::Passenger(const string surname, const string name, const string patronymic)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
}

Passenger::Passenger(const Passenger& passenger)
{
	*this = passenger;
}

Passenger& Passenger::operator=(const Passenger& passenger)
{
	surname = passenger.surname;
	name = passenger.name;
	patronymic = passenger.patronymic;
	date = passenger.date;
	depTime = passenger.depTime;
	arrTime = passenger.arrTime;
	train = passenger.train;
	typeCar = passenger.typeCar;
	carriage = passenger.carriage;
	seat = passenger.seat;
	departure = passenger.departure;
	arrival = passenger.arrival;
	return *this;
}

bool Passenger::operator==(const Passenger& passenger)
{
	if (surname == passenger.surname && name == passenger.name && patronymic == passenger.patronymic
		&& depTime == passenger.depTime && arrTime == passenger.arrTime && date == passenger.date
		&& train == passenger.train && typeCar == passenger.typeCar && carriage == passenger.carriage
		&& seat == passenger.seat && departure == passenger.departure && arrival == passenger.arrival)
		return true;
	return false;
}

void Passenger::newSeatInfo(const int train, const string depTime, const string arrTime, const int carriage,
	const int typeCar, const int seat, const string departure, const string arrival, const string date)
{
	this->train = train;
	this->depTime = depTime;
	this->arrTime = arrTime;
	this->carriage = carriage;
	this->typeCar = typeCar;
	this->seat = seat;
	this->departure = departure;
	this->arrival = arrival;
	this->date = date;
}

istream& operator>>(istream& stream, Passenger& passenger)
{
	cout << "Фамилия: ";
	stream >> passenger.surname;
	cout << "Имя: ";
	stream >> passenger.name;
	cout << "Отчество: ";
	stream >> passenger.patronymic;

	return stream;
}

ostream& operator<<(ostream& stream, const Passenger& passenger)
{
	stream << "ФИО: " << passenger.surname << ' ' << passenger.name << ' ' << passenger.patronymic << '\n';
	stream << "Рейс: " << passenger.departure << " - " << passenger.arrival << '\n';
	stream << "Дата отправления: " << passenger.date << '\n';
	stream << "Время отправления: " << passenger.depTime << '\n';
	stream << "Время прибытия: " << passenger.arrTime << '\n';
	stream << "Поезд номер: " << passenger.train << '\n';
	stream << "Вагон: " << passenger.carriage << '\n';
	stream << "Место: " << passenger.seat;
	if (passenger.typeCar == 0)
		stream << " нижнее\n";
	else
		stream << "Верхнее\n";
	return stream;
}

