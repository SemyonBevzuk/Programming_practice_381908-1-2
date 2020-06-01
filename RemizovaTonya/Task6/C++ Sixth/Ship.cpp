#include "Ship.h"

ship::ship()
{

	x = 0;
	y = 0;
	type = 0;
	size = 0;
	dead = 0;
}

ship::~ship()
{
	x = 0;
	y = 0;
	type = 0;
	size = 0;
	dead = 0;

}

int ship::getx()
{
	return x;
}

int ship::gety()
{
	return y;
}

int ship::gett()
{
	return type;
}

int ship::gets()
{
	return size;
}

int ship::getd()
{
	return dead;
}

void ship::set(int xx, int yy, int t, int siz)
{
	x = xx;
	y = yy;
	type = t;
	size = siz;
	dead = siz;
}

int ship::shot(int xx, int yy)
{
	int res = 2, _x, _y;
	int* shp = new int[size];


	if (type == 1)
	{
		_x = x + size;
		for (int i = x; i < _x; i++)
		{
			shp[i - x] = i;
		}
		for (int i = 0; i < size; i++)
		{
			if (shp[i] == xx && yy == y)
			{
				res = 1;
				dead--;
				break;
			}
		}
		if (dead == 0)
			res = 3;
	}
	if (type == 2)
	{
		_y = y + size;
		for (int i = y; i < _y; i++)
		{
			shp[i - y] = i;
		}
		for (int i = 0; i < size; i++)
		{
			if (shp[i] == yy && xx == x)
			{
				res = 1;
				dead--;
				break;
			}
		}
		if (dead == 0)
			res = 3;
	}
	delete[] shp;
	return res;

}

ship& ship::operator=(const ship& s)
{
	x = s.x;
	y = s.y;
	type = s.type;
	size = s.size;
	dead = s.size;
	return *this;
}