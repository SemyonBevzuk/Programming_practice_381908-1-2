#pragma once
class ship {

private:
	int x;
	int y;
	int type;
	int size;
	int dead;
public:
	ship();
	~ship();
	int getx();
	int gety();
	int gett();
	int gets();
	int getd();
	void set(int xx, int yy, int t, int siz);
	int shot(int xx, int yy);
	ship& operator=(const ship& s);

};