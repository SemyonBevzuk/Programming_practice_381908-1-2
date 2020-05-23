#include "GameField.h"
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>

bool GameField::TryToDestroyShip(int x, int y, int side)
{
	set<pair<int, int>> miss;
	vector<pair<int, int>> death;
	queue<pair<int, int>> decks;
	decks.push(make_pair(x, y));
	while (!decks.empty())
	{
		if ((decks.front().second - 1) > -1 && (decks.front().first + 1) < 10)
			miss.insert(make_pair(decks.front().first + 1, decks.front().second - 1));
		if ((decks.front().second - 1) > -1 && (decks.front().first - 1) > -1)
			miss.insert(make_pair(decks.front().first - 1, decks.front().second - 1));
		if ((decks.front().second + 1) < 10 && (decks.front().first + 1) < 10)
			miss.insert(make_pair(decks.front().first + 1, decks.front().second + 1));
		if ((decks.front().second + 1) < 10 && (decks.front().first - 1) > -1)
			miss.insert(make_pair(decks.front().first - 1, decks.front().second + 1));
		if ((decks.front().second - 1) > -1)
		{
			if (CellForBool(decks.front().first, decks.front().second - 1, side) == 1)
			{
				for (int i = 0; i < death.size(); i++)
					Cell(death[i].first, death[i].second, side) = 2;
				return false;
			}
			if (CellForBool(decks.front().first, decks.front().second - 1, side) == -1)
				miss.insert(make_pair(decks.front().first, decks.front().second - 1));
			if (CellForBool(decks.front().first, decks.front().second - 1, side) == 2)
				decks.push(make_pair(decks.front().first, decks.front().second - 1));
		}
		if ((decks.front().second + 1) < 10)
		{
			if (CellForBool(decks.front().first, decks.front().second + 1, side) == 1)
			{
				for (int i = 0; i < death.size(); i++)
					Cell(death[i].first, death[i].second, side) = 2;
				return false;
			}
			if (CellForBool(decks.front().first, decks.front().second + 1, side) == -1)
				miss.insert(make_pair(decks.front().first, decks.front().second + 1));
			if (CellForBool(decks.front().first, decks.front().second + 1, side) == 2)
				decks.push(make_pair(decks.front().first, decks.front().second + 1));
		}
		if ((decks.front().first - 1) > -1)
		{
			if (CellForBool(decks.front().first - 1, decks.front().second, side) == 1)
			{
				for (int i = 0; i < death.size(); i++)
					Cell(death[i].first, death[i].second, side) = 2;
				return false;
			}
			if (CellForBool(decks.front().first - 1, decks.front().second, side) == -1)
				miss.insert(make_pair(decks.front().first - 1, decks.front().second));
			if (CellForBool(decks.front().first - 1, decks.front().second, side) == 2)
				decks.push(make_pair(decks.front().first - 1, decks.front().second));
		}
		if ((decks.front().first + 1) < 10)
		{
			if (CellForBool(decks.front().first + 1, decks.front().second, side) == 1)
			{
				for (int i = 0; i < death.size(); i++)
					Cell(death[i].first, death[i].second, side) = 2;
				return false;
			}
			if (CellForBool(decks.front().first + 1, decks.front().second, side) == -1)
				miss.insert(make_pair(decks.front().first + 1, decks.front().second));
			if (CellForBool(decks.front().first + 1, decks.front().second, side) == 2)
				decks.push(make_pair(decks.front().first + 1, decks.front().second));
		}
		death.push_back(decks.front());
		Cell(decks.front().first, decks.front().second, side) = 0;
		decks.pop();
	}
	for (int i = 0; i < death.size(); i++)
		Cell(death[i].first, death[i].second, side) = 2;
	set <pair<int, int>> ::iterator it = miss.begin();
	for (it; it != miss.end(); it++)
		Cell((*it).first, (*it).second, side) = 0;
	return true;
}
char GameField::UserCell(int c)const
{
	if (c == -1)
		return 'O';
	if (c == 0)
		return '*';
	if (c == 1)
		return 'K';
	if (c == 2)
		return 'X';
}
char GameField::AICell(int c)const
{
	if (c == 1)
		return 'K';
	if (c == -1 || c == 1)
		return 'O';
	if (c == 0)
		return '*';
	if (c == 2)
		return 'X';
}
GameField::GameField()
{
	alf = "ABCDEFGHIJ";
	ColUserDecks = 20;
	ColAIDecks = 20;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			UserField[i][j] = -1;
			AIField[i][j] = -1;
		}
}
bool GameField::AddUserShip(Ship ship)
{
	vector<pair<int, int>> decks;
	int startx, starty, endx, endy;
	if (ship.X == ship.X1)
	{
		startx = ship.X;
		endx = startx;
		endy = max(ship.Y, ship.Y1);
		starty = min(ship.Y, ship.Y1);
	}
	else
	{
		startx = min(ship.X, ship.X1);
		endx = max(ship.X, ship.X1);
		starty = ship.Y;
		endy = ship.Y;
	}
	for (int i = starty; i <= endy; i++)
	{
		for (int j = startx; j <= endx; j++)
		{
			if (UserField[i][j] == -1 && IsAroundClear(j, i, 1))
				decks.push_back(make_pair(i, j));
			else
				return false;
		}
	}
	for (int i = 0; i < decks.size(); i++)
		UserField[decks[i].first][decks[i].second] = 1;
	return true;
}
void GameField::AddAIShip(int type)
{
	vector<pair<int, int>> decks;
	bool f;
	int pos_x, pos_y;
	int oriental;
	do
	{
		f = true;
		pos_x = rand() % 10;
		pos_y = rand() % 10;
		oriental = rand() % 4;
		for (int i = 0; i < type; i++)
		{
			if (!(pos_x < 0 || pos_x > 9 || pos_y < 0 || pos_y > 9) && AIField[pos_y][pos_x] == -1 && IsAroundClear(pos_x, pos_y, 2))
			{
				decks.push_back(make_pair(pos_y, pos_x));
			}
			else
			{
				decks.clear();
				f = false;
				break;
			}
			switch (oriental)
			{
			case 0:pos_x++; break;
			case 1:pos_y--; break;
			case 2:pos_x--; break;
			case 3:pos_y++;	break;
			}
		}
	} while (!f);
	for (int i = 0; i < type; i++)
		AIField[decks[i].first][decks[i].second] = 1;
}
int GameField::ShotResult(Shot shot, int side)
{
	if (CellForBool(shot.X, shot.Y, side) == 2 || CellForBool(shot.X, shot.Y, side) == 0)
		return 0;
	if (CellForBool(shot.X, shot.Y, side) == -1)
	{
		Cell(shot.X, shot.Y, side) = 0;
		return -1;
	}
	else
	{
		Cell(shot.X, shot.Y, side) = 2;
		if (side == 1)
			ColUserDecks--;
		else
			ColAIDecks--;
		if (TryToDestroyShip(shot.X, shot.Y, side))
			return 2;
		return 1;
	}
}
int& GameField::Cell(int x, int y, int side)
{
	if (side == 1)
		return UserField[y][x];
	return AIField[y][x];
}
int GameField::CellForBool(int x, int y, int side)
{
	if (side == 1)
		return UserField[y][x];
	return AIField[y][x];
}
int GameField::IsGameOver()
{
	if (ColUserDecks == 0)
		return 1;
	if (ColAIDecks == 0)
		return 2;
	return 0;
}
bool GameField::IsCorrectShip(int x, int y, int x1, int y1, int type)
{
	if (x > -1 && x < 10 && y > -1 && y < 10 && x1 > -1 && x1 < 10 && y1 > -1 && y1 < 10)
		if (x == x1 && abs(y1 - y) == type - 1 || y == y1 && abs(x1 - x) == type - 1)
			return true;
	return false;
}
bool GameField::IsCorrectShot(int x, int y)
{
	if (x > 9 || x < 0 || y > 9 || y < 0)
		return false;
	return true;
}
bool GameField::IsAroundClear(int x, int y, int side)
{
	if ((y - 1) > -1 && CellForBool(x, y - 1, side) == 1 || (y - 1) > -1 && (x + 1) < 10 && CellForBool(x + 1, y - 1, side) == 1 || (y - 1) > -1 && (x - 1) > -1 && CellForBool(x - 1, y - 1, side) == 1 || (y + 1) < 10 && CellForBool(x, y + 1, side) == 1 || (y + 1) < 10 && (x + 1) < 10 && CellForBool(x + 1, y + 1, side) == 1 || (y + 1) < 10 && (x - 1) > -1 && CellForBool(x - 1, y + 1, side) == 1 || (x + 1) < 10 && CellForBool(x + 1, y, side) == 1 || (x - 1) > -1 && CellForBool(x - 1, y, side) == 1)
		return false;
	return true;
}
ostream& operator<<(ostream& out, const GameField& field)
{
	out << "  Ваша игровая доска" << "            " << "Игровая доска компьютера" << endl;
	out << "   ";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			out << "|" << field.alf[j];
		}
		out << "|         ";
	}
	out << endl;
	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
			out << " ";
		else
			out << "  ";
		out << i + 1;
		for (int j = 0; j < 10; j++)
		{
			out << "|" << field.UserCell(field.UserField[i][j]);
		}
		if (i == 9)
			out << "|       ";
		else
			out << "|        ";
		out << i + 1;
		for (int j = 0; j < 10; j++)
		{
			out << "|" << field.AICell(field.AIField[i][j]);
		}
		out << "|";
		out << endl;
	}
	return out;
}