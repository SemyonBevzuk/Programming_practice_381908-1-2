#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Bulls_Cows
{
	int* number;
	int length;

public:
	Bulls_Cows();
	~Bulls_Cows();
	bool newNumber(const int length = 4);
	bool checkCorrect(const string num);
	bool checkBullCow(string num, int& cow, int& bull);
};


