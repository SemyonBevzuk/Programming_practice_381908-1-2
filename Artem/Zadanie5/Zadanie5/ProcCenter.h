#pragma once
#include<iostream>
#include<string>

using namespace std;

class ProcCenter
{
private:
	string card;
	string password;
	string client;
	int money;
	bool wrong;
public:
	ProcCenter();
	ProcCenter(string _card, string _password, string _client, int _money);
	ProcCenter(const ProcCenter& proc);
	~ProcCenter();

	string GetCard();
	string GetPassword();
	string GetClient();
	int GetMoney();
	bool GetWrong();

	void SetCard(string _card);
	void SetPassword(string _password);
	void SetClient(string _client);
	void SetMoney(int _money);
	void SetWrong(bool _wrong);

	ProcCenter& operator=(ProcCenter& proc);
};