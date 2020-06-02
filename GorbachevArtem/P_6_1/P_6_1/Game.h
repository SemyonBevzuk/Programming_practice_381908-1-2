#pragma once
#include <string>
using namespace std;

class Game
{
private:
	string number;
	int cows;
	int bulls;
public:
	Game() {};
	~Game() {};
	void GenerateNumber(int n);
	bool VerifyNumber(string _number);
	int GetCows() { return cows; };
	int GetBulls() { return bulls; };
};