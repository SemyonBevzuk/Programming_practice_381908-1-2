#include "Field.h"

field::field()
{
	pai = new int* [13];
	for (int i = 0; i < 13; i++)
	{
		pai[i] = new int[13];
	}
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			pai[i][j] = 126;

		}
	}
	for (int i = 2; i < 13; i++)
	{
		pai[i][0] = i + 47;
		pai[0][i] = i + 47;

	}
	pai[0][11] = 'D';
	pai[11][0] = 'D';

}

field::~field()
{
	for (int i = 0; i < 13; i++)
	{
		delete[] pai[i];
	}
	delete[] pai;


}




void field::Draw()
{

	int ki, kj, iSmesh, jSmesh;
	for (ki = 0; ki < 13 - 2; ki++)
	{
		if (ki == 0)
			iSmesh = 0;
		else
			iSmesh = 1;
		for (kj = 0; kj < 13 - 2; kj++)
		{
			if (kj == 0)
				jSmesh = 0;
			else
				jSmesh = 1;
			cout << static_cast<char>(pai[ki + iSmesh][kj + jSmesh]) « ' ';
		}
		cout << endl;

	}

}

bool field::CheckSet(int t, int siz, int xx, int yy)
{
	int ix, jy;
	bool place = false;
	if (t == 2)
	{
		ix = xx + siz + 1;
		jy = yy + 2;
	}
	else
	{
		jy = yy + siz + 1;
		ix = xx + 2;
	}
	if (jy > 12 || ix > 12)
	{
		return false;
	}
	for (int i = xx; i < ix + 1; i++)
	{
		for (int j = yy; j < jy + 1; j++)
		{
			if (pai[i][j] == 126)
			{
				place = true;
			}
			else
			{
				return false;
			}
		}
	}


	if (t == 2)
	{
		for (int i = xx + 1; i < ix; i++)
		{
			pai[i][yy + 1] = siz + 48;
		}
	}
	else
	{
		for (int i = yy + 1; i < jy; i++)
		{
			pai[xx + 1][i] = siz + 48;
		}
	}
	return place;
}

bool field::shoot(int xx, int yy)
{
	bool p = false;
	if (pai[xx][yy] != 126 && pai[xx][yy] != 42)
	{
		pai[xx][yy] = 88;
		p = false;
	}
	if (pai[xx][yy] == 126 || pai[xx][yy] == 42)
	{
		pai[xx][yy] = 42;
		p = true;
	}

	return p;

}

void field::eshoot(int xx, int yy, bool miss)
{
	if (miss == false)
		pai[xx][yy] = 88;
	if (miss == true)
		pai[xx][yy] = 42;
}


bool field::win(ship s[])
{
	bool p = false;
	for (int i = 0; i < 10; i++)
	{
		if (s[i].getd() == 0)
			p = true;
		else
			return false;
	}
	return p;
}

bool field::coincident(int xx, int yy)
{
	if (pai[xx][yy] != 88 && pai[xx][yy] != 42)
		return true;
	else
		return false;
}

ship field::gen(int m)
{
	int xx, yy, t;
	bool seted = false;
	ship shp;
	do
	{
		xx = 1 + rand() % 10;
		yy = 1 + rand() % 10;
		t = 1 + rand() % 2;
		seted = CheckSet(t, m, xx, yy);
		shp.set(yy, xx, t, m);
	} while (seted == false);
	return shp;
}

void field::dead(int t, int s, int x, int y)
{
	int ix, jy;
	if (t == 2)
	{
		ix = x + s + 2;
		jy = y + 3;
	}
	else
	{
		jy = y + s + 2;
		ix = x + 3;
	}

	for (int i = x; i < ix; i++)
	{
		for (int j = y; j < jy; j++)
		{
			pai[i][j] = 42;
		}
	}
	if (t == 2)
	{
		for (int i = x + 1; i < x + s + 1; i++)
		{
			pai[i][y + 1] = 88;
		}
	}
	else
		for (int i = y + 1; i < y + s + 1; i++)
		{
			pai[x + 1][i] = 88;
		}
}