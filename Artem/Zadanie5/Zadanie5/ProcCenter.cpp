#include"ProcCenter.h"

ProcCenter::ProcCenter()
{
	card = "null";
	password = "null";
	client = "noname";
	money = 0;
	wrong = false;
}

ProcCenter::~ProcCenter()
{
	card = "null";
	password = "null";
	client = "noname";
	money = 0;
	wrong = false;
}

ProcCenter::ProcCenter(string _card, string _password, string _client, int _money)
{
	this->card = _card;
	this->password = _password;
	this->client = _client;
	this->money = _money;
}

ProcCenter::ProcCenter(const ProcCenter& proc)
{
	card = proc.card;
	password = proc.password;
	client = proc.client;
	money = proc.money;
	wrong = proc.wrong;
}

void ProcCenter::SetCard(string s)
{
	this->card = s;
}

void ProcCenter::SetPassword(string s)
{
	this->password = s;

}

void ProcCenter::SetClient(string s)
{
	this->client = s;
}

void ProcCenter::SetMoney(int m)
{
	this->money = m;
}

void ProcCenter::SetWrong(bool b)
{
	wrong = b;
}

string ProcCenter::GetCard()
{
	return this->card;
}

string ProcCenter::GetPassword()
{
	return this->password;
}

string ProcCenter::GetClient()
{
	return this->client;
}

int ProcCenter::GetMoney()
{
	return this->money;
}

bool ProcCenter::GetWrong()
{
	return wrong;
}

ProcCenter& ProcCenter::operator=(ProcCenter& proc)
{
	card = proc.card;
	password = proc.password;
	client = proc.client;
	money = proc.money;
	wrong = proc.wrong;

	return *this;
}