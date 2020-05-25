#pragma once

#include "GameField.h"
#include "Shot.h"

class AI
{
private:
	vector<Shot> AbleShots;
	vector<Shot> SmartShots;
	Shot RandomShot(GameField& field, int& rez);// 1 ����� -1 ������ 2 ����
	Shot SmartShot(GameField& field, int& rez);// 1 ����� -1 ������ 2 ����
	void Refresh(GameField field);
	void AddSmartShots(GameField& field, Shot shot);
public:
	AI() {};
	AI(GameField field);
	Shot AIShot(GameField& field, int& rez);
};

