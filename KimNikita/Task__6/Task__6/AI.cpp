#include "AI.h"

Shot AI::RandomShot(GameField& field, int& rez)
{
	int k = rand() % AbleShots.size();
	Shot shot(AbleShots[k].X, AbleShots[k].Y);
	AbleShots.erase(AbleShots.begin() + k);
	rez = field.ShotResult(shot, 1);
	if (rez == 1)
	{
		AddSmartShots(field, shot);
	}
	if (rez == 2)
	{
		Refresh(field);
	}
	return shot;
}
Shot AI::SmartShot(GameField& field, int& rez)
{
	int k = rand() % SmartShots.size();
	Shot shot(SmartShots[k].X, SmartShots[k].Y);
	SmartShots.erase(SmartShots.begin() + k);
	rez = field.ShotResult(shot, 1);
	if (rez == 1)
	{
		AddSmartShots(field, shot);
	}
	if (rez == 2)
	{
		SmartShots.clear();
		Refresh(field);
	}
	return shot;
}
void AI::Refresh(GameField field)
{
	AbleShots.clear();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field.UserField[i][j] == 1 || field.UserField[i][j] == -1)
				AbleShots.push_back(Shot(i, j));
		}
	}
}
AI::AI(GameField field)
{
	Refresh(field);
}
Shot AI::AIShot(GameField& field, int& rez)
{
	if (SmartShots.size() != 0)
		return SmartShot(field, rez);
	return RandomShot(field, rez);
}
void AI::AddSmartShots(GameField& field, Shot shot)
{
	if (shot.X + 1 < 10)
		if (field.UserField[shot.Y][shot.X + 1] != 0)
			if (field.UserField[shot.Y][shot.X + 1] == 2)
			{
				SmartShots.clear();
				if (shot.X - 1 > -1)
					SmartShots.push_back(Shot(shot.X - 1, shot.Y));
				int k = shot.X + 1;
				while (k < 10 && field.UserField[shot.Y][k] == 2)
					k++;
				if (k < 10)
					SmartShots.push_back(Shot(k, shot.Y));
			}
			else
			{
				SmartShots.push_back(Shot(shot.X + 1, shot.Y));
			}
	if (shot.X - 1 > -1)
		if (field.UserField[shot.Y][shot.X - 1] != 0)
			if (field.UserField[shot.Y][shot.X - 1] == 2)
			{
				SmartShots.clear();
				if (shot.X + 1 < 10)
					SmartShots.push_back(Shot(shot.X + 1, shot.Y));
				int k = shot.X - 1;
				while (k > -1 && field.UserField[shot.Y][k] == 2)
					k--;
				if (k > -1)
					SmartShots.push_back(Shot(k, shot.Y));
			}
			else
			{
				SmartShots.push_back(Shot(shot.X - 1, shot.Y));
			}
	if (shot.Y + 1 < 10)
		if (field.UserField[shot.Y + 1][shot.X] != 0)
			if (field.UserField[shot.Y + 1][shot.X] == 2)
			{
				SmartShots.clear();
				if (shot.Y - 1 > -1)
					SmartShots.push_back(Shot(shot.X, shot.Y - 1));
				int k = shot.Y + 1;
				while (k < 10 && field.UserField[k][shot.X] == 2)
					k++;
				if (k < 10)
					SmartShots.push_back(Shot(shot.X, k));
			}
			else
			{
				SmartShots.push_back(Shot(shot.X, shot.Y + 1));
			}
	if (shot.Y - 1 > -1)
		if (field.UserField[shot.Y - 1][shot.X] != 0)
			if (field.UserField[shot.Y - 1][shot.X] == 2)
			{
				SmartShots.clear();
				if (shot.Y + 1 < 10)
					SmartShots.push_back(Shot(shot.X, shot.Y + 1));
				int k = shot.Y - 1;
				while (k > -1 && field.UserField[k][shot.X] == 2)
					k--;
				if (k > -1)
					SmartShots.push_back(Shot(shot.X, k));
			}
			else
			{
				SmartShots.push_back(Shot(shot.X, shot.Y - 1));
			}
}