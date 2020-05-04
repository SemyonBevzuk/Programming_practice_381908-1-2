#include "Battlefield.h"
#include<vector>
#include<cstdlib>
#include<iostream>
#include<locale>
#include<queue>

using namespace std;

class AI {
private:
	int HitCount;
	vector<pair<int,int>> LastHit;
	short AIField[10][10]{};
	vector<pair<int, int>> points;
public:
	AI();
	bool randomShoot(Battlefield& field, int& x, int& y);
	bool smartShoot(Battlefield& field, int& x, int& y);
	bool isUserShipDestroyed(Battlefield& field);
	bool isCompShipDestroyed(Battlefield& field, int x, int y);
	void deleteExcessPoints(Battlefield& field);
};